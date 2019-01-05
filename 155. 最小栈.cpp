#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>>stk;
    MinStack() {
        while(!stk.empty()) stk.pop();
    }

    void push(int x) {
        if(stk.empty()){
            stk.push(make_pair(x, x));
        }else{
            stk.push(make_pair(x, min(x, stk.top().second)));
        }
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top().first;
    }

    int getMin() {
        return stk.top().second;
    }
};

int main() {

    return 0;
}
