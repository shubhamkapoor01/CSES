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

	ll x, q;
	cin >> x >> q;

	map<ll, ll> mp;
	set<ll> st;

    mp[x] = 1;
	st.insert(0);
	st.insert(x);

	while (q --) {
	  ll input;
		cin >> input;
		auto lower = st.lower_bound(input);
		ll right = *lower;
		lower --;
		ll left = *lower;
		
		mp[right - left] --;
		if (!mp[right - left]) mp.erase(right - left);
		mp[right - input] ++;
		mp[input - left] ++;
		
		st.insert(input);
		cout << mp.rbegin() -> first << " ";
	}
	return 0;
}