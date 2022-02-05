#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


ll solve(ll x, ll y, vector<vector<ll>>& dp) {
	if (x == y) return 0;
	if (dp[x][y] != -1) return dp[x][y];

	ll ans = 1e9;
	
	for (ll i = 1; i < x; i ++) {
		ans = min(ans, 1 + solve(i, y, dp) + solve(x - i, y, dp));
	}
	for (ll i = 1; i < y; i ++) {
		ans = min(ans, 1 + solve(x, i, dp) + solve(x, y - i, dp));
	}

	dp[x][y] = ans;
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll a, b;
	cin >> a >> b;

	vector<vector<ll>> dp(a + 1, vector<ll> (b + 1, -1));
	cout << solve(a, b, dp);
	return 0;
}