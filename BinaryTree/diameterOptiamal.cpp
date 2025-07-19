#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int diameter = 0;
public:
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftHeight = solve(root -> left);
        int rightHeight = solve(root -> right);

        int currentNodeDiameter = (leftHeight + rightHeight);
        diameter = max(currentNodeDiameter, diameter);
        int maxHeight = max(leftHeight, rightHeight) + 1;
        return maxHeight;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return diameter;
    }
};