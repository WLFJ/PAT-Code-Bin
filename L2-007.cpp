#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN = 10005;
int parent[MAXN];
int Find(int a){
    if(parent[a] == a) return a;
    else return parent[a] = Find(parent[a]);
}
struct house{
    int cnt;
    int s;
    int people;
    int id;
    house():cnt(0), s(0), people(1), id(0){};
    house(int cnt, int s, int people, int id):cnt(cnt), s(s), people(people), id(id){};
    house(const house& h1, const house& h2){
        this->cnt = h1.cnt + h2.cnt;
        this->s = h1.s + h2.s;
        this->people = h1.people + h2.people;
    };
    bool operator< (const house& h) const{
        if( s * 1.0 / people != h.s * 1.0 / h.people ){
            return s * 1.0 / people > h.s * 1.0 / h.people;
        }else return id < h.id;
    }
};
void Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}
int main(void){
    for(int i = 0; i <= 10000; i ++) parent[i] = i;
    int N;
    cin >> N;
    vector<house> arr(10000);
    for(int i = 0; i < N; i ++){
        int id, f, m, k;
        cin >> id >> f >> m >> k;
        if(~f) Union(id, f);
        if(~m) Union(id, m);
        while(k --){
            int c;
            cin >> c;
            Union(id, c);
        }
        int cnt, s;
        cin >> cnt >> s;
        arr[id] = house(cnt, s, 1, id);
    }
    //我们现将所有信息保存在当前人名下，之后再遍历
    map<int, vector<int> > group;
    for(int i = 0; i <= 9999; i ++){
        if(Find(i) != i){
            group[Find(i)].push_back(i);
        }else if(arr[i].cnt){
            group[Find(i)] = vector<int>();
        }
    }
    vector<house> ans;
    for(auto it = group.begin(); it != group.end(); it ++){
        int admin = it->first;
        //现在我们知道都是同一个组的了 并且管理员的id一定是最小的
        vector<int> sub_group = group[admin];
        house h = arr[admin];
        //cout << admin << "---" << endl;
        for(int i = 0; i < sub_group.size(); i ++){
            h = house(h, arr[ sub_group[i] ]);
            //cout << sub_group[i] << endl;
        }
        //cout << "---" << endl;
        h.id = admin;
        ans.push_back(h);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i ++){
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].cnt * 1.0 / ans[i].people, ans[i].s * 1.0 / ans[i].people);
    }


    return 0;
}