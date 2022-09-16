//NAME: SRUSHTI THAKAR
//SECTION 2
//DATA STRUCTURES AND ALGORITHMS 
//LAB 4 STACKS AND QUEUES

//QUES 3: TO CHECK FOR BALANCED/UNBALANCED PARENTHESIS

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};
                                       //declaring and defining the structure of node and stack
struct Stack{
    Node *head;
    int size;
    Stack(){
        head = NULL;
        size = 0;
    }

    void push(char value){
        Node *temp = new Node(value);
        temp -> next = head;                //pushing data into the stack
        head = temp;
        size++;
    }

    int pop(){
        if (head == NULL){
            cout << "Underflow/ empty" << endl;           //popping elements from the stack
            
        }

        int result = head -> data;
        head = head -> next;
        size--;
        return result;
    }

    int peek(){
        if (head == NULL){
            cout << "Empty" << endl;
                                        //finding the top element
        }

        return head -> data;
    }

    bool isEmpty(){
        return head==NULL;                   //checking if the stack is empty or not
    }

    void display(){
        Node *temp = head;
        while (temp != NULL)
        {
            
            cout << temp -> data << " ";          //display the stack
            temp = temp -> next;
        }
        cout << endl;
    }

};

bool check(char a,char b){
    return (( a=='(' && b==')' )||( a=='[' && b==']' )||( a=='{' && b=='}' ));
}

bool isBalanced(string s1){
                                                //checking if the string is balanced or not 
    Stack s; 
    
    for (int i = 0; i < s1.length(); i++)  
    { 
        if(s1[i]=='/' && s1[i+1]=='/'){
            break;
        }
        else if (s1[i] == '(' || s1[i] == '[' || s1[i] == '{')  
        {  
            s.push(s1[i]); 
        } 
        else {
                if (s.isEmpty()==true) 
                    return false;
                else if(check(s.peek(),s1[i])==false)
                    return false;
                else
                    s.pop();
         }
    }    
    return (s.isEmpty()==true); 
}

int main()
{
    string str = "{([{()}]]}"; 
    
    if (isBalanced(str)) 
        cout << "Valid expression"; 
    else
        cout << "Invalid expression"; 

    return 0; 
}

//output:
// Invalid expression


