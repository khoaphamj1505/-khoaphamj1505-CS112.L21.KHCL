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
typedef pair<ii, int> i3;
const ll INF = 1e9+1;
const int N = 2001;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

int a[N][N];
i3 c[N];

void solve(){
	int n, t, p;
	cin >> n >> t >> p;
	vt<int> scores(t+1, n);

	rep(i, 1, n){
		rep(j, 1, t){
			cin >> a[i][j];
			scores[j] -= a[i][j];
		}
	}

	rep(i, 1, n){
		c[i] = i3(ii(0,0), -i);
		c[i].fi.se = 0;
		c[i].se = -i;
		rep(j, 1, t){
			c[i].fi.fi += scores[j] * a[i][j];
			c[i].fi.se += a[i][j];
		}
	}

	sort(c + 1, c + n + 1, greater<i3> ());

	rep(i, 1, n){
		if (c[i].se == -p){
			cout << c[i].fi.fi << " " << i << endl;
			return;
		}
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
