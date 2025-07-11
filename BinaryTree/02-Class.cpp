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



int height(Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        int heightOfLeft = height(root -> left);
        int heightOfRight = height(root -> right);

        int ans = max(heightOfLeft, heightOfRight) + 1;

        return ans;
    }
}

bool isBalanced(Node* root){
    // base case
    if(root == NULL){
        return true;
    }

    // Left Height
    int heightOfLeft = height(root -> left);
    // Right height
    int heightOfRight = height(root -> right);
    // get Diff
    int diff = abs(heightOfLeft - heightOfRight);

    bool currNodeAns;
    if(diff <= 1){
        currNodeAns = true;
    }else{
        currNodeAns = false;
    }

    // Repeat above for the left
    bool leftAns = isBalanced(root -> left);
    // Repeat above for the Right
    bool rightAns = isBalanced(root -> right);

    if(currNodeAns && leftAns && rightAns){
        return true;
    }else{
        return false;
    }
}

int main(){

    Node* root = createTree();

    bool ans = isBalanced(root);
    if(ans){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"Not Balanced"<<endl;
    }
    
    return 0;
};