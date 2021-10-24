#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


ll solve(ll n) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 0) {
		ll t = solve(n / 2) % mod;
		return (t % mod * t % mod) % mod;
	} else {
		return (solve(n - 1) % mod * 2) % mod;
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	cout << solve(n) % mod << endl;
	return 0;
}