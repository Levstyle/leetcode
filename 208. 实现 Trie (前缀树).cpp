#include<bits/stdc++.h>

using namespace std;

const int nch = 26;
const int maxn = 200010;

static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

struct Node {
    int ch[nch];
    bool flag;

    void reset(){
        for(int i = 0; i < nch; ++i){
            ch[i] = -1;
        }
        flag = false;
    }
};

Node tree[maxn];

class Trie {
public:
    /** Initialize your data structure here. */
    int tot;
    Trie() {
        tree[tot = 0].reset();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int root = 0;
        for(auto &chr:word) {
            if(tree[root].ch[chr - 'a'] == -1) {
                tree[root].ch[chr - 'a'] = ++tot;
                tree[tot].reset();
            }
            root = tree[root].ch[chr - 'a'];
        }
        tree[root].flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int root = 0;
        for(auto &chr: word) {
            if(tree[root].ch[chr - 'a'] == -1)
                return false;
            root = tree[root].ch[chr - 'a'];
        }
        return tree[root].flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int root = 0;
        for(auto &chr: prefix) {
            if(tree[root].ch[chr - 'a'] == -1)
                return false;
            root = tree[root].ch[chr - 'a'];
        }
        return true;
    }
};

int main() {

    return 0;
}
