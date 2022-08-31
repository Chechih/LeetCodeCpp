#include<string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) //測試可能會只有一 直接回傳
        {
            return s;
        }
        int roundRule = 2 * numRows - 2;//會有幾個波型
        int strCount = s.length(); //自圓長度
        string newStr = "";//#回傳值
        int maxRound = strCount / roundRule + 2;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < maxRound; j++)
            {
                if (i == 0) //最上面
                {
                    if (roundRule * j < strCount) 
                    {
                        newStr = newStr + s[roundRule * j];
                    }
                }
                else if (i == numRows - 1) //最下面
                {
                    if (roundRule * j + roundRule / 2 < strCount)
                    { 
                        newStr = newStr + s[roundRule * j + int(roundRule / 2)];
                    }
                }
                else //中間部分
                {
                    if (roundRule * j - i > 0 and roundRule * j - i < strCount) //中間部分可能多 i
                    {
                        newStr = newStr + s[roundRule * j - i];
                    }
                    if (roundRule * j + i > 0 and roundRule * j + i < strCount) //少 i
                    {
                        newStr = newStr + s[roundRule * j + i];
                    }
                }
            }
        }
        return newStr;
    }
};