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


ll solve(ll n, ll idx, ll sum, vector<vector<ll>>& dp) {
	if (sum == 0) {
		return 1;
	}

	if (idx == n || sum < 0) {
		return 0;
	}

	if (dp[idx][sum] != -1) {
		return dp[idx][sum];
	}

	ll ways = 0;
	ways = (ways % mod + solve(n, idx + 1, sum, dp) % mod) % mod;
	ways = (ways % mod + solve(n, idx + 1, sum - idx, dp) % mod) % mod;

	dp[idx][sum] = ways;
	return ways;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;

	if ((n * (n + 1) / 2) % 2 != 0) {
		cout << 0 << endl;
		return 0;
	}

	ll req = n * (n + 1) / 4;
	vector<vector<ll>> dp(n, vector<ll> (req + 1, -1));
	cout << solve(n, 1, req, dp) << endl;
	return 0;
}