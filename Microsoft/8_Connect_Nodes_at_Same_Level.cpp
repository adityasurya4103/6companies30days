#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *nextRight;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;

    return temp;
}

Node *buildTree(string str)
{

    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void connect(struct Node *p);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */

void printSpecial(Node *root)
{
    if (root == NULL)
        return;

    Node *next_root = NULL;

    while (root != NULL)
    {
        cout << root->data << " ";

        if (root->left && (!next_root))
            next_root = root->left;
        else if (root->right && (!next_root))
            next_root = root->right;

        root = root->nextRight;
    }

    printSpecial(next_root);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//main function
class Solution
{
public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
        // Your Code Here
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int c = q.size();
            for (int i = 0; i < c; i++)
            {
                Node *n = q.front();
                q.pop();
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
                if (i + 1 == c)
                    n->nextRight = NULL;
                else
                    n->nextRight = (q.front());
            }
        }
    }
};

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        Solution obj;
        obj.connect(root);
        printSpecial(root);
        cout << endl;
        inorder(root);
        cout << endl;
    }
    return 0;
}
