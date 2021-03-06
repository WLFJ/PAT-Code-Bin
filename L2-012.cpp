#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> heap;
void make_heap(int num){
    heap.push_back(num);
    //现在开始调整
    int pos = heap.size() - 1;
    while(pos != 1){
        if(heap[pos >> 1] > heap[pos]){
            swap(heap[pos >> 1], heap[pos]);
            pos >>=  1;
        }else{
            break;
        }
    } 
}
int get_pos(int num){
    return find(heap.begin(), heap.end(), num) - heap.begin();
}
void out(bool exp){
    cout << (exp ? "T" : "F") << endl;
}
int main(void){
    //现在的关键是我们要知道怎样创建堆？核心思想是从下向上比较！
    heap.push_back(-10005);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i ++){
        int num;
        cin >> num;
        make_heap(num);
    }
    //我们输出一下结果
    while(M --){
        int x;
        string word1;
        cin >> x >> word1;
        if(word1 == "and"){
            //兄弟节点
            int y;
            cin >> y;
            //现在要查找两个数字的位置关系，之后判断下标
            int x_pos = get_pos(x), y_pos = get_pos(y);
            //注意这个地方！在判断兄弟节点的时候要看是不是同一个父亲！
            out((x_pos >> 1) == (y_pos >> 1));
            cin >> word1 >> word1;
        }else{
            cin >> word1;
            if(word1 == "a"){
                //x是y的儿子
                cin >> word1 >> word1;
                int y;
                cin >> y;
                int x_pos = get_pos(x), y_pos = get_pos(y);
                out((x_pos >> 1) == y_pos);
            }else{
                //根
                cin >> word1;
                if(word1 == "root"){
                    int x_pos = get_pos(x);
                    out(x_pos == 1);
                }else{
                    //x是y的父亲
                    cin >> word1;
                    int y;
                    cin >> y;
                    int x_pos = get_pos(x), y_pos = get_pos(y);
                    out((y_pos >> 1) == x_pos);
                }
            }
        }            
    }
}
