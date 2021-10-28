#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


ll solve(ll n, vector<ll> &dp) {
	// TODO try dp 
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