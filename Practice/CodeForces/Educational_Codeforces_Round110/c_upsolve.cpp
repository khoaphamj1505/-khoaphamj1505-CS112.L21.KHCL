#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define down(i, a, b) for(int i=a; i>=b; i--)
#define dbg(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";
#define fi first 
#define sec second

typedef long long ll;
typedef pair<int, int> ii;
template <class T> using ordered_set = tree<T, null_type, \
less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

template <class K, class V> using ordered_map = tree<K, V, \
less<K>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k): k-th largest element (from 0)
// order_of_key(x): the number of items that strictly smaller than x

const ll INF = 1e9+1;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
void solve(){
	string s; 
	cin >> s;

	vt<int> check(sz(s), 0);

	ll ans = 0;

	auto count = [&]() -> ll{
		ll res = 0;
		ll c = 0;
		for(auto x : check){
			if(x == 1){
				res++;
				c += res;
			}
			else res = 0;
		}

		return c;
	};

	for(int pos0 : {0, 1}){
		rep(i, 0, sz(s)-1){
			if(s[i] == '?' || (s[i] == '0' && i % 2 == pos0) || (s[i] == '1' && i % 2 != pos0))
				check[i] = 1;
		}

		ans += count();
		check = vt<int> (sz(s), 0);
	}

	rep(i, 0, sz(s) - 1){
		if(s[i] == '?')
			check[i] = 1;
		else 
			check[i] = 0;
	}

	ans -= count();

	cout << ans << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--)
	solve();
}
