#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *_merge(ListNode *x, ListNode *y) {
        if(!x)
            return y;
        if(!y)
            return x;
        if(x->val < y->val) {
            x->next = _merge(x->next, y);
            return x;
        } else {
            y->next = _merge(x, y->next);
            return y;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        auto fast = head;
        auto slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        auto x = sortList(head);
        auto y = sortList(fast);
        return _merge(x, y);
    }
};

int main() {

    return 0;
}
