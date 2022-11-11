// AU2140117 
// SRUSHTI THAKAR
// DSA-DATA STRUCTURES AND ALGORITHMS 
// section 2

//ques-4: implement binary search tree with the following operations: insert,remove, and find minimum:


#include<bits/stdc++.h>
using namespace std;

struct node
{
public:
    int data;
    node *left;
    node *right;                //defining the structure of node
    node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

node* search(node* root, int value){                // search function
     if (root == NULL || root->data == value)
       return root;                                      // if the node to be searched is the root
    
    if (root->data < value)
       return search(root->right, value);                     // if the node to be searched is greater than the root
 
    return search(root->left, value);            // if the node to be searched is less than the root
}


node* insert(node* root, int value)                  //insert function
{
    node* insertNew = new node(value);
    if (!root) {
        root = insertNew;                      // if the tree is empty, the node added will be the root
        return root;
    }
    node* prev = NULL;
    node* temp = root;
    while (temp) {
        if (temp->data > value) {       // if temp> value; temp added to left subtree
            prev = temp;
            temp = temp->left;
        }
        else if (temp->data < value) {      // if temp< value, temp added to right subtree
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->data > value)
        prev->left = insertNew;
    else
        prev->right = insertNew;

        return temp;
}


// the deletion operation

node* deleteNode(node* root, int value)
{

    if (root == NULL)
        return root;
  
  
    if (root->data > value) {
        root->left = deleteNode(root->left, value);         // delete from left subtree
        return root;
    }
    else if (root->data < value) {
        root->right = deleteNode(root->right, value);           // delete from right subtree
        return root;
    }

    if (root->left == NULL) {
        node* temp = root->right;          // left subtree is null; delete right
        delete root;
        return temp;
    }
    else if (root->right == NULL) {       // right subtree is null, delete left
        node* temp = root->left;
        delete root;
        return temp;
    }

    else {
  
        node* parent = root;
        node* n = root->right;
        while (n->left != NULL) {
            parent = n;
            n = n->left;
        }
 
        if (parent != root)
            parent->left = n->right;
        else
            parent->right = n->right;

        root->data = n->data;

        delete n;
        return root;
    }
}
  
  
// finding the minimum operation:

int mini(node* root)  
{  
    while(root->left != NULL) {  
        root = root->left;  
    }  
    return root->data;     // the leftmost entry will be the least value in the entire binary search tree
}  

node *input()
{

    int data;
    cout << "enter value of the root:";
    cin >> data;
    if (data == -1)
        return NULL;
    node *temp = new node(data);
    cout << "Enter value of left child: " << data << endl;
    node *leftTree = input();
    cout << "Enter value of right child:  " << data << endl;
    node *rightTree = input();

    temp->left = leftTree;
    temp->right = rightTree;
    return temp;
}

void inorder(node *root)              // function for inorder traversal
{
    if (root == NULL)
        return;
    node *temp = root;
    stack<node *> s;
    while (temp != NULL || !s.empty())
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;                  // printing left subtree
        }
        else
        { 
            temp = s.top();
            s.pop();                          // printing the root value
            cout << temp->data << " ";        // printing the right subtree
            
            temp = temp->right;
            
        }
    }
}

int main(){

    node* root = input();
    cout << "the binary search tree initially looks like this  : "<<endl;
    inorder(root);
    insert(root,10);
    cout << "After insertion of an element , the tree looks like this : "<<endl;
    inorder(root);
    cout << endl;
    deleteNode(root,10);
    cout << "After deletion of an element , the tree looks like this : "<<endl;
    
    inorder(root);
    cout << "the minimum element in the tree is : " << mini(root);

    return 0;
}