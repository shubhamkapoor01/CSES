#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


int main () {
	ll n, x;
	cin >> n >> x;
	vector<ll> v(n);
	for (ll i = 0; i < n; i ++) {
		cin >> v[i];
	}
	
	vector<ll> dp(x + 1, 0);
	dp[0] = 1;

	for (ll i = 1; i <= n; i ++) {
		for (ll j = 1; j <= x; j ++) {
			if (j - v[i - 1] >= 0) {
				dp[j] = (dp[j] % mod + dp[j - v[i - 1]] % mod) % mod;
			}
		}
	}

	cout << dp[x] << endl;
	return 0;
}