#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAXN = 100000 + 10;
struct edge{
    int left, v, right;
}Edge[MAXN];
int Head[MAXN], Tail[MAXN], Next[MAXN];
int e_tot = 0;
void addedge(int a, int b, edge c){
    a += 2, b += 2;
    Tail[++ e_tot] = b, Edge[e_tot] = c, Next[e_tot] = Head[a], Head[a] = e_tot; 
}
int main(void){
    /**
     * 现在我们要实现一个链表遍历操作 同时还能够更改其地址啊
     * */
    int startAddr, N;
    cin >> startAddr >> N;
    for(int i = 0; i < N; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        edge e = {a, b, c};
        addedge(a, c, e);
    }
    set<int> mem;
    vector<edge> ans1, ans2;
    for(int i = Head[startAddr + 2]; i; i = Head[ Tail[i] ]){
        if(mem.count(abs(Edge[i].v))){
            ans2.push_back(Edge[i]);
        }else{
            ans1.push_back(Edge[i]);
            mem.insert(abs(Edge[i].v));
        }
    }
    for(int i = 0; i < ans1.size(); i ++){
        if(i == ans1.size() - 1){
            //cout << ans1[i].left << " " << ans1[i].v << " " << -1 << endl;
            printf("%05d %d %d\n", ans1[i].left, ans1[i].v, -1);
        }else{
            //cout << ans1[i].left << " " << ans1[i].v << " " << ans1[i + 1].left << endl;
            printf("%05d %d %05d\n", ans1[i].left, ans1[i].v, ans1[i + 1].left);
        }
    }
    for(int i = 0; i < ans2.size(); i ++){
        if(i == ans2.size() - 1){
            //cout << ans1[i].left << " " << ans1[i].v << " " << -1 << endl;
            printf("%05d %d %d\n", ans2[i].left, ans2[i].v, -1);
        }else{
            //cout << ans1[i].left << " " << ans1[i].v << " " << ans1[i + 1].left << endl;
            printf("%05d %d %05d\n", ans2[i].left, ans2[i].v, ans2[i + 1].left);
        }
    }

    return 0;
}