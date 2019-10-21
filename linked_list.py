class Node:
    def __init__(self, value):
        self.value = value
        self.nextN = None

    def __str__(self):
        return f'Node({self.value})'

    __repr__ = __str__


class OrderedLinkedList:
    def __init__(self):
        self.head = None 
        self.tail = None 
        self.count = 0 

    def __str__(self):
        temp=self.head 
        out = []
        while temp:
            out.append(str(temp.value))
            temp = temp.nextN
        out = ' '.join(out)
        return f'Head:{self.head}\nTail:{self.tail}\nList:{out}'

        __repr__ = __str__
    
    def isEmpty(self):
        return self.head == None
    
    def __len__(self):
        return self.count
    
    def add(self, value):
        if self.head == None:
            self.head = Node(value)
            self.count += 1
        elif self.tail == None:
            if value > self.head.value:
                self.head.nextN = Node(value)
                self.tail = Node(value)
                self.count += 1 
            else:
                self.head, self.tail = Node(value), self.head
                self.head.nextN = self.tail
                self.count += 1 
        else: 
            current_node = self.head
            for i in range(self.count):
                print(current_node.value, value)
                if value < current_node.value:
                    current_node.nextN = Node(value)
                    print(current_node.value, current_node.nextN)

                current_node = current_node.nextN
            self.count += 1

            '''
            print(current_node)
            while current_node != None:
                print(current_node, current_node.nextN)
                if value > current_node.value:
                    current_node = current_node.nextN
                 
                current_node.value, current_node.nextN = value, current_node
                self.count += 1
            '''
    
    def pop(self):
        current_node = self.head
        while current_node != None: 
            current_node.value, current_node.nextN = current_node.nextN.value, current_node.nextN.nextN 
            if current_node.nextN == None:
                self.tail = current_node
            current_node = current_node.nextN
    
    def remDups(self):
        current_node = self.head
        while current_node != None and current_node.nextN != None: 
            if current_node.nextN.value == current_node.value:
                while current_node != None: 
                    current_node.value, current_node.nextN = current_node.nextN.value, current_node.nextN.nextN 
                    if current_node.nextN == None:
                        self.tail = current_node
                    current_node = current_node.nextN 
            else: 
                current_node = current_node.nextN


x = OrderedLinkedList()
x.add(1)
print(x)
print(x.head, x.head.nextN)
x.add(5)
print(x)
x.add(3)
print(x)
