#include<cstdio>
#include<vector>
#include<iostream>
#include<set>
using namespace std;
const int MAXN = 500 + 10;
int mem[MAXN];//记录是否是失去的城市
int p[MAXN];
int Find(int a){
    if(p[a] == a) return a;
    else return p[a] = Find(p[a]);
}
void Union(int a, int b){
    if(mem[a] || mem[b]) return; 
    a = Find(a), b = Find(b);
    p[a] = b;
}
int Count(int n){
    set<int> cnt;
    for(int i = 0; i < n; i ++){
        if(mem[i]) continue;
        cnt.insert(Find(i)); 
    } 
    for(int i = 0; i < n; i ++) p[i] = i;
    return cnt.size();
}
int main(void){
    //我们每一次删除一个点之后就要计算一下集合数量了Orz
    int N, M;
    cin >> N >> M;
    Count(N);
    //我们要标记一下哪些节点是不能用的 在构建的时候就能方便搜索了
    //这里我们读到之后只要是被放弃的点就不连接这条边了
    vector<pair<int, int> > edges(M);
    for(int i = 0; i < M; i ++){
        cin >> edges[i].first >> edges[i].second;
        Union(edges[i].first, edges[i].second);
    }    
    int lastUnions = Count(N);
    set<int> cnt;
    int P = 0;
    cin >> P;
    for(int i = 0; i < P; i ++){
        int segCity;
        cin >> segCity;
        cnt.insert(segCity);
        mem[segCity] ++;
        for(pair<int, int> p : edges){
            Union(p.first, p.second);
        } 
        int curUnions = Count(N);
        if(curUnions <= lastUnions){
           printf("City %d is lost.\n", segCity); 
        }else{
           printf("Red Alert: City %d is lost!\n", segCity);
        }
        lastUnions = curUnions;
    }    
    if((int)cnt.size() == N) cout << "Game Over." << endl;
    return 0;
}
