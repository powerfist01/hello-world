#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
	ll s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+ch-'0',ch=getchar();
	return s*f;
}
int n;
ll a,b,c,d,x,p,q,s,r,t,m,ans;
inline bool check(ll y){
	__int128 lcnt=max(0ll,y+b-a)/b,rcnt=max(0ll,y+d-c)/d;
	return lcnt*(a-b)+(lcnt*(lcnt+1)/2)*b+rcnt*(c-d)+(rcnt*(rcnt+1)/2)*d<=(__int128)x;
}
inline ll calc(ll y){
	__int128 lcnt=max(0ll,y+b-a)/b,rcnt=max(0ll,y+d-c)/d;ll ret=lcnt+rcnt;
	__int128 cost=lcnt*(a-b)+(lcnt*(lcnt+1)/2)*b+rcnt*(c-d)+(rcnt*(rcnt+1)/2)*d;
	if(cost+a+lcnt*b<=x)++ret;
	return ret;
}
int main(){
	n=read();
	x=read();a=read();b=read();c=read();d=read();
	p=read();q=read();r=read();s=read();t=read();m=read();
	for(int i=1;i<=n;++i){
		if(i>1){
			a=(a+ans*t)%m+p;
			b=(b+ans*t)%m+q;
			c=(c+ans*t)%m+r;
			d=(d+ans*t)%m+s;
		}
		ll l=1,r=x,ret,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid))ret=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%lld\n",ans=calc(ret));
	}
}
