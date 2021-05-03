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
typedef tree<int,null_type,less<int>,rb_tree_tag, \
tree_order_statistics_node_update> indexed_set;
// find_by_order(k): k-th largest element (from 0)
// order_of_key(x): the number of items that strictly smaller than x

const ll INF = 1e9+1;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
typedef pair<ii, int> i3;

bool cmp(i3 a, i3 b){
	if(a.fi.fi == b.fi.fi)
		return a.fi.sec > b.fi.sec;
	return a.fi.fi < b.fi.fi;
}

void solve(){
	int n; cin >>n;
	vt<i3> arr(n);
	vt<int> contains(n), contained(n);

	rep(i, 0, n-1){
		cin >> arr[i].fi.fi >> arr[i].fi.sec;
		arr[i].sec = i;
	}
	sort(all(arr), cmp);
	// arr[i] < arr[j] <=> arr[j] can be inside arr[i]
	int MinR = INT_MAX; // min right pivot so far

	down(i, n-1, 0){
		if(arr[i].fi.sec >= MinR)
			contains[arr[i].sec] = 1;
		MinR = min(MinR, arr[i].fi.sec);
	}
	
	int MaxR = -1;
	rep(i, 0, n-1){
		if(arr[i].fi.sec <= MaxR)
			contained[arr[i].sec] = 1;
		MaxR = max(MaxR, arr[i].fi.sec);
	}

	for(auto x : contains)
		cout << x << " ";
	cout << endl;

	for(auto x : contained)
		cout << x << " ";
	cout << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
