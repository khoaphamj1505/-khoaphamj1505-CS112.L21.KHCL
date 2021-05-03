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
	int n, m; cin >> n >> m;
	vt<ii> arr(n+2);	
	vt<int> index(n+2, 0);
	rep(i, 1, n){
		cin >> arr[i].fi;
		arr[i].sec = i;
	}
	arr[0] = ii(0, 0);
	arr[n+1] = ii(n+1, n+1);
	
	sort(all(arr));
	
	int cnt = 1;	

	rep(i, 1, n){
		if(arr[i].sec > arr[i+1].sec)
			++cnt;
		index[arr[i].sec] = i;
	}

	while(m--){
		int x, y;
		cin >> x >> y;
		int pos1 = index[x];
		int pos2 = index[y];
		set<int> s;
		s.insert({pos1, pos1-1, pos2, pos2-1});
		for(auto pos : s){
			if(arr[pos].sec > arr[pos+1].sec)
				--cnt;
		}
		swap(index[x], index[y]);
		swap(arr[pos1].sec, arr[pos2].sec);

		for(auto pos : s){
			if(arr[pos].sec > arr[pos+1].sec)
				++cnt;
		}
		cout << cnt << endl;
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
