#include<bits/stdc++.h>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

using Unordered_map = std::unordered_map<pair<int,int>, int, pair_hash>;

int main() {
    Unordered_map mp;

    return 0;
}
