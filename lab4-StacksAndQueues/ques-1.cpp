//NAME: SRUSHTI THAKAR
//SECTION 2
//DATA STRUCTURES AND ALGORITHMS 
//LAB 4 STACKS AND QUEUES


//QUES -1: IMPLEMENTATION OF STACKS USING LINKED LISTS

#include <iostream>
using namespace std;

//using linked list saves us from pre-defining the size (instead of using arrays)
// stack: LIFO: Last In First Out
//top here is similar to the use head in the linked lists


 
// Declare linked list node
 
class node {
    public:
    
    int data;
    node* next;
};
node*top;
 
   
 
//adding an element in the stack:

void push(int data)
{
 
    // Creating a new node temp
    node* temp = new node();
 
    //if the stack is full,inserting an element would mean stack overflow

    if (temp==NULL) {
        cout << "\nStack Overflow";
        exit(1);
    }
 
    
    temp->data = data;
 
    temp->next = top;
 
   
    top = temp;
}
 

// the stack is empty or not
int isEmpty()
{
    // If top is NULL it means that
    // there are no elements are in stack
    return top == NULL;
}
 
// to return top element in a stack
int peek()
{
 
    // If stack is not empty , return the top element
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}
 
// 
// remove an element from the stack
void pop()
{
    node* temp;
 
    // Check for stack underflow
    if (top == NULL) {
        cout << "\nStack Underflow" << endl;  //no elements are present
        exit(1);
    }
    else {
 
        
        temp = top;
 
        top = top->next;
 
        free(temp);
    }
}
 
// Function to print all the
// elements of the stack
void display()
{
    node* temp;
 
    // Check for stack underflow
    if (top == NULL) {
        cout << "\nStack Underflow";
        exit(1);
    }
    else {
        temp = top;                             // here the head of the linked list is same as top
        while (temp != NULL) {
 
            // Print node data
            cout << temp->data << " ";
 
            // Assign temp link to temp
            temp = temp->next;
        }
    }
}

int main()
{
    
    node*top;
    // Push the elements of stack
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
 
    // Display stack elements
    display();
 
    // Print top element of stack
    cout << "\nTop element is " << peek() << endl;
 
    // Delete top elements of stack
    pop();
    pop();
 
    // Display stack elements
    display();
 
    // Print top element of stack
    cout << "\nTop element is " << peek() << endl;
 
    return 0;
}


//output:

// 50 40 30 20 10 
// Top element is 50
// 30 20 10 ( after popping the top 2 elements ,we get the following stack )
// Top element is 30

