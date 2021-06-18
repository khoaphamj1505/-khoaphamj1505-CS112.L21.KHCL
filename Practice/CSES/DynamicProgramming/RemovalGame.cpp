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


void solve(){
	int n; cin >> n;
	ll sum = 0;
	vt<ll> arr(n);

	for(auto &x : arr){
		cin >> x;
		sum += x;
	}

	vt<vt<ll>> dp(n + 1, vt<ll> (n + 1, -1));

	function<ll(int, int)> F = [&] (int i, int j){
		if( j - i <= 0){
			return max(arr[i], arr[j]);
		}
		// dbg(i) dbg(j) endln
		if(dp[i][j] == -1){
			dp[i][j] = max(arr[i] - F(i+1, j),\
			 arr[j] - F(i, j-1));
		}

		return dp[i][j];
	};

	ll res = F(0, n-1);

	cout << (res + sum) / 2 << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
