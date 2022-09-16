//NAME: SRUSHTI THAKAR
//SECTION 2
//DATA STRUCTURES AND ALGORITHMS 
//LAB 4 STACKS AND QUEUES 

// QUES -4: IMPLEMENTATION OF QUEUES USING LINKED LISTS

// queues follows FIFO -First In First Out method: it has 2 ends: read and front :elements are added at the rear end and removed from the front end

#include <iostream>
using namespace std;

class Node
{
public:
    int data;

    Node *next;
    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

Node *front = NULL;
Node *rear = NULL;

// Function to check if queue is empty or not
bool isempty()
{
    if (front == NULL && rear == NULL)
        return true;
    else
        return false;
}

// function to enter elements in queue
void enqueue(int d)
{
    Node *temp = new Node(d);

    // If inserting the first element/node
    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

// function to delete/remove element from queue
void dequeue()
{
    if (isempty())
        cout << "Queue is empty, nothing to dequeue" << endl;
    else
        // only one element/node in queue.
        if (front == rear)
        {
            delete (front);
            front = rear = NULL;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete (temp);
        }
}

// function to show the element at front
void showfront()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
        cout << "element at front is:" << front->data << endl;
}

void showRear(){
    if(isempty()){
        cout<<"queue is empty\n";

    }
    else{
        cout<<"element at rear end is: "<<rear->data<<endl;
    }
}



// function to display queue
void displayQueue()
{
    if (isempty())
        cout << "Queue is empty\n";
    else
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// Main Function
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    displayQueue();
    showfront();

    isempty();
    dequeue();
    
    showfront();
    showRear();

    return 0;
}

// output:

// 10 20 30 40
// element at front is:10
// front element after dequeing :
// element at front is:20
