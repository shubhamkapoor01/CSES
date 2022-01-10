#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"

void solve(vector<vector<char>> v, ll r, ll &ans, 
						vector<bool> vr, vector<bool> vc, 
							vector<bool> vd1, vector<bool> vd2) {

	if (r == 8) {
		ans ++;
		return;
	}
	
	for (int i = 0; i < 8; i ++) {
		if (v[r][i] == '.' && !vr[r] && !vc[i] && !vd1[i + r] && !vd2[7 + i - r]) {
			v[r][i] = 'q';
			vr[r] = true;
			vc[i] = true;
			vd1[i + r] = true;
			vd2[7 + i - r] = true;

			solve(v, r + 1, ans, vr, vc, vd1, vd2);

			vd2[7 + i - r] = false;
			vd1[i + r] = false;
			vc[i] = false;
			vr[r] = false;
			v[r][i] = '.';
		}
	}
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

	vector<bool> vr(8, false);
	vector<bool> vc(8, false);
	vector<bool> vd1(15, false);
	vector<bool> vd2(15, false);

	ll ans = 0;
  solve(v, 0, ans, vr, vc, vd1, vd2);
	cout << ans << endl;
	return 0;
}