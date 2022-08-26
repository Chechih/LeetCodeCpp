#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr)
		{
			return false;//如果沒有代表不是跟直接回傳 false
		}
		TreeNode* leftNode = root->left;
		TreeNode* rightNode = root->right;
		targetSum -= root->val;
		if (leftNode == nullptr && rightNode == nullptr)
		{
			//檢查底部的節點
			return targetSum == 0;
		}
		return hasPathSum(leftNode, targetSum) || hasPathSum(rightNode, targetSum);
	}
};

int main()
{
	TreeNode root(1, 
		new TreeNode(2), nullptr);
	Solution s;
	bool a = s.hasPathSum(&root, 1);
	return 0;
}
