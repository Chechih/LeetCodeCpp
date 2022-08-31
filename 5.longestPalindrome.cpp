#include<string>
#include<vector>
#include<math.h>
#include <map>

using namespace std;

class Solution {
private:
    map<string, vector<int>> findedCharIndex = {};
    map<string, bool> findedPalindromicSubstring = {};
    bool isPalindromicSubstring(string s)
    {
        if (findedPalindromicSubstring.count(s))
        {
            return findedPalindromicSubstring[s];
        }
        for (int i = 0, sCount = s.length(); i < sCount / 2; i++)
        {
            if (s[i] != s[sCount - 1 - i])// 只要左右有不合的直接跳出
            {
                findedPalindromicSubstring[s] = false;
                return false;
            }
        }
        findedPalindromicSubstring[s] = true;
        return true;
    }
    vector<int> findAllCharIndex(string s, string target)
    {
        if (!findedCharIndex.count(target)) 
        {
            vector<int> pos;
            for (int i = 0, leg = s.length(); i < leg; i++)
            {
                char c = s[i];
                if (string(1, c) == target)//string(1, c)-->char to string
                {
                    pos.push_back(i);
                }
            }
            findedCharIndex[target] = pos;
            return findedCharIndex[target];
        }
        return findedCharIndex[target];
    }
public:
    string longestPalindrome(string s) {
        findedCharIndex.clear();
        findedPalindromicSubstring.clear();
        string maxPalindromicSubstring = "";
        for (int i = 0, sCount = s.length(); i < sCount; i++)
        {
            if (maxPalindromicSubstring.length() >= s.length() - i + 1)//如果最大值
            {
                break;
            }
            string ic = string(1, s[i]);//string(1, c)-->char to string
            if (maxPalindromicSubstring == "")
            {
                maxPalindromicSubstring = ic;
            }
            vector<int> reversedAllSameCharInds(findAllCharIndex(s, ic));
            reverse(reversedAllSameCharInds.begin(), reversedAllSameCharInds.end());
            for (int j : reversedAllSameCharInds)
            {
                if (maxPalindromicSubstring.length() >= j - i + 1) //如果最大值
                {
                    break;
                }
                string rangeStr = s.substr(i, j + 1 - i);//切字串 地一個參數起始點 第二個是長度
                bool isPS = isPalindromicSubstring(rangeStr);
                if (isPS && rangeStr.length() > maxPalindromicSubstring.length())
                {
                    maxPalindromicSubstring = rangeStr;
                    break;
                }
            }
        }
        return maxPalindromicSubstring;
    }
};