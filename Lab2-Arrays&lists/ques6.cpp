// AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS

// LAB 2

//ques-6: to search an element in a linked list; return index if element present else return -1



//linked lists are dynamic containers consisting of the data value and pointer to next node.
//if a linked list points to null ,means that it is the end of the list.
//the 1st node is called the head, if the linked list is pointing to null the list is empty.
// no need to predefine the size, can easily remove and add elements in the list





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

void search(node* &head,int value){
    node*temp=head;
    int index=0;
    while(temp!=NULL){
        if(temp->data==value){
            cout<<"the element is present at index: "<<index<<" ";
        }
        temp=temp->next;
        index++;
    }
    cout<<"-1"<<endl;  //the element is not present in the linked list.
}

int main(){
   node*head=NULL;
   insertAtTail(head,10);
   insertAtTail(head,20);
   insertAtTail(head,35);
   insertAtTail(head,67);
   search(head,38);
}


//sample output:

// the element is present at index: 2 


