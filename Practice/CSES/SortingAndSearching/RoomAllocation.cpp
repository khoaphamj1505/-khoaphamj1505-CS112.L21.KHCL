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
typedef pair<ii, int> i3;
/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
void solve(){
	int n; cin >> n;
	vt<i3> arr(n);
	int i = 0;
	for(auto &x : arr){
		cin >> x.fi.fi >> x.fi.sec;
		x.sec = i++;
	}
	sort(all(arr));

	ordered_set<ii> s;

	int cnt = 0;
	vt<int> ans(n);

	rep(i, 0, n-1){
		int k = s.order_of_key(ii(arr[i].fi.fi, -1));
		if(k==0){
			++cnt;
			s.insert(ii(arr[i].fi.sec, cnt));	
			ans[arr[i].sec] = cnt;
		}else{
			auto pos = s.find_by_order(k-1);
			int index = (*pos).sec;
			s.erase(pos);
			s.insert(ii(arr[i].fi.sec, index));
			ans[arr[i].sec] = index;
		}
	}

	cout << cnt << endl;
	for(auto x : ans)
		cout << x << " ";
	cout << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
