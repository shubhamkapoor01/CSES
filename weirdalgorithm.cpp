#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define endl "\n"

void solve(ll n) {

	cout << n << endl;
	if (n == 1) {
		return;
	}

	if (n % 2 == 0) {
		n = n / 2;
	} else {
		n = 3 * n + 1;
	}
	solve(n);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	solve(n);
	return 0;
}