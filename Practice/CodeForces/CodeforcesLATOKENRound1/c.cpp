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

const ll INF = 1e9+7;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

ll p(ll x){
	if(x == 0)
		return 1;
	if (x == 1)
		return 2;
	ll ans = p(x/2);
	ans = ((ans % INF) * (ans % INF)) % INF;
	if(x % 2)
		ans = ((ans % INF) * 2) % INF;
	return ans;
}

void solve(){
	int n;
	cin >> n;
	vt<int> arr1(n), arr2(n);

	for(auto &x : arr1){
		cin >> x;
		x -= 1;
	}

	for(auto &x : arr2){
		cin >> x;
		x -= 1;
	}

	vt<vt<int>> adj(n);

	rep(i, 0, n-1){
		adj[arr2[i]].pb(arr1[i]);
		adj[arr1[i]].pb(arr2[i]);
	}

	vt<int> check(n, 0);

	function<void(int)> dfs = [&](int u) {
		if(check[u])
			return;
		check[u] = 1;
		for(auto x : adj[u])
			if(!check[x])
				dfs(x);
	};

	ll cnt = 0;
	rep(i, 0, n-1){
		if(!check[i]){
			++cnt;
			dfs(i);
		}
	}

	ll ans = p(cnt);


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
