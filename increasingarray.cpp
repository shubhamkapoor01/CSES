#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> v(n);
	for (ll i = 0; i < n; i ++)
		cin >> v[i];

	ll ans = 0;
	for (ll i = 1; i < n; i ++) {
		if (v[i - 1] > v[i]) {
			ll t = v[i - 1] - v[i];
			v[i] += t;
			ans += t;
		}
	}
	cout << ans;
	return 0;
}