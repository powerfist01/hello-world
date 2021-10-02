#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 2e18;

int n, k, m;
vector<int> vals;

struct item {
	int x, y, v;
	bool operator < (item& other) const {
		return y < other.y;
	}
} ar[100005];

int tree[800005];
int lazy[800005];

void change(int v, int id) {
	tree[id] += v;
	lazy[id] += v;
}

void push(int id) {
	change(lazy[id], id * 2);
	change(lazy[id], id * 2 + 1);
	lazy[id] = 0;
}

void update(int l, int r, int v, int id, int tl, int tr) {
	if (r < tl || tr < l) {
		return;
	}
	if (l <= tl && tr <= r) {
		change(v, id);
		return;
	}
	push(id);
	int tm = (tl + tr) / 2;
	update(l, r, v, id * 2, tl, tm);
	update(l, r, v, id * 2 + 1, tm + 1, tr);
	tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

void update(int l, int r, int v) {
	update(l, r, v, 1, 0, m);
}

signed main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i].x >> ar[i].y >> ar[i].v;
		vals.push_back(ar[i].x);
		vals.push_back(ar[i].y);
	}
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	m = vals.size();
	sort(ar + 1, ar + n + 1);
	for (int i = 0; i <= 800004; i++) {
		tree[i] = -INF;
	}
	int ans = 0;
	int cur = 0;
	for (int r = 0; r < m; r++) {
		update(r, r, INF + k * vals[r]);
		while (cur + 1 <= n && ar[cur + 1].y <= vals[r]) {
			cur++;
			if (ar[cur].v > 0) {
				int id = lower_bound(vals.begin(), vals.end(), ar[cur].x) - vals.begin();
				update(0, id, ar[cur].v);
			}
		}
		ans = max(ans, tree[1] - k * vals[r]);
	}
	cout << ans << '\n';
	return 0;
}
