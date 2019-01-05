#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int gcd(int a, int b) {
    while(b) {
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int nthMagicalNumber(int N, int A, int B) {
    LL low = 1, high = 0x3f3f3f3f3f3f3fLL;
    LL lcm_ab = A * (LL)B/gcd(A, B);
    LL ret = 0;
    while(high >= low){
        LL mid = (low + high)>>1;
        LL cnt = mid/A + mid/B - mid / lcm_ab;
        if (cnt >= N){
            high = mid-1;
            ret = mid;
        }else{
            low = mid+1;
        }
    }
    return int(ret%(LL)(1e9 + 7));
}

int main() {
    cout<<nthMagicalNumber(1,2,3)<<endl;
    return 0;
}
