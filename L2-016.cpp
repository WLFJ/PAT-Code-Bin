#include<set>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int MAXN = 100000 + 10;
char mem_sex[MAXN];
int Head[MAXN], Tail[MAXN], Next[MAXN];
int tot = 0;
void addedge(int a, int b){
    if(a <= 0 || b <= 0) return;
    Tail[++tot] = b, Next[tot] = Head[a], Head[a] = tot;
}
int main(void){
    int N;
    cin >> N;
    for(int i = 0; i < N; i ++){
        int id, ida, idb;
        char sex;
        cin >> id >> sex >> ida >> idb;
        id ++, ida ++, idb ++;
        addedge(id, ida);
        addedge(id, idb);
        mem_sex[id] = sex; 
        mem_sex[ida] = 'M';
        mem_sex[idb] = 'F';
    }
    int K;
    cin >> K;
    while(K --){
        int ida, idb;
        cin >> ida >> idb;
        ida ++, idb ++;
        if(mem_sex[ida] == mem_sex[idb]){
            cout << "Never Mind" << endl;
        }else{
            //下面开始搜索
            bool isOK = true;
            queue<int> bfs;
            set<int> mem;
            bfs.push(ida);bfs.push(idb);
            bfs.push(-1);
            int cnt = 0;
            while(cnt < 5 && !bfs.empty()){
                int curP = bfs.front();
                bfs.pop();
                if(curP == -1){
                    cnt ++;
                    bfs.push(-1);
                }else{
                    //现在我们拿到了一个人 要检查其是否冲突！
                    if(mem.count(curP)){
                        isOK = false;
                        break;
                    }else{
                        mem.insert(curP);
                        //在这里将相关联的人添加进去
                        for(int i = Head[curP]; i; i = Next[i]){
                           bfs.push(Tail[i]); 
                        }
                    }
                }
            }
            cout << (isOK ? "Yes" : "No") << endl;
        }
    }

    return 0;
}
