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
const ll INF = 1e9+7;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/


void solve(){
	int n;
	cin >> n;
	vt<ll> a(n);
	for(auto &x : a){
		cin >> x;
	}
	sort(all(a));

	ll min_sub = LLONG_MAX;
	vt<ii> id;

	rep(i, 0, n-2)
		min_sub = min(min_sub, a[i+1] - a[i]);

	rep(i, 0, n-2){
		if (a[i+1] - a[i] == min_sub){
			id.pb(ii(i, i+1));
		}
	}

	auto cnt = [&](vt<ll> arr) -> ll{
		ll ans = 0;
		rep(i, 0, sz(arr)-2)
			if(arr[i] <= arr[i+1])
				++ans;
		return ans;
	};

	vt<ll> final;
	int final_cnt = 0;

	for(auto idx : {0, sz(id)-1}){

		vt<ll> b, b1;
		int id_min = id[idx].first;
		int id_max = id[idx].second;

		b.pb(a[id_min]);
		down(i, n-1, 0)
			if (i != id_min && i != id_max)
				b.pb(a[i]);
		b.push_back(a[id_max]);

		b1.pb(a[id_min]);
		rep(i, 0, n-1)
			if (i != id_min && i != id_max)
				b1.pb(a[i]);
		b1.push_back(a[id_max]);

		int cnt_b = cnt(b);
		int cnt_b1 = cnt(b1);

		if(cnt_b > final_cnt){
			final_cnt = cnt_b;
			final = b;
		}

		if(cnt_b1 > final_cnt){
			final_cnt = cnt_b1;
			final = b1;
		}

	}
		
	for(auto x : final)
		cout <<x <<" ";
	
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	solve();
}