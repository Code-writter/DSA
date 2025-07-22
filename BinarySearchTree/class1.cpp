#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    Node* left; 
    int data;
    Node* right;

    Node(int data){
        this -> left = NULL;
        this -> data = data;
        this -> right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(root -> data < data){
        root -> right = insertIntoBST(root -> right , data);
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
        root = insertIntoBST(root, data);
        cout<<"Enter data : ";
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
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
            if(front -> left){
                q.push(front -> left);
            }
            if(front ->  right){
                q.push(front -> right);
            }
        }
    }

}

void inOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    // LNR
    inOrderTraversal(root -> left);
    cout<<root ->data <<"  ";
    inOrderTraversal(root -> right);
}

int minValue(Node* root){
    if(root == NULL){
        return 0;
    }
    Node* temp = root;
    while(temp -> left != NULL){
        temp = temp -> left;
    }

    return temp -> data;
}

Node* maxValue(Node* root){
    if(root == NULL){
        return 0;
    }
    Node* temp = root;
    while(temp -> right != NULL){
        temp = temp -> right;
    }

    return temp;
}

bool searchInBST(Node* root, int target){
    if(root == NULL){
        return false;
    }
    bool leftKaAns = false;
    bool rightKaAns = false;
    int currentVal = root -> data;
    if(currentVal == target){
        return true;
    }
    else if(currentVal > target){
        // search in left with recurrseton
        leftKaAns = searchInBST(root -> left, target);
    }else{
        rightKaAns = searchInBST(root -> right, target);
    }

    return leftKaAns || rightKaAns;
}

Node* deleteFromBST(Node* root, int target){
    if(root == NULL){
        return NULL;
    }
    // Find the target

    if(root ->data == target){
        // There are four cases

        if(root -> left == NULL && root -> right == NULL){
            // Case 1 : left == NULL and Right == NULL (leaf Node)
            return NULL;
        }
        else if(root -> left != NULL && root -> right == NULL){
            Node* nextNode = root -> left;
            delete(root);
            return nextNode;
        }else if(root -> left == NULL && root -> right != NULL){
            Node* nextNode = root -> right;
            delete(root);
            return nextNode;

        }else{
            // we have two options to delete
            // 1. Left Sub tree max value
            // 2. Right Sub tree min Value
            // using 1st
            Node* max = maxValue(root -> left);
            
            // Now replace max with the root val
            root -> data = max -> data;

            // find root and delete
            return root -> left = deleteFromBST(root -> left, max -> data);
        }

    }else if( root -> data > target){
        // go in left
        root -> left = deleteFromBST(root -> left, target);
    }
    else{
        // go in right
        root -> right = deleteFromBST(root -> right, target);
    }
    // return the new root
    return root;
}

Node* inOrderToBST(vector<int> arr, int start, int end){
    // Base case
    if(start > end){
        return NULL;
    }

    int mid = (start + end)/2;
    int midEle = arr[mid];
    cout<<"funciton called"<<endl;
    // Create the root node
    Node* root = new Node(midEle);

    root -> left = inOrderToBST(arr, start, mid - 1);
    root -> right = inOrderToBST(arr, mid + 1, end);

    return root;
}

Node* inOrderToBST(vector<int> arr, int start, int end){
    // Base case
    if(start > end){
        return NULL;
    }

    int mid = (start + end)/2;
    int midEle = arr[mid];
    cout<<"funciton called"<<endl;
    // Create the root node
    Node* root = new Node(midEle);

    root -> left = inOrderToBST(arr, start, mid - 1);
    root -> right = inOrderToBST(arr, mid + 1, end);

    return root;
}


int main(){
    // Node* root = NULL;
    // createBST(root);
    // cout<<"\n After creation Level Order traversal "<<endl;
    // inOrderTraversal(root);
    // levelOrderTraversal(root);
    // inOrderTraversal(root);

    // int small = minValue(root);
    // cout<<"Smallet value "<<small<<endl;

    // Node* biggest = maxValue(root);
    // cout<<"Biggest value "<<biggest -> data<<endl;

    // if(searchInBST(root, 30)){
    //     cout<<"\n Present"<<endl;
    // }else{
    //     cout<<"\n Not present"<<endl;
    // }
    // cout<<"\n Starting deletion"<<endl;
    // int target;
    // cout<<"Enter value to delete : ";
    // cin>>target;

    // while(target != -1){
    //     Node* newRoot =  deleteFromBST(root, target);

    //     cout<<endl<<"After deletion level Order tarvesal"<<endl;
    //     levelOrderTraversal(newRoot);
    //     cout<<"\n Enter value to delete : ";
    //     cin>>target;

    // }
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int start = 0;
    int end = arr.size() - 1;
    Node* root = inOrderToBST(arr, start, end);
    cout<<"BST created"<<endl;
    cout<<"Root data : "<<root -> data<<endl;
    levelOrderTraversal(root);
};
