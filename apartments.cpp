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

	ll n, m, k;
	cin >> n >> m >> k;

	vector<ll> desired(n);
	vector<ll> actual(m);
	for (ll i = 0; i < n; i ++)
		cin >> desired[i];
	for (ll i = 0; i < m; i ++)
		cin >> actual[i];

	sort(desired.begin(), desired.end());
	sort(actual.begin(), actual.end());

	ll i = 0;
	ll j = 0;
	ll ans = 0;

	while (i < n && j < m) {
		if (actual[j] >= desired[i] - k && actual[j] <= desired[i] + k) {
			ans ++;
			i ++;
			j ++;
		
		} else if (actual[j] < desired[i] - k) {
			j ++;

		} else if (actual[j] > desired[i] + k) {
			i ++;
		}
	}

	cout << ans << endl;
	return 0;
}