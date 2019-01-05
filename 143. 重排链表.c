#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        auto fast = head;
        auto slow = head;
        vector<ListNode*>vec;
        while(fast && fast->next){
            vec.push_back(slow);
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast){
            // ÆæÊý
        }else{
            // Å¼Êý
        }
    }
};

int main(){


    return 0;
}
