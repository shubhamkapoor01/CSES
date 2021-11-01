#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"

ll ans = 0;
bool col[0], d1[16], d2[16];

void solve(vector<vector<char>> v, ll r) {
	if (r == 8) {
		ans ++;
		return;
	}

	ll ans = 0;

	for (ll i = 0; i < 8; i ++) {
		if (v[r][i] == '.' && !col[i] && !d1[r - i + 7] && !d2[r + i]) {
			col[i] = true;
			d2[r + i] = true;
			d1[r - i + 7] = true;
			solve(v, r + 1);
			d1[r - i + 7] = false;
			d2[r + i] = false;
			col[i] = false;
		}
	}

	return;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<char>> v(8, vector<char> (8, '.'));
	for (ll i = 0; i < 8; i ++) {
		for (ll j = 0; j < 8; j ++) {
			cin >> v[i][j];
		}
	}

  solve(v, 0);
	cout << ans << endl;
	return 0;
}