#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


ll solve(vector<ll>& v, ll limit, ll idx, ll prev, vector<vector<ll>>& dp) {
	if (idx == v.size()) {
		for (ll i = 1; i < v.size(); i ++) {
			if (abs(v[i] - v[i - 1]) > 1) {
				return 0;
			}
		}
		return 1;
	}

	if (v[idx] != 0) return solve(v, limit, idx + 1, v[idx], dp);
	if (dp[idx][prev] != -1) return dp[idx][prev];

	if (idx == 0) {
		ll tot = 0;
		for (ll i = 1; i <= limit; i ++) {
			tot += solve(v, limit, idx + 1, i, dp);
		}
		dp[idx][prev] = tot;
		return tot;
	}

	ll tot = 0;
	if (prev - 1 >= 1) {
		v[idx] = prev - 1;
		tot += solve(v, limit, idx + 1, v[idx], dp);
	}

	v[idx] = prev;
	tot += solve(v, limit, idx + 1, v[idx], dp);

	if (prev + 1 <= limit) {
		v[idx] = prev + 1;
 		tot += solve(v, limit, idx + 1, v[idx], dp);
	}

	dp[idx][prev] = tot;
	return tot;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m;
	cin >> n >> m;
	vector<ll> v(n);
	for (ll i = 0; i < n; i ++) {
		cin >> v[i];
	}

	vector<vector<ll>> dp(n, vector<ll> (101, -1));
	cout << solve(v, m, 0, -1, dp) +  << endl;
	return 0;
}