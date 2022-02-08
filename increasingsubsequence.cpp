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
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}

	vector<ll> lis;
	for (int i = 0; i < n; i ++) {
		if (!lis.size() || lis.back() < v[i]) {
			lis.pb(v[i]);
		} else {
			ll pos = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
			if (v[pos] != v[i]) {
				lis[pos] = v[i];
			}
		}
	}

	cout << lis.size() << endl;
	return 0;
}