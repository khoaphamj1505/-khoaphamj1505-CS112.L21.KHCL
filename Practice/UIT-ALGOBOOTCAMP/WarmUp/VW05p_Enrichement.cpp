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
#define sec second

typedef long long ll;
typedef pair<int, int> ii;
const ll INF = 1e9+1;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

ll solve(vt<vt<ll>> arr){
	int m = sz(arr[1]);
	rep(i, 1, 3){
		rep(j, 1, m-1)
			arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
	}	

	ll ans = LLONG_MAX;
	rep(i, 3, m-1)
		ans = min(ans, arr[3][i] - arr[0][i] - arr[3][i-3] + arr[0][i-3]);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vt<vt<ll>> arr(4, vt<ll>(m+1, 0));

	rep(i, 1, 2){
		rep(j, 1, m)
			cin >> arr[i][j];
	}

	ll ans = LLONG_MAX;
	rep(i, 3, n){
		rep(j, 1, m)
			cin >> arr[3][j];
		ans = min(ans, solve(arr));
		arr[1] = arr[2];
		arr[2] = arr[3];
	}	

	cout << ans << endl;

}
