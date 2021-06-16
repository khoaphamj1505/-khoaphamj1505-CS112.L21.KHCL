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

int f = 1;

void solve(){
	int n;
	cin >> n;
	if( n == 0){
		f = 0;
		return;
	}

	int x, y;
	cin >> x >> y;

	rep(i, 1, n){
		int a, b;
		cin >> a >> b;
		a -= x;
		b -= y;
		if ( a* b == 0)
			cout << "divisa" << endl;
		else{
			if ( a > 0 && b > 0)
				cout << "NE" << endl;
			if ( a < 0 && b > 0)
				cout << "NO" << endl;
			if (a < 0 && b < 0)
				cout << "SO" << endl;
			if (a > 0 && b < 0)
				cout << "SE" << endl;
		}
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(f){
		solve();
	}
}
