#include<iostream>
#include <queue>
#include<stack>
#include<map>


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

void topView(Node* root){
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));


    
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int level = temp.second;

        if(mp.find(level) == mp.end()){
            // create Entry of the following node
            mp[level] = frontNode -> data;
        }

        if(frontNode -> left != NULL){
            q.push(make_pair(frontNode -> left, level - 1));
        }
        if(frontNode -> right != NULL){
            q.push(make_pair(frontNode -> right, level + 1));
        }

    }

    cout<<"\n Top view of tree : "<<endl;
    for(auto i : mp){
        cout<<i.second<<"  ";
    }
}

void bottomView(Node* root){
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));


    
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int level = temp.second;

            // create Entry of the following node
        mp[level] = frontNode -> data;

        if(frontNode -> left != NULL){
            q.push(make_pair(frontNode -> left, level - 1));
        }
        if(frontNode -> right != NULL){
            q.push(make_pair(frontNode -> right, level + 1));
        }

    }

    cout<<"\n Bottom view of tree : "<<endl;
    for(auto i : mp){
        cout<<i.second<<"  ";
    }
}

void leftBoundry(Node* root){
    if(root == NULL){
        return;
    }
    // don't print leaf
    if(root -> left == NULL && root -> right == NULL){
        return;
    }
    cout<<root -> data <<" ";
    if(root -> left != NULL){
        leftBoundry(root -> left);
    }else{
        leftBoundry(root -> right);
    }
}

void bottomBoundry(Node* root){
    if(root == NULL){
        return;
    }

    if(root -> left == NULL && root -> right == NULL){
        cout<< root -> data << " ";
    }

    bottomBoundry(root -> left);
    bottomBoundry(root -> right);
}

void rightBoundry(Node* root){
    if(root == NULL){
        return;
    }
    if(root -> left == NULL && root -> right == NULL){
        return;
    }
    if(root -> right != NULL){
        rightBoundry(root -> right);
    }else{
        rightBoundry(root -> left);
    }
    cout<<root -> data<< " ";
}

int D = 0;
int Diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = Diameter(root -> left);
    int rh = Diameter(root -> right);
    int currentD = lh + rh;
    D = max(D, currentD);
    return lh + rh + 1;
}

bool isBalanced = true;
bool isHeightBalanced(Node* root){
    if(root == NULL){
        return true;
    }

    int lh = isHeightBalanced(root -> left);
    int rh = isHeightBalanced(root -> right);


    if(isBalanced && abs(lh - rh) > 1){
        isBalanced = false;
    }
    return (lh + rh + + 1);

}



vector<int> diagoanlTraverse(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* fornt = q.front(); q.pop();
       while(fornt){
            if(fornt -> left != NULL){
                q.push(fornt -> left);
            }
            cout<<fornt -> data<<" ";
            fornt = fornt -> right;
        }
    }

}

void printBoundry(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root -> data<<"  ";
    leftBoundry(root);
    bottomBoundry(root);
    // rightBoundry(root );
    // This condition to prevent the two time printing of root node while returning
    // if(root -> right != NULL){
    //     rightBoundry(root -> right);
    // }else{
    //     rightBoundry(root -> left);
    // }

    // NOTE : If there is only one node then this code will print root two times so
    cout<<root -> data<<"  ";
    leftBoundry(root);
    bottomBoundry(root -> left);
    bottomBoundry(root -> right);
    rightBoundry(root -> right);
}


int main(){

    Node* root = createTree();
    // cout<<"Pre Order "<<endl;
    // preOrder(root);
    // cout<<"In Order "<<endl;
    // inOrder(root);
    // cout<<"Post Order "<<endl;
    // postOrder(root);
    cout<<"\n Diagonal Order Traversal"<<endl;
    // levelOrder(root);
    // topView(root);
    vector<int> ans = diagoanlTraverse(root);
    cout<<"\n Diagonal Order Traversal : "<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    // cout<<"\n Diameter of tree : "<<Diameter(root)<<endl;
    // bottomView(root);
    printBoundry(root);
    return 0;
};