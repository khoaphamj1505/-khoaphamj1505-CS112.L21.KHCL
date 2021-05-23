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
typedef pair<ll, ll> ii;
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
	int n, k;
	cin >> n >> k;
	vt<ll> arr(n);
	for(auto &x : arr)
		cin >> x;
	ordered_set<ii> low, high;
	ll sum_low = 0;
	ll sum_high = 0;

	rep(i, 0, k-2){
		if(sz(low) == sz(high)){
			low.insert(ii(arr[i], (ll)i));
			sum_low += arr[i];
		}
		else{
			sum_high += arr[i];
			high.insert(ii(arr[i], i));
		}
	}

	int index = 0;
	rep(i, k-1, n-1){
		if(sz(low) == sz(high)){
			low.insert(ii(arr[i], i));
			sum_low += arr[i];
		}
		else{
			sum_high += arr[i];
			high.insert(ii(arr[i], i));
		}

		ll median = (*low.rbegin()).first;
		dbg(sz(low)) dbg(sz(high)) dbg(sum_low) dbg(sum_high) dbg(median) endln
		// cout << (median*sz(low) - sum_low) + (sum_high - median*sz(high)) << " ";

		if(arr[index] > median){
			sum_high -= arr[index];
			high.erase(ii(arr[index], index));
		}else{
			sum_low -= arr[index];
			low.erase(ii(arr[index], index));
		}
		++index;
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
