#include<bits/stdc++.h>

using namespace std;
static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int m = grid.size();
        if(!m) return 0;
        const int n = grid[0].size();
        int ret = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    ++ret;
                    bfs(grid, i, j);
                }
            }
        }

        return ret;
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int,int>>q;

        const int dx[] = {0, -1, 0, 1};
        const int dy[] = {-1, 0, 1, 0};

        q.push(make_pair(i,j));

        const int m = grid.size();
        const int n = grid[0].size();

        grid[i][j] = '0';

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i) {
                const int nx = top.first + dx[i];
                const int ny = top.second + dy[i];

                if(nx >= 0 and nx < m and ny >= 0 and ny  < n and grid[nx][ny] == '1'){
                    grid[nx][ny] = '0';
                    q.push(make_pair(nx, ny));
                }

            }
        }
    }
};

int main() {

    return 0;
}
