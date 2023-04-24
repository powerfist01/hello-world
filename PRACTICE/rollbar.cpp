#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define rep(i,n,m) for(int i=n;i<m;i++)
#define ld long double
#define pi pair<int,int>
#define pld pair<ld,ld>
#define f first
#define s second
const double PI=acos(-1);
const int nax=1e3+10,mod=1e9+7,inf=1e18;//998244353
/*40019015
*/
string s[nax];
int n,m,d[nax][nax][3];
queue<pair<pi,int>> q;
bool inside(int x,int y)
{
	if(x<1 or x>n or y<1 or y>m or s[x][y]=='0')
		return 0;
	return 1;
}
void find(int x,int y,int st,int cost)
{
	if(d[x][y][st]!=-1)
		return;
	d[x][y][st]=cost;
	q.push({{x,y},st});
}
void rec(int x,int y,int st)
{
	int c=d[x][y][st];
	if(st==0)
	{
		if(inside(x,y-1) and inside(x,y-2))
			find(x,y-2,1,c+1);
		if(inside(x,y+1) and inside(x,y+2))
			find(x,y+1,1,c+1);
		if(inside(x-1,y) and inside(x-2,y))
			find(x-2,y,2,c+1);
		if(inside(x+1,y) and inside(x+2,y))
			find(x+1,y,2,c+1);
	}
	if(st==1)
	{
		if(inside(x-1,y) and inside(x-1,y+1))
			find(x-1,y,1,c+1);
		if(inside(x+1,y) and inside(x+1,y+1))
			find(x+1,y,1,c+1);
		if(inside(x,y+2))
			find(x,y+2,0,c+1);
		if(inside(x,y-1))
			find(x,y-1,0,c+1);
	}
	if(st==2)
	{
		if(inside(x,y-1) and inside(x+1,y-1))
			find(x,y-1,2,c+1);
		if(inside(x,y+1) and inside(x+1,y+1))
			find(x,y+1,2,c+1);
		if(inside(x+2,y))
			find(x+2,y,0,c+1);
		if(inside(x-1,y))
			find(x-1,y,0,c+1);
	}
}
void solve()
{
	memset(d,-1,sizeof(d));
	int src,dst;
	cin>>n>>m>>src>>dst;
	rep(i,1,n+1)
	{
		cin>>s[i];
		s[i]="#"+s[i];
	}
	d[src][dst][0]=0;
	q.push({{src,dst},0});
	while(!q.empty())
	{
		auto cur=q.front();
		q.pop();
		rec(cur.f.f,cur.f.s,cur.s);
	}
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		cout<<d[i][j][0]<<' ';
		cout<<endl;
	}
	//cout<<endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
	#endif
    int tt=1;
	cin>>tt;
	for(int i=1;i<=tt;i++)
	{
		//cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
