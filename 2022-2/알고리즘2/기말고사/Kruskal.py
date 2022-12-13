from pathlib import Path
from queue import PriorityQueue
import timeit

'''
Class for storing weighted edges
'''
class Edge:
    def __init__(self, v, w, weight): # Create an edge v-w with a double weight
        if v<=w: self.v, self.w = v, w  # Put the lesser number in v for convenience
        else: self.v, self.w = w, v        
        self.weight = weight
    
    def __lt__(self, other): # < operator, used to sort elements (e.g., in a PriorityQueue, sorted() function)
        assert(isinstance(other, Edge))
        return self.weight < other.weight

    def __gt__(self, other): # > operator, used to sort elements
        assert(isinstance(other, Edge))
        return self.weight > other.weight

    def __eq__(self, other): # == operator, used to compare edges for grading
        assert(isinstance(other, Edge))
        return self.v == other.v and self.w == other.w and self.weight == other.weight

    def __str__(self): # Called when an Edge instance is printed (e.g., print(e))
        return f"{self.v}-{self.w} ({self.weight})"

    def __repr__(self): # Called when an Edge instance is printed as an element of a list
        return self.__str__()

    def other(self, v): # Return the vertex on the Edge other than v
        if self.v == v: return self.w
        else: return self.v

'''
Class for storing WUGraphs (Weighted Undirected Graphs)
'''
class WUGraph:
    def __init__(self, V): # Constructor
        self.V = V # Number of vertices
        self.E = 0 # Number of edges
        self.adj = [[] for _ in range(V)]   # adj[v] is a list of vertices adjacent to v
        self.edges = []

    def addEdge(self, v, w, weight): # Add edge v-w. Self-loops and parallel edges are allowed
        e = Edge(v, w, weight) # Create one edge instance and use it for adj[v], adj[w], and edges[]
        self.adj[v].append(e)
        self.adj[w].append(e)
        self.edges.append(e)
        self.E += 1

    def removeEdge(self, e):
        assert(isinstance(e, Edge))
        assert(e in self.adj[e.v] and e in self.adj[e.w])
        self.adj[e.v].remove(e)
        self.adj[e.w].remove(e)
        self.edges.remove(e)
        self.E -= 1

    def degree(self, v):
        return len(self.adj[v])

    def __str__(self):
        rtList = [f"{self.V} vertices and {self.E} edges\n"]
        for v in range(self.V):
            for e in self.adj[v]:
                if v == e.v: rtList.append(f"{e}\n") # Do not print the same edge twice
        return "".join(rtList)

    '''
    Create a WUGraph instance from a file
        fileName: Name of the file that contains graph information as follows:
            (1) the number of vertices, followed by
            (2) one edge in each line, where an edge v-w with weight is represented by "v w weight"
            e.g., the following file represents a digraph with 3 vertices and 2 edges
            3
            0 1 0.12
            2 0 0.26
        The file needs to be in the same directory as the current .py file
    '''
    @staticmethod
    def fromFile(fileName):
        filePath = Path(__file__).with_name(fileName)   # Use the location of the current .py file   
        with filePath.open('r') as f:
            phase = 0
            line = f.readline().strip() # Read a line, while removing preceding and trailing whitespaces
            while line:                                
                if len(line) > 0:
                    if phase == 0: # Read V, the number of vertices
                        g = WUGraph(int(line))
                        phase = 1
                    elif phase == 1: # Read edges
                        edge = line.split()
                        if len(edge) != 3: raise Exception(f"Invalid edge format found in {line}")
                        g.addEdge(int(edge[0]), int(edge[1]), float(edge[2]))                        
                line = f.readline().strip()
        return g

'''
Class for performing Union Find using weighted quick union
    and storing the results    
'''
class UF:
    def __init__(self, V): # V: the number of vertices
        self.ids = [] # ids[i]: i's parent
        self.size = [] # size[i]: size of tree rooted at i
        for idx in range(V):
            self.ids.append(idx)
            self.size.append(1)       

    def root(self, i):
        while i != self.ids[i]: i = self.ids[i]
        return i

    def connected(self, p, q):
        return self.root(p) == self.root(q)

    def union(self, p, q):    
        id1, id2 = self.root(p), self.root(q)
        if id1 == id2: return
        if self.size[id1] <= self.size[id2]: 
            self.ids[id1] = id2
            self.size[id2] += self.size[id1]
        else:
            self.ids[id2] = id1
            self.size[id1] += self.size[id2]


'''
Find an MST (Minimum Spanning Tree) using Prim's algorithm (lazy version)
    and return the MST with its weight sum
'''
def mstPrimLazy(g):
    def include(v):
        included[v] = True
        for e in g.adj[v]:            
            if not included[e.other(v)]: pq.put(e)

    assert(isinstance(g, WUGraph))

    edgesInMST = [] # Stores edges selected as part of the MST
    included = [False] * g.V # included[v] == True if v is in the MST
    weightSum = 0  # Sum of edge weights in the MST    
    pq = PriorityQueue() # Build a priority queue
    include(0)

    while not pq.empty() and len(edgesInMST) < g.V-1:
        e = pq.get()        
        if included[e.v] and included[e.w]: continue # Ignore the edge v-w if both v and w are included in the MST
        edgesInMST.append(e)
        weightSum += e.weight
        if not included[e.v]: include(e.v) # Add to the MST the vertex not yet included
        if not included[e.w]: include(e.w)

    return edgesInMST, weightSum    


'''
Find an MST (Minimum Spanning Tree) using Kruskal's algorithm
    and return the MST with its weight sum
'''
def mstKruskal(g):
    assert (isinstance(g, WUGraph))

    edge = []
    w_sum = 0
    pq = PriorityQueue()
    uf = UF(g.V)

    for e in g.edges:
        pq.put(e)

    while not pq.empty() and len(edge) < g.V - 1:
        e = pq.get()
        if not uf.connected(e.v, e.w):
            uf.union(e.v, e.w)
            edge.append(e)
            w_sum += e.weight

    return edge, w_sum
    

if __name__ == "__main__":
    # Unit test for mstKruskal
    correct = True

    print("Correctness test with wugraph8.txt")
    g8 = WUGraph.fromFile("wugraph8.txt")
    edges, weightSum = mstKruskal(g8)
    print("Kruskal on g8", edges, weightSum)    
    if edges == [Edge(0,7,0.16), Edge(2,3,0.17), Edge(1,7,0.19), Edge(0,2,0.26), Edge(5,7,0.28), Edge(4,5,0.35), Edge(2,6,0.4)]: print ("pass")
    else: 
        print ("fail")
        correct = False
    if weightSum == 1.81: print ("pass")
    else: 
        print ("fail")
        correct = False
    print()
    
    print("Correctness test with wugraph8a.txt")
    g8a = WUGraph.fromFile("wugraph8a.txt")
    edges, weightSum = mstKruskal(g8a)
    print("Kruskal on g8a", edges, weightSum)
    if edges == [Edge(2,3,4.0), Edge(0,1,5.0), Edge(1,2,6.0), Edge(5,6,7.0), Edge(1,4,8.0), Edge(5,7,9.0), Edge(0,5,11.0)]: print ("pass")
    else: 
        print ("fail")
        correct = False
    if weightSum == 50: print ("pass")
    else: 
        print ("fail")
        correct = False
    print()

    print("Correctness test with wugraph1.txt")
    g1 = WUGraph.fromFile("wugraph1.txt")
    edges, weightSum = mstKruskal(g1)
    print("Kruskal on g1", edges, weightSum)
    if edges == []: print ("pass")
    else: 
        print ("fail")
        correct = False
    if weightSum == 0: print ("pass")
    else: 
        print ("fail")
        correct = False
    print()

    print("Correctness test with wugraph5.txt")
    g5 = WUGraph.fromFile("wugraph5.txt")
    edges, weightSum = mstKruskal(g5)
    print("Kruskal on g5", edges, weightSum)
    if edges == [Edge(0,1,1.0), Edge(1,2,3.0), Edge(2,3,5.0), Edge(3,4,7.0)]: print ("pass")
    else: 
        print ("fail")
        correct = False
    if weightSum == 16.0: print ("pass")
    else: 
        print ("fail")
        correct = False
    print()

    print("Speed test with wugraph8.txt")
    if not correct: print("fail (since the algorithm is not correct)")
    else:
        n = 1000        
        tKruskal = timeit.timeit(lambda: mstKruskal(g8), number=n)/n
        tPrimLazy = timeit.timeit(lambda: mstPrimLazy(g8), number=n)/n
        print(f"Average running time for g8 with Kruskal ({tKruskal:.10f}) and PrimLazy ({tPrimLazy:.10f})")
        if tKruskal < tPrimLazy * 1.4: print ("pass")
        else: print("fail")
        if tKruskal < tPrimLazy * 1.2: print ("pass")
        else: print("fail")
    print()
    
    