class Book:

    def __init__(self, name, publisher, price, grade):
        self.name = name
        self.publisher = publisher
        self.price = price
        self.grade = grade

    def info(self):
        print(f'제목: {self.name}')
        print(f'출판사: {self.publisher}')
        print(f'가격: {self.price}')
        print(f'평점: {self.grade}')
        print()

    def mark(self, num):
        print(self.grade[num])


book1 = Book('나는 라인 개발자입니다', '한빛미디어', '16000', ['*5', '*3', '*1'])
book2 = Book('알아두면 쓸모있는 IT 상식', '원앤원북스', '15000', ['*5', '*3', '*1'])
book3 = Book('게임 만드는 사람들의 리얼 수다', '한빛미디어', '18000', ['*5', '*3', '*1'])

book1.info()
book2.info()
book2.info()

book1.mark(1)
book2.mark(0)
book3.mark(2)