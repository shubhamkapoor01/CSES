#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define endl "\n"


void solve(vector<ll>& v, ll idx, ll sum, set<ll>& sums, vector<vector<bool>>& dp) {
	if (idx == v.size()) {
		sums.insert(sum);
		return;
	}

	if (dp[idx][sum]) {
		return;
	}

	solve(v, idx + 1, sum, sums, dp);
	solve(v, idx + 1, sum + v[idx], sums, dp);

	dp[idx][sum] = true;
	return;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, s = 0;
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
		s += v[i];
	}

	set<ll> sums;
	vector<vector<bool>> dp(n, vector<bool> (s + 1, false));
	solve(v, 0, 0, sums, dp);
	sums.erase(0);

	cout << sums.size() << endl;
	for (auto i: sums) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}