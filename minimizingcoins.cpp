#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


ll solve(vector<ll>& v, ll rem, vector<ll>& dp) {
	if (rem < 0) return 1e9;
	if (rem == 0) return 0;
	if (dp[rem] != -1) return dp[rem];

	ll ans = 1e9;
	for (ll i = 0; i < v.size(); i ++) {
		ans = min(ans, 1 + solve(v, rem - v[i], dp));
	}

	dp[rem] = ans;
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, x;
	cin >> n >> x;
	vector<ll> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}

	vector<ll> dp(x + 1, -1);
	ll ans = solve(v, x, dp);
	if (ans == 1e9) {
	    cout << -1 << endl;
	} else {
	    cout << ans << endl;
	}
	return 0;
}