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

	if ((n + 1) / 2 % 2 != 0) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	if (n % 2 == 0) {
		cout << n / 2 << endl;
		for (ll i = 1; i < n / 2; i += 2) {
			cout << i << " ";
		}
		for (ll i = n; i > n / 2 + 1; i -= 2) {
			cout << i << " ";
		}

		cout << endl << n / 2 << endl;
		
		for (ll i = 2; i <= n / 2; i += 2) {
			cout << i << " ";
		}
		for (ll i = n - 1; i >= n / 2 + 1; i -= 2) {
			cout << i << " ";
		}
		cout << endl;

	} else {
		cout << n / 2 + 1 << endl;
		cout << 1 << " " << 2 << " ";
		for (ll i = 4; i <= n - 3; i += 4) {
			cout << i << " " << i + 3 << " ";
		}

		cout << endl << n / 2 << endl;

		cout << 3 << " ";
		for (ll i = 4; i <= n - 3; i += 4) {
			cout << i + 1 << " " << i + 2 << " ";
		}
		cout << endl;
	}

	return 0;
}