#include <bits/stdc++.h>
using namespace std;

#define mod 1e9 + 7
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


ll solve(ll a, ll b) {
	if (b == 0) {
		return 1;
	}

	if (b % 2 == 0) {
		ll half = solve(a, b / 2);
		return (half % mod * half % mod) % mod;

	} else {
		return (a % mod * solve(a, b - 1) % mod) % mod;
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll tc;
	cin >> tc;
	while (tc --) {

		ll a, b;
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
	return 0;
}