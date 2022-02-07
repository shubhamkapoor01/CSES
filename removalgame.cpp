#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


ll solve(vector<ll>& v, ll l, ll r, ll turn, vector<vector<ll>>& dp) {
	if (l > r) return 0;
	if (dp[l][r] != -1e18) return dp[l][r];

	if (turn) {
		ll takeLeft = solve(v, l + 1, r, !turn, dp) + v[l];
		ll takeRight = solve(v, l, r - 1, !turn, dp) + v[r];
		dp[l][r] = max(takeLeft, takeRight);

	} else {
		ll takeLeft = solve(v, l + 1, r, !turn, dp);
		ll takeRight = solve(v, l, r - 1, !turn, dp);
		dp[l][r] = min(takeLeft, takeRight);
	}

	return dp[l][r];
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> v(n);
	for (ll i = 0; i < n; i ++) {
		cin >> v[i];
	}

	vector<vector<ll>> dp(n, vector<ll> (n, -1e18));
	cout << solve(v, 0, n - 1, 1, dp) << endl;
	return 0;
}