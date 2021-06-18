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
	int n;
	cin >> n;
	vt<int> arr(n);
	ll sum = 0;

	for(auto &x : arr){
		cin >> x;
		sum += x;
	}
	sort(all(arr));
	vt<vt<int>> dp(sum + 1, vt<int> (n+1, 0));
	vt<int> res(sum + 1, 0);
	int cnt = 0;

	dp[0] = vt<int> (n+1, 1);

	rep(i, 1, sum){
		rep(j, 1, n){
			dp[i][j] = dp[i][j-1];
			if(i >= arr[j-1]){
				// dbg(i) dbg(j) dbg(i- arr[j-1]) dbg(dp[i- arr[j-1]][j-1]) endln
				dp[i][j] = max(dp[i][j],\
				 dp[i- arr[j-1]][j-1]);
			}
			res[i] = max(res[i], dp[i][j]);
		}
		cnt += res[i];
	}
	
	cout << cnt << endl;
	rep(i, 1, sum)
		if (res[i])
			cout << i << " ";
	cout << endl;	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
