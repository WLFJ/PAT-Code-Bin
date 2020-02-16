#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
int a[N];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  scanf("%d",&a[i]);
	sort(a,a+n);
	int mid=n/2;
	int ans=0;
	for(int i=mid;i<n;i++) ans+=a[i];
	for(int i=0;i<mid;i++) ans-=a[i];
	printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d\n",n-n/2,n/2,ans);
	return 0;
}
