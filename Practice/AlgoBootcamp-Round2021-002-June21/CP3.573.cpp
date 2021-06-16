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
int H;
double U, D, F;

void solve(){
	double dis = 0.00;
	double loss = ((F / 100.00))*U;
	double h = double(H);
	// dbg(h) dbg(U) dbg(D) dbg(F) endln
	int day = 0;
	while(true){
		++day;

		dis += U;
		if (dis > h ){
			cout << "success on day " << day << endl;
			return;
		}
		if (U > 0)
			U -= loss;
		dis -= D;
		if (dis < 0){
			cout << "failure on day " << day << endl;
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin >> H >> U>> D>> F){
		if (H == 0)
			break;
		solve();
	}
}
