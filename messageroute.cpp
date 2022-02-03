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

	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> graph(n + 1);
	for (ll i = 0; i < m; i ++) {
		ll u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	vector<bool> vis(n + 1, false);
	vector<ll> from(n + 1, -1);
	vis[1] = true;
	queue<ll> q;
	q.push(1);

	while (!q.empty()) {
		ll u = q.front();
		q.pop();

		for (ll v : graph[u]) {
			if (!vis[v]) {
				vis[v] = true;
				from[v] = u;
				q.push(v);
			}
		}
	}

	if (from[n] == -1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	vector<ll> path;
	path.pb(n);
	ll cur = n;
	while (path[path.size() - 1] != 1) {
		path.pb(from[cur]);
		cur = from[cur];
	}

	cout << path.size() << endl;
	for (ll i = path.size() - 1; i >= 0; i --) {
		cout << path[i] << " ";
	}
	cout << endl;
	return 0;
}