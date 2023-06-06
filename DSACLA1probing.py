'''Consider telephone book database of N clients. Make use of a hash table
implementation to quickly look up client‘s telephone number. Make use of two collision
handling techniques and compare them using number of comparisons required to find a
set of telephone numbers'''

class Linearprobing:
    teleno = []
    name = []

    def __init__(self):
        self.m = int(input("Enter size of the hash table : "))
        for i in range(self.m):
            self.teleno.append(0)
            self.name.append(0)

    def hashfunc(self, x):
        key = x % self.m
        return key

    def initialize(self, arr, names):
        for i in range(len(arr)):
            key = self.hashfunc(arr[i])
            while (self.teleno[key] != 0):
                key = (key + 1) % self.m
            self.teleno[key] = arr[i]
            self.name[key] = names[i]

    def search(self, name):
        comparisons = 0
        for i in range(self.m):
            comparisons += 1
            if self.name[i] == name:
                print("Telephone number for", name, "is", self.teleno[i])
                return comparisons
        print(name, "not found")
        return comparisons

    def display(self):
        print("\nsr no. - teleno - name")
        for i in range(self.m):
            print(i, ' - ', self.teleno[i], ":", self.name[i])


class Doublehashing:
    teleno = []
    name = []

    def __init__(self):
        self.m = int(input("Enter size of the hash table : "))
        self.p = self.primeno(self.m - 1)
        for i in range(self.m):
            self.teleno.append(0)
            self.name.append(0)

    def primeno(self, n):
        while True:
            if self.isprime(n):
                return n
            n -= 1

    def isprime(self, n):
        if n <= 1:
            return False
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True

    def hashfunc1(self, x):
        return x % self.m

    def hashfunc2(self, x):
        return self.p - (x % self.p)

    def initialize(self, arr, names):
        for i in range(len(arr)):
            key = self.hashfunc1(arr[i])
            if self.teleno[key] == 0:
                self.teleno[key] = arr[i]
                self.name[key] = names[i]
            else:
                j = self.hashfunc2(arr[i])
                while True:
                    next = (key + j) % self.m
                    if self.teleno[next] == 0:
                        self.teleno[next] = arr[i]
                        self.name[next] = names[i]
                        break
                    else:
                        j += self.hashfunc2(arr[i])

    def search(self, name):
        comparisons = 0
        for i in range(self.m):
            comparisons += 1
            if self.name[i] == name:
                print("Telephone number for", name, "is", self.teleno[i])
                return comparisons
        print(name, "not found")
        return comparisons
    def display(self):
        print("\nsr no. - teleno - name")
        for i in range(self.m):
            print(i, ' - ', self.teleno[i], ":", self.name[i])


def main():
    n = int(input("Enter number of the persons : "))
    s = []
    p = []
    for i in range(n):
        t = int(input("Enter telephone number : "))
        s.append(t)
        n = (input("Enter name : "))
        p.append(n)
    print("MENU")
    print("1.Linear probing")
    print("2.Double hashing")
    print("3.EXIT")
    while (True):
        choice = int(input("Enter your choice : "))
        if choice == 1:
            linear = Linearprobing()
            linear.initialize(s, p)
            linear.display()
            name = input("Enter name to search : ")
            comparisons = linear.search(name)
            print("Number of comparisons made : ", comparisons)

        elif choice == 2:
            double = Doublehashing()
            double.initialize(s, p)
            double.display()
            name = input("Enter name to search : ")
            comparisons = double.search(name)
            print("Number of comparisons made : ", comparisons)


        elif choice == 3:
            print("Exit the program")
            break


main()