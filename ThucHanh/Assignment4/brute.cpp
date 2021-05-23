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
	int n, m;
	cin >> n;
	vt<int> a(n);
	for(int &x : a)
		cin >> x;

	cin >> m;
	vt<int> b(m);
	for(int &x : b)
		cin >> x;

	auto cal_sum = [&](int state1, int state2){
		vt<int> r1;
		rep(i, 0, n-1)
			if(state1 & (1 << i))
				r1.pb(i);

		vt<int> r2;
		rep(i, 0, m - 1)
			if(state2 & (1 << i))
				r2.pb(i);

		if(sz(r1) != sz(r2)){
			return 0;
		}

		vt<int> tempa = a;

		rep(i, 0, sz(r1) -1)
			tempa[r1[i]] += b[r2[i]];

		int ans = INT_MAX;
		for(auto x : tempa)
			ans = min(ans, x);
		return ans;
	};

	int ans = 0;
	int state_a, state_b;
	rep(state1, 0, (1 << n) - 1){
		rep(state2, 0, (1 << m) - 1){
			int res = cal_sum(state1, state2);
			if (res > ans){
				ans = res;
				state_a = state1;
				state_b = state2;
			}
		}
	}
	cout << ans << " ";
	vt<int> arr1, arr2;
	rep(i, 0, n-1)
		if (state_a & (1 << i))
			arr1.pb(i + 1);

	rep(i, 0, m-1)
		if (state_b & (1 << i))
			arr2.pb(i + 1);

	cout << sz(arr1) << endl;
	rep(i, 0, sz(arr1)-1)
		cout << arr1[i] << " " << arr2[i] << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
