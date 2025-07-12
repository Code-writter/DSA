
// Definition for a binary tree node.
#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int h = 0;
        h++;
        // calculate for left
        int leftHeight = height(root -> left);
        // calculate for right
        int rightHeight = height(root -> right);
        // max(left + right) + 1 : return
        int total = max(leftHeight, rightHeight) + 1;

        return total;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        // Calculate the height of left
        int leftHeight = height(root -> left);
        // Calculate the height of Right
        int rightHeight = height(root -> right);
        // Check them that its abs is less or equal to one
        int height = abs(leftHeight - rightHeight);

        bool balanced;
        if(height <= 1){
            balanced = true;
        }else{
            balanced = false;
        }

        // repeat for left
        int leftIsBalanced = isBalanced(root -> left);
        // repeat for the right
        int rightIsBalanced = isBalanced(root -> right);
        // check if all is true then return true

        if(balanced && leftIsBalanced && rightIsBalanced){
            return true;
        }else{
            return false;
        }
        // else false
    }
};