//AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS 

// QUES-8(B): DELETES THE LAST ELEMENT OF THE LINKED LIST.

#include<iostream>
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
void deleteLastElement(node* &head){
    node*temp=head;
    while(temp->next->next!=NULL){         //checking the linked list to find out the second last element : temp->next->next==NULL.
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=NULL;
    
}

int main(){
   node*head=NULL;
   insertAtTail(head,10);
   insertAtTail(head,20);
   insertAtTail(head,35);
   insertAtTail(head,67);
   
   cout<<"the linked before deleting the last element: "<<endl;
   display(head);
   deleteLastElement(head);
   cout<<"the linked list after deleting the last element : "<<endl;
   display(head);
}


// sample output:


// the linked before deleting the last element: 
// 10 20 35 67 
// the linked list after deleting the last element : 
// 10 20 35 

