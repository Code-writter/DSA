#include<iostream>
#include <queue>
#include<stack>

using namespace std;
  
class Node{
    public:
    Node* left;
    int data;
    Node* right;

    Node(int data){
        this->left = NULL;
        this -> data = data;
        this -> right = NULL;
    }
};

Node* createTree(){
    int data;
    cout<<"Enter the value : ";
    cin>>data;


    // -1 = return null
    // It also act as base case for the recursion
    if(data == -1){
        return NULL;
    }
    // create Node
    Node* root = new Node(data);

    // create Left Sub treee
    root -> left = createTree();
    // Create Right sub tree
    root -> right = createTree();

    // return root
    return root;
}

void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    // N L R

    // N
    cout<<root -> data<<" -> ";
    // L
    preOrderTraversal(root -> left);
    // R
    preOrderTraversal(root -> right);

}

void inOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    // L N R

    // L
    inOrderTraversal(root -> left);
    // N
    cout<<root ->data<<" -> ";
    // R
    inOrderTraversal(root -> right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    // L R N

    // L
    postOrder(root -> left);
    // R
    postOrder(root -> right);
    // N
    cout<<root -> data<<" -> ";
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        // Pop the root 
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            cout<<endl;
            if(!q.empty())
            q.push(NULL);

        }else{        
            // Print
            cout<<front -> data<<"  ";
            // Push Left part
            if(front -> left != NULL){
                q.push(front -> left);
            }
            // Push Right part
            if(front -> right != NULL){
                q.push(front -> right);
            }
        }
    }
}

int getTheElement(vector<int> inOrder, int element){
    for(int i = 0; i<inOrder.size(); i++){
        if(inOrder[i] == element){
            return i;
        }
    }
    return -1;
}

Node* createTreeFromInAndPreOrderTraversal(vector<int> preOrder, vector<int> inOrder, int &preIndex, int inOrderStart, int inOrderEnd, int size){
    // base case
    if(preIndex >= preOrder.size() || inOrderStart > inOrderEnd){
        // That is not tree can be created 
        // Invalid Arrays
        return NULL;
    }

    // get first element of the Pre Order
    int element = preOrder[preIndex];
    preIndex++;

    // Now create node of that element
    Node* temp = new Node(element);
    
    // Now get the division part of the InOrder tarversal
    int index = getTheElement(inOrder, element);

    // Now divide the parts and give it to the left and Right part
    // Left part of the tree
    temp -> left = createTreeFromInAndPreOrderTraversal(preOrd er, inOrder, preIndex, inOrderStart, index - 1, size);
    temp -> right = createTreeFromInAndPreOrderTraversal(preOrder, inOrder, preIndex, index + 1, inOrderEnd , size);

    return temp;
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftKiHeight = height(root -> left);
    int rightKiHeight = height(root -> right);

    return max(leftKiHeight, rightKiHeight) + 1;
}

int main(){
    vector<int> inOrder  = {10, 20, 40, 80, 90, 50, 30, 60, 70, 100, 110,};
    // pre => NLR
    vector<int> preOrder = {80, 90, 40, 50, 20, 60, 100, 110, 70, 30, 10,};
    // in => LNR
    
    int preIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = inOrder.size();
    int size = preOrder.size() - 1;

    Node* temp = createTreeFromInAndPreOrderTraversal(preOrder, inOrder, preIndex, inOrderStart, inOrderEnd, size);
    cout<<"Level Order Traversal"<<endl;
    levelOrder(temp);
    int h = height(temp);
    cout<<"Height of tree is : "<<h<<endl;
    return 0;
};