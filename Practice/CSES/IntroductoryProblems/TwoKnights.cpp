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
    int n;
    cin >> n;
    // So cach dat 2 quan ma trong ban co kxk sao cho 2 quan k tan cong duoc nhau???
    // khi 2 quan ma an duoc nhau tuc la co 1 ban co 2x3 hoac 3x2 trong ban co kxk
    // So luong ban co 2x3 trong ban co kxk : (k-2)*(k-1)
    // So luong ban co 3x2 trong ban co kxk : (k-2)*(k-1)
    // So cach dat 2 quan ma trong ban co kxk : (n^2)*(n^2-1)*2
    rep(k, 1, n){
        ll cnt1 = (k-2)*(k-1) * 4;
        ll shl = k*k;
        ll cnt2 = (shl)*(shl-1)/2;
        cout << cnt2 - cnt1 << endl;
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
