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

	string s;
	cin >> s;

	unordered_map<char, ll> m;
	for (auto i: s) {
		m[i] ++;
	}

	ll cntodd = 0;

	for (auto i: m) {
		if (i.second % 2 != 0) {
			cntodd ++;
		}
	}

	if (cntodd > 1) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}

	char odd;
	ll oddfreq = 0;
	string start;
	string end;
	for (auto i: m) {
		if (i.second % 2 != 0) {
			odd = i.first;
			oddfreq = i.second;
		} else {
			ll t = i.second / 2;
			while (t --) {
				start.push_back(i.first);
				end.push_back(i.first);
			}
		}
	}
	if (oddfreq) {
		while (oddfreq --) {
			start.push_back(odd);
		}
	}
	
// 	cout << start << endl;
// 	cout << end << endl;
	
	for (ll i = 0; i < start.size(); i ++) {
		cout << start[i];
	}
	for (ll i = end.size() - 1; i >= 0; i --) {
		cout << end[i];
	}
	return 0;
}