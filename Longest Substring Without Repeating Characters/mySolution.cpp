#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //s=abcabcbb

        auto i=0,sol=0,left=0;
        unordered_set<char> set;

        while(i<s.size()){
            if(set.find(s[i])==set.end()){
                set.insert(s[i++]);
            }
            else{
                if(set.size()>sol) sol = set.size();
                while(set.find(s[i])!=set.end())
                    set.erase(s[left++]);
                set.insert(s[i++]);
            }
        }
        if(set.size()>sol) sol = set.size();
        return sol;
    }
};


int main(){
    Solution sol;
    cout<<sol.lengthOfLongestSubstring("abcabcbb");
    return 0;
}
