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


ll solve(vector<vector<char>>& v, ll i, ll j, vector<vector<ll>>& dp) {
	if (i < 0 || j < 0 || i == v.size() || j == v[0].size() || v[i][j] == '*') return 0;
	if (i == v.size() - 1 && j == v[0].size() - 1) return 1;
	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = (solve(v, i + 1, j, dp) % mod + solve(v, i, j + 1, dp) % mod) % mod;
	return dp[i][j];
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<vector<char>> v(n, vector<char> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	vector<vector<ll>> dp(n, vector<ll> (n, -1));
	cout << solve(v, 0, 0, dp) << endl;
	return 0;
}