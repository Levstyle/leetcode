#include<bits/stdc++.h>

using namespace std;



struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
    RandomListNode *_copy(RandomListNode *head, unordered_map<RandomListNode *, RandomListNode *>&ump){
        if(!head) return nullptr;
        auto hd = new RandomListNode(head->label);
        ump[head] = hd;
        hd->next = _copy(head->next, ump);
        return hd;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*>us;
        auto hd = _copy(head, us);
        auto nx = hd;
        while(head){
            if(head->random){
                nx->random = us[head->random];
            }
            nx = nx->next;
            head = head->next;
        }
        return hd;
    }
};

int main(){

    return 0;
}
