#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;
struct person{
    int cnt, cash, id;
    bool operator < (const person p) const {
        if(this->cash != p.cash) return this->cash > p.cash;
        else if (this->cnt != p.cnt) return this->cnt > p.cnt;
        else{
            //cout << id << endl;
            return this->id < p.id;
        }
    }
};
int main(void){
    int N;
    cin >> N;
    vector<person> arr(N + 1);
    for(int i = 1; i <= N; i ++) arr[i].id = i;
    for(int id = 1; id <= N; ++ id){
        int K;
        cin >> K;
        while(K --){
            int Ni, Pi;
            cin >> Ni >> Pi;
            arr[id].cash -= Pi;
            arr[Ni].cash += Pi;
            arr[Ni].cnt ++;
        }
    }
    sort(arr.begin() + 1, arr.end());
    for(person p : arr){
        if(p.id)
            printf("%d %.2f\n", p.id, p.cash * 1.0 / 100);
    }

    return 0;
}