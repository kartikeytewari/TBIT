// input/output is given on 0-indexed reference
// internal tree structure is based on 1-index reference

#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> left_tree;
vector<int> right_tree;

void update_left (int index, int val)
{
    int n=(sizeof(arr)/sizeof(arr[0]))-1;
    while (index<=n)
    {
        left_tree[index]=min(left_tree[index],val);
        index=index+(index&(-index));
    }
    return;
}

void update_right (int index, int val)
{
    while (index>=1)
    {
        right_tree[index]=min(right_tree[index],val);
        index=index-(index&(-index));
    }
    return;
}

int __min(int l, int r)
{
    int ans=INT_MAX;
    // get values of right tree by climbing left tree
    int index=l;
    while (index<=r)
    {
        int father_node=index+(index&(-index));
        if (father_node<=r)
        {
            ans=min(ans,right_tree[index]);
        }       
        index=father_node;
    }

    // get values of left tree by climbing right tree
    index=r;
    int splitter;
    while (index>=l)
    {
        int father_node=index-(index&(-index));
        if (father_node>=l)
        {
            ans=min(ans,left_tree[index]);
        }
        else
        {
            splitter=index;
        }
        index=father_node;
    }
 
    ans=min(ans,arr[splitter]);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    arr.resize(n+1,INT_MAX);
    left_tree.resize(n+1,INT_MAX);
    right_tree.resize(n+1,INT_MAX);

    for (int i=1;i<=n;i++)
    {
        cin >> arr[i];
        update_left(i,arr[i]);
        update_right(i,arr[i]);
    }

    int q;
    cin >> q;
    for (int i=0;i<=q-1;i++)
    {
        int type;
        cin >> type;
        if (type==1)
        {
            // query
            int l,r;
            cin >> l >> r;
            l++;
            r++;
            cout << __min(l,r) << endl;
        }
        else
        {
            // update
            int index,val;
            cin >> index >> val;
            index++;
            if (val>arr[index])
            {
                cout << "Invalid update process terminating" << endl;
                return 0;
            }
            arr[index]=val;
            update_left(index,val);
            update_right(index,val);
        }
    }
    return 0;
}