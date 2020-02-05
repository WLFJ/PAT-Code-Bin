#include<iostream>
#include<string>
using namespace std;
const int MAXN = 1000 + 10;
int zerr[MAXN][MAXN];
int p[MAXN];
string ans[] = {"OK", "No way", "No problem", "OK but..."};
int Find(int a){
    if(p[a] == a) return a;
    else return p[a] = Find(p[a]);
}
void Union(int a, int b){
    a = Find(a), b = Find(b);
    p[a] = b;
}
bool check(int a, int b){
    return Find(a) == Find(b);
}
int main(void){
    for(int i = 0; i < MAXN; i ++){
        p[i] = i;
    }
    int N, M, K;
    cin >> N >> M >> K;
    while(M --){
        int a, b, c;
        cin >> a >> b >> c;
        if(~c) Union(a, b);
        else zerr[a][b] = zerr[b][a] = 1;
    }
    while(K --){
        int a, b;
        cin >> a >> b;
        int status = (check(a, b) << 1) + (zerr[a][b]);
        cout << ans[status] << endl;
    }

    return 0;
}