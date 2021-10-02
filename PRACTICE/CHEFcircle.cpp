#include<iostream>
using namespace std;
#include<string.h>
#include <sstream>
typedef long long int ll;
typedef long double ld;

int main() {
	ll t;
	cin >> t;

	while (t--) {

		ll n;
		cin >> n;

		ll a[n];
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}

		ll start, end;
		cin >> start >> end;

		start--;
		end--;

		ll p1 = 0, s1 = 0;
		ll sum = 0;
		for (ll i = start; i < end; i++) {
			p1 += a[i];
			sum += a[i];

			if (sum < 0) {
				sum = 0;
			}
			if (sum > s1) {
				s1 = sum;
			}
		}

		ll p2 = 0, s2 = 0;
		sum = 0;

		for (ll i = start - 1; i >= 0; i--) {

			p2 += a[i];
			sum += a[i];

			if (sum < 0) {
				sum = 0;
			}
			if (sum > s2) {
				s2 = sum;
			}
		}

		for (ll i = n - 1; i >= end; i--) {
			p2 += a[i];
			sum += a[i];

			if (sum < 0) {
				sum = 0;
			}
			if (sum > s2) {
				s2 = sum;
			}
		}

//		cout << p1 << " " << p2 << endl;
//		cout << s1 << " " << s2 << endl;

		ll aa = p1 + (p2 - s2) * 2;
		ll bb = p2 + (p1 - s1) * 2;
		cout << min(aa, bb) << endl;
	}
}
