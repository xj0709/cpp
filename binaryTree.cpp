#include<iostream>
#include<queue>
using namespace std;

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

TreeNode* CreateBinaryTree (int arr[], int size) {
    if (!arr && size == 0) {
        return NULL;
    }
    
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    //int arr[] = {10, 2, -1, 3, -1, -1, 15, -1, -1}; 3 15 2 10 
    while (!q.empty() && i < size) {
        TreeNode* currNode = q.front();
        q.pop();

        if (arr[i] != -1) {
            currNode->leftChild = new TreeNode(arr[i]);
            q.push(currNode->leftChild);
        }
        i++;

        if (i < size && arr[i] != -1) {
            currNode->rightChild = new TreeNode(arr[i]);
            q.push(currNode->rightChild);
        }
        i++;
    }
    return root;
}
TreeNode* CreateBinaryTreeQueue (int arr[], int size) {
    if (size == 0 || !arr) {
        return NULL;
    }
    
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    //int arr[] = {10, 2, -1, 3, -1, -1, 15, -1, -1}; 3 15 2 10 
    while (!q.empty() && i < size) {
        while (!q.empty() && i < size) {
            if (arr[i] != -1) {
                TreeNode* currNode = q.front();
                q.pop();
                currNode->leftChild = new TreeNode(arr[i]);
                q.push(currNode->leftChild);
            }
            i++;
        }

        if (i < size && arr[i] != -1) {
            TreeNode* currNode = q.front();
            q.pop();
            currNode->rightChild = new TreeNode(arr[i]);
            q.push(currNode->rightChild);
        }
        i++;
    }
    return root;
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        root = new TreeNode(value);

        return root;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* currNode = q.front();
        q.pop();

        if (currNode->leftChild) {
            q.push(currNode->leftChild);
        } else {
            currNode->leftChild = new TreeNode(value);
            return root;
        }

        if (currNode->rightChild) {
            q.push(currNode->rightChild);
        } else {
            currNode->rightChild = new TreeNode(value);
            return root;
        }
    }

    return root;
}

void preorderTrave (TreeNode* node) {
    if (node == NULL) {
        return;
    }

    cout<<node->data<<" ";
    inorderTrave(node->leftChild);

    inorderTrave(node->rightChild);

    return;
}

void inorderTrave (TreeNode* node) {
    if (node == NULL) {
        return;
    }

    inorderTrave(node->leftChild);
    cout<<node->data<<" ";
    inorderTrave(node->rightChild);

    return;
}


class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertRecrucive(TreeNode* node, int value) {
        if (node == NULL) {
            node = new TreeNode(value);
            return node;
        }
        //cout<<"node->data:"<<node->data<<", value:"<<value<<endl;
        if (value < node->data) {
            node->leftChild = insertRecrucive(node->leftChild, value);
        }
        else if (value > node->data) {
            node->rightChild = insertRecrucive(node->rightChild, value);
        }
    
        return node;
    }

    void inorderTraversal (TreeNode* node) {
        if (node == NULL) {
            return;
        }


        inorderTraversal(node->leftChild);
        // cout<<node->data<<" ";
        inorderTraversal(node->rightChild);

        return;
    }
public:
    BinarySearchTree() : root(NULL) {}

    void insertNode(int value) {
        root = insertRecrucive(root, value);

        return;
    }
    void inorderTraversal () {
        inorderTraversal(root);
        return;
    }
};

int main()
{
    int arr[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int size = sizeof(arr)/sizeof(arr[0]);

    TreeNode* node = CreateBinaryTree(arr, size);
    preorderTrave(node);
    cout<<endl;

    inorderTrave(node);
    cout<<endl;

    return 0;
}
