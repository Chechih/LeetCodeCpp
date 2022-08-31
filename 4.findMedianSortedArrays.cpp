#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
private:
    /// <summary>
    /// 合併兩個 vector
    /// </summary>
    vector<int> twoVectorIntConcatenating(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> rlt;
        rlt.insert(rlt.end(), nums1.begin(), nums1.end());
        rlt.insert(rlt.end(), nums2.begin(), nums2.end());
        return rlt;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> allNums = twoVectorIntConcatenating(nums1, nums2);
        std::sort(allNums.begin(), allNums.end());
        int numCount = allNums.size() - 1;
        double middle = numCount / 2.0;
        if (int(middle) == middle)
        {
            return allNums[int(middle)];
        }
        else
        {
            int cv = allNums[int(ceil(middle))];
            int fv = allNums[int(floor(middle))];
            return (cv + fv) / 2.0;
        }
    }
};