#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a;
	string b;
	cin >> a;
	cin >> b;

	ll n = a.size();
	ll m = b.size();

	vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, 0));

	for (ll i = 0; i <= n; i ++) {
		dp[i][0] = i;
	}

	for (ll i = 0; i <= m; i ++) {
		dp[0][i] = i;
	}

	for (ll i = 1; i <= n; i ++) {
		for (ll j = 1; j <= m; j ++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
			}
		}
	}

	cout << dp[n][m];
	return 0;
}