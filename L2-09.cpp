#include<algorithm>
#include<set>
#include<iostream>
#include<vector>
using namespace std;
bool is_prime(int num){
    //素数是除了1和自己 没有其他数字能够整除的
    for(int i = 2; i * i <= num; i ++){
        if(num % i == 0) return false;
    }
    return true;
}
//注意不要将vector开在程序中！
int main(void){
    int a, b;
    cin >> a >> b;
    //之后我们要遍历结算每一个值    
    vector<int> mem(100010, -1);
    vector<int> ccnt(100010);
    for(int i = a; i <= b; i ++){
        vector<int> link;
        int num = i;
       while(num != 1){
        int sum = 0;
        int t = num;
        while(t){
            sum += (t % 10) * (t % 10);
            t /= 10;
        }
        //现在要看成环了没有
        if(find(link.begin(), link.end(), sum) != link.end()) break;
        link.push_back(sum);
        num = sum;
        if(num == 1){
            ccnt[i] = link.size();
            if(is_prime(i)) ccnt[i] <<= 1;
            //现在我们处理一下指向问题
            auto p = link.begin();
            while(p != link.end()){
                if(p == link.begin()){
                    mem[i] = *p;
                }else{
                    mem[*(p - 1)] = *p;
                }
                p ++;
            }
         }

       } 
    }
    //之后我们要检查一下没有被指向并且在区间内的数字'
    vector<int> v(100010, -1);
    for(int i = 1; i < 100001; i ++){
        v[mem[i]] = 1;
    } 
    int tag = 0;
    for(int i = a; i <= b; i ++){
        if(v[i] == -1&&mem[i] != -1){
            //现在得到的就是答案
            tag ++;
            cout << i << " " << ccnt[i] << endl;
        }
    } 
    if(tag == 0) cout << "SAD" << endl;

    return 0;
}
