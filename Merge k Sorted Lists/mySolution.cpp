/* Merge k Sorted Lists */
/* an elegant but slow solution to the problem*/

#include <climits>
#include <cstddef>
#include <stdio.h>
#include <vector>
#include <queue>
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
        queue<int> q1;
        vector<queue<int>>* queues_p = queefy(lists);
        vector<queue<int>> queues = *queues_p;
        int min_val=INT_MAX;
        int min_idx=0;
        ListNode* lst_head = nullptr;
        ListNode* lst_tail = nullptr;

        min_val=INT_MAX;
        while (min_idx != -1) {
            min_idx=-1;
            min_val=INT_MAX;
            for(size_t i=0; i<queues.size();i++){
                if(queues[i].size()!=0&&queues[i].front()<min_val){
                    min_idx = i;
                    min_val = queues[i].front();
                }
            }
            if(min_idx != -1){
                if(lst_head == nullptr){
                    lst_head = new ListNode(queues[min_idx].front());
                    queues[min_idx].pop();
                    lst_tail = lst_head;
                }
                else{
                    lst_tail->next = new ListNode(queues[min_idx].front());
                    queues[min_idx].pop();
                    lst_tail = lst_tail->next;
                }
            }
        }

        return lst_head;
        
    }
private:
    vector<queue<int>>* queefy(vector<ListNode*>& lists){
        vector<queue<int>>* q = new vector<queue<int>>(lists.size());
        for (size_t i=0; i<lists.size(); i++) {
            for (ListNode* n=lists[i]; n!=nullptr; n=n->next) {
                (*q)[i].push(n->val);
            }
        }
        return q;
    }
};



// 🔧 Costruisce un ListNode* da un vector<int>
ListNode* buildList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : values) {
        ListNode* node = new ListNode(val);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = tail->next;
        }
    }
    return head;
}

// 🔧 Costruisce un vector<ListNode*> da un vector<vector<int>>
vector<ListNode*> buildLists(const vector<vector<int>>& input) {
    vector<ListNode*> lists;
    for (const auto& vec : input) {
        lists.push_back(buildList(vec));
    }
    return lists;
}

// 🧪 Funzione di test
int main() {
    vector<vector<int>> input = {{1,4,5}, {1,3,4}, {2,6}};
    vector<ListNode*> lists = buildLists(input);
    Solution s;
    s.mergeKLists(lists);

    return 0;
}

