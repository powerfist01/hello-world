#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define deb(x) cout << #x << " " << x << endl
#define all(x) (x).begin(),(x).end()
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#include<climits>
const int MOD = 1e9 + 7;
const ll INF = 1e12;

ll mod(ll a) {
	if (a >= 0)
		return a;
	else
		return (-1 * a);
}

void swap(ll a, ll b) {
	ll temp = a;
	a = b;
	b = temp;
}

ll power(ll a, ll b) {
	ll result = 1;
	while (b) {
		if (b % 2)
			result = (result % MOD) * (a % MOD);
		a = ((a % MOD) * (a % MOD)) % MOD;
		b = b / 2;
	}
	return result;
}
bool power_check(ll a) {
	bool ans = true;
	while (a > 1) {
		if (a % 2 == 0) {
			a = a / 2;
		}
		else {
			ans = false;
			break;
		}
	}
	return ans;
}

void solve() {
	unordered_map<string,int> mp;
	int n;
	cin >>n;
	for (int i = 0; i < 3*n; ++i)
	{
		string s;
		cin >> s;
		int v;
		cin >> v;
		mp[s] += v;
	}
	vector<int> v;
	for(auto x:mp){
		v.pb(x.second);
	}
	sort(all(v));
	for(int x:v){
		cout << x << " ";
	}
	cout << endl;
	return;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fio
	//cout << 1000000000 * 1000000000;
	int qqq;
	cin >> qqq;
	//qqq = 1;
	while (qqq--) {
		solve();
	}
	//ll ans = 1LL << 64;
	//cout << ans << endl;
	return 0;
}
