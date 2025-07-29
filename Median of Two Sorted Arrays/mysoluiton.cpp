#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //[1,2,3,4,5] [2,5,7]
        //[1,2,3,4,70] [2,5]

        // O(n) Solution
        auto i = 0, j = 0;
        auto cnt=0;
        vector<int>nums(nums1.size()+nums2.size());
        while(i<nums1.size() || j<nums2.size()){
            if(i<nums1.size()&&(j==nums2.size()||nums1[i]<nums2[j]))
                nums[max(i,j)]=nums1[i++];
            else
                nums[max(i,j)]=nums2[j++];
        }
        if(nums.size()%2==0)
            return (double)(nums[nums.size()/2]+nums[(nums.size()+1)/2])/2;
        else
            return (double)(nums[nums.size()/2]);
    }
};
