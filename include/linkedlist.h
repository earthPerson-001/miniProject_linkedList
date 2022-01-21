#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define True 1
#define False 0

/**A datatype node (renamed student) which represent a node of the linked list.
  *roll number of student,
  *name of student,
  *marks obtained in physics,
  *marks obtained in chemistry,
  *marks obtained in mathematics,
  *marks obtained in computer,
  *a pointer to next node 
  *and average marks of all subject*/
typedef struct node
{
    int rollNo;
    char name[50];
    float marksPhysics;
    float marksChemistry;
    float marksMaths;
    float marksComputer;
    struct node *next;
    float average;
} student;

int countStudents();
int isRollUnique(int rollNo);
void outputFormatter(int number, int lines, int newLines);

void addHead(int rollNo, char name[], float physics, float chemistry, float maths, float computer);
void addTail(int rollNo, char name[], float physics, float chemistry, float maths, float computer);
void addBody(student *previousPtr, student *currentPtr, int rollNo, char name[], float physics, float chemistry, float maths, float computer);
void addAtPlace(int random, int rollNo, char name[], float physics, float chemistry, float maths, float computer);

void sortAll();
int print(student *initial, student *final, int match, student *structurePointer);
int search(int rollNo, char name[], float averageRange[]);
int takeInputToSearch();
student *delete ();

void menu();
void add();

void getWithColor(char inputHolder[]);