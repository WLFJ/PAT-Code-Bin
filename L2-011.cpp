#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
vector<int> pre, mid;
map<int, int> tree;
//我们使用前闭后开区间！
void build_tree(int root, int p_l, int m_l, int m_r){
    if(m_l < m_r){
        int i;
        for(i = m_l; i < m_r && pre[p_l] != mid[i]; i ++);
        tree[root] = mid[i];
        build_tree(root << 1, p_l + 1, m_l, i);
        build_tree(root << 1 | 1, p_l + i - m_l + 1, i + 1, m_r);
    }
}
int main(void){
    int N;
    cin >> N;
    pre = vector<int>(N);
    mid = vector<int>(N);
    for(int i = 0; i < N; ++ i) cin >> mid[i];
    for(int i = 0; i < N; ++ i) cin >> pre[i];
    //我们先把树建出来
    build_tree(1, 0, 0, N);
    queue<int> bfs;
    bfs.push(1);
    while(!bfs.empty()){
        int cur = bfs.front();
        bfs.pop();
        if(cur != 1) cout << " ";
        cout << tree[cur];
        if(tree[cur << 1 | 1]) bfs.push(cur << 1 | 1);
        if(tree[cur << 1]) bfs.push(cur << 1);
    }
    return 0;
}