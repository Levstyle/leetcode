#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPrime(int x) {
        if(x < 2)
            return false;
        if(x == 2)
            return true;
        for(int i = 2; i * i <= x; ++i)
            if(x%i == 0)
                return false;
        return true;
    }
    int countPrimes(int n) {
        int ret = 0;
        for(int i = 2; i <= n; i == 2?++i:i += 2) {
            ret += isPrime(i);
        }
        return ret;
    }
};

int main() {

    return 0;
}
