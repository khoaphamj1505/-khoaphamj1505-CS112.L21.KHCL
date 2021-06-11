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
	cin >> n;
	vt<int> arr(n);

	for(auto &x : arr)
		cin >> x;

	int pos_min = 0;
	int pos_max = 0;

	rep(i, 0, n-1){
		if( arr[i] > arr[pos_max])
			pos_max = i;
		if (arr[i] < arr[pos_min])
			pos_min = i;	
	}

	int ans = min({max(pos_max + 1, pos_min + 1), \
		max(n-pos_max, n-pos_min), (n-pos_min + pos_max + 1), (n-pos_max + pos_min + 1)});

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
