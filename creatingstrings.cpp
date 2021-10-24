#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define endl "\n"


void solve(string s, ll i, set<string> &ans, string curr, vector<bool> &vis) {
	if (i == s.size()) {
		ans.insert(curr);
		return;
	}

	for (ll idx = 0; idx < s.size(); idx++) {
		if (!vis[idx]) {
			vis[idx] = true;
			curr.push_back(s[idx]);
			solve(s, i + 1, ans, curr, vis);
			curr.pop_back();
			vis[idx] = false;
		}
	}
	return;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	vector<bool> vis(s.size(), false);
	set<string> ans = {};
	string curr = "";

	solve(s, 0, ans, curr, vis);

	vector<string> v;
	for (auto i: ans) {
		v.push_back(i);
	}

	sort(v.begin(), v.end());

	cout << v.size() << endl;
	for (ll i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}