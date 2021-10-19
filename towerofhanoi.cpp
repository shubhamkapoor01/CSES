#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"

void solve(ll start, ll end, ll extra, ll n, vector<pair<ll, ll>> &v) {
	if (n == 1) {
	    v.push_back({start, end});
		return;
	}
	solve(start, extra, end, n - 1, v);
	v.push_back({start, end});
	solve(extra, end, start, n - 1, v);
	return;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	vector<pair<ll, ll>> v;
	solve(1, 3, 2, n, v);
	cout << v.size() << endl;
	for (auto i: v) {
	    cout << i.first << " " << i.second << endl;
	}
	return 0;
}