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


ll solve(ll n, vector<ll>& dp) {
	if (n < 0) return 0;
	if (n == 0) return 1;
	if (dp[n] != -1) return dp[n];
	
	ll combinations = 0;
	for (ll i = 1; i <= 6; i ++) {
		combinations = (combinations % mod + solve(n - i, dp) % mod) % mod;
	}

	dp[n] = combinations;
	return dp[n];
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> dp(n + 1, -1);
	cout << solve(n, dp) << endl;
	return 0;
}