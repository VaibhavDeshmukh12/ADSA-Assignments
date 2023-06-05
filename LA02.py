'''
Implement all the functions of a dictionary (ADT) using hashing and handle collisions
using chaining with / without replacement.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)
'''

class Dictionery:
    def __init__(self):
        self.size = int(input("\nEnter size of hash Table: "))
        self.dict = {}
    
    def add_list(self):
        for i in range(self.size):
            self.dict[i] = []
    
    def insert(self,key,val):
        index = val % self.size
        lst = []
        lst += [key,val]
        self.dict[index].append(lst)
        return self.dict
    
    def search(self,key):
        flag = 0
        for i in self.dict:
            for j in self.dict[i]:
                if j[0] == key:
                    flag = 1
                    break
        if(flag == 1):
            print("\nKey is present!!")
        else:
            print("\nKey is not present!")

    def dele(self,key):
        flag = 0
        for i in self.dict:
            for j in self.dict[i]:
                if j[0] == key:
                    print("\nKey deleted successfully!!")
                    self.dict[i].remove(j)
                    flag = 1
                    break
        if(flag == 0):
            print("\nKey is not present!!")
    
    def main(self):
        while True:
            print("\n\t1-Insert Record\n\t2-Display Record\n\t3-Search Record\n\t4-Delete Record\n\t5-Exit\n")
            ch = int(input("Enter your choice: "))
            if(ch == 1):
                key = input("\nEnter Key: ")
                val = int(input("\nEnter Value: "))
                self.arr = self.insert(key,val)
            elif(ch == 2):
                print("\n\tKey \t\tValue")
                for i in self.arr:
                    print(f"\t{i}\t:\t{self.arr[i]}")
            elif(ch == 3):
                key = input("\nEnter key to search: ")
                self.search(key)
            elif(ch == 4):
                key = input("\nEnter key to delete: ")
                self.dele(key) 
            elif(ch == 5):
                print("\n\t----THANK YOU----")
                break
            else:
                print("\nInvalid choice!!")

obj = Dictionery()
obj.add_list()
obj.main()