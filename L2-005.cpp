#include<iostream>
#include<set>
#include<vector>
#include<cstdio>
using namespace std;
int main(void){
    //我们要动态计算两个集合的交集个并集
    //事实上只需要计算并集就全知道了
    int N;
    scanf("%d", &N);
    vector<set<int> > arr(N + 1);
    for(int i = 1; i <= N; i ++){
        int L;
        scanf("%d", &L);
        while(L --){
            int num;
            scanf("%d", &num);
            arr[i].insert(num);
        }
    }
    int K;
    scanf("%d", &K);
    while(K --){
        int a, b;
        scanf("%d%d", &a, &b);
        set<int> s_a = arr[a];
        int size_a = s_a.size(), size_b = arr[b].size();
        int same = 0;//注意我们要学习stl！
        for(int num : arr[b]){
            if(s_a.count(num)) same ++;
        }
        printf("%.2f%%\n", 100.0 * same / (size_a + size_b - same));
    }


    return 0;
}