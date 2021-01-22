/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*04.12:给定一棵二叉树，其中每个节点都含有一个整数数值(该值或正或负)。设计一个算法，打印节点数值总和等于某个给定值的所有路径的数量。注意，路径不一定非得从二叉树的根节点或叶节点开始或结束，但是其方向必须向下(只能从父节点指向子节点方向)。
*/
class Solution {
    int count = 0;
    int v[1000] = {0};
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        count = 0;
        v[0] = root->val;
        if(v[0] == sum)count++;
        if(root->left) dfs(root->left,1,sum);
        if(root->right) dfs(root->right,1,sum);
        return count;
    }
    void dfs(TreeNode* root,int n,int sum) {
        v[n] = root->val + v[n - 1];
        if(v[n] == sum) count++;
        for(int i = 0; i < n; i++) {
            if(v[n] - v[i] == sum) count++;
        }
        if(root->left != NULL) dfs(root->left,n + 1,sum);
        if(root->right != NULL) dfs(root->right,n + 1,sum);
    }
};
