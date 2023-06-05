'''
Consider telephone book database of N clients. Make use of a hash
table implementation to quickly look up client‘s telephone number. Make use of two
collision handling techniques and compare them using number of comparisons
required to find a set of telephone numbers.
'''

class Hashing:
    def __init__(self):
        self.size = int(input("\nEnter size of hashTable: "))
        self.count = 0
        self.hashTable = [None for i in range(self.size)]

    def hashFunction(self, ele):
        return (ele % self.size)

    def isFull(self):
        if (self.count == self.size):
            return True
        else:
            return False

    def insert(self, ele):
        if (self.isFull()):
            print("\nHash Table is Full!")
        else:
            key = self.hashFunction(ele)
            if (self.hashTable[key] == None):
                self.hashTable[key] = ele
                self.count += 1
                self.display()
            else:
                print("\nCollision occurs!!")
                self.collision(ele)

    def collision(self, ele):
        print("\n\t1-Linear Probing\n\t2-Quadratic Probing")
        ch = int(input("\nEnter your choice: "))
        if (ch == 1):
            self.linear(ele)
        elif (ch == 2):
            self.quadratic(ele)
        else:
            print("\nInvalid Choice!!")

    def linear(self, ele):
        flag = 0
        key = self.hashFunction(ele)
        for i in range(key, self.size):
            if (self.hashTable[i] == None):
                self.hashTable[i] = ele
                self.count += 1
                flag = 1
                self.display()
                break
        if (flag == 0):
            print("\nThis element cannot be placed in hash table!")

    def quadratic(self, ele):
        flag = 0
        key = self.hashFunction(ele)
        for i in range(self.size):
            hk = (key + i**2) % self.size
            if (self.hashTable[hk] == None):
                self.hashTable[hk] = ele
                self.count += 1
                flag = 1
                self.display()
                break
        if (flag == 0):
            print("\nThis element cannot be placed in hash Table!!")

    def display(self):
        print("\n\tIndex \t Key")
        for i in range(self.size):
            print(f"\t{i} : \t{self.hashTable[i]}")

obj = Hashing()

n = int(input("\nEnter how many elements you want to insert: "))
for i in range(n):
    ele1 = int(input("\nEnter element: "))
    obj.insert(ele1)
