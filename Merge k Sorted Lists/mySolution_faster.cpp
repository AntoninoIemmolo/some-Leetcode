/* Merge k Sorted Lists */
/* lets try to improve my solution*/

#include <climits>
#include <cstddef>
#include <stdio.h>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int min_val=INT_MAX;
        int min_idx=0;
        ListNode* lst_head = nullptr;
        ListNode* lst_tail = nullptr;

        min_val=INT_MAX;
        while (min_idx != -1) {
            min_idx=-1;
            min_val=INT_MAX;
            for(size_t i=0; i<lists.size();i++){
                if(lists[i]!=nullptr && lists[i]->val<min_val){
                    min_idx = i;
                    min_val = lists[i]->val;
                }
            }
            if(min_idx != -1){
                if(lst_head == nullptr){
                    lst_head = new ListNode(lists[min_idx]->val);
                    lists[min_idx] = lists[min_idx]->next;
                    lst_tail = lst_head;
                }
                else{
                    lst_tail->next = new ListNode(lists[min_idx]->val);
                    lists[min_idx] = lists[min_idx]->next;
                    lst_tail = lst_tail->next;
                }
            }
        }

        return lst_head;
        
    }
};
