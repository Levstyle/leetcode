#include<bits/stdc++.h>

using namespace std;
const int maxn = 100010;




class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        bool dp[maxn] = {false};
        dp[0] = true;
        int s_length = (int)s.length();
        int wd_size = (int)wordDict.size();
        for(int i = 1; i <= s_length; ++i) {
            for(int j = 0; j < wd_size; ++j) {
                if(i - (int)wordDict[j].length() >= 0 && wordDict[j] == s.substr(i - (int)wordDict[j].length(), wordDict[j].length())) {
                    dp[i] = dp[i]||dp[i - (int)wordDict[j].length()];
                }
            }
        }

        vector<string>ans;
        if(!dp[(int)s.length()]) return ans;
        track(s, wordDict, (int)s.length(), string(""), dp, ans);
        return ans;

    }

    void track(const string &raw, vector<string>&wordDict, int cur, string cs, bool *dp, vector<string>&ans) {
        if(cur == 0) {
            if (cs.length())
                ans.push_back(cs);
            return;
        }
        for(auto &word: wordDict) {
            if(cur - (int)word.length() >= 0 && dp[cur] && dp[cur - (int)word.length()]) {
                if(word != raw.substr(cur - (int)word.length(), (int)word.length())) continue;
                if(cs.length())
                    track(raw, wordDict, cur - (int)word.length(),  raw.substr(cur - (int)word.length(), (int)word.length()) + " " + cs , dp, ans);
                else
                    track(raw, wordDict, cur - (int)word.length(), raw.substr(cur - (int)word.length(), (int)word.length()) + cs, dp, ans);
            }
        }
    }
};
int main() {
    string xs = "catsanddog";
    vector<string>yz = {"cat","cats","and","sand","dog"};
    auto s = Solution();
    auto ans = s.wordBreak(xs, yz);
    for(auto &s: ans)
        cout<<s<<endl;
    return 0;
}
