// input/output is given on 0-indexed reference
// internal tree structure of segment tree is 1-indexed reference
// and array is 0-indexed
#include <vector>
#include <iostream>
#include <climits>
using namespace std;


// ===============================================
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
 
template<typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{'; __print(x.first);
    cerr << ','; __print(x.second);
    cerr << '}';
}
 
template<typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
 
void _print()
{
    cerr << "]\n";
}
 
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", "; _print(v...);
}
 
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// ===============================================

int n, q;
vector<int> arr;
vector<int> tree;

void build (int start = 0, int end = n - 1, int node = 1)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    build(start, mid, 2 * node);
    build(mid + 1, end, 2 * node + 1);
    tree[node] = min(tree[2 * node] , tree[2 * node + 1]);

    return;
}

void update (int index, int val, int start=0, int end=n-1, int node=1)
{
    if (start==end)
    {
        arr[start]=val;
        tree[node]=val;
    }
    else
    {
        int mid=(start+end)/2;
        if (start<=index and index<=mid)
        {
            update(index,val,start,mid,2*node);
        }
        else
        {
            update(index,val,mid+1,end,2*node+1);
        }
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
    return;
}

int __min (int l, int r, int start = 0, int end = n - 1, int node = 1)
{
    if (r < start or end < l)
    {
        return INT_MAX;
    }

    if (l <= start and end <= r)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return min(__min(l, r, start, mid, 2 * node), __min(l, r, mid + 1, end, 2 * node + 1));
}

int main()
{
    cin >> n;

    arr.resize(n, 0);
    tree.resize(4 * n, 0);

    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr[i];
    }

    build();

    cin >> q;
    for (int i = 0; i <= q - 1; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            // query
            int l, r;
            cin >> l >> r;
            cout << __min(l, r, 0, n - 1, 1) << endl;
        }
        else
        {
            // update
            int index, val;
            cin >> index >> val;
            update(index, val);
            debug(tree);
        }
    }

    return 0;
}