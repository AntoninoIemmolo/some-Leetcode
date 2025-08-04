
/* Definition for singly-linked list. */
#include <cstdio>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = sum(l1,l2,0);
        return l;
    }
private:
    ListNode* sum(ListNode* l1, ListNode* l2, int carry_in){
        ListNode* l=new ListNode();
        int carry_out=0;

        if(l1 == nullptr && l2 == nullptr){
            if(carry_in!=0){
                l->val=carry_in;
                return l;
            }
            return nullptr;
            }

        if(l1!=nullptr)
            l->val = l1->val;
        if(l2!=nullptr){
            if(l->val + l2->val < 10){
                l->val += l2->val;
            }
            else{
                l->val += l2->val - 10;
                carry_out=1;
            }
        }
        if(l->val+carry_in < 10)
            l->val += carry_in;
        else{
            l->val += carry_in - 10;
            carry_out=1;
        }

        if(l1==nullptr)
            l->next = sum(l1, l2->next, carry_out);
        else if(l2==nullptr)
            l->next = sum(l1->next, l2, carry_out);
        else
            l->next = sum(l1->next, l2->next, carry_out);
        return l;
    }
};


