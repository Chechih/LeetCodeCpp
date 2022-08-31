#include<string>

class Solution {
private:
    int maxNum = 2147483647;
    int minNum = -2147483648;
    bool numberIsNegative(int x) 
    {
        return x < 0;
    }
public:
    int reverse(int x) {
        int absNum = abs(x);
        string strNum = to_string(absNum);
        string reversedStrNum = strNum;
        std::reverse(reversedStrNum.begin(), reversedStrNum.end());
        long long rlt = numberIsNegative(x) ? -1 * atoll(reversedStrNum.c_str()): atoll(reversedStrNum.c_str());//atoi-->const char * to int
        if (rlt < maxNum and rlt > minNum)
        {
            return rlt;
        }
        return 0;
    }
};