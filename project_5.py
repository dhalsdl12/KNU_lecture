import turtle as t 

with open('test.txt', 'r') as f: 
    lines = f.readlines() 
    values = list(map(int, lines)) 

    
t.shape('turtle') 
n = len(values) 

for i in range(0, n - 1, 2): 
    t.forward(values[i]) 
    t.right(values[i + 1]) 
 
t.forward(values[-1]) 
