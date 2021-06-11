#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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
typedef pair<ll, ll> ii;
template <class T> using ordered_set = tree<T, null_type, \
less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

template <class K, class V> using ordered_map = tree<K, V, \
less<K>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k): k-th largest element (from 0)
// order_of_key(x): the number of items that strictly smaller than x

const ll INF = 1e9+1;
const int N = 1e5+1;

/* stuff you should look for
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

struct Heap
{
	ordered_set<ii> arr;
	ll sum = 0;

	void push(ii x){
		arr.insert(x);
		sum += x.first;
	}

	void pop(ii x){
		if(arr.find(x) != arr.end()){
			arr.erase(x);
			sum -= x.first;
		}
	}

	ii Min(){
		return (*arr.find_by_order(0));	
	}

	ii Max(){
		int n = sz(arr) - 1;
		if(!arr.empty())
			return (*arr.find_by_order(n));
		return ii(-1, -1);
	}

	bool empty(){
		return sz(arr) == 0;
	}

	int size(){
		return sz(arr);
	}

	void print(){
		for(auto x : arr){
			cout << x.first << " ";
		}
		cout << endl;
	}
};

Heap MinHeap, MaxHeap;

void solve(){

	int n, k;

	cin >> n >> k;
	vt<int> arr(n);

	rep(i, 0, k-1){
		cin >> arr[i];	
		if(MinHeap.empty() && MaxHeap.empty()){
			MinHeap.push(ii(arr[i],i));

		}else if (!MinHeap.empty() && MaxHeap.empty()){
			ii temp = MinHeap.Max();
			if(arr[i] >= temp.first){
				MaxHeap.push(ii(arr[i],i));
			}else{
				MaxHeap.push(temp);
				MinHeap.pop(temp);
				MinHeap.push(ii(arr[i], i));
			}

		}else{

			if(MinHeap.size() == MaxHeap.size()){
				ii temp = MaxHeap.Min();
				if(arr[i] >= temp.first){
					MinHeap.push(temp);
					MaxHeap.pop(temp);
					MaxHeap.push( ii(arr[i], i) );
				}else{
					MinHeap.push( ii(arr[i], i) );	
				}
			}else{
				ii temp = MinHeap.Max();
				if(arr[i] >= temp.first)
					MaxHeap.push( ii(arr[i], i) );
				else{
					MaxHeap.push(temp);
					MinHeap.pop(temp);
					MinHeap.push( ii(arr[i], i) );
				}
			}	

		}
	}

	rep(i, k, n-1){
		cin >> arr[i];
		ii temp = MinHeap.Max();
		cout << temp * MinHeap.size() - MinHeap.sum\
				-temp * MaxHeap.size() + MaxHeap.sum;
		break;
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
