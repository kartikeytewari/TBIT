#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}

template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";} void _print() {cerr << "]\n";}
template <typename T, typename... V>void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef HOME
#warning CHECK int:ll::INT_MAX:LLONG_MAX
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define ff first
#define endl "\n"
#define ss second
#define maxn 2000006
#define pb push_back
#define ll long long
#define lll __int128
#define vll vector<ll>
#define mll map<ll,ll>
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define pll pair<ll,ll>
#define ull unsigned long long
#define f(i,x,n) for(ll i=x;i<=n;i++)
#define fr(i,x,n) for(ll i=x;i>=n;i--)
inline ll min(ll a, ll b, ll c) { return min(min(a, b), c);}
inline ll max(ll a, ll b, ll c) { return max(max(a, b), c);}
inline void fastio() {ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);}

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};


int main(int argc, const char* argv[]) {
	fastio();

	int t = atoi(argv[1]) * 1000;
	map<int, vector<int>> freq;
	while (t--) {
		int n, tim; cin >> n >> tim;
		freq[n].push_back(tim);
	}

	cout << freq.size() << endl;
	for (auto i : freq) {
		cout << i.ff << "->";
		for (auto j : i.ss) cout << j << ", ";
		cout << endl;
	}
	cout << endl;

	return 0;
}