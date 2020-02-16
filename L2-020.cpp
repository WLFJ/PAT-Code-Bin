#include<iostream>
#include<queue>
#define int long long
using namespace std;
const int MAXN = 100000 + 10;
int spe[MAXN];
int Head[MAXN], Tail[MAXN], Next[MAXN];
int mem[MAXN];
int tot = 0;
void addedge(int a, int b){
    if(a <= 0 || b <= 0) return;
    Tail[++tot] = b, Next[tot] = Head[a], Head[a] = tot; 
}
using pid = pair<int, double>;
signed main(void){
    int N;
    double z, r;
    cin >> N >> z >> r;
    //现在我们读入的首先是边 所以现在我们要先建图 之后再看特殊点的标记 
    for(int i = 0; i < N; i ++){
        int k;
        cin >> k;
        if(k){
            //现在我们要加边了
            for(int j = 0; j < k; j ++){
                int p;
                cin >> p;
                addedge(i + 1, p + 1);
            }
        }else{
            cin >> spe[i];
            mem[i] ++;
        }
    }
    queue<pid> bfs;
    bfs.push(make_pair(0, z)); 
    double ans = 0;
    while(!bfs.empty()){
        pid cur = bfs.front();
        bfs.pop();
        //现在我们要更新所有子代的功力值
        for(int i = Head[cur.first + 1]; i; i = Next[i]){
            int nextP = Tail[i] - 1;
            if(mem[nextP]){
               //bfs.push(make_pair(nextP,  cur.second * (100 - r) / 100* spe[nextP]));
               ans += cur.second * (100 - r) / 100* spe[nextP];
            }else{
               bfs.push(make_pair(nextP, cur.second * (100 - r) / 100));
            }
        }
    }
    cout << (int)ans << endl;
    return 0;
}
