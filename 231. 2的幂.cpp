#include<bits/stdc++.h>

using namespace std;

static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n > 0 and (n&(n-1)) == 0) return true;
        return false;
    }
};

int main() {

    return 0;
}
