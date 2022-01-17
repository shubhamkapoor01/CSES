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

	ll n;
	cin >> n;
	vector<ll> v(n);
	map<ll, ll> mp;

	for (ll i = 0; i < n; i ++) {
		cin >> v[i];
		mp[v[i]] = i;
	}

	ll curr = 1;
	ll rounds = 1;

	while (curr < n) {
		if (mp[curr] > mp[curr + 1]) {
			rounds ++;
		}
		curr ++;
	}

	cout << rounds << endl;
	return 0;
}