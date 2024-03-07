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

class BinaryTree {
private:
    TreeNode* root;

    void CreateTreeNode (int arr[], int size) {
        if (arr == NULL || size == 0) {
            return;
        }
        if (root == NULL) {
            root = new TreeNode(arr[0]);
        }

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        // {1, 2, 3, 4, 5, -1, -1}
        while (!q.empty() && i < size) {
            TreeNode* currNode = q.front();
            q.pop();
            cout<<"i="<<i<<endl;
            if (arr[i] != -1) {
                currNode->leftChild = new TreeNode(arr[i]);
                q.push(currNode->leftChild);
            }
            i++;
            if (arr[i] != -1 && i < size) {
                currNode->rightChild = new TreeNode(arr[i]);
                q.push(currNode->rightChild);
            }
            i++;
        }
    
        return;
    }

    void insert (int value) {
        if (root == NULL) {
            root = new TreeNode(value);
        }

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        // {1, 2, 3, 4, 5, -1, -1}
        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            cout<<"data="<<currNode->data<<endl;
            if (currNode->leftChild) {
                q.push(currNode->leftChild);
            }
            else {
                currNode->leftChild = new TreeNode(value);

                return;
            }

            if (currNode->rightChild) {
                q.push(currNode->rightChild);
            }
            else {
                currNode->rightChild = new TreeNode(value);

                return;
            }
        }
    
        return;
    }

    void layerTraversalInner (TreeNode* node) {
        if (node == NULL) {
            return;
        }

        queue<TreeNode*> q;
        q.push(node);

        while (!q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            cout<<currNode->data<<" ";

            if (currNode->leftChild) {
                q.push(currNode->leftChild);
            }

            if (currNode->rightChild) {
                q.push(currNode->rightChild);
            }
        }
    
        return;
    }
    void preorderTraversalInner (TreeNode* node) {
        if (node == NULL) {
            return;
        }

        cout<<node->data<<" ";
        preorderTraversalInner(node->leftChild);
        preorderTraversalInner(node->rightChild);

        return;
    }
public:
    BinaryTree() : root(NULL) {}

    void CreateBinaryTree(int arr[], int size) {
        CreateTreeNode(arr, size);

        return;
    }
    void insertNode (int value) {
        insert(value);
        return;
    }
    void preorderTraversal () {
        preorderTraversalInner(root);
        return;
    }

    void layerTraversal () {
        layerTraversalInner(root);

        return;
    }
};

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

int main()
{
    //int arr[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int arr[] = {1, 2, 3, 4, 5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    BinaryTree bt;
    bt.CreateBinaryTree(arr, size);
    cout<<endl;

    bt.preorderTraversal();
    cout<<endl;

    bt.insertNode(8);
    bt.layerTraversal();
    cout<<endl;

    return 0;
}
