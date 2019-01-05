#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(const int numCourses, vector<pair<int, int>>& prerequisites) {
        int in[numCourses] = {};
        vector<int>edge[numCourses];
        int cnt = 0;
        for(auto &p:prerequisites) {
            edge[p.second].push_back(p.first);
            ++in[p.first];
        }
        queue<int>q;
        for(int i = 0; i < numCourses; ++i)
            if (0 == in[i]) {
                q.push(i);
                ++cnt;
            }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto to:edge[top]){
                if(--in[to] == 0){
                    q.push(to);
                    ++cnt;
                }
            }
        }
        return cnt == numCourses;
    }
};

int main() {

    return 0;
}
