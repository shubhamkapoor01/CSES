#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"

string binary(ll n, ll len) {
	string s = "";
	while (n) {
		if (n % 2 == 0) {
			s.push_back('0');
		} else {
			s.push_back('1');
		}
		n /= 2;
	}
	reverse(s.begin(), s.end());
	
	string z = "";
	while (z.size() < len - s.size()) {
		z.push_back('0');
	}

	return z + s;
}

void dfs(vector<ll> graph[], vector<bool> &vis, ll start, ll n, vector<string> &ans) {
	if (vis[start]) {
		return;
	}

	ans.push_back(binary(start, n));
	vis[start] = true;

	for (auto i: graph[start]) {
		dfs(graph, vis, i, n, ans);
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;

	vector<ll> graph[1 << n];

	for (ll i = 0; i < (1 << n); i ++) {		
		ll next = 1;
		while (next < (1 << n)) {
			graph[i].push_back(i ^ next);
			next *= 2;
		}
	}

	vector<string> ans;
	vector<bool> vis(1 << n, false);
	dfs(graph, vis, 0, n, ans);

	for (ll i = 0; i < (1 << n); i ++) {
		cout << ans[i] << endl;
	}
	return 0;
}