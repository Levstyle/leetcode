#include<bits/stdc++.h>

using namespace std;
static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}
();



class Solution {
public:
    void dfs(vector<int>vec, int cur, int n, vector<vector<int>>&ans) {
        if (cur == vec.size()-1) {
            vector<int>tmp;
            int sum = 0;
            for(int i = 0; i < 9; ++i)
                if(vec[i]) {
                    tmp.push_back(i + 1);
                    sum += i + 1;
                }
            if (sum == n)
                ans.push_back(tmp);
            return;
        }
        for(int i = cur; i < vec.size(); ++i) {
            if(i != cur and vec[i] == vec[cur])
                continue;
            swap(vec[i], vec[cur]);
            dfs(vec, cur + 1, n, ans);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>vec;
        vector<vector<int>>ans;
        for(int i = 0; i < 9; ++i)
            vec.push_back(i < k?1:0);
        dfs(vec, 0, n, ans);
        return ans;
    }

};


int main() {

    return 0;
}
