/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Note : ans is passed by reference because we want to store the ans
    void solve(TreeNode* root, int targetSum,vector<vector<int>> &ans, vector<int> temp, int sum ){
        // base case
        if(root == NULL){
            return;
        }
        // get sum
        sum += root -> val;
        // store it in the temp
        temp.push_back(root -> val);
        // check for the leaf node
        if(root -> left == NULL && root -> right == NULL){
            // verify the sum
            if(sum == targetSum){
                // then push the temp into the main Ans
                ans.push_back(temp);
            }else{
                return;
            }
        }

        // Same for the left
        solve(root -> left, targetSum, ans, temp, sum);
        // Same for the right
        solve(root -> right, targetSum, ans, temp, sum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, targetSum,ans, temp, sum);
        return ans;
    }
};