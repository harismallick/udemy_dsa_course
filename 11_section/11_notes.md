## Linked List

#### 172 - Intro to Linked List

- In this video, the following topics will be covered:
  - What is a linked list
  - What is a node
  - Node structure
  - How to create a node
  - How to access a node

#### Improving Linear Search in a Linked List

- Binary search in a linked list is not possible.
- Linear search takes O(N) time.
- But, searching through a linked list can be optimised by using transposition or move-to-head methods learned previously.
- In move to head, the node being searched will be made the head of the LL.
- If the same value is searched again, then the operation would be done in O(1) time.

#### Lesson 198

- Reversing the elements in the nodes rather than the pointers pointing to each node.
- Not an optimal solution as you need to create an array the same size as the linked list to hold all the values.
- Time complexity: O(2n) ~ O(n)

```
Pseudocode

p = first_node; //pointer_to_node
array[n]; // n elements in the linked list
int i = 0;

while (p != NULL)
    copy data from node at p to array[i];
    i++;
    p = p->next;

p = first_node

while (p != NULL)
    copy data from array[i] to p->data;
    i--;
    p = p->next;
```

#### Lesson 199

- Reversing the pointers connecting the linked list to reverse the list.
- This operation can be done by looping through the linked list only **once**.
- **Three pointers** needed to solve the problem.
- One pointer to point to the current node.
- One to point to the previous node.
- One to point to the next node.


#### Lesson 224 - Comparing the different types of linked lists

- The four types of linked-lists and their properties:

1. Singly Linked List:
   1. Space: n nodes, n links
   2. Insert: O(1) for head; O(N) otherwise. One pointer reference modified for head, otherwise two.
   3. Delete: One pointer to be modified.
   4. Traverse: O(N) time; one direction only
2. Circular Singly Linked List:
   1. Space: n nodes, n links
   2. Insert: O(N) for every case because the last node's next-pointer needs to be modified if head is changed. Two pointer references modified.
   3. Delete: One pointer to modify.
   4. Traverse: O(N) time; one direction only
3. Doubly Linked List
   1. Space: n nodes, 2n links
   2. Insert: O(1) for head/tail; O(N) otherwise. Three pointer links modified for insert at head, otherwise three.
   3. Delete: Two pointers to modify.
   4. Traverse: O(N) time; bi-directional
4. Circular Doubly Linked List:
   1.  Space: n nodes, 2n links
   2.  Insert: O(1) for head/tail; O(N) otherwise. Always four pointer links modified.
   3.  Delete: Two pointers to modify.
   4.  Traverse: O(N) time; bi-directional

Which to use? Depends on the requirements.
But as space constraints is no longer a concern in modern development, doubly linked list or circular doubly linked list is best.


#### Lesson 225: Array vs Linked List

- These are the two core data structures.
- All other data structures are created using these two, in some fasion.
- Array can be created in stack or heap memory. LLs always created in heap.
- Arrays are static in size; need to create a new array of larger size to hold more elements.
- Linked list can hold as many elements are heap memory will allow.
- The space utilised by an array is n * datatype. Linked list is n * (node + pointer to next node). So LL takes more space.
- Data access: O(1) for array. O(N) for LL.
- Insert operation: O(1) inserting at end and O(N) inserting at start for an array. Its oppposite for LL.
- Delete operation: Same time complexity as for insertion.
- Search algorithms: Both linear and binary search can be done on arrays. Only linear search on LL (binary search on LL is O(nlogn) which is worse than linear)


#### Lesson 226 - Finding middle node of a linked list

- Optimal solution: use two pointers.
- Loop through the LL and in each iteration, one pointer moves forward twice, while the other only moves forward once.
- By the time the two-move pointer reaches the end of the LL, the one-move pointer will be in the middle.
- Return the Node address held by the one-move pointer.

#### Lesson 227 - Finding the intersection point of two linked lists

- Need to create stack data structures to solve this problem.
- Loop through LL1 and add all nodes to stack1.
- Loop through LL2 and add all nodes to stack2.
- Now loop through both stacks until the node at the top of each stack is **not** identical.
- use a pointer to hold the previously popped node.
- Once the loop ends, return last value held by this pointer.

TODO: Code the implementation after learning the stack data structure in the course.