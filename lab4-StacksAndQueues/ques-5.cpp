//NAME: SRUSHTI THAKAR
//SECTION 2
//DATA STRUCTURES AND ALGORITHMS 
//LAB 4 STACKS AND QUEUES

// ques-5 : implement priority queue using an unsorted linked list...

#include<bits/stdc++.h>
using namespace std;


// structure of node
struct Node
{
  int data;
  int priority;
  Node * next;
};

Node * front = NULL;


// inserting elements in the priority queue
void enqueue (int data, int priority)
{

 Node * temp, *current, *prev = NULL;

 temp = new Node;
 temp->data = data;
 temp->priority = priority;

 if (front == NULL or priority < front->priority)
  {
    temp->next = front;
    front = temp;
  }

 else
  {
    current = front;

    while (current and priority >= current->priority)
	{
	  prev = current;
	  current = current->next;
	}

    temp->next = prev->next;
    prev->next = temp;
  }
}


//deleting elements from the priority queue
void dequeue ()
{
  if (front == NULL)
  {
    cout << "Priority Queue is underflow" << endl;
    return;
  }

  else
    {
      Node * temp;
      temp = front;

      cout << "Deleted item is " << temp->data << endl;

      front = temp->next;
      free (temp);
    }
}


//displaying the elements of the priority queue
void display ()
{
  if (front == NULL)
    cout << "Priority-Queue is empty" << endl;

  Node * current = front;

  cout<<"\nPriority-Queue elements are : ";

  while (current)
    {
      cout << current->data << " ";
      current = current->next;
    }

  cout << endl;

  return;
}

void peak ()
{
  cout << "Peak element is :" << front->data << endl;
}

int main ()
{
  enqueue (2, 0);
  enqueue (4, 1);
  enqueue (6, 1);
  enqueue (5, 2);
  enqueue(4,3);

  display ();

  peak();

  dequeue ();
  dequeue ();
  display ();

  return 0;

}


//output:

// Priority-Queue elements are : 2 4 6 5 4 
// Peak element is :2
// Deleted item is 2
// Deleted item is 4

// Priority-Queue elements are : 6 5 4
