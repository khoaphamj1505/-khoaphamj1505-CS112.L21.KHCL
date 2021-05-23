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

vt<ll> SumOfThree(vt<ii> arr, ll value, int start){
	int n = sz(arr);
	int l=0, r = n-1;
	int flag = 0;
	vt<ll> ans;
	rep(i, start, n-3){
		ll val = value - arr[i].fi;
		l = i+1;
		r = n-1;
		flag = 0;
		while(l < r){
			if(arr[l].fi + arr[r].fi == val){
				flag = 1;
				break;
			}
			if(arr[l].fi + arr[r].fi < val)
				++l;
			else 
				--r;
		}
		if(flag){
			ans.pb(arr[l].sec);
			ans.pb(arr[r].sec);
			ans.pb(arr[i].sec);
			return ans;
		}
	}
	return ans;
}

void solve(){
	int n;
	ll x;
	cin >> n >> x;
	vt<ii> arr(n);

	rep(i, 0, n-1){
		cin >> arr[i].fi;
		arr[i].sec = i;
	}

	sort(all(arr));

	rep(i, 0, n-4){
		vt<ll> ans = SumOfThree(arr, x - arr[i].fi, i+1);
		if(sz(ans) == 3){
			cout << arr[i].sec+1 << " ";
			for(auto x : ans)
				cout << x+1 << " ";
			cout << endl;
			return;
		}
	}	

	cout <<"IMPOSSIBLE" << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
