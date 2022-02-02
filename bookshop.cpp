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


int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, tot;
	cin >> n >> tot;
	vector<ll> price(n);
	vector<ll> pages(n);
	for (int i = 0; i < n; i ++)
		cin >> price[i];
	for (int i = 0; i < n; i ++)
		cin >> pages[i];

	vector<pair<ll, ll>> dp(tot + 1, {0, 0});

	for (ll i = 1; i <= n; i ++) {
		for (ll j = 1; j <= tot; j ++) {
			if (j - price[i - 1] >= 0) {
				dp[j].second = max(dp[j].second, (pages[i - 1] + dp[j - price[i - 1]].first % mod) % mod);
			}
		}
		for (ll j = 1; j <= tot; j ++) {
			dp[j].first = dp[j].second;
		}
	}

	cout << dp[tot].second << endl;
	return 0;
}