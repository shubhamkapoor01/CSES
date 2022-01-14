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
	vector<ll> arr(n);
	vector<ll> dep(n);
	for (ll i = 0; i < n; i ++) {
		cin >> arr[i] >> dep[i];
	}

	sort(arr.begin(), arr.end());
	sort(dep.begin(), dep.end());

	ll current = 0;
	ll maximum = 0;
	ll i = 0;
	ll j = 0;

	while (i < n && j < n) {
		if (arr[i] < dep[j]) {
			current ++;
			i ++;
		} else {
			current --;
			j ++;
		}

		maximum = max(maximum, current);
	}

	cout << maximum << endl;
	return 0;
}