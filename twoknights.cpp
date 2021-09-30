#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define endl "\n"

ll solve(ll n, vector<ll> &dp) {
	if (n < 2) {
		dp[n] = 0;
		return dp[n];
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> dp(n + 1, -1);
	ll ans = solve(n, dp);
	for (ll i = 0; i <= n; i ++)
		cout << dp[i] << endl;
	return 0;
}