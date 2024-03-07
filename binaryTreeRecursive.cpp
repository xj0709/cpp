#include<iostream>
using namespace std;
// C style struct
/*
struct TreeNode {
    int data;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
};

TreeNode* CreateBinaryTree (int arr[], int n) {
    if (n == 0 || !arr) {
        return NULL;
    }
    
    static int index = -1;
    ++index;

    if(index >= n || arr[index] == -1) {
        return NULL;
    }

    TreeNode* node = new TreeNode();
    node->data = arr[index];

    node->leftChild = CreateBinaryTree(arr, n);
    node->rightChild = CreateBinaryTree(arr, n);

    return node;
}

TreeNode* insertNode (TreeNode* node, int value) {
    if (node == NULL) {
        node = new TreeNode();
        node->data = value;
        return node;
    }

    if (value <= node->data) {
        node->leftChild = insertNode(node->leftChild, value);
    } else {
        node->rightChild = insertNode(node->rightChild, value);
    }
    return node;
}

void preorderTraversal (TreeNode* node) {
    if (node == NULL) {
        return;
    }

    cout<<node->data<<" ";
    preorderTraversal(node->leftChild);
    preorderTraversal(node->rightChild);

    return;
}
*/

class TreeNode {
public:
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(int value) {
        this->data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class CreateBinaryTree {
    private:
    int index;
    TreeNode* root;
    
    TreeNode* CreateTreeNode(TreeNode* node, int arr[], int size){
        if (arr == NULL || size == 0)
        {
            return NULL;
        }
        // cout<<"index = "<<index<<", ";

        if (index < size)
        {
            // cout<<"arr["<<index<<"] = "<<arr[index]<<endl;
            // no need to new a TreeNode for -1
            if (arr[index] == -1) {
                index++;
                return NULL;
            }
            if (NULL == node) {
                // cout<<"new node"<<endl;
                node = new TreeNode(arr[index++]);
            }

            node->leftChild = CreateTreeNode(node->leftChild, arr, size);
            node->rightChild = CreateTreeNode(node->rightChild, arr, size);
        }

        return node;
    }

    TreeNode* insertNodeRecursive (TreeNode* node, int value) {
        if (node == NULL) {
            node = new TreeNode(value);
            return node;
        }

        if (value <= node->data) {
            node->leftChild = insertNodeRecursive(node->leftChild, value);
        } else {
            node->rightChild = insertNodeRecursive(node->rightChild, value);
        }

        return node;
    }
    void preorderTraversalRecursive (TreeNode* node) {
        if (node == NULL) {
            return;
        }

        cout<<node->data<<" ";
        preorderTraversalRecursive(node->leftChild);
        preorderTraversalRecursive(node->rightChild);

        return;
    }

    void inorderTraversalRecursive (TreeNode* node) {
        if (node == NULL) {
            return;
        }

        inorderTraversalRecursive(node->leftChild);
        cout<<node->data<<" ";
        inorderTraversalRecursive(node->rightChild);

        return;
    }
    public:
    CreateBinaryTree() {
        index = 0;
        root = NULL;
    }
    void createTree (int arr[], int size) {
        root = CreateTreeNode(root, arr, size);

        return;
    }
    
    void insertNode (int value) {
        if (value != -1) {
            root = insertNodeRecursive(root, value);
        }
        return;
    }

    void preorderTraversal () {
        if (root == NULL) {
            return;
        }

        preorderTraversalRecursive(root);

        return;
    }

    void inorderTraversal () {
        if (root == NULL) {
            return;
        }

        inorderTraversalRecursive(root);

        return;
    }
};

int main()
{
    //create and insert binary tree
    int arr[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int n = sizeof(arr)/sizeof(arr[0]);

    //use C style struct
    /*
    TreeNode* node = CreateBinaryTree(arr, n);
    preorderTraversal(node);
    cout<<endl;
    TreeNode* tempNode = insertNode(node, 6);
    preorderTraversal(node);
    cout<<endl;
    */

    CreateBinaryTree bt;
    bt.createTree(arr, n);
    bt.preorderTraversal();
    cout<<endl;

    bt.insertNode(6);
    bt.preorderTraversal();
    cout<<endl;

    return 0;
}
