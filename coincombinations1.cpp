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


ll solve(vector<ll>& v, ll rem, vector<ll>& dp) {
	if (rem < 0) return 0;
	if (rem == 0) return 1;
	if (dp[rem] != -1) return dp[rem];

	ll ans = 0;
	for (ll i = 0; i < v.size(); i ++) {
		ans = (ans % mod + solve(v, rem - v[i], dp) % mod) % mod;
	}

	dp[rem] = ans;
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, x;
	cin >> n >> x;
	vector<ll> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}

	vector<ll> dp(x + 1, -1);
	cout << solve(v, x, dp) % mod << endl;
	return 0;
}