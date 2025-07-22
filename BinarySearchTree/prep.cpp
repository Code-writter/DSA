#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

  
Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root -> data){
        root -> right = insertIntoBST(root -> right, data);
    }else{
        root -> left = insertIntoBST(root -> left, data);
    }
    return root;
}

void createBST(Node* &root){
    int data;
    cout<<"Enter data : ";
    cin>>data;

    while(data != -1){
        root  =   insertIntoBST(root, data);
        cout<<"Enter data : ";
        cin>>data;
    }
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<front -> data<<"  ";
            if(front -> left != NULL){
                q.push(front -> left);
            }
            if(front -> right != NULL){
                q.push(front -> right);
            }
        }

    }
}

bool search(Node* root, int target){
    if(root ->data == target){
        return true;
    }
    bool rightAns;
    bool leftAns;
    if(root -> data > target){
        leftAns = search(root -> left, target);
    }else{
        rightAns = search(root -> right, target);
    }
    return leftAns || rightAns;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root -> data<<"  ";
    preOrder(root -> left);
    preOrder(root -> right);
}

int main(){
    Node* root = NULL;
    createBST(root);
    levelOrder(root);

    if(search(root, 35)){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not found"<<endl;
    }
    return 0;
};