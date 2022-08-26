// AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS

// LAB 2

// ques-12: to remove an element from a doubly linked list.

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;
    node(int value){
        this->data=value;
        this->next=NULL;
        this->prev=NULL;
    }
};
void insertAtHead(node* &head, int value){
    node*n=new node(value);
    n->next=head;
    while(head!=NULL){
        head->prev=n;
    }
    head=n;
}
void insertAtTail(node* &head,int value){
    node*n=new node(value);
    node*temp=head;
    if(head==NULL){
        insertAtHead(head,value);
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void deleteAtHead(node* &head){
    node*temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;

    }

void dubbly_remove(node* &head,int value){
    node*temp=head;
    while(temp->data==value){
        deleteAtHead(head);
        return;
    }
    while(temp!=NULL and temp->data!=value){
        temp=temp->next;

    }
    temp->prev->next=temp->next;
    while(temp->next!=NULL){
        temp->next->prev=temp->prev;

    }
    delete temp;
}

void display(node*head){
    node*temp=head;
    cout<<"null"<<"->";
    while(temp!=NULL){
        
        cout<<temp->data<<"->";
        
        temp=temp->next;
    }
    cout<<"null "<<endl;
    
}

int main(){
    node*head=NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    dubbly_remove(head,5);
    display(head);

    return 0;
}


// sample output:

// the doubly linked list before removing elements: 
// 1 2 3 4 5 
// the doubly linked list after removing elements: 
// 1 2 3 4 
