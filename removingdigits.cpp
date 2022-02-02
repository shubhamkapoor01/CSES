#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


ll solve(ll n, vector<ll>& dp) {
	if (n == 0) return 0;
	if (dp[n] != -1) return dp[n];

	ll ans = 1e9;
	ll temp = n;

	while (temp) {
		ll digit = temp % 10;
		temp /= 10;
		if (digit > 0) {
			ans = min(ans, 1 + solve(n - digit, dp));
		}
	}

	dp[n] = ans;
	return ans;
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