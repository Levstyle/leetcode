#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int maxn = 1000010;
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[maxn] = {false};
        dp[0] = true;
        for(int i = 1, slength = s.length(); i <= slength; ++i) {
            for(int j = 0,wsize = wordDict.size(); j < wsize && !dp[i]; ++j) {
                if(i - wordDict[j].length() >= 0) {

                    dp[i] = (dp[i]||dp[i - wordDict[j].length()]);
                }
            }
        }
        return dp[s.length()];
    }
};

int main() {
    string s = "catsandog";

    vector<string>x = {"cats","dog","sand","and","cat"};
    auto sl = Solution();
    cout<<sl.wordBreak(s, x)<<endl;
    return 0;
}
