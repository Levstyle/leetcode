#include<bits/stdc++.h>

using namespace std;
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

bool operator<(const Point &a, const Point &b) {
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}


bool operator==(const Point &a, const Point &b) {
    return a.x == b.x and a.y == b.y;
}

int gcd(int a, int b) {
    return b?gcd(b, a%b):a;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

const pair<int, int> zero_pair = make_pair(0, 0);

pair<int,int> cmp(const Point &a, const Point &b) {
    int c = b.y - a.y;
    int d = b.x - a.x;
    if(c == d && c == 0)
        return make_pair(0,0);
    if(c == 0)
        return make_pair(0, 1);
    if(d == 0)
        return make_pair(1, 0);
    int g = gcd(c, d);
    return make_pair(c/g, d/g);
}



class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() < 2)
            return points.size();
        sort(points.begin(), points.end());
        unordered_map<pair<int,int>,int, pair_hash>mp;
        int ret = 2, sz = points.size();
        for(int i = 0; i < sz; ++i) {
            mp.clear();
            for(int j = i + 1; j < sz; ++j) {
                auto xy = cmp(points[i], points[j]);
                if(mp.count(xy)) {
                    mp[xy] += 1;
                } else
                    mp[xy] = 2;

                if(mp.count(zero_pair) and xy != zero_pair) {
                    ret = max(ret, mp[xy] + mp[zero_pair] - 1);
                } else
                    ret = max(ret, mp[xy]);
            }

        }
        return ret;
    }
};

int main() {

    return 0;
}
