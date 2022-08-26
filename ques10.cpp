// AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS

// LAB 2

//ques -10: to replace an element at a given position in a linked list.

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

void replaceElement(node* &head,int pos,int element){
    int index=0;
    node*temp=head;
    bool flag=0;
    while(temp!=NULL){
        if(index==pos){
            temp->data=element;
            flag=1;
            break;
            
        }
        temp=temp->next;
        index++;
    }
    if(flag==0){
        cout<<-1<<endl;
    }
    else{
        
        cout<<"the linked list after replacement is: "<<endl;
        display(head);
    }
    
}

// void replaceElement(node* &head,int pos,int element){
//     int index=0;
//     node*temp=head;
//     node*n=new node(element);
//     if(pos==0){
//         replaceAtHead(head,element);
//         return;
//     }
//     while(temp!=NULL){
//         if(index==pos-1){
//             n->next=temp->next->next;
//             temp->next=n;
            


//         }
//         temp=temp->next;
//         index++;
//     }


// }

int main(){
   node*head=NULL;
   insertAtTail(head,10);
   insertAtTail(head,20);
   insertAtTail(head,35);
   insertAtTail(head,67);
   cout<<"the linked list before replacement is: "<<endl;
   display(head);
   replaceElement(head,1,15);
   
   
   
  
   
}

//sample output:

// the list before replacing the element : 
// 10 20 35 67
// the list after replacing the element :
// 10 15 35 67


//sample output:

// the list before replacing the element : 
// 10 20 35 67
// the list after replacing the element :
// 10 15 35 67
// PS C:\Users\s9



