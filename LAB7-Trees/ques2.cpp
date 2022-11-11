// AU2140117
// SRUSHTI THAKAR
// DSA-DATA STRUCTURES AND ALGORITHMS
// section 2

// ques-2: implement breadth first search on a tree ( not necessarily binary):

// level order traversal of a binary tree (BFS : BREADTH FIRST SEARCH )

#include <bits/stdc++.h>
using namespace std;

// defining the structure of the node
class node
{
public:
    int data;
    node *left;
    node *right;
};

// printing nodes which are present at the same level

void printcurrentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1) // at level 1 , only root is present
        cout << root->data << " ";
    else if (level > 1)
    {
        printcurrentLevel(root->left, level - 1);
        printcurrentLevel(root->right, level - 1);
    }
}

void printLevel(node *root, int level);
int height(node *node);
node *newnode(int data);

// the function for printing level order
void printLevelOrder(node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printcurrentLevel(root, i);
    cout << endl;
}

// calculating the height of the tree ; the farthest distance from root to the leaf nodes.
int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {

        int l = height(node->left);  // left subtree's height
        int r = height(node->right); // right subtree's height

        // we will take the greater height
        if (l > r)
        {
            return (l + 1);
        }
        else
        {
            return (r + 1);
        }
    }
}

node *newnode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = NULL; // function for creating a new node
    temp->right = NULL;

    return (temp);
}

// driver's code

int main()
{
    node *root = newnode(50);
    root->left = newnode(60);
    root->right = newnode(70);
    root->left->left = newnode(80);
    root->left->right = newnode(90);

    cout << "Level Order traversal of binary tree is as follows: ";
    printLevelOrder(root);

    return 0;
}

// sample output:

// Level Order traversal of binary tree is as follows: 50 60 70 80 90
