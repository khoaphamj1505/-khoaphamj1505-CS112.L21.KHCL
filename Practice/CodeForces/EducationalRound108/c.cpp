#include <bits/stdc++.h>

using namespace std;
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
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const ll INF = 1e9+1;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

void solve(){
	int n;
	cin >> n;
	vt<ii> arr(n+1, ii(0, 0));
	map<int, int> pos, last;

	rep(i, 1, n)
		cin >> arr[i].fi;

	rep(i, 1, n)
		cin >> arr[i].se;

	sort(rall(arr));

	rep(i, 1, n){
		if(!pos[arr[i].fi])
			pos[arr[i].fi] = i;
		last[arr[i].fi] = i;
		arr[i].se += arr[i].se;
	}

	rep(k, 1, n){
		ll ans = 0;
		for(auto x : pos){
			int len = last[x.fi] - x.se + 1;
			dbg(x.fi) dbg(len) endln
		}
	}

	cout << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
}
