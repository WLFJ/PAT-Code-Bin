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