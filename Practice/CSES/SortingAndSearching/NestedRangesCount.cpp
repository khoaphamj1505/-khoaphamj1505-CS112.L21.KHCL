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
struct interval
{
	int l, r, id;	
};

bool cmp(interval a, interval b){
	if(a.l == b.l)
		return a.r > b.r;
	return a.l < b.l;
}

void solve(){
	int n;
	cin >> n;
	vt<interval> arr(n);
	rep(i, 0, n-1){
		cin >> arr[i].l >> arr[i].r;
		arr[i].id = i;
	}

	vt<int> number_interval_contains(n);
	vt<int> number_interval_contained(n);
	sort(all(arr), cmp);
	ordered_set<ii> s1, s2;

	rep(i, 0, n-1){
		int cnt = s1.order_of_key(ii(arr[i].r, -1));
		number_interval_contained[arr[i].id] = sz(s1) - cnt;
		s1.insert(ii(arr[i].r, i));
	}

	down(i, n-1, 0){
		int cnt = s2.order_of_key(ii(arr[i].r+1, -1));
		// cnt : number arr[j].r <= arr[i].r
		number_interval_contains[arr[i].id] = cnt;
		s2.insert(ii(arr[i].r, i));
	}

	rep(i, 0, n-1)
		cout << number_interval_contains[i] << " ";
	cout << endl;

	rep(i, 0, n-1)
		cout << number_interval_contained[i] << " ";
	cout << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
