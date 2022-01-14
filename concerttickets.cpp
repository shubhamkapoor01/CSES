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
	multiset<ll> tickets;
	vector<ll> customers(m);

	for (ll i = 0; i < n; i ++) {
		ll ele;
		cin >> ele;
		tickets.insert(ele);
	}
	
	for (ll i = 0; i < m; i ++) {
		cin >> customers[i];
		auto ele = tickets.lower_bound(customers[i]);
	    
	    if (tickets.find(customers[i]) != tickets.end()) {
		    cout << *ele << endl;
		    tickets.erase(ele);
		    
		} else if (ele == tickets.begin()) {
			cout << -1 << endl;
			
		} else {
		    ele --;
			cout << *ele << endl;
			tickets.erase(ele);
		}
	}
	return 0;
}