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

	ll n, x;
	cin >> n >> x;
	vector<ll> v(n);
	for (ll i = 0; i < n; i ++)
		cin >> v[i];

	sort(v.begin(), v.end());

	ll gondolas = 0;
	ll left = 0;
	ll right = n - 1;

	while (v[right] > x) {
		gondolas ++;
		right --;
	}

	while (left <= right) {
		if (v[left] + v[right] <= x) {
			gondolas ++;
			right --;
			left ++;

		} else if (v[left] + v[right] > x) {
			gondolas ++;
			right --;
		}
	}

	cout << gondolas << endl;
	return 0;
}