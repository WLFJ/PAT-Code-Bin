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