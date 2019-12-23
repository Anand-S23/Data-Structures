class Node:
    def __init__(self, value):
        self.value = value
        self.nextN = None
        self.prevN = None

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
        elif self.tail == None:
            if self.head.value > value:
                self.tail = self.head
                self.head = Node(value)
                self.head.nextN = self.tail
                self.tail.prevN = self.head
            else:
                self.tail = Node(value)
                self.tail.prevN = self.head
                self.head.nextN = self.tail
        else: 
            current_node = self.head
            the_pos = 0
            while current_node.value < value and current_node.nextN != None: 
                the_pos += 1
                current_node = current_node.nextN
            
            if the_pos == 0:
                self.head, self.head.nextN = Node(value), self.head
                self.head.nextN.prevN = self.head 
            elif the_pos == self.count - 1:
                self.tail, self.tail.prevN = Node(value), self.tail
                self.tail.prevN.nextN = self.tail
            else: 
                current = self.head
                for i in range(the_pos-1):
                    current = current.nextN

                temp = current.nextN
                current.nextN = Node(value)
                current.nextN.prevN = current
                current.nextN.nextN = temp
        
        self.count += 1
    
    def pop(self, pos=0):
        if pos == 0:
            self.head = self.head.nextN
            self.head.prevN = None
        elif pos == self.count - 1:
            self.tail = self.tail.prevN
            self.tail.nextN = None
        else: 
            current_node = self.head
            for i in range(pos-1):
                current_node = current_node.nextN
            
            current_node.nextN = current_node.nextN.nextN
            current_node.nextN.nextN = current_node

    def remDups(self):
        current_node = self.head
        while current_node.nextN != None:
            if current_node.value == current_node.nextN.value:
                current_node.nextN, current_node.nextN.nextN.prevN = current_node.nextN.nextN, current_node
            current_node = current_node.nextN


if __name__ == '__main__':
    x = OrderedLinkedList()
    x.add(2)
    x.add(3)
    x.add(1)
    x.add(1)
    x.remDups()
    print(x)
