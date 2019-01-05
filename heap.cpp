#include<bits/stdc++.h>
using namespace std;

vector<int>heap;

void push_heap(vector<int>&heap, int new_value){
    heap.push_back(new_value);
    int idx = head.size() - 1;
    while(idx and heap[(idx-1)>>1] < heap[idx]){
        swap(heap[(idx-1)>>1], heap[idx]);
        idx = (idx - 1) >> 1;
    }
}

void pop_heap(vector<int>&heap){
    if(not heap.size()) return;
    heap[0] = heap.back();
    heap.pop_back();
    int idx = 0;
    while(true){
        int lt = (idx<<1)|1;
        int rt = lt + 1;
        if(lt >= heap.size()) break;
        int nxt = idx;
        if(heap[lt] > heap[idx]) nxt = lt;
        if(rt < heap.size() && heap[rt] > heap[nxt]) nxt = rt;
        if(lt == rt) return;
        swap(heap[nxt], heap[idx]);
        idx = nxt;
    }
}
