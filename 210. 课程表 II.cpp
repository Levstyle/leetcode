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
    vector<int> findOrder(const int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int>e[numCourses];
        int in[numCourses] = {0};
        for(auto &p:prerequisites) {
            ++in[p.first];
            e[p.second].push_back(p.first);
        }

        queue<int>q;

        for(int i = 0; i < numCourses; ++i) {
            if(0 == in[i]) {
                q.push(i);
            }
        }

        vector<int>ret;

        while(!q.empty()) {
            int top = q.front();
            q.pop();
            ret.push_back(top);
            for(auto &to: e[top]) {
                if(--in[to] == 0) {
                    q.push(to);
                }
            }
        }
        return ret.size() == numCourses?ret:vector<int> {};
    }
};

int main() {

    return 0;
}
