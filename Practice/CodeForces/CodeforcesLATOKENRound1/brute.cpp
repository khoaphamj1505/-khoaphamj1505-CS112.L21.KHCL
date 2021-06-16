#include <bits/stdc++.h>

using namespace std;
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define down(i, a, b) for(int i=a; i>=b; i--)
#define imie(x) cerr << "[" << #x << ": " << (x) << "] ";
#define endln cerr << "\n";


typedef long long ll;
typedef pair<int, int> ii;
const ll INF = 1e9+1;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

void solve(){
	int n, h;
	cin >> n >> h;
	vt<int> a(n, 0);
	for(auto &x : a)
		cin >> x ;
	
	int t = 1;
	
	int pos = 0;
	int haveCrane = 0;
	
	while(1){
		cin >> t;
		if(t==0){
			for(auto x : a)
				cout << x << " ";
			cout << endl;
			return;
		}else if(t == 1){
			pos -= 1;
			pos = max(pos, 0);
		}else if(t == 2){
			pos += 1;
			pos = min(pos, n-1);
		}else if(t == 3){
			if(!haveCrane && a[pos] != 0)
				haveCrane = 1, --a[pos];
		}else if(t == 4){
			if(haveCrane && a[pos] < h)
				haveCrane = 0, ++a[pos];
		}
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
