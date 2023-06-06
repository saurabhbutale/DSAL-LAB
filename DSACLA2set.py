'''To create ADT that implement the "set" concept.
a. Add (new Element) -Place a value into the set , b. Remove (element) Remove the
value
c. Contains (element) Return true if element is in collection, d. Size () Return number of
values in collection Iterator () Return an iterator used to loop over collection, e.
Intersection of two sets , f. Union of two sets, g. Difference between two sets, h. Subset'''
class CustomList:
    def __init__(self):
        self.elements = []

    def create(self):
        z = int(input("Enter the number of element: "))
        for i in range(z):
            iteam = int(input(f"Enter element {i + 1} of a set: "))
            self.elements.append(iteam)

    def add_element(self, element):
        self.elements.append(element)

    def remove_element(self, element):
        for i in range(len(self.elements)):
            if self.elements[i] == element:
                del self.elements[i]
                return True
        return False

    def contains_element(self, element):
        for i in range(len(self.elements)):
            if self.elements[i] == element:
                return True
        return False

    def size(self):
        return len(self.elements)

    def iterator(self):
        return iter(self.elements)

    def intersection(self, other_list):
        result = CustomList()
        for element in self.elements:
            if other_list.contains_element(element):
                result.add_element(element)
        return result

    def union(self, other_list):
        result = CustomList()
        for element in self.elements:
            result.add_element(element)
        for element in other_list.elements:
            if not result.contains_element(element):
                result.add_element(element)
        return result

    def difference(self, other_list):
        result = CustomList()
        for element in self.elements:
            if not other_list.contains_element(element):
                result.add_element(element)
        return result

    def is_subset(self, other_list):
        for element in self.elements:
            if not other_list.contains_element(element):
                return False
        return True


list1 = CustomList()
list2 = CustomList()
while True:
    print("\n***MAIN MENU****")
    print("1.create a two set")
    print("2. Add element")
    print("3. Remove element")
    print("4. Check if element exists")
    print("5. Get size of list")
    print("6. Get intersection of lists")
    print("7. Get union of lists")
    print("8. Get difference between lists")
    print("9. Check if one list is a subset of the other")
    print("10. Quit")
    ch = int(input("enter your choice:"))
    if ch == 1:
        print("create a first set.")
        list1.create()
        print("Set1:", "{" + str(list1.elements)[1:-1] + "}")
        print("create a second set.")
        list2.create()
        print("Set2:", "{" + str(list2.elements)[1:-1] + "}")
    # getting user input for list1
    elif ch == 2:
        lst = int(input("enter a set that you want to be add element(1 or 2):"))
        if lst == 1:
            element = int(input("Enter element  to be  insert in set1: "))
            list1.add_element(element)
            print("set1:", "{" + str(list1.elements)[1:-1] + "}")
        elif lst == 2:
            element = int(input("Enter element  to be  insert in set2: "))
            list2.add_element(element)
            print("set2:", "{" + str(list2.elements)[1:-1] + "}")
    elif ch == 3:
        lst = int(input("enter a set that you want to be remove element(1 or 2):"))
        if lst == 1:
            element = int(input("Enter element  to be  remove in set1: "))
            list1.remove_element(element)
            print("set1:", "{" + str(list1.elements)[1:-1] + "}")
        elif lst == 2:
            element = int(input("Enter element  to be  remove in set2: "))
            list2.remove_element(element)
            print("set2:", "{" + str(list2.elements)[1:-1] + "}")

    elif ch == 4:

        lst = int(input("enter a set in which we can check(1 or 2):"))
        if lst == 1:
            ck_element = int(input("enter a element to be check for inside the set or not:"))
            print(list1.contains_element(ck_element))
        elif lst == 2:
            ck_element = int(input("enter a element to be check for inside the set or not:"))
            print(list2.contains_element(ck_element))



    elif ch == 5:
        print("size of set1:", list1.size())
        print("size of set2:", list2.size())
        print("Iterator for set1:")
        for element in list1.iterator():
            print(element)
        print("Iterator for set2:")
        for element in list2.iterator():
            print(element)

    # print(list2.iterator())
    elif ch == 6:
        print("Intersection:", list1.intersection(list2).elements)
    elif ch == 7:
        print("Union:", list1.union(list2).elements)
    elif ch == 8:
        print("Difference:", list1.difference(list2).elements)
    elif ch == 9:
        print("set1 is subset of set2:", list1.is_subset(list2))
    elif ch == 10:
        print("EXIT")
        print("THE PROGRAM IS SUCCESSFULLY RUN")
        break

