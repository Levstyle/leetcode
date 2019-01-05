#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int matrix[maxn][maxn], rows, cols;

vector<int> printMatrix() {
    vector<int> result;
    int left = 0;
    int right = cols-1;
    int top = 0;
    int btm = rows-1;
    while(left <= right && top <= btm) {
        for(int i=left; i<=right; ++i)
            result.push_back(matrix[top][i]);

        if(top<btm)
            for(int i=top+1; i<=btm; ++i)
                result.push_back(matrix[i][right]);

        if(top<btm && left<right)
            for(int i=right-1; i>=left; --i)
                result.push_back(matrix[btm][i]);

        if(top+1<btm && left<right)
            for(int i=btm-1; i>=top+1; --i)
                result.push_back(matrix[i][left]);
        ++left;
        --right;
        ++top;
        --btm;
    }
    return result;
}

int main() {
    while(cin>>rows>>cols) {
        if(rows==-1 && cols == -1)
            break;
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                cin>>matrix[i][j];

        auto res =  printMatrix();
        for(int i = 0; i < res.size(); ++i)
            if(i == 0)
                cout<<res[i];
            else
                cout<<","<<res[i];
        cout<<endl;
    }
    return 0;
}
