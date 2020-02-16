#include<set>
#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    //这里我们我们知道使用lower_bound，但是在就在数列的有序性，事实上没有那个必要，使用set轻轻松松解决～
    set<int> mem;
    for(int i = 0; i < n; i ++){
        int num;
        cin >> num;
        auto p = mem.lower_bound(num);
        if(p == mem.end()) mem.insert(num);
        else{
            mem.erase(p);
            mem.insert(num);
        }
    }
    cout << mem.size() << endl;
    return 0;
}
