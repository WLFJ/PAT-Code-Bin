#incldue<iostream>
using namespace std;
const int MAXN = 100 + 10;
int parent[2][MAXN];
int Find(int k, int a){
    if(parend[k + 1][a] == a) return a;
    else return parent[k + 1][a] = Find(parent[k + 1][a]);
}
int Union(int a, int b, int k){
    a = Find(k, a), b = Find(k, b);
    parent[k + 1][a] = b;
}
int main(void){
    /*
    我们可以使用两个并差集维护其关系
    */
    for(int k = 0; k <= 1; k ++){
        for(int i = 0; i < MAXN; i ++){
            parent[k][i] = i;
        }
    }
    int N, M, K;
    cin >> N >> M >> K;


    return 0;
}