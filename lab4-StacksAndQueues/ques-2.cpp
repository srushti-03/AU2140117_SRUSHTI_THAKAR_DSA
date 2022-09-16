//NAME: SRUSHTI THAKAR
//SECTION 2
//DATA STRUCTURES AND ALGORITHMS 
//LAB 4 STACKS AND QUEUES

//ques-2: evaluating a postfix expression using stack data structure


#include<bits/stdc++.h>
using namespace std;
  class node {
	public:

        int data;
        node *next;
  };
    node *top = NULL;

//  create a new node 
  node* createNode(int data) {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
  }

  //push into the stack
  void pushStack (int data) {
        node *ptr = createNode(data);
        if (top == NULL) {
                top = ptr;
                return;
        }
        ptr->next = top;
        top = ptr;
  }

  //popping top element from the stack
  int pop () {
        int data;
        struct node *temp;
        if (top == NULL)
                return -1;
        data = top->data;
        temp = top;
        top =  top->next;
        free(temp);
        return (data);
  }

  int main() {
        char str[100]="20 8 4 + *";
        int i, data = -1, op1, op2, res;
        for (i = 0; i < strlen(str); i++) {
                if (isdigit(str[i])) {         //checking if it is a digit or not
                       
                        if(data==-1){
                            data=0;
                        }
                        else{
                            data=data;
                        }
                        data = (data * 10) + (str[i] - 48);
                        continue;
                }

                
				
                if (data != -1) {
                        pushStack(data);
                }

                if (str[i] == '+' || str[i] == '-'
                        || str[i] == '*' || str[i] == '/') {
                      
                        //if the character is an operator,then pop top two elements from the stack,
						//perform the operation and push back the resultant to the stack
                         
                        op2 = pop();
                        op1 = pop();
                        if (op1 == -1 || op2 == -1)
                                break;
                        switch (str[i]) {
                                case '+':
                                        res = op1 + op2;
                                        /* pushing result into the stack */
                                        pushStack(res);
                                        break;
                                case '-':
                                        res = op1 - op2;
                                        pushStack(res);
                                        break;
                                case '*':
                                        res = op1 * op2;
                                        pushStack(res);
                                        break;
                                case '/':
                                        res = op1 / op2;
                                        pushStack(res);
                                        break;
                        }
                }
                data = -1;
        }
        if (top != NULL && top->next == NULL)
                cout<<"Resultant of the given postfix operation is: "<<top->data<<endl;
        else
                cout<<"The expression is invalid..."<<endl;
        return 0;
  }

//sample output:

// Resultant of the given postfix operation is: 240