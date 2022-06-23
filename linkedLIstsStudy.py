# LINKED LIST CONCEPTS AND TERMS:

# Abstraction: All a user needs to kno are the alloable data types and allowable operations
# No understanding of implementation is required

#Consistency: Implementation can change

# Difference between a list and a linked list: 
# LIST: a mutable ordered collection of items that do not have to be of the same type, implemented in C using dynamic array
# LINKED LIST: mutable, ordered collection of items linked with pointers; Linear data structure, or SEQUENTIAL ACCESS DATA STRUCTURE. They are also RECURSIVE

# NODES: data stored in a series of nodes, contains data and a pointer to the memory slot of the next node in the list.
# DOUBLY-LINKED LISTS: Pointers to the previous slot of memory and the next
# SINGLY-LINKED LISTS: Points only to the next slot of memory

# HEAD: Entry-point to the linked list. Reference to the first node, not a separate node.
# TAIL: Last node, pointer points to none

# To-do: 
# 1 - Add a node to the beginning and end of the list
#  - We may need to add a key, which is a node added just before or after an existing node whose data item matches something we're looking for
# 2 - Remove a node at the head or tail, or just before or after a key
# 3 - Identify if a list is empty
# 4 - Identify how many nodes are in the list
# 5 - Find a node's index given it's key

# WHEN would we use a linked list?:
# 1. Inserting items 'in between' other items
# 2. Collection size is unknown
# 3. You don't need random access
# 4. Not concerned about memory usage

# LINKED LISTS are RECURSIVE:
# - Either empty, or consists of a node that contains data and a pointer to a linked list


# PRACTICE:

class SLLNode:
    
    def __init__(self, data):
        self.data = data
        self.next = None
    
    def __repr__(self):
        return "SLLNode Object: data={}".format(self.data)
        
    def get_data(self):
        """Return the self.data attribute"""
        return self.data
    
    def set_data(self, new_data):
        """Replace the existing value of the self.data atribute with new_data parameter."""
        self.data = new_data
    
    def get_next(self):
        """Return the self.next attribute"""
        return self.next
    
    def set_next(self, new_next):
        """Replace the existing value of the self.next attribute with the new_next parameter."""
        self.next = new_next

class SLL:
    
    def __init__(self):
        self.head = None
    
    def __repr__(self):
        return "SLL object: head{}".format(self.head)
    
    def is_empty(self):
        """When we call this method, it will return true if the list is empty, otherwise, it will return false. """
        return self.head is None
    
    def add_front(self, new_data):
        """Add a Node whose data is the new_data argument to the front of the Linked List."""
        temp = SLLNode(new_data)
        temp.set_next(self.head)
        self.head = temp
    
    def size(self):
        """Traverses the Linked List and returns an integer value represending the number of nodes in the Linked List
        
        The time complexity is 0(n), because every node in the linked list must be visited in order to calculate the size of the linked list.        
        """
        size = 0
        if self.head is None:
            return 0
        current = self.head
        while current is not None:
            size += 1
            current = current.get_next()
            
        return size
    
    def search(self, data):
        """Traversed the Linked List and returns True if the data searched for is present in one of the Nodes. Otherwise, it returns false.
        
        The time complexity is 0(n), because every node in the Linked List must be visited in order to calculate the size of the Linked List.
        """
        if self.head is None:
            return "Linked List is empty. No Nodes to search."
        
        current = self.head
        while current is not None:
            if current.get_data() == data:
                return True
            else:
                current = current.get_next()
        return False
    
    def remove(self, data):
        """Removes the first occurance of the Node that contains the data argument as its self.data variable. Returns nothing.
        
        Time complexity is O(n), because in the worst case scenario, the node we want to remove is the last node in the Linked List."""
        if self.head == None:
            return "The Linked List is empty. No Nodes to remove."
        current = self.head
        previous = None
        found = False
        while not found: 
            if current.get_data() == data:
                found = True
            else:
                if current.get_next() == None:
                    return "A Node with that data value is not present."
                else:
                    previous = current
                    current = current.get_next()
        if previous is None:
            self.head = current.get_next()
        else:
            previous.set_next(current.get_next())
            
        pass
    
    
        
        
        
        
        
        
class DLLNode:
    
    def __init__(self, data):
        self.data = data
        self.next = None
        self.previous = None
    
    def __repr__(self):
        return "SLLNode Object: data={}".format(self.data)
        
    def get_data(self):
        """Return the self.data attribute"""
        return self.data
    
    def set_data(self, new_data):
        """Replace the existing value of the self.data atribute with new_data parameter."""
        self.data = new_data
    
    def get_next(self):
        """Return the self.next attribute"""
        return self.next
    
    def set_next(self, new_next):
        """Replace the existing value of the self.next attribute with the new_next parameter."""
        self.next = new_next
        
    def get_previous(self):
        """Return the self.previous attribute"""
        return self.previous
    
    def set_previous(self, new_previous):
        """Replace the existing value of the self.previous attribute with the new_next parameter."""
        self.previous = new_previous


sll = SLL()
print(sll.search(3))
print(sll.is_empty())
print(sll.size())
print(sll.remove(14))

sll.head
sll.add_front('apple')
sll.add_front('orange')
sll.add_front('pickle')
print(sll.head)
print(sll.size())
print(sll.search('apple'))
print(sll.remove('cheese'))
sll.remove('pickle')
print(sll.head)
sll.add_front('Michael Scott')
sll.remove('orange')
print(sll.head)
print(sll.search('apple'))
    
# node2 = SLLNode('carrot')
# node.set_next(node2)
# print(node.get_next())

print(sll.is_empty())

# node1 = DLLNode(1)
# node3 = DLLNode(2)
# node1.get_previous()
# node1.set_previous(node3)
# print(node1.get_previous())
