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

	ll tc;
	cin >> tc;
	while (tc --) {

		ll x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

		ll val = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);
		if (val == 0) cout << "TOUCH" << endl;
		if (val > 0) cout << "RIGHT" << endl;
		if (val < 0) cout << "LEFT" << endl;
	}
	return 0;
}