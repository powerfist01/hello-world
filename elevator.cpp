#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;
 
 
 
long long readInt(long long l,long long r,char endd){
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true){
		char g=getchar();
		if(g=='-'){
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g && g<='9'){
			x*=10;
			x+=g-'0';
			if(cnt==0){
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);
			
			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd){
			assert(cnt>0);
			if(is_neg){
				x= -x;
			}
			assert(l<=x && x<=r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l,int r,char endd){
	string ret="";
	int cnt=0;
	while(true){
		char g=getchar();
		assert(g!=-1);
		if(g==endd){
			break;
		}
		cnt++;
		ret+=g;
	}
	assert(l<=cnt && cnt<=r);
	return ret;
}
long long readIntSp(long long l,long long r){
	return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
	return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
	return readString(l,r,'\n');
}
string readStringSp(int l,int r){
	return readString(l,r,' ');
}
 
 
int T;
int n;
int sm_n=0;
int m;
int A[100100];
int dp[100100][2]; // 0 going down - 1 going up
 
int calculate(int start_y,int start_x,int end_y,int end_x,bool & going_up){
	int cur = start_y;
	int idx = start_x;
	int cost = 0;
	while(true){
		if(idx == end_x){
			break;
		}
		if(going_up && cur - end_y == end_x - idx){
			cost++;
			going_up = ! going_up;
			break;
		}
		if(!going_up && end_y - cur == end_x - idx){
			cost++;
			going_up = ! going_up;
			break;
		}
		if(going_up){
			if(cur == m){
				cost++;
				going_up =false;
				cur = m-1;
			} else {
				cur++;
			}
		} else {
			if(cur==1){
				cost ++;
				going_up =true;
				cur = 2;
			} else {
				cur--;
			}
		}
		idx++;
	}
	return cost;
}
 
int get_ans(int l,int r,bool is_forced_up,bool is_forced_down,bool is_forced_up_end,bool is_forced_down_end){
	vector<pair<int,int> > arr;
	for(int i=l;i<=r;i++){
		if(A[i] != -1)
			arr.push_back(make_pair(i-l,A[i]));
	}
	int len= r-l;
	int s = arr.size();
	for(int i=1;i<s;i++){
		if(abs(arr[i].second - arr[i-1].second) > arr[i].first - arr[i-1].first){
			return 1<<20;
		}
	}
	for(int i=0;i<s;i++){
		dp[i][0] = dp[i][1]= 1<<20;
	}
	if(!is_forced_down){
		if(arr[0].second -1 < arr[0].first){
			dp[0][1] = ( arr[0].first - arr[0].second +1 + m - 2) /(m-1);
		} else {
			dp[0][1]= 0;
		}
	}
	if(!is_forced_up){
		if(m-arr[0].second < arr[0].first){
			dp[0][0] = ( arr[0].first - (m-arr[0].second) + m - 2) /(m-1);
		} else {
			dp[0][0]= 0;
		}
	}
	for(int i=0;i<s-1;i++){
		dp[i][0] =min(dp[i][0] ,dp[i][1]+1);
		dp[i][1] =min(dp[i][1] ,dp[i][0]+1);
		bool going_up=true;
		int cst =calculate(arr[i].second,arr[i].first,arr[i+1].second,arr[i+1].first,going_up);
		if(going_up){
			dp[i+1][1] = min(dp[i+1][1], dp[i][1] + cst);
		} else {
			dp[i+1][0] = min(dp[i+1][0], dp[i][1] + cst);
		}
 
		going_up=false;
		cst =calculate(arr[i].second,arr[i].first,arr[i+1].second,arr[i+1].first,going_up);
		if(going_up){
			dp[i+1][1] = min(dp[i+1][1], dp[i][0] + cst);
		} else {
			dp[i+1][0] = min(dp[i+1][0], dp[i][0] + cst);
		}
	}
	dp[s-1][0] =min(dp[s-1][0] ,dp[s-1][1]+1);
	dp[s-1][1] =min(dp[s-1][1] ,dp[s-1][0]+1);
	if(arr[s-1].first == len){
		int ans = 1<<20;
		if(!is_forced_up_end){
			ans = min(ans,dp[s-1][0]);
		}
		if(!is_forced_down_end){
			ans = min(ans,dp[s-1][1]);
		}
		return ans;
	}
	int ans = 1<<20;
	if(len - arr[s-1].first > m- arr[s-1].second){
		ans =min(ans,dp[s-1][1]+  (len - arr[s-1].first - (m- arr[s-1].second) + (m-2))/ (m-1));
	} else {
		ans =min(ans,dp[s-1][1]);
	}
 
	if(len - arr[s-1].first > arr[s-1].second - 1){
		ans =min(ans,dp[s-1][0]+  (len - arr[s-1].first - (arr[s-1].second - 1) + (m-2))/ (m-1));
	} else {
		ans =min(ans,dp[s-1][0]);
	}
	return ans;
}
 
int main(){
	//freopen("03.txt","r",stdin);
	//freopen("03o.txt","w",stdout);
	T=readIntLn(1,1000);
	while(T--){
		bool ok=true;
		n=readIntSp(1,100000);
		m=readIntLn(2,100000);
		sm_n+=n;
		assert(sm_n<=1000000);
		
		for(int i=0;i<n;i++){
			if(i==n-1){
				A[i]=readIntLn(-1,m);
			} else {
				A[i]=readIntSp(-1,m);
			}
			assert(A[i] != 0);
		}
		int val = -1;
		for(int i=0;i<n;i++){
			if(A[i]==-1)continue;
			if(val == -1){
				val = (A[i]+i)%2;
			} else {
				if(val != (A[i]+i) %2){
					ok=false;
				}
			}
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		if(val == -1){
			cout<< (n-2)/(m-1)<<endl;
			continue;
		}
		int cur_x=-1;
		int cur_y= -1;
		for(int i=0;i<n;i++){
			if(A[i] == -1)continue;
			if(cur_x == -1){
				cur_x = i;
				cur_y = A[i];
				continue;
			}
			if(i - cur_x < abs(cur_y - A[i])){
				ok=false;
			}
		}
		if(!ok){
			cout<<-1<<endl;
			continue;
		}
 
		int ans = get_ans(0,n-1,false,false,false,false);
		if(ans >= 1<<20){
			cout<<-1<<endl;
			continue;
		} else {
			cout<<ans<<endl;
		}
	}
	assert(getchar()==-1);
}
