#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        auto length = s.length();
        swap_str(s, 0, length - 1);
        string bs = "";
        dfs(s, bs, 0, length);
        s = bs;
    }


    void dfs(string &s, string &bs, int low, int length){
        while(low < length && s[low] == ' ') ++low;
        int high = low;
        while(high < length && s[high] != ' ') ++high;
        if(high > low){
            swap_str(s, low, high - 1);
            if (bs.length()) bs += " ";
            bs += s.substr(low, high - low);
            if(high < length) dfs(s, bs, high, length);
        }
    }

    void swap_str(string &s, int low, int high) {
        while(low < high) {
            swap(s[low], s[high]);
            ++low;
            --high;
        }
    }
};

int main() {
    auto s = Solution();
    string _s = "the sky is blue";
    s.reverseWords(_s);
    cout<<_s<<endl;
    cout<<_s.length()<<endl;
    return 0;
}
