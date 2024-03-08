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
            // cout<<"i="<<i<<endl;
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
            // cout<<"data="<<currNode->data<<endl;
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

        stack<TreeNode*> st;
        st.push(node);

        while (!st.empty()) {
            TreeNode* currNode = st.top();
            st.pop();
            cout<<currNode->data<<" ";
            
            if (currNode->rightChild) {
                st.push(currNode->rightChild);
            }

            if (currNode->leftChild) {
                st.push(currNode->leftChild);
            }
        }
        // cout<<node->data<<" ";
        // preorderTraversalInner(node->leftChild);
        // preorderTraversalInner(node->rightChild);

        return;
    }

    void inorderTraversalInner (TreeNode* node) {
        if (node == NULL) {
            return;
        }

        stack<TreeNode*> st;
        TreeNode* currNode = node;

        while (currNode != NULL || !st.empty()) {
            // traverse the left children until the last leftChild
            while (currNode != NULL) {
                st.push(currNode);
                currNode = currNode->leftChild;
            }
            // print the 'last' leftChild, it may be in the 'last' layer, or may have rightChild
            if (!st.empty()) {
                currNode = st.top();
                st.pop();
                cout<<currNode->data<<" ";

                currNode = currNode->rightChild;
            }
        }

        // inorderTraversalInner(node->leftChild);
        // cout<<node->data<<" ";
        // inorderTraversalInner(node->rightChild);

        return;
    }

    void postorderTraversalInner (TreeNode* node) {
        if (node == NULL) {
            return;
        }

        stack<TreeNode*> st;

        TreeNode* currNode = node;
        TreeNode* preNode = NULL; // the last visit node

        while (currNode != NULL || !st.empty()) {
            // traverse the left children until the last leftChild
            while (currNode) {
                st.push(currNode);
                currNode = currNode->leftChild;
            }
            
            currNode = st.top();
            st.pop();

            // if the node has no rightChild, print out, and its parent node should be printed if itself is rightChild:
            // mark this node with preNode, otherwise this node will be printed again when its parent node became currNode and
            // need to be printed.
            if (currNode->rightChild == NULL || currNode->rightChild == preNode) {
                cout<<currNode->data<<" ";
                preNode = currNode;
                currNode = NULL;
            } else {
                st.push(currNode);
                currNode = currNode->rightChild;
            }
        }

        // postorderTraversalInner(node->leftChild);
        // postorderTraversalInner(node->rightChild);
        // cout<<node->data<<" ";

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

    void inorderTraversal () {
        inorderTraversalInner(root);
        return;
    }

    void postorderTraversal () {
        postorderTraversalInner(root);
        return;
    }

    void layerTraversal () {
        layerTraversalInner(root);

        return;
    }
};

int main()
{
    //int arr[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int arr[] = {1, 2, 3, 4, 5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    BinaryTree bt;
    bt.CreateBinaryTree(arr, size);
    cout<<endl;

    bt.insertNode(8);

    cout<<"preorder: ";
    bt.preorderTraversal();
    cout<<endl;

    cout<<"inorder: ";
    bt.inorderTraversal();
    cout<<endl;

    cout<<"postorder: ";
    bt.postorderTraversal();
    cout<<endl;

    return 0;
}
