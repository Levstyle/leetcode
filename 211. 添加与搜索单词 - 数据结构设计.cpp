#include<bits/stdc++.h>

using namespace std;


const int nch = 26;
const int maxn = 200010;

static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}
();

struct Node {
    int ch[nch];
    bool flag;

    void reset() {
        for(int i = 0; i < nch; ++i) {
            ch[i] = -1;
        }
        flag = false;
    }
};

Node tree[maxn];

class WordDictionary {
public:
    /** Initialize your data structure here. */
    int tot;
    WordDictionary() {
        tree[tot = 0].reset();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
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

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return _search(word, 0, 0);
    }

    bool _search(string &word, int cur, int root) {
        if(cur == word.size() && tree[root].flag)
            return true;
        if(cur >= word.size() or root == -1)
            return false;
        if(word[cur] == '.') {
            for(int i = 0; i < nch; ++i) {
                if(tree[root].ch[i] != -1 && _search(word, cur + 1, tree[root].ch[i]))
                    return true;
            }
            return false;
        }
        if(tree[root].ch[word[cur]-'a'] != -1)
            return _search(word, cur + 1, tree[root].ch[word[cur]-'a']);
        return false;
    }
};

int main() {

    return 0;
}
