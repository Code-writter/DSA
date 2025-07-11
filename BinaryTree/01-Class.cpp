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

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    // N L R

    // N
    cout<<root -> data<<" -> ";
    // L
    preOrder(root -> left);
    // R
    preOrder(root -> right);

}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    // L N R

    // L
    inOrder(root -> left);
    // N
    cout<<root ->data<<" -> ";
    // R
    inOrder(root -> right);
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
            cout<<front -> data<<" -> ";
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

int main(){

    Node* root = createTree();
    // cout<<"Pre Order "<<endl;
    // preOrder(root);
    // cout<<"In Order "<<endl;
    // inOrder(root);
    // cout<<"Post Order "<<endl;
    // postOrder(root);
    cout<<"\n Level Order Traversal"<<endl;
    levelOrder(root);

    return 0;
};