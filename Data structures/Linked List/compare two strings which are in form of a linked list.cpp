/*Given two linked lists, represented as linked lists (every character is a node in linked list). Write a function compare() that works similar to strcmp(), i.e., it returns 0 if both strings are same, 1 if first linked list is lexicographically greater,
 and -1 if second string is lexicographically greater.*/
 
int compare(node* list1, node* list2) {
	
	while(list1 and list2 and list1->data == list2->data) {
		list1 = list1->next;
		list2 = list2->next;
	}
	
	if(list1 and list2) 
		return (list1->data > list2->data) ? 1 : -1;
	
	if(list1 and !list2) return 1;
	if(list2 and !list1) return -1;
	
	return 0;
}

// python //

# Python program to compare two strings represented as
# linked lists
 
# A linked list node structure
class Node:
 
    # Constructor to create a new node
    def __init__(self, key):
        self.c = key ; 
        self.next = None
 
def compare(list1, list2):
     
    # Traverse both lists. Stop when either end of linked 
    # list is reached or current characters don't watch
    while(list1 and list2 and list1.c == list2.c):
        list1 = list1.next
        list2 = list2.next
 
    # If both lists are not empty, compare mismatching
    # characters 
    if(list1 and list2):
        return 1 if list1.c > list2.c else -1
 
    # If either of the two lists has reached end
    if (list1 and not list2):
        return 1
 
    if (list2 and not list1):
        return -1
    return 0
 
# Driver program
 
list1 = Node('g')
list1.next = Node('e')
list1.next.next = Node('e')
list1.next.next.next = Node('k')
list1.next.next.next.next = Node('s')
list1.next.next.next.next.next = Node('b')
 
list2 = Node('g')
list2.next = Node('e')
list2.next.next = Node('e')
list2.next.next.next = Node('k')
list2.next.next.next.next = Node('s')
list2.next.next.next.next.next = Node('a')
 
print compare(list1, list2)
