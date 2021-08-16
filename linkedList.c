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

//Setting initial linked list as a empty list.
student *head = NULL;

/**Setting a tail of linked list which is the last node of the list.
  *This makes it easier to add and remove to and from the last position.
  *Initially this is also empty */
student *tail = NULL;

//Functions for changing colors

//red
void red () 
{
  printf("\033[1;31m");
}

//green
void green () 
{
  printf("\033[1;32m");
}

//yellow
void yellow()
{
    printf("\033[1;33m");
}

//blue
void blue ()
{
  printf("\033[1;34m");
}

//cyan
void cyan()
{
    printf("\033[1;36m");
}

//purple
void purple()
{
    printf("\033[1;35m");
}

//function for resetting the color
void reset () {
  printf("\033[0m");
}

//The main function
int main()
{
    //Seed for rand()
    srand(time(NULL));

    //To display menu initially
    menu();

    //for making the location in heap free.
    student *ptr = head;
    while (ptr != NULL)
    {
        free(ptr);
        ptr = ptr->next;
    }

    return (EXIT_SUCCESS);
}

/**A function to add a node a first position before 
  *the previous head if there was any.*/
void addHead(int rollNo, char name[], float physics, float chemistry, float maths, float computer)
{

    student *newHead = (student *)malloc(sizeof(student));

    newHead->rollNo = rollNo;
    strcpy(newHead->name, name);
    newHead->marksPhysics = physics;
    newHead->marksChemistry = chemistry;
    newHead->marksMaths = maths;
    newHead->marksComputer = computer;
    newHead->average = (physics + chemistry + maths + computer) / 4;
    newHead->next = head;

    head = newHead;
}

/**A function to add a node at the last position
 * after the tail */
void addTail(int rollNo, char name[], float physics, float chemistry, float maths, float computer)
{
    if (!countStudents())
    {
        addHead(rollNo, name, physics, chemistry, maths, computer);
    }
    else
    {
        student *newTail = (student *)malloc(sizeof(student));

        student *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        tail = ptr;

        tail->next = newTail;

        newTail->rollNo = rollNo;
        strcpy(newTail->name, name);
        newTail->marksPhysics = physics;
        newTail->marksChemistry = chemistry;
        newTail->marksMaths = maths;
        newTail->marksComputer = computer;
        newTail->average = (physics + chemistry + maths + computer) / 4;
        newTail->next = NULL;

        tail = newTail;
    }
}

//A function to add a node at a specified place except head and tail.
void addBody(student *previousPtr, student *currentPtr, int rollNo, char name[], float physics, float chemistry, float maths, float computer)
{
    student *newNode = (student *)malloc(sizeof(student));

    newNode->rollNo = rollNo;
    strcpy(newNode->name, name);
    newNode->marksPhysics = physics;
    newNode->marksChemistry = chemistry;
    newNode->marksMaths = maths;
    newNode->marksComputer = computer;
    newNode->average = (physics + chemistry + maths + computer) / 4;
    newNode->next = currentPtr;

    previousPtr->next = newNode;
}

/**  A function to add a node.
  * The index(value of random > 0) will be the index of new node in the list. 
  *@param random < 0 - node will be added at random
  *@param random > 0 - node will be added at that index (starting from 0)*/
void addAtPlace(int random, int rollNo, char name[], float physics, float chemistry, float maths, float computer)
{
    random--;
    int index, total;
    if (random < 0)
    {
        total = countStudents();
        if (total == 0)
        {
            index = 0;
        }
        else
        {
            index = rand() % total;
        }
    }
    else
    {
        index = random;
    }

    student *currentPtr = head;
    student *previousPtr = NULL;

    if (index >= (total - 1))
    {
        currentPtr = tail;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            if (currentPtr->next == NULL)
            {
                break;
            }
            previousPtr = currentPtr;
            currentPtr = currentPtr->next;
        }
    }

    if (currentPtr == head)
    {
        addHead(rollNo, name, physics, chemistry, maths, computer);
    }
    else if (currentPtr == tail)
    {
        addTail(rollNo, name, physics, chemistry, maths, computer);
    }
    else
    {
        addBody(previousPtr, currentPtr, rollNo, name, physics, chemistry, maths, computer);
    }
}

/**A function to check if inputed roll no is unique or not.
 * returns 0 if roll no is already present and
 * returns 1 if rol no is unique */
int isRollUnique(int rollNo)
{
    for (student *i = head; i != NULL; i = i->next)
    {
        if (i->rollNo == rollNo)
        {
            return False;
        }
    }
    return True;
}

//A function to count total number of nodes in the list
int countStudents()
{
    student *ptr = head;
    int counter = 0;
    while (ptr != NULL)
    {
        counter++;
        ptr = ptr->next;
    }
    return counter;
}

//A funciton to format output.
void outputFormatter(int number, int lines, int newLines)
{
    yellow();
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < number; j++)
        {
            printf("-");
        }
        printf("\n");
    }
    for (int k = 1; k < newLines; k++)
    {
        printf("\n");
    }
    reset();
}  

/**A function to sort students based on the roll number.
 * This function implements bubble sorting 
 * and pointer is swapped rather than swapping of data.
*/
void sortAll()
{
    int noOfStudents = countStudents();

    for (int i = 0; i < noOfStudents - 1; i++)
    {
        student *current = head;
        student *next = current->next;
        student *previous;
        for (int j = 0; j < noOfStudents - i - 1; j++)
        {
            if (current->rollNo > next->rollNo)
            {
                if (current == head)
                {
                    current->next = next->next;
                    head = next;
                    head->next = current;
                }
                else
                {
                    previous->next = next;
                    current->next = next->next;
                    next->next = current;
                }
                previous = next;
                next = current->next;
            }
            else
            {
                previous = current;
                current = next;
                next = current->next;
            }
        }
    }
    print(head, NULL, False, NULL);
}

/**A function to print either 
  *all data starting from head node or 
  *data of a specific student 
  *and returns false if the list is empty.*/
/** @param initial  the initial pointer to starting printing from
  * @param final the final pointer to stop printing(The stopping condition: NULL to print all). 
  * @param match  number of matching searches if it's a search
    [which match is it first, second, third, ....]
  * @param structurePointer pointer to a matching search */
int print(student *initial, student *final, int match, student *structurePointer)
{
    --match;
    if (head == NULL)
    {
        return False;
    }
    student *ptr = head;

    if (match < 1 || initial != NULL)
    {
        printf("\n");
        outputFormatter(100, 1, 1);
        cyan();
        printf("%12s| %12s %12s %12s %12s %12s %12s \n",
               "ROLL NO", "NAME", "PHYSICS", "CHEMISTRY",
               "MATHEMATICS", "COMPUTER", "AVERAGE");

        outputFormatter(100, 1, 1);
    }

    if (initial != NULL)
    {
        while (ptr != final)
        {
            cyan();
            printf("%12d| %12s %12.2f %12.2f %12.2f %12.2f %12.2f \n",
                   ptr->rollNo, ptr->name, ptr->marksPhysics, ptr->marksChemistry,
                   ptr->marksMaths, ptr->marksComputer, ptr->average);
            outputFormatter(100, 1, 1);
            printf("\n");

            ptr = ptr->next;
        }
    }
    else if (initial == NULL)
    {
        student *ptr = structurePointer;

        cyan();
        printf("%12d| %12s %12.2f %12.2f %12.2f %12.2f %12.2f \n",
               ptr->rollNo, ptr->name, ptr->marksPhysics, ptr->marksChemistry,
               ptr->marksMaths, ptr->marksComputer, ptr->average);
        outputFormatter(100, 1, 1);
    }
    reset();
    return True;
}

/**A function to search specific data of a student or students.
 * and call print function to display it
 * returns 0 if search was unsuccessfull and returns number > 0 
 * where the number is the number of matches*/
int search(int rollNo, char name[], float averageRange[])
{

    student *ptr = head;
    int match = 0;
    while (ptr != NULL)
    {
        if ((ptr->rollNo == rollNo) || !strcmp(ptr->name, name) || ((ptr->average >= averageRange[0]) && (ptr->average <= averageRange[1])))
        {
            match++;
            print(NULL, NULL, match, ptr);
            ptr = ptr->next;
        }
        else
        {
            ptr = ptr->next;
        }
    }

    if (match <= 0)
    {
        red();
        printf("\n NO MATCH FOUND !");
        reset();
    }
    else
    {
        char plural1[10] = "matchs";
        char plural2[10] = "students";
        if (match == 1)
        {
            strcpy(plural1, "Match");
        }
        int nStudents = countStudents();
        if(nStudents < 2)
        {
            strcpy(plural2, "student");
        }
        printf("\n%d %s found out of %d %s. \n", match, plural1, nStudents, plural2);
    }
    return match;
}

/**Takes input from the user
 * and calls search function to search.
 * And search function calls print function
 * to display the search results.
 * Returns False if no result is found.*/
int takeInputToSearch()
{
    int rollNo, searchSuccess = 0;
    char strRollNo[10], strAverage1[10], strAverage2[10];
    char name[50];
    float average[2];

    outputFormatter(100, 1, 1);

    char input[10];
    printf("\nHow do you want to search ? \n ");
    printf("[ \033[0;32mRoll no \033[0m/ \033[0;32mName  \033[0m/ \033[0;32mAverage range \033[0m]");
    printf(" || [ \033[0;32mR\033[0m/ \033[0;32mN \033[0m/ \033[0;32mA] \033[0m: ");
    getWithColor(input);
    printf("\n");
    outputFormatter(100, 1, 1);

    if (!strcmp(input, "Rollno") || input[0] == 'r' || input[0] == 'R')
    {
        printf("\nEnter the roll number you want to search : ");
        getWithColor(strRollNo);
        rollNo = atoi(strRollNo);

        average[0] = average[1] = -100;
        searchSuccess = search(rollNo, "  ", average);
    }
    else if (!strcmp(input, "Name") || input[0] == 'n' || input[0] == 'N')
    {
        printf("\nEnter the name you want to search : ");
        getWithColor(name);
        average[0] = average[1] = -100;
        searchSuccess = search(-1, name, average);
    }
    else if (!strcmp(input, "Average range") || input[0] == 'A' || input[0] == 'a')
    {
        printf("\nEnter the range of average marks you want to search \nmin:    ");
        getWithColor(strAverage1);
        average[0] = atoi(strAverage1);

        printf("max:     ");
        getWithColor(strAverage2);
        average[1] = atoi(strAverage2);

        searchSuccess = search(-1, "  ", average);
    }
    else
    {
        red();
        printf("Invalid Input !\n");
        reset();
        takeInputToSearch();
    }
    return searchSuccess;
}

/**Takes input from the user and deletes as specified.
 * And returns the pointer to the node which is deleted
 * if it finds the match. Returns NULL if it can't. */
student *delete ()
{
    int rollNo;
    char delInput[10];
    student *ptr = NULL;
    if (takeInputToSearch())
    {
        ptr = head;
        //Taking the roll number as string.
        printf("Enter the Roll Number you want to delete : ");
        getWithColor(delInput);

        //Converting string to integer.
        rollNo = atoi(delInput);

        while (ptr != NULL)
        {
            if ((ptr == head) && (head->rollNo == rollNo))
            {
                head = head->next;
                break;
            }
            else if ((ptr->next)->rollNo == rollNo)
            {
                student *ptrNext = ptr->next;
                ptr->next = (ptr->next)->next;
                ptr = ptrNext;
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
    return ptr;
}

//Displays menu and performs operations from there.
void menu()
{
    
    printf("\n\n");
    outputFormatter(100, 2, 2);
    purple();
    printf("Select an operation\n");
    printf("\033[0;32m1. \033[1;35mAdd\t\t");
    printf("\033[0;32m2. \033[1;35mRemove\n");
    printf("\033[0;32m3. \033[1;35mSearch\t");
    printf("\033[0;32m4. \033[1;35mDisplay\n");
    printf("\033[0;32m5. \033[1;35mSort\t\t");
    printf("\033[0;32m6. \033[1;35mExit\n\n");
    outputFormatter(100, 2, 2);

    char input[10];
    printf("Operation :     ");
    getWithColor(input);
    outputFormatter(100, 1, 1);

    char validInputs[][10] = {"1", "2", "3", "4", "5", "6", "Add",
                              "add", "exit", "Exit", "remove", "Remove",
                              "display", "Display", "sort", "Sort"
                                                            "search",
                              "Search"};

    int valid = 0;
    int n = sizeof(validInputs) / 10;

    for (int i = 0; i < n; i++)
    {
        if (!strcmp(validInputs[i], input))
        {
            valid = 1;
            break;
        }
    }

    if (!valid)
    {
        red();
        printf("\nInvalid Input!\nPlease enter a valid input.\n");
        reset();
    }
    else
    {
        if (!strcmp(input, "1") || !strcmp(input, "add") || !strcmp(input, "Add"))
        {
            add();
        }
        else if (!strcmp(input, "6") || !strcmp(input, "exit") || !strcmp(input, "Exit"))
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            if (countStudents())
            {
                if (!strcmp(input, "2") || !strcmp(input, "remove") || !strcmp(input, "Remove"))
                {
                    student *deleteSuccess = delete ();
                    if (deleteSuccess != NULL)
                    {

                        printf("\nThe following item has been deleted successfully.\n");
                        print(NULL, NULL, 1, deleteSuccess);
                        printf("\n");
                        free(deleteSuccess);
                        outputFormatter(100, 1, 1);
                        printf("\nThe remaining items are: \n");
                    }
                    else
                    {
                        printf("\n");
                        outputFormatter(100, 1, 1);
                        printf("The operation was unsuccessful.\n");
                    }
                    print(head, NULL, False, NULL);
                }
                else if (!strcmp(input, "3") || !strcmp(input, "search") || !strcmp(input, "Search"))
                {
                    takeInputToSearch();
                }
                else if (!strcmp(input, "4") || !strcmp(input, "display") || !strcmp(input, "Display"))
                {
                    print(head, NULL, False, NULL);
                }
                else if (!strcmp(input, "5") || !strcmp(input, "sort") || !strcmp(input, "Sort"))
                {
                    sortAll();
                }
            }
            else
            {
                printf("\nThe list is empty.\nDo you want to add data ? (\033[0;32mY\033[0m/\033[0;32mN\033[0m):  ");
                getWithColor(input);

                if (!strcmp(input, "Y") || !strcmp(input, "y") || !strcmp(input, "yes"))
                {
                    add();
                }
                else
                {
                    outputFormatter(100, 1, 1);
                    red();
                    printf("\nThe operation isn't valid under current list.\n");
                    reset();
                }
            }
        }
    }
    reset();
    menu();
}

//Function to add data in list in various ways.
void add()
{
    int addInput, n, addValid, row;
    char place[10], nIn[10], rowInput[10], strAddInput[10];

    do
    {
        addValid = True;
        printf("\n");

        outputFormatter(100, 2, 1);
        purple();
        printf("How would you like to add the data in the list ?\n");
        printf("\033[0;32m1.\033[1;35mAdd data at the first position.\n");
        printf("\033[0;32m2.\033[1;35mAdd data at the last position.\n");
        printf("\033[0;32m3.\033[1;35mAdd data somewhere else.\n");
        outputFormatter(100, 2, 1);

        printf("Select (\033[0;32m1\033[0m/\033[0;32m2\033[0m/\033[0;32m3\033[0m) :");
        getWithColor(strAddInput);
        addInput = atoi(strAddInput);
        printf("\n");
        outputFormatter(100, 1, 1);

        if (addInput != 1 && addInput != 2 && addInput != 3)
        {
            red();
            printf("\nInvalid Input!\n Please enter a valid input.\n");
            reset();
            addValid = False;
        }
    } while (!addValid);

    //For looping
    printf("How many entries do you want to add ? : ");
    getWithColor(nIn);
    n = atoi(nIn);
    printf("\n");
    outputFormatter(100, 1, 1);

    for (int count = 1; count <= n; count++)
    {
        char name[50];
        int rollNo;
        char input1[10], input2[10], input3[10], input4[10], input5[10];
        float physics, chemistry, mathematics, computer;

        int notValid;

        //Loops until unique roll no is provided.
        do
        {
            notValid = False;
            //taking roll no
            blue();
            printf("\nEnter the roll no of the student %d : ", count);
            getWithColor(input1);
            rollNo = atoi(input1);

            if (rollNo <= 0)
            {
                red();
                printf("\nPlease enter a valid natural number.\n");
                notValid = True;
            }
            else if ((countStudents()) && (!isRollUnique(rollNo)))
            {
                red();
                printf("\nThe entered roll no already exists!\nPlease enter a different one\n");
                notValid = True;
            }
        } while (notValid);

        //Taking data to store

        //taking name
        blue(); printf("\nEnter the name of the student %d: ", count);
        getWithColor(name);

        //taking marks in physics
        blue(); printf("\nEnter the marks obtained in physics: ");
        getWithColor(input2);
        physics = atoi(input2);

        //taking marks in chemistry
        blue(); printf("\nEnter the marks obtained in chemistry: ");
        getWithColor(input3);
        chemistry = atoi(input3);

        //taking marks in mathematics
        blue(); printf("\nEnter the marks obtained in mathematics: ");
        getWithColor(input4);
        mathematics = atoi(input4);

        //taking marks in computer
        blue(); printf("\nEnter the marks obtained in computer: ");
        getWithColor(input5);
        computer = atoi(input5);

        switch (addInput)
        {
        case 1:
            addHead(rollNo, name, physics, chemistry, mathematics, computer);
            break;

        case 2:
            addTail(rollNo, name, physics, chemistry, mathematics, computer);
            break;

        case 3:
            row = -100;
            outputFormatter(100, 1, 1);
            printf("\nDo you want to add at fixed place or at random place ? (F/R)  : ");
            getWithColor(place);

            if (!strcmp(place, "F") || !strcmp(place, "f") || !strcmp(place, "fixed"))
            {
                printf("\nEnter the row where you want to add the data entry : (1/2/3/....)");
                getWithColor(rowInput);
                row = atoi(rowInput);
            }
            addAtPlace(row, rollNo, name, physics, chemistry, mathematics, computer);
            break;
        }
        outputFormatter(100, 1, 1);
    }
    print(head, NULL, 0, NULL);
}

/**sets color to green takes input as string and resets the text color. **/
/** @param inputHolder char pointer to store the input **/
void getWithColor(char inputHolder[])
{
    green();
    gets(inputHolder);
    reset();
}