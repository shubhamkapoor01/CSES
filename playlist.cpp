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

	map<ll, ll> m;
	ll ans = 0;
	ll we = 0;
	ll ws = 0;

	while (we < n) {
		m[v[we]] ++;

		while (m[v[we]] > 1) {
			m[v[ws]] --;
			ws ++;
		}

		ans = max(ans, we - ws + 1);
		we ++;
	}

	cout << ans << endl;
	return 0;
}