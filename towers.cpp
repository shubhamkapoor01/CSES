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
	vector<ll> v;

	for (ll i = 0; i < n; i ++) {
		ll ele;
		cin >> ele;
		ll pos = upper_bound(v.begin(), v.end(), ele) - v.begin();
		
		if (pos >= v.size()) {
			v.push_back(ele);
		} else {
			v[pos] = ele;
		}
	}

	cout << v.size() << endl;
	return 0;
}