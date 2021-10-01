#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define endl "\n"

ll solve(ll i, ll j) {
	if (i == j) {
		return i * j - (j - 1);
	} else if (i > j) {
		ll t = i * i - (i - 1);
		if (i % 2 == 0) {
			return t + (i - j);
		} else {
			return t - (i - j);
		}
	} else {
		ll t = j * j - (j - 1);
		if (j % 2 == 0) {
			return t - (j - i);
		} else {
			return t + (j - i);
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll q;
	cin >> q;
	while (q --) {
		ll i, j;
		cin >> i >> j;
		cout << solve(i, j) << endl;
	}
	return 0;
}