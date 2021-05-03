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
	int n; cin >> n;
	vt<int> arr(n+1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}	

	map<int, int> mp;

	int head = 1;
	int	tail = 2; 
	int cnt = 1;
	mp[arr[1]] = 1;
	while(head <= n && tail <= n){
		while(tail <= n && mp[arr[tail]] < head){
			mp[arr[tail]] = tail;
			tail++;
		}
		cnt = max(cnt, tail - head);
		head = mp[arr[tail]]+1; 
		// break;
	}

	cout << cnt << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
