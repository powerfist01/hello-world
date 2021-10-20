#include <bits/stdc++.h>
#define INF 1000 * 1000 * 1000
using namespace std;
int t, n, l[55], b[55], v[55], c[55];
double get(double t){double ans = 0;for(int i = 0; i < n; i++){double wher = c[i] - (v[i] * t + b[i]);
    ans += wher * wher;} return sqrt(ans) / t;}
int main(){ios_base::sync_with_stdio(0); cin >> t;
	while (t--){cin >> n; for(int i = 0; i < n; i++){cin >> l[i];} for(int i = 0; i < n; i++){cin >> b[i];}
		for(int i = 0; i < n; i++){cin >> v[i];} for(int i = 0; i < n; i++){cin >> c[i];} double R = INF;
		for(int i = 0; i < n; i++){if (v[i] > 0){R = min(R ,  (l[i] - b[i]) / (1.0 * v[i]));}
		    else{if (v[i] < 0){R = min(R , -b[i] / (1.0 * v[i]));}}
		}double ans = get(R);double chisel = 0;double znam = 0;
		for(int i = 0; i < n; i++){chisel += (b[i] - c[i]) * (b[i] - c[i]);znam += v[i] * (c[i] - b[i]);}
		if (chisel / znam >= 0 && chisel / znam <= R){ans = min(ans , get(chisel / znam));}
		if (chisel < 1e-5){ans = 0;}cout << fixed << setprecision(10) << ans << endl;}}
