// input/output is given on 0-indexed reference
// internal tree structure of segment tree is 1-indexed reference
// and array is 0-indexed

#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> tree;

void build (int start, int end, int node)
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

void update (int index, int val, int start, int end, int node)
{
    if (end < index and index < start)
    {
        return;
    }

    if (start <= index and index <= end)
    {
        tree[node] = min(tree[node], val);
        return;
    }

    int mid = (start + end) / 2;
    update(index, val, start, mid, 2 * node);
    update(index, val, mid + 1, end, 2 * node + 1);
    tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
    return;

}

int __min (int l, int r, int start, int end, int node)
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
    int n;
    cin >> n;

    arr.resize(n, 0);
    tree.resize(4 * n, 0);

    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr[i];
    }

    build(0, n - 1, 1);
    int q;
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
            update(index, val, 0, n - 1, 1);
        }
    }

    return 0;
}