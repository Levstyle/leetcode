#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        auto hd = new ListNode(0);
        ListNode *pre = hd;
        while(head) {
            if(head->val != val) {
                pre->next = head;
                pre = head;
            }
            head = head->next;
        }
        pre->next = nullptr;
        return hd->next;
    }
};


int main() {

    return 0;
}
