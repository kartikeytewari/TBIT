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

double actual(int alg, int n, int q = 0) {
	if (alg == 0) {
		return (n * q) / 1e2;
	}
	else return (alg * log2(n) * (n + q)) / 1e2;
}
vector<string> title = {"\nbrute", "\nseg_tree", "\nfen_tree"};

int main(int argc, const char* argv[]) {
	fastio();

	int a = argv[1][0] - '0';
	int r = argv[1][1] - '0';
	int n = 0, t = 0, cnt = 0;
	double avg = 0;

	while (cin >> n) {
		cin >> t;
		cnt++;

		avg += (t - actual(a, n, ((n * r * 2) / 10)));
	}
	if (r == 1) cout << title[a] << "\t";
	cout << fixed << setprecision(2);
	cout << (avg / cnt) << " ms\t";
	return 0;
}