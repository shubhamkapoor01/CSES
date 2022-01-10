#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


void solve(vector<ll> v, ll i, ll s1, ll s2, ll &ans) {
	if (i == v.size()) {
		ans = min(ans, abs(s1 - s2));
		return;
	}

	solve(v, i + 1, s1 + v[i], s2, ans);
	solve(v, i + 1, s1, s2 + v[i], ans);
	return;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> v(n);
	for (ll i = 0; i < n; i ++) 
		cin >> v[i];

	ll ans = INT_MAX;
	solve(v, 0, 0, 0, ans);
	cout << ans << endl;
	return 0;
}