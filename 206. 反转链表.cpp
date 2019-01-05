#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto new_head = new ListNode(0);
        auto tmp = head;
        while(tmp){
            auto _tmp = tmp->next;
            tmp->next = new_head->next;
            new_head->next = tmp;
            tmp = _tmp;
        }
        return new_head->next;
    }
};

int main() {

    return 0;
}
