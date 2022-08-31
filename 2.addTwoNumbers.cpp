#include <iostream>
#include <string>
using namespace std;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	string listNode2string(ListNode *node)
	{
		string rlt = "";
		ListNode* n = node;
		while (n != NULL) 
		{
			rlt += to_string(n->val);
			n = n->next;
		}
		return rlt;
	}
	/// <summary>
	/// 兩個字串相加
	/// </summary>
	string stringSunReverse(string s1, string s2)
	{
		int maxLeg = max(s1.size(), s2.size());
		int carry = 0;
		string rlt = "";
		for (int i = 0; i < maxLeg; i++)
		{
			int s = carry;
			if (i < s1.size())
			{
				s += stol(string(1, s1[i]));//字串轉 int
			}
			if (i < s2.size())
			{
				s += stol(string(1, s2[i]));
			}
			string sStr = to_string(s);
			rlt += sStr[sStr.size() - 1];
			carry = 0;
			if (sStr.size() != 1)
			{
				carry = stol(string(1, sStr[0]));
			}
		}
		if (carry > 0)
		{
			rlt += to_string(carry);//int 轉字串
		}
		return rlt;
	}
	ListNode* str2listNode(string str)
	{
		ListNode *rlt = new ListNode;
		ListNode *node = rlt;
		ListNode *preNode = nullptr;
		for (char c : str) 
		{
			node->val = stoi(string(1, c));
			node->next = new ListNode;
			preNode = node;
			node = node->next;
		}
		if (preNode != NULL) {
			preNode->next = nullptr;
		}
		return rlt;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		string i1 = listNode2string(l1);
		string i2 = listNode2string(l2);
		string sumStr = stringSunReverse(i1, i2);
		//reverse(sumStr.begin(), sumStr.end());//反轉
		return str2listNode(sumStr);
	}
};

int main()
{
	ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(9)));
	ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(9))));
	Solution s;
	auto a = s.addTwoNumbers(l1, l2);
	return 0;
}
