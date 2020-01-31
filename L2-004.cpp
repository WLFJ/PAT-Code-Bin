#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> pre;
bool isOK = true;
vector<int> ans, mid;
void make_tree1(int l, int r, int root){
    if(l == r){
        ans.push_back(pre[l]);
        mid.push_back(pre[l]);
    }else if(l < r){
        int p = l + 1;
        while(p <= r && pre[p] < pre[l]) p ++;
        make_tree1(l + 1, p - 1, root << 1);
        mid.push_back(pre[l]);
        if(p <= r)
            make_tree1(p, r, root << 1 | 1);
        ans.push_back(pre[l]);
    }
}
void make_tree2(int l, int r, int root){
    if(l == r){
        ans.push_back(pre[l]);
        mid.push_back(pre[l]);
    }else if(l < r){
        int p = l + 1;
        while(p <= r && pre[p] >= pre[l]) p ++;
        make_tree2(l + 1, p - 1, root << 1);
        mid.push_back(pre[l]);
        if(p <= r)
            make_tree2(p, r, root << 1 | 1);
        ans.push_back(pre[l]);
    }
}
int main(void){
    int N;
    cin >> N;
    pre = vector<int>(N);
    for(int i = 0; i < N; i ++) cin >> pre[i];
    //判断是不是标准的树呢？
    make_tree1(0, N - 1, 1);

    isOK = is_sorted(mid.begin(), mid.end());
    if(isOK){
        cout << "YES" << endl;
        for(int i = 0; i < ans.size(); i ++){
            if(i) cout << " ";
            cout << ans[i];
        }
    }else{
        ans.clear();
        mid.clear();
        make_tree2(0, N - 1, 1);
        isOK = is_sorted(mid.rbegin(), mid.rend());
        if(isOK){
            cout << "YES" << endl;
            for(int i = 0; i < ans.size(); i ++){
                if(i) cout << " ";
                cout << ans[i];
            }
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}