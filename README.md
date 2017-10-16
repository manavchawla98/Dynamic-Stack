# Dynamic-Stack

The goal of this project is to design and implement a dynamic stack data structure. A
stack is a data structure that stores elements in an ordered list and allows insertions and
deletions at one end only (the top of stack) in O(1) time. A dynamic stack is able to
increase its size if necessary in O(n). 

The Dynamic_stack class implements a dynamic stack data structure using an array. 

Member Variables
The Dynamic_stack class has four member variables:
• int* array – A pointer to be used as an array
• int count – Number of elements in the stack
• int array_size – The size of the array
• int initial_size – The initial size of the array

Constructor
Dynamic_stack (int n=10) - The constructor takes as argument the initial size of the
array and allocates memory for it. The default capacity (or number of entries) is 10. If
the argument n is less than one, use an array size of 1. Other class members should be
initialized with appropriate values.

Destructor
~Dynamic_stack() – The destructor deletes the memory allocated for the array.

Accessors
This class has four accessors:
• int top() const – Return the integer at the top of the stack in O(1). It may throw
an underflow exception.
• int size() const – Return the number of elements currently stored in the stack in
O(1).
• bool empty() const – Return true if stack is empty false otherwise in O(1).
• int capacity() const – Return the capacity of stack in O(1).

Mutators
This class has three mutators:
• void push(int const &) – Insert a new item at the head of the stack in O(1). If the
array is full, create a new array with size 2n (where n is current size of the array)
and copy the elements from the current array to the new array in O(n).
• int pop() – Remove the element at the top of the stack in O(1). This may throw an
underflow exception.
• void clear() – Remove all elements from the stack in O(1). If the current array
size does not equal the initial size, delete the array and create a new array equal to
the initial size.
