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
	vector<vector<pair<ll, ll>>> graph(n + 1);
	for (int i = 0; i < m; i ++) {
		ll u, v, w;
		cin >> u >> v >> w;
		graph[u].pb({w, v});
	}

	priority_queue<pair<ll, ll>, vector<pair<ll,  ll>>, greater<pair<ll, ll>>> pq;
	vector<ll> dist(n + 1, 1e18);
	pq.push({0, 1});
	dist[1] = 0;

	while (!pq.empty()) {
		ll root = pq.top().second;
		ll wt = pq.top().first;
		pq.pop();

		if (dist[root] < wt) continue;

		for (auto i: graph[root]) {
			if (dist[i.ss] > wt + i.ff) {
				dist[i.ss] = wt + i.ff;
				pq.push({wt + i.ff, i.ss});
			}
		}
	}

	for (ll i = 1; i <= n; i ++) {
		cout << dist[i] << " ";
	}
	return 0;
}