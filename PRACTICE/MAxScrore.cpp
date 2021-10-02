#include <bits/stdc++.h>
using namespace std;

vector< map<long long,long long> > D(1000+2);
long long dp[1000+2][10000+2][2];

int main() {
	int T, N,K;
	cin >> T;
	long long x, y;
	while(T--){
	    cin >> N >> K;
	    for(int i = 1 ;  i <= N ; i++){
	        cin >> x >> y;
	        D[i][0] = x;
	        D[i][1] = y;
	    }
	    
	    
	    for(int i = 0 ; i <= N ; i++){
	        for(int j = 0 ; j <= K ; j++){
	            dp[i][j][0] = dp[i][j][1] = -1e18;
	        }
	    }
	    
	    for(int i = 0; i <=K ; i++){
	        dp[0][i][0] = 0;
	    }
	    
	    for(int i = 1 ; i <= N ; i++){
	        for(int j = 0 ; j <= K ; j++){
	            dp[i][j][0] = dp[i-1][j][0];
	            if(j >= D[i][1]){
	                dp[i][j][0] = max(dp[i][j][0] , dp[i-1][j-D[i][1]][0] + D[i][0]);
	            }
	            dp[i][j][1] = dp[i-1][j][1];
	            if(j >= D[i][1]){
	                dp[i][j][1] = max(dp[i][j][1] , dp[i-1][j-D[i][1]][0]);
	                dp[i][j][1] = max(dp[i][j][1] , dp[i-1][j-D[i][1]][1] + D[i][0]);
	            }
	        }
	    }
	    
	    long long ans=0;
	    for(int i = 1 ; i <= K ; i++){
	        ans = max(ans, dp[N][i][1]);
	    }
	    cout << ans << endl;
	    
	}
	return 0;
}
