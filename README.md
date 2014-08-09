#Heapsort

In many books and tutorials online, you will see that they use an array where the first number has index 1.

This simplifies the indices of the parent and children:

- Parent = i/2
- Left child = 2*i
- Right child = 2*i+1

But, when implementing heapsort, the array or vector we receive, its first number has index 0. We have to adapt the mathematical calculations.

- Parent = (i-1)/2
- Left child = 2*i +1
- Right child = 2*i + 2

The heapsort algorithm can be divided in two seperate parts.

1. Constructing the heap
2. Sort the array using the heap

#Constructing the heap

For the first step there are two approaches.

1. By inserting
2. By merging partial heaps

##By inserting
A heap can be built by adding elements one by one to an empty heap. We can transform an array without using a secondary array.
When the first $i$ elements form a heap, element i+1 can be added to it.

To restore the heap condition when a node is inserted, we move up the heap, exchanging the node at position $i$ with its parent (at position (i-1)/2) if necessary, continuing as long as the inserted node is smaller than its parent.

We start with inserting item at index 1 in the heap (item at index $0$ is already a heap). We continu until we have added all the elements of the array to the heap.

##Merging partial heaps
This method is more efficient. Merging partial heaps means, making a node that contains both partial heaps, root of a bigger partial heap that contains both those first partial heaps. Only the root node can violate the heap condition. It is important to notice that the heap condition only needs to be satisfied in the new partial heap. How do we find the first partial heaps?

All nodes on the bottom level are a heap, they don't have any children. The heap condition is satisfied for these nodes.
That's why we start at the before last level, the nodes with children. The order in which we process the nodes isn't important, the partial heaps don't overlap. We go throught our array from right to left, starting at the middle.

To restore the heap condition when a node's priority is decreased, we move down the heap, exchanging the node at position k with the larget of that node's two children if necessary and stopping when the node at k is not smaller than either child or the bottom is reached.

#2. Heapsort

Using the top-down heapify method gives the classical heapsort algorithm. The while loop exchanges the largest element with the final element in the array and repairs the heap, continuing until the heap is empty.