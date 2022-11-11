// AU2140117
// SRUSHTI THAKAR
// DSA-DATA STRUCTURES AND ALGORITHMS section 2
// QUES-1: implement preorder, postorder and inorder using stacks (not recursion)

//DFS : Depth First Search

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data; // defining the structure of the node
  struct Node *left;
  struct Node *right;
  Node(int data)
  {
    this->data = data;
    left = right = NULL; // initially left and right are null
  }
};

void inorder(struct Node *root)
// inorder prints: left-root-right
{
  stack<Node *> s1;
  Node *temp = root;

  while (temp != NULL || s1.empty() == false)
  {
    // starting from the leftmost node
    while (temp != NULL)
    {
      // visiting the left subtree first

      s1.push(temp);
      temp = temp->left;
    }

    // the temp node must be NULL
    temp = s1.top();
    s1.pop();

    cout << temp->data << " ";
    // visiting the right subtree
    temp = temp->right;
  }
}

void preorder(Node *root)

// preorder prints: root-left-right
{
  if (root == NULL) // base condition
  {
    return;
  }
  stack<Node *> s; // creating an empty stack
  s.push(root);    // push root
  while ((s.empty() == false))
  {

    Node *temp = s.top(); // print root first
    cout << (temp->data) << " ";
    s.pop();
    if (temp->right != NULL)
      s.push(temp->right);
    if (temp->left != NULL)
      s.push(temp->left);
  }
}

void postorder(Node *root)
// prints the postorder traversal: left-right-root
{

  if (root == NULL)
  {
    return;
  }

  // create an empty stack and push root
  stack<Node *> s;
  s.push(root);

  // create another stack for storing postorder values
  stack<int> s2;

  while (!s.empty())
  {
    // popping a node from the stack and pushing it into the stack that is to be outputted
    Node *temp = s.top();
    s.pop();

    s2.push(temp->data);

    // pushing the left and right child into the stack
    if (temp->left)
    {
      s.push(temp->left);
    }

    if (temp->right)
    {
      s.push(temp->right);
    }
  }

  while (!s2.empty())
  {
    cout << s2.top() << " ";
    s2.pop();
  }
}

// driver's code

int main()
{

  // providing values

  struct Node *root = new Node(40);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(50);
  root->left->right = new Node(90);

  cout << "the inorder traversal is as follows: " << endl;
  inorder(root);
  cout << endl;

  cout << "the preorder traversal is as follows: " << endl;
  preorder(root);
  cout << endl;

  cout << "the postorder traversal is as follows: " << endl;
  postorder(root);
  cout << endl;

  return 0;
}

// sample output:

// the inorder traversal is as follows:
// 50 20 90 40 30
// the preorder traversal is as follows:
// 40 20 50 90 30
// the postorder traversal is as follows:
// 50 90 20 30 40
