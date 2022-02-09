#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


ll solve(vector<pair<ll, pair<ll, ll>>>& v, ll idx, ll prev, 
					unordered_map<ll, unordered_map<ll, ll>>& dp) {
						
	if (idx == v.size()) return 0;
	if (prev != -1 && dp[idx].find(prev) != dp[idx].end()) return dp[idx][prev];
	if (prev != -1 && v[prev].ff >= v[idx].ss.ff) return solve(v, idx + 1, prev, dp);

	ll profit = solve(v, idx + 1, prev, dp);
	if (prev == -1) prev = idx;
	if (v[idx].ff >= v[prev].ff) prev = idx;

	profit = max(profit, v[idx].ss.ss + solve(v, idx + 1, prev, dp));

	dp[idx][prev] = profit;
	return profit;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<pair<ll, pair<ll, ll>>> v(n);
	for (ll i = 0; i < n; i ++) {
		cin >> v[i].ss.ff >> v[i].ff >> v[i].ss.ss;
	}

	sort(v.begin(), v.end());
	unordered_map<ll, unordered_map<ll, ll>> dp;
	cout << solve(v, 0, -1, dp) << endl;
	return 0;
}