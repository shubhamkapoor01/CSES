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

	ll n, x;
	cin >> n >> x;
	map<ll, ll> mp;
	
	for (ll i = 0; i < n; i ++) {
		ll input;
		cin >> input;

		if (mp.find(x - input) != mp.end()) {
			cout << mp[x - input] + 1 << " " << i + 1 << endl;
			return 0;
		}

		mp[input] = i;
	}

	cout << "IMPOSSIBLE" << endl;
	return 0;
}