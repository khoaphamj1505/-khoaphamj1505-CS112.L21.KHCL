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
	int n, m, k;
	cin >> n >> m >> k;
	vt<int> a(n), b(m);
	for(auto &x : a)
		cin >> x;

	for(auto &x : b)
		cin >> x;

	sort(all(a));
	sort(rall(b));

	int pivot = n;
	int cnt = 0;
	for(auto sizeX :  b){
		int min_pos = lower_bound(a.begin(), a.begin()+pivot, sizeX-k) - a.begin();
		if(min_pos == pivot)
			continue;
		int max_pos = upper_bound(a.begin(), a.begin()+pivot, sizeX+k) - a.begin();
		int new_pivot = max(min_pos, max_pos-1);
		if(new_pivot >= 0 && new_pivot < pivot && abs(a[new_pivot] - sizeX) <= k)
			++cnt, pivot = new_pivot;

	}
	cout << cnt << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
