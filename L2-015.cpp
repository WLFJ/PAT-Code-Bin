#include<algorithm>
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(void){
    int N, k, M;
    cin >> N >> k >> M;
    vector<double> mem;
    for(int i = 0; i < N; i ++){
       double min = 101, max = -1, sum = 0;
       for(int j = 0; j < k; j ++){
            double s;
            cin >> s;
            min = (min > s ? s : min);
            max = (max < s ? s : max);
            sum += s;      
       }
       mem.push_back((sum - min - max) / (k - 2));
    } 
    sort(mem.rbegin(), mem.rend());
    for(int i = M - 1; i >= 0; i --){
        if(i != M - 1) cout << " ";
        printf("%.3f", mem[i]);
    }
    puts("");
    return 0;
}
