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
	int n, x;
	cin >> n >> x;
	vt<int> arr(n);

	for(auto &x : arr)
		cin >> x;

	sort(all(arr));

	vt<int> check(n, 0);

	int cnt = 0;
	int pivot = n;
	rep(i, 0, n-1){
		if(!check[i]){
			++cnt;
			if(i < pivot){
				int pos = upper_bound(arr.begin()+i+1, arr.begin()+pivot, x - arr[i]) - arr.begin();
				--pos;
				if(i < pos && pos < n)
					check[pos] = 1;
				pivot = pos;
			}
		}
	}
	cout << cnt << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
