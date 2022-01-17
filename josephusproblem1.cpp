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

	ll n;
	cin >> n;
	queue<ll> q;
	for (int i = 0; i < n; i ++) {
		q.push(i + 1);
	}

	while (q.size() > 1) {
		ll f = q.front();
		q.pop();
		ll s = q.front();
		q.pop();

		cout << s << " ";
		q.push(f);
	}

	cout << q.front() << endl;
	q.pop();
	return 0;
}