#include<string>

using namespace std;

class Solution {
private:
    bool isPalindromicSubstring(string s) 
    {
        for (int i = 0, sCount = s.length(); i < sCount; i++)
        {
            if (s[i] != s[sCount - 1 - i])//只要左右有不合的直接跳出
            {
                return false;
            }
        }
        return true;
    }
    bool numberIsNegative(int x)
    {
        return x < 0;
    }
public:
    bool isPalindrome(int x) 
    {
        if (numberIsNegative(x))
        {
            return false;
        }
        string strNum = to_string(x);
        return isPalindromicSubstring(strNum);
    }
};
