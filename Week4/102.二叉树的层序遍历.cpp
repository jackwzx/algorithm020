/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if (!root)
        {
            return result;
        }
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty())
        {
            int curLevelSize = nodeQueue.size();

            result.push_back(vector<int> ());

            for (size_t i = 1; i <= curLevelSize; i++)
            {
                TreeNode* curNode = nodeQueue.front();
                nodeQueue.pop();

                result.back().push_back(curNode->val);

                if (curNode->left)
                {
                   nodeQueue.push(curNode->left); 
                }
                if (curNode->right)
                {
                   nodeQueue.push(curNode->right); 
                }
            }
        }
        return result;
    }
};
// @lc code=end

