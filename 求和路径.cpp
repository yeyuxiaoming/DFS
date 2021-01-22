/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*04.12:����һ�ö�����������ÿ���ڵ㶼����һ��������ֵ(��ֵ������)�����һ���㷨����ӡ�ڵ���ֵ�ܺ͵���ĳ������ֵ������·����������ע�⣬·����һ���ǵôӶ������ĸ��ڵ��Ҷ�ڵ㿪ʼ������������䷽���������(ֻ�ܴӸ��ڵ�ָ���ӽڵ㷽��)��
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
