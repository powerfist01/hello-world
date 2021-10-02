// Author : Harsh Modi
// Question Link : https://cses.fi/problemset/task/1140/

#include <iostream>
#include <limits.h>
#include <cstdint>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <cstring>
#include <deque>
#include <stack>
#include <queue>
#include <utility> 
#include <iomanip>      // std::setprecision
#include <sstream>      // std::stringstream
using namespace std;
typedef long long l1;
typedef long long unsigned lu1;
typedef long double ld;
#define FIO std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI acos(-1.0)
#define pb push_back
#define deb(x) cout << #x << ": " << x << "\n"
#define PrintArray(arr) for(int i=0;i<(int)arr.size();i++)cout<<arr[i]<<" ";cout<<"\n";
#define pii pair<int,int>
#define pll pair<long long int , long long int>
#define puu pair<long long unsigned , long long unsigned>
#define int long long
const int MOD = 1e9+7;
 
// custom comparator to sort intervals based on their ending times.
bool cmp(vector<int>& v1, vector<int>& v2)
{
    return v1[1] < v2[1];
}
 
int bs(vector<vector<int> >& v, int start)
{
    // last index such that v[indx][1] (ending time) < start time of the ith project
    int low = 0, high = v.size()-1, ans = -1, mid;
    while(low<=high)
    {
        mid = (low+high)>>1;
        if(v[mid][1] < start)
        {
            ans = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        
    }
    return ans;
}
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    FIO;
    int t;
    t = 1;
    // cin>>t; 
    for (int tc=0;tc<t;tc++) 
    { 
        // n is number of projects
        int n;
        cin>>n;

        // start, end and amount are arrays denoting starting time, ending time and reward amount of corresponding to ith project.
        // dp[i] = max. amount that can be earned from first i+1 projects (i.e. projects from index = 0 to index = i).
        vector<int> start(n), end(n), amount(n), dp(n);
        for(int i1=0;i1<n;i1++)
        {
            cin>>start[i1]>>end[i1]>>amount[i1];
        }

        vector<vector<int> > v;
        for(int i=0;i<n;i++) v.push_back({start[i], end[i], amount[i]});
 
        // sort the array using custom comparator based on their end times
        sort(v.begin(), v.end(), cmp);
        
        dp[0] = v[0][2];
        for(int i=1;i<n;i++)
        {
            // for adding each new project we have two 3 choices:
            // 1) Just take the ith project
            // 2) Don't take ith project and carry on
            // 3) Take ith project such that it doesn't violate the condition that we can only do one project a day.
            // We try to maximize amount earned in each iteration.

            // 1st choice
            dp[i] = v[i][2];

            // 2nd choice
            dp[i] = max(dp[i], dp[i-1]);
            
            // 3rd choice
            // If we want to take the ith project, we must find a jth project such that end[j] < start[i] using binary search
            // Also j need to be as large as possible as we want to maximize our reward amount.
            int indx = bs(v,v[i][0]);
            if(indx != -1) dp[i] = max(dp[i], v[i][2] + dp[indx]);
        }
        cout<<dp[n-1]<<"\n";
    }
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}

// Time complexity: O(Nlog(N)) where N = number of total projects. We are traversing all N projects and in each iteration we call 
// our binary search function which has O(log(N)) time complexity.

// Space complexity: O(N) because of dp array and vector of vectors v.