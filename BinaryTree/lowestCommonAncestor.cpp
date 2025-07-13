/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root -> val == p -> val){
            return p;
        }
        if(root -> val == q -> val){
            return q;
        }

        TreeNode* leftKaAns = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightKaAns = lowestCommonAncestor(root -> right, p, q);

        // Now we have leftAns and rightAns

        // 4 cases
        if(leftKaAns == NULL && rightKaAns == NULL){
            return NULL;
        }
        else if(leftKaAns != NULL && rightKaAns == NULL){
            return leftKaAns;
        }
        else if(leftKaAns == NULL && rightKaAns != NULL){
            return rightKaAns;
        }
        else{
            return root;
        }


    }
};