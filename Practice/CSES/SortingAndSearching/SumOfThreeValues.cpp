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
	int n;
	ll x;
	cin >> n >> x;
	vt<ii> arr(n);

	rep(i, 0, n-1){
		cin >> arr[i].fi;
		arr[i].sec = i;
	}

	sort(all(arr));

	int l=0, r = n-1;
	int flag = 0;
	rep(i, 0, n-3){
		ll val = x - arr[i].fi;
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
			cout << arr[i].sec+1 << " " << arr[l].sec+1 << " " << arr[r].sec+1 << endl;
			break;
		}
	}
	if(!flag)
		cout << "IMPOSSIBLE" << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
