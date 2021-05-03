#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define down(i, a, b) for(int i=a; i>=b; i--)

const int N = 1e5+1;
typedef long long ll;
typedef pair<int, int> ii;

ll rand(ll a, ll b){
	return rand() % (b-a+1) +a;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	srand(time(NULL));

	cout << 1 << endl;
	int n = rand(2, 5);
	cout << n <<endl;
	rep(i, 1, n)
		cout << rand(1, 1000) << " ";
	cout << endl;
}
