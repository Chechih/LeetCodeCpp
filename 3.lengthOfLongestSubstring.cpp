#include <iostream>
#include <thread>
#include<mutex>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sCount = s.length();
        string sSpilt = "";
        string sMax = "";
        for (int i = 0; i < sCount; i++)
        {
            char c = s[i];
            sSpilt = c;
            if (sMax == "" && sSpilt != "")
            {
                sMax = sSpilt;
            }
            for (int j = i + 1; j < sCount; j++)
            {
                c = s[j];
                auto aaa = sSpilt.find(c);
                if (sSpilt.find(c) != string::npos) {//contains a string in C++
                    break;
                }
                else
                {
                    sSpilt += c;
                }
                if (sSpilt.length() > sMax.length())
                {
                    sMax = sSpilt;
                }
            }
        }
        return sMax.length();
    }
};

int main() {

    Solution s;
    auto aaa = s.lengthOfLongestSubstring("abcabcbb");
    return 0;
}