#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


ll solve(ld a, ld b) {
	if (max(a, b) > 2 * min(a, b)) {
		return false;
	}
	ld x = (ld)((2 * b - a) / 3);
	ld y = (ld)((2 * a - b) / 3);
	if ((ld)(y) == (ll)(y) && (ld)(x) == (ll)(x)) {
		return true;
	}
	return false;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll q;
	cin >> q;
	while (q --) {
		ll a, b;
		cin >> a >> b;
		if (solve(a, b)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}