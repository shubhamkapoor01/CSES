#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define endl "\n"


bool compare(pair<ll, ll> x, pair<ll, ll> y) {
	if (x.ss < y.ss)
		return true;
	if (y.ss < x.ss)
		return false;
	return x.ff < y.ff;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<pair<ll, ll>> v(n);
	for (ll i = 0; i < n; i ++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), compare);

	ll count = 1;
	pair<ll, ll> curr = v[0];
	
	for (ll i = 1; i < n; i ++) {
		if (curr.ss <= v[i].ff) {
			curr.ss = max(curr.ss, v[i].ss);
			count ++;
		}
	}

	cout << count << endl;
	return 0;
}