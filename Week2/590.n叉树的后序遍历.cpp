/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postorderImp(vector<int>& result, Node* node) {
        if (node)
        {
            for (int i = 0; i < node->children.size(); i++)
            {
                postorderImp(result, node->children[i]);
            }
            result.push_back(node->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> result;
        postorderImp(result, root);

        return result;
    }
};
// @lc code=end

