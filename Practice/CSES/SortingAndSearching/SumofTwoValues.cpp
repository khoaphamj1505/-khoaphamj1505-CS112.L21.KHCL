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
#define no "IMPOSSIBLE"

typedef long long ll;
typedef pair<int, int> ii;
const ll INF = 1e9+1;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/


void solve(){
	int n, x;
	cin>> n >> x;
	vt<ii> arr(n);

	rep(i, 0, n-1){
		cin >> arr[i].fi;
		arr[i].sec = i;
	}

	sort(all(arr));
	int l = 0, r = n-1;
	while(l < r){
		if(arr[l].fi + arr[r].fi == x)
			break;
		if(arr[l].fi + arr[r].fi > x)
			--r;
		else 
			++l;
	}

	if(l>=r)
		cout << no << endl;
	else{
		cout << arr[l].sec + 1<< " " << arr[r].sec + 1<< endl;
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
