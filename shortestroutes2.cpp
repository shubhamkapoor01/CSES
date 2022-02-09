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

	ll n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll>> graph(n, vector<ll> (n, 1e18));
	for (ll i = 0; i < m; i ++) {
		ll u, v, w;
		cin >> u >> v >> w;
		-- u;
		-- v;
		graph[u][v] = min(graph[u][v], w);
		graph[v][u] = min(graph[v][u], w);
	}

	for (ll k = 0; k < n; k ++) {
		for (ll i = 0; i < n; i ++) {
			for (ll j = 0; j < n; j ++) {
				if (i == j) graph[i][j] = 0;
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				graph[j][i] = min(graph[j][i], graph[j][k] + graph[k][i]);
			}
		}
	}

	while (q --) {
		ll u, v;
		cin >> u >> v;
		-- u;
		-- v;
		cout << (graph[u][v] >= 1e18 ? -1 : graph[u][v]) << endl;
	}
	return 0;
}