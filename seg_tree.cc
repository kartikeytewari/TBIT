// input/output is given on 0-indexed reference
// internal tree structure of segment tree is 1-indexed reference
// and array is 0-indexed
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

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
            cout << __min(l, r) << endl;
        }
        else
        {
            // update
            int index, val;
            cin >> index >> val;
            update(index, val);
        }
    }

    return 0;
}