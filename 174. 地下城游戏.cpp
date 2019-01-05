#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int m = dungeon.size();
        const int n = dungeon[0].size();
        int dp[m][n] = {};
        dp[m-1][n-1] = dungeon[m-1][n-1] >= 0?0:-dungeon[m-1][n-1];
        for(int i = m-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                int ret = 0x3f3f3f3f;
                if(i < m - 1)
                    ret = min(ret, dp[i+1][j] - dungeon[i][j]);
                if(j < n - 1)
                    ret = min(ret, dp[i][j+1] - dungeon[i][j]);
                if (i < m - 1 or j < n - 1)
                    dp[i][j] = max(0, ret);
            }
        }
        return dp[0][0] + 1;
    }
};

int main() {

    return 0;
}
