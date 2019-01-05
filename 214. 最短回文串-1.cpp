#include<bits/stdc++.h>

using namespace std;

static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}
();


const int maxn = 100010;
int fail[maxn];

class Solution {
public:
    string shortestPalindrome(string s) {
        string t(s);
        reverse(t.begin(), t.end());
        string st = s + "#" + t;
        int sz = st.size();
        for(int i = 0,j = fail[0] = -1; i < sz; ++i) {
            while(j != -1 && st[i] != st[j])
                j = fail[j];
            fail[i + 1] = ++j;
            if(st[i + 1] == st[j])
                fail[i+1] = fail[j];
        }
        return t.substr(0, t.size()-fail[sz]) + s;
    }
};

int main() {

    return 0;
}
