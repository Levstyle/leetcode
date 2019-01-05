#include<bits/stdc++.h>

using namespace std;
static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ret = 0;
        for(int i = 31; i >= 0; --i){
            int c = (1<<i);
            if((m&c) == (n&c)){
                ret |= (m&c);
            }else break;
        }
        return ret;
    }
};

int main() {

    return 0;
}
