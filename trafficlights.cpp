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

	ll x, n;
	cin >> x >> n;
	vector<ll> v(n);
	for (ll i = 0; i < n; i ++) {
		cin >> v[i];
	}

	ll ans = max(v[0], x - v[n - 1]);
	for (ll i = 1; i < n; i ++) {
		ans = max(ans, v[i] - v[i - 1]);
	}

	
	return 0;
}