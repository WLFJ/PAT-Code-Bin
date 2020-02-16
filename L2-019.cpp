#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
int main()
{
    int n,m,k,t,sum = 0;
    string s;
    scanf("%d",&n);
    map<string,int> m1,m2;
    for(int i=0;i<n;i++){
        cin>>s;
        m1[s] = 1;//标记为1表示被关注的id
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        cin>>s>>k;
        m2[s] = k;
        sum += k;//总点赞数
    }
    t = sum/m;//平均点赞数
    int flag = 0;//标记有没有悄悄关注的人
    map<string,int>::iterator it;
    for(it=m2.begin();it!=m2.end();it++){
        if(it->second>t&&m1[it->first]==0){//满足被该用户点赞次数大于其点赞平均数、且不在其关注列表上的人
          cout<<it->first<<endl;
            flag = 1;
        }
    }
    if(flag==0){
        printf("Bing Mei You\n");
    }
    return 0;
}
