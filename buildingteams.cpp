#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


bool dfs(vector<vector<ll>>& graph, ll root, vector<ll>& team, ll toSet) {
	team[root] = toSet;

	if (toSet == 1) toSet = 2;
	else if (toSet == 2) toSet =1;

	for (auto i: graph[root]) {
		if (!team[i] && !dfs(graph, i, team, toSet)) {
			return false;
		}

		if (team[i] != 0 && toSet != team[i]) {
			return false;
		}
	}

	return true;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> graph(n + 1);
	for (ll i = 0; i < m; i ++) {
		ll u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<ll> team(n + 1, 0);
	for (ll i = 1; i <= n; i ++) {
		if (team[i] == 0 && !dfs(graph, i, team, 1)) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}

	for (ll i = 1; i <= n; i ++) {
		cout << team[i] << " ";
	}

	cout << endl;
	return 0;
}