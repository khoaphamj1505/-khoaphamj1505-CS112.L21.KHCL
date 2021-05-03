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
const ll INF = 1e18;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
vt<ll> F(19, 0);

void precompute(){
	ll base = 9;
	rep(i, 1, 18){
		F[i] = F[i-1] + base*i;
		base = base * 10;
		dbg(i) dbg(F[i]) endln
		if(F[i] >= INF)
			return;
	}	

}

void solve(){
	ll k; cin >> k;
	int digit = lower_bound(all(F), k) - F.begin();
	dbg(k) dbg(digit) endln
	if(F[digit] == k){
		cout << 9 << endl;
		return;
	}

	ll num = 0;
	rep(i, 1, digit-1)
		num = num * 10 + 9;

	ll current_digit = F[digit-1];
	ll need_digit = (k-current_digit);

	num = num + (need_digit/digit) ;
	current_digit += (need_digit/digit)*digit;

	if(need_digit % digit){
		++num;
		current_digit += digit;
	}

	while(current_digit != k){
		--current_digit;
		num /= 10;
	}

	cout << num % 10 << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	precompute();
	while(t--)
	solve();
}
