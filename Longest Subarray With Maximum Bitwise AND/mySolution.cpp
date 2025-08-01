#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto maxval=-1,maxcnt=-1,cnt=1;
        unordered_map<int, int>* map = new unordered_map<int, int>;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) cnt++;
            else{
                if(nums[i-1]>maxval){
                    maxval = nums[i-1];
                    maxcnt=cnt;
                }
                if(nums[i-1]==maxval && cnt>maxcnt)
                    maxcnt=cnt;
                cnt=1;
            }
        }

        if(nums[nums.size()-1]>maxval){
            maxval = nums[nums.size()-1];
            maxcnt=cnt;
        }
        if(nums[nums.size()-1]==maxval && cnt>maxcnt)
                maxcnt=cnt;
        return maxcnt;
    }
};
