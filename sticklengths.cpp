#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


bool possible(vector<ll> v, ll m) {
	ll n = v.size();
	ll req = 0;

	if (n % 2 == 0) {
		ll m1 = v[n / 2 - 1];
		ll m2 = v[n / 2];
		ll t1 = 0;
		ll t2 = 0;

		for (ll i = 0; i < n; i ++) {
			t1 += abs(m1 - v[i]);
			t2 += abs(m2 - v[i]);
		}
		req = min(t1, t2);

	} else {
		ll median = v[n / 2];
		for (ll i = 0; i < n; i ++) {
			req += abs(median - v[i]);
		}
	}

	return req <= m;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> v(n);
	for (ll i = 0; i < n; i ++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	ll l = 0;
	ll r = v[n - 1] * n;
	ll ans = -1;

	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (possible(v, m)) {
			ans = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	cout << ans << endl;
	return 0;
}