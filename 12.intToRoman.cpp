class Solution {
private:
    map<int, string> symbols = {
        {1, "I"},
        { 4 , "IV"},
        {5 , "V"},
        {9 , "IX"},
        {10 , "X"},
        {40 , "XL"},
        {50 , "L"},
        {90 , "XC"},
        {100 , "C"},
        {400 , "CD"},
        {500 , "D"},
        {900 , "CM"},
        {1000 , "M"}
    };
    const vector<int> symbolsKey = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
public:
    string intToRoman(int num) {
        int symbolsKeyCount = symbolsKey.size();
        string rlt = "";
        for (int sk : symbolsKey) 
        {
            int divide = num / sk;
            if (divide != 0)
            {
                for (int i = 0; i < divide; i++)
                {
                    rlt += symbols[sk];
                    num %= sk;
                }
            }
        }
        return rlt;
    }
};