#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> post, mid;
map<int, int> tree;

//注意我们分割的是post数组！
void build_tree(int l, int r, int root, int mid_l, int mid_r){
    //cout << l << " " << r << endl;
    if(l == r){
        tree[root] = post[l];
    }else if(l < r){
        tree[root] = post[r];
        //现在我们要将两边分开来
        int mid_pos;
        for(mid_pos = mid_l; mid_pos <= mid_r; mid_pos ++){
            if(mid[mid_pos] == tree[root]) break;
        }
        //现在我们知道两边的大小了。
        int left_size = mid_pos - mid_l;
        int right_size = mid_r - mid_pos;
        if(left_size) build_tree(l, l + left_size - 1, root << 1, mid_l, mid_pos - 1);
        if(right_size) build_tree(l + left_size, r - 1, root << 1 | 1, mid_pos + 1, mid_r);
    }
}

int main(void){
    int N;
    cin >> N;
    post = vector<int>(N);
    mid = vector<int>(N);
    for(int i = 0; i < N; i ++) cin >> post[i];
    for(int i = 0; i < N; i ++) cin >> mid[i];
    tree = map<int, int>();
    build_tree(0, N - 1, 1, 0, N - 1);
    queue<int> bfs;
    vector<int> ans;
    bfs.push(1);
    while(!bfs.empty()){
        int root = bfs.front();
        ans.push_back(tree[root]);
        bfs.pop();
        if(tree[root << 1]) bfs.push(root << 1);
        if(tree[root << 1 | 1]) bfs.push(root << 1 | 1);
    }
    for(int i = 0; i < ans.size(); i ++){
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;


    return 0;
}