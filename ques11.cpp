// AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS

// LAB 2

//ques-11: to append an element in a doubly linked list.

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int value){
        this->data=value;
        this->next=NULL;
        this->prev=NULL;
    }

};

void insertAtHead(node* &head,int value){
    node*n=new node(value);
    n->next=head;
    if(head!=NULL){
    head->prev=n;
    }
    head=n;

}


void insertAtTail(node* &head,int value){
    if(head==NULL){
        insertAtHead(head,value);
        return;
    }
    node* n=new node(value);
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void display(node* head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node*head=NULL;
    
    
    insertAtTail(head,10);
    insertAtTail(head,12);
    insertAtTail(head,23);
    cout<<"the doubly linked list before appending element is: "<<endl;
    display(head);
    cout<<"the doubly linked list after appending the element is : "<<endl;
    insertAtTail(head,35);
    display(head);

    return 0;
}

// Sample output:

// the doubly linked list before appending element is: 
// 10 12 23
// the doubly linked list after appending the element is :
// 10 12 23 35
