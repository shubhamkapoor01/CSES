#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


vector<ll> cycle;
ll root;

bool dfs(vector<vector<ll>>& graph, ll start, ll par,
					vector<bool>& vis, vector<ll>& cyc) {

	if (vis[start]) return false;
	vis[start] = true;
	cyc.push_back(start);

	for (auto i: graph[start]) {
		if ((vis[i] && par != i) || dfs(graph, i, start, vis, cyc)) {
			cycle = cyc;
			root = start;
			return true;
		}
	}

	cyc.pop_back();
	return false;
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

	vector<bool> vis(n + 1, false);
	for (ll i = 1; i <= n; i ++) {
		if (!vis[i]) {
			vector<ll> cyc = {};
			if (dfs(graph, i, -1, vis, cyc)) {
				cycle.push_back(root);
				ll idx = cycle.size() - 1;
				ll cnt = 0;
				while (true) {
					if (cycle[idx] == root) {
						cnt ++;
					}
					if (cnt == 2) {
						break;
					}
					idx --;
				}
				cout << cycle.size() - idx + 1 << endl;
				for (ll i = idx; i < cycle.size(); i ++) {
					cout << cycle[i] << " ";
				}
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}