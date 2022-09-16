//NAME: SRUSHTI THAKAR
//SECTION 2
//DATA STRUCTURES AND ALGORITHMS 
//LAB 4 STACKS AND QUEUES

//ques 6: deque operations: a queue where enqueue and dequeue operations can take place at both the ends

#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node*next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }

};
node*front=NULL;
node*rear=NULL;

bool isEmpty(){
    if(front==NULL and rear==NULL){
        return true;
        }
    else{
        return false;

    }
}

void enqueueAtFront(int d){
    node *temp = new node(d);

    // If inserting the first element/node
    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        temp->next = front;
        front = temp;
    }

    
}

void enqueueAtRear(int d){
    node *temp = new node(d);

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

void dequeueAtFront(){
    if (isEmpty())
        cout << "Queue is empty, nothing to dequeue"<<endl;
    else
        // only one element/node in queue.
        if (front == rear)
        {
            delete (front);
            front = rear = NULL;
        }
        else
        {
            node *temp = front;
            front = front->next;
            delete (temp);
        }

}

void dequeueAtRear()
{
   if (isEmpty())
        cout << "Queue is empty, nothing to dequeue"<<endl;
    else
        // only one element/node in queue.
        if (front == rear)
        {
            delete (front);
            front = rear = NULL;
        }
        else
        {
            node*temp=front;
            while(temp->next->next!=NULL){   //accessing the second last element
                temp=temp->next;            
            }
            temp->next=NULL;
            rear=temp;
        }
    
}
void display(){
      if (isEmpty())
        cout << "Queue is empty\n";
    else
    {
        node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
 
    
}

void getFront(){
    if (isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "element at front is: " << front->data << endl;
    
}

void getRear(){
    if (isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "element at rear is: " << rear->data << endl;
}


int main(){
    
    enqueueAtFront(10);
    enqueueAtFront(20);
    enqueueAtFront(30);
    
    enqueueAtRear(40);
    enqueueAtRear(50);
    display();
    isEmpty();
    getFront();
    getRear();
    dequeueAtFront();
    dequeueAtRear();
    display();


    

    
    return 0;
}


//output:

// 30 20 10 40 50 
// element at front is: 30
// element at rear is: 50
// 20 10 40