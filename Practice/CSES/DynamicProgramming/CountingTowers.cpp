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
const ll INF = 1e9+7;
const int N = 1e6+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

ll dp[N][3];

void solve(){

	dp[1][1] = dp[1][2] = 1;

	rep(i, 2, N){
		dp[i][1] = (((dp[i-1][1] * 4) % INF) + dp[i-1][2])%INF;
		dp[i][2] = (((dp[i-1][2] * 2) % INF) + dp[i-1][1])%INF;
	}


}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	solve();

	while(t--){
		int n;
		cin >> n;
		cout << (dp[n][1] + dp[n][2]) % INF << endl;
	}
}
