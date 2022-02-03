#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


void dfs(vector<vector<ll>>& adj, ll u, vector<bool>& visited, vector<ll>& component) {
		visited[u] = true;
		component.pb(u);

		for (int v : adj[u]) {
				if (!visited[v]) {
						dfs(adj, v, visited, component);
				}
		}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m, r, c;
	cin >> n >> m;
	vector<vector<ll>> graph(n + 1);
	for (ll i = 0; i < m; i ++) {
		ll u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	vector<vector<ll>> components;
	vector<bool> vis(n + 1, false);

	for (ll i = 1; i <= n; i ++) {
		if (!vis[i]) {
			components.pb(vector<ll>());
			dfs(graph, i, vis, components.back());
		}
	}

	cout << components.size() - 1 << endl;
	for (ll i = 1; i < components.size(); i ++) {
		cout << components[i][0] << " " << components[i - 1][0] << endl;
	}
	return 0;
}