# Linked List
A miniproject implementing linked list data structure.

# Description
The program implements the linked list type of data structure. This program is capable of storing, managing and deleting of data of students. The data includes name, roll number, marks in various subjects and the average marks of all the subjects. 

# Linked List
In computer programming linked list is a type of data storing list in which data isn't stored contiguously in the memory of the computer. The data of single list can be stored across any locations of the memory. The list stores not only data, it also stores the pointer to the next data of the list. Same is true for every data in the last. Each element of the list is called node. A node consists of pointer to the next node and data which need to be stored. The node starts starts from a head node whose location needs to be stored separately and ends at the last node which points to NULL. The linked list used here is singly linked list as each node only stores pointer to the next node not the previous one.

# Linked List in this project
In this project linked list is used to store data of students. Here, a structure node is created which represents a node of the linked list. The node is further typedefined into student for ease of use. The student structure contains name of the student, roll number of the student, marks obtained in physics, chemistry, mathematics, computer and average marks combining all the subjects. The list starts with head node and ends at tail node which points to NULL. Tail isn't mandatory to keep track of but tracking it makes it a bit easier to manipulate data at the last position. Because it is a linked list for manipulating data at the position other than first and last positions requires traversal which means going through each node of the list to performing certain operation. For changing data in the middle part of the list traversal through head node has to be done moving through each node by accessing pointer to the next node.

# The project has the following features
- The program is able to add data of a student to first position and last position of the list.
- The program is able to insert data to any middle part of the list randomly or at fixed place.
- The program is able to search data of student taking name, roll number, average range as the search value.
- The program is able to display all the contents of the list or a specified one through search.
- The program is able to sort the data of students by roll number in ascending order.
- The program is able to delete the data of a student.

# IMPLEMENTATION OF FEATURES

# Insertion
The program keeps track of head node. If data has to be inserted at the first position. The new node along with data is added and head will be the new node. And new node will now point to the previous head. For any other position traversal has to be done and the new node is added. Previously present node at that position will be pointed to by the new node and the node present before the previously present node will now point to the new node. For the last position the new node will point to NULL and the previous node will point to the new node. The program is only swapping the pointers not the data.

# Search and Display 
Traversal is done and the search value is compared to the data in each iteration. If match is found then the pointer to the matching node is passed to print function to display the content. 

# Display All
Here also traversal is done and in each iteration the pointer to stucture is passed to printf function to display every row.

# Sort
Bubble sorting algorithm is used. Bubble sort is used because bubble sort sorts two consequtive data item at a time and in linked list two consequtive data are easily accessible. If instead selection sort was used the program needs to keep track of many nodes. Bubble sort is done by comparing the roll number of two students. Let the two student nodes be current and next, for swapping the node which is pointing to current should now point to next and next should point to current. Also the current node must point to the node which is being pointed by the next node. If selection sort was used instead the program needs to stores double the pointers in each iteration of bubble sort. 

# Deletion
The program is able to delete any data by searching through roll number. First the delete function will call search to show the matching entries and then only deletion will occur with speified roll number. Here roll number is used because roll numbers are unique in case of this program.

# Building
For building with mingw in linux, simply run compile.sh script. The output file will be written to build directory.
