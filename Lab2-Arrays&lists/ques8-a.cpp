// AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS

// LAB 2

//ques-8 (a): INSERTING AN ELEMENT AN ELEMENT AT THE BEGINNING OF THE LINKED LIST.


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

void insertAtHead(node *&head,int value){
    node*temp=new node(value);
    temp->next=head;
    head=temp;
}
void insertAtTail(node* &head,int value){
    node*n=new node(value);
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
    if(temp==NULL){
        cout<<"the linked list is empty...";
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node*head=NULL;
    insertAtTail(head,12);
    insertAtTail(head,25);
    insertAtTail(head,34);
    cout<<"the linked list before adding a node: "<<endl;
    display(head);
    insertAtHead(head,15);
    cout<<"the linked list after adding a node: "<<endl;
    display(head);
    
}


//sample output:

// the linked list before adding a node: 
// 12 25 34 
// the linked list after adding a node: 
// 15 12 25 34 
