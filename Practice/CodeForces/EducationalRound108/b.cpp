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
	#define yes "YES"
	#define no "NO"
	const ll INF = 1e9+1;
	const int N = 1e5+1;

	/* stuff you should look for
		* WRITE STUFF DOWN
		* DON'T GET STUCK ON ONE APPROACH
	*/
	int a[101][101];

	int dp(int x, int y, int val){
		if(x == 1 && y == 1){
			return val == 0;
		}
		if(a[x][y] != -1)
			return a[x][y];
		if(x > 1)
			a[x][y] = dp(x-1, y, val-y);
		if(a[x][y]==1)
			return a[x][y];
		if(y > 1)
			a[x][y] = dp(x, y-1, val-x);
		return a[x][y];
	}

	void solve(){
		int n, m, k;
		cin >> n >> m >> k;
		memset(a, -1, sizeof(a));
		int check = dp(n, m, k);
		if(check)
			cout << yes << endl;
		else 
			cout << no << endl;
	}

	int main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		int n; cin >> n;
		while(n--)
		solve();
	}
