#include <bits/stdc++.h>
using namespace std;

template <typename T>
class binaryTreeNode
{
public:
    T data;
    binaryTreeNode *left;
    binaryTreeNode *right;

    binaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};

int numNodes(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}

binaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    queue<binaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        binaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of" << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            binaryTreeNode<int> *child = new binaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of" << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            binaryTreeNode<int> *child = new binaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

binaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);
    binaryTreeNode<int> *leftChild = takeInput();
    binaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

bool isNodePresent(binaryTreeNode<int> *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        cout << "Found";
        return true;
    }
    return isNodePresent(root->left, key) || isNodePresent(root->right, key);
}

void inOrder(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}

void printLevelWise(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<binaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        binaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L:" << front->left->data << ",";
            pendingNodes.push(front->left);
        }
        else
        {
            cout << "L:" << -1 << ",";
        }

        if (front->right != NULL)
        {
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        else
        {
            cout << "R:" << -1;
        }
        cout << endl;
    }
}

void printTree(binaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

/*
15 11 13 12 16 35 20 -1 -1 20 25 -1 -1 -1 -1 -1 -1 -1 -1

*/

int main()
{
    /*
    binaryTreeNode<int> *root = new binaryTreeNode<int>(15);
    binaryTreeNode<int> *node1 = new binaryTreeNode<int>(11);
    binaryTreeNode<int> *node2 = new binaryTreeNode<int>(13);
    root->left = node1;
    root->right = node2;
    */
    // binaryTreeNode<int> *root = takeInput();
    binaryTreeNode<int> *root = takeInputLevelWise();
    // printTree(root);
    printLevelWise(root);
    cout << "Number of nodes: " << numNodes(root) << endl;

    int key;
    cout << "Enter searchNode :" << endl;
    cin >> key;
    isNodePresent(root, 6) ? cout << "Found\n" : cout << "Not Found\n";
    cout << "PreOrder Traversal:";
    preOrder(root);
    cout << endl;
    cout << "InOrder Traversal:";
    inOrder(root);
    cout << endl;
    cout << "PostOrder Traversal:";
    postOrder(root);
    cout << endl;
    delete root;

    // return 0;
}
