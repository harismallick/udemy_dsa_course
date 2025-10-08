## Section 4: Introduction to datastructures

### Video 39 Notes
- What is a datastructure?
- It is simply a collection of data for efficient access and manipulation.
- Depending on the datatype and/or the type of operation (CRUD), a different datastructure might be more appropriate for the task.
- __Datastructures__ are created in the main memory.
- __Databases__ are created in the storage drive (HDD, SSD).
- The database entries need to be read into the main memory to perform any operations on them.
- A __data warehouse__ is a large collection of HDDs or SSDs or tape-storage for storing large amounts legacy data that is not accessed regularly.
- Algorithms written to access data from warehouses are known as data-mining algorithms.

### Video 40 Notes
- Each byte of main memory can be accessed using its memory address, which is a hexadecimal identifier.
- Main memory is divided into segments. Each segment is composed of 64 KB.
- A computer program utilises a memory segment by dividing it into 3 segments:
    1. Code section: The machine code of a program occupies this section.
    2. Stack memory: Any variables declared in the main() function of the program occupy the stack. All helper function variables also occupy the stack.
           - Stack memory management is handled by the compiler.
    3. Heap memory: Any memory allocation required by the program is accessed from the heap.

### Video 42 Notes
- There are two categories of data strutures: physical and logical.
- Arrays and linked lists are physical datastructures, because this is how data is actually loaded onto the main memory, or some variation of it.
- Arrays can be allocated in the stack or heap.
- Linked list can only be allocated from the heap. This is because the size of a linked list is unknown. As more elements are added, more memory will be needed.
- Logical data structures are:
  - Stack - Linear DS; LIFO
  - Queue - Linear DS; FIFO
  - Tree - Non-linear
  - Graph - Non-linear
  - Hash Table - Tabular DS
- All logical data strctures are created using either arrays or linked lists, or a combination of the two.

### Video 43 Notes
- Abstract data types (ADT)
- Each datatype has its representation and group of operations that can be performed on the datatype.
- Abstract datatypes are created by the programmer using OOP.
- int, float, bool, char and byte are considered primitive datatypes.
- A combination of OOP and primitive datatypes can be done to create abstract data types, like in Python, there are Lists, Dictionaries, Sets.
- ADT will be covered in more detail in later lessons.

### Video 44 Notes
- Depending on the type of operation being performed, the time of execution for the overall program is either linear, quadratic, logarithmic or instant -> O(1).
- The total time complexity for a program can be determined by summing the big-O of all the functions and executions that make up the program.

