# PTA天梯赛L2刷题心得

## 最短路

注意相关问题的求解！

```cpp
/**
 * 现在我们实现边版本的
 * 首先找到最小的点
 * 之后将其打上标记！
 * 在遍历所有这个点的邻接点，进行收缩操作
 * */

#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN = 5000 + 10;
const int MAXM = (1 + MAXN) * MAXN / 2;
int Head[MAXM], Edge[MAXM], Tail[MAXM], Next[MAXM];
int e_tot = 0;
void addedge(int a, int b, int c){
    a ++, b ++;
    Tail[++e_tot] = b, Edge[e_tot] = c, Next[e_tot] = Head[a], Head[a] = e_tot;
}

using pii = pair<int, int>;//第一个代表距离，第二个代表下标

int N, M, S, D;
vector<int> weight;

vector<int> path;
vector<int> dist;
vector<int> path_sum;
vector<int> weight_sum;

void Dijkstra(){

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    path = vector<int>(N);
    path[S] = -1;

    dist = vector<int>(N, 0x3f3f3f3f);
    dist[S] = 0;
    pq.push(make_pair(0, S));

    path_sum = vector<int>(N);
    path_sum[S] = 1;

    weight_sum = vector<int>(N);
    weight_sum[S] = weight[S];

    vector<int> vis(N);

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;//注意打上标记!
        for(int i = Head[u]; i; i = Next[i]){
            int b = Tail[i], c = Edge[i];
            if(dist[b] > dist[u] + c){
                //如果缩短更佳
                dist[b] = dist[u] + c;
                pq.push(make_pair(dist[b], b));
                path[b] = u;
                path_sum[b] = path_sum[u];
                weight_sum[b] = weight_sum[u] + weight[b];
            }else if(dist[b] == dist[u] + c){
                //到两边的路都可以走
                path_sum[b] += path_sum[u];
                if(weight_sum[b] < weight_sum[u] + weight[b]){
                    weight_sum[b] = weight_sum[u] + weight[b];
                    path[b] = u;
                }
            }
        }

    }
}

void getPath(int destination){
    if(path[destination] == -1){
        cout << destination - 1;
    }else{
        getPath(path[destination]);
        cout << " " << destination - 1;
    }
}

int main(void){
    cin >> N >> M >> S >> D;
    S ++, D ++, N ++;
    weight = vector<int>(N);
    for(int i = 1; i < N; i ++) cin >> weight[i];
    for(int i = 0; i < M; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        addedge(a, b, c);
        addedge(b, a, c);
    }
    Dijkstra();
    cout << path_sum[D] << " " << weight_sum[D] << endl;
    getPath(D);
    cout << endl;
    return 0;
}
```

## 链表题

```cpp
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
```

## 递归判树

```cpp
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
```

## 结构体排序

```cpp
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct goods{
    double cnt, total_cost;
    goods(){};
    //下面我们练习一下重载小于号
    bool operator < (const goods& g) const{
        return total_cost / cnt > g.total_cost / g.cnt;
    }
};
int main(void){
    int N;
    double D;
    cin >> N >> D;
    vector<goods> arr(N);
    for(int i = 0; i < N; i ++){
        cin >> arr[i].cnt;
    }
    for(int i = 0; i < N; i ++){
        cin >> arr[i].total_cost;
    }
    for(auto it = arr.begin(); it != arr.end();){
        if(it -> cnt > 0){
            it ++;
        }else{
            arr.erase(it);
        }
    }
    sort(arr.begin(), arr.end());
    double ans = 0;
    int p = 0;
    while(D > 0 && p < N){
        if(D >= arr[p].cnt){
            D -= arr[p].cnt;
            ans += arr[p ++].total_cost;
        }else{
            ans += arr[p].total_cost / arr[p].cnt * D;
            D = 0;
        }
        //cout << ans << endl;
    }
    printf("%.2f\n", ans);
    return 0;
}
```

