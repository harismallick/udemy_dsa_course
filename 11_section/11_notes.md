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

