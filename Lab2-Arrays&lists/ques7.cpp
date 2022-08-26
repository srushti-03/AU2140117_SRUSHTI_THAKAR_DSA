// AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS

// LAB 2

//ques-7: inserting an element at the end of a linked list.

#include<iostream>
#include<list>
using namespace std;


class node{
    public:
    int data;
    node*next;

    node(int value){
        this->data=value;
        this->next=NULL;
    }
};

void insertAtTail(node* &head,int d){
    
    node*n=new node(d);
    if(head==NULL){
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
   
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
    insertAtTail(head,12);
    insertAtTail(head,14);
    cout<<"the linked list before adding a node: "<<endl;
    display(head);
    insertAtTail(head,15);
    cout<<"the linked list after adding a node: "<<endl;
    display(head);
    
}


//sample output:

// the linked list before adding a node: 
// 12 14 
// the linked list after adding a node: 
// 12 14 15 



