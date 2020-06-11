// input/output is given on 0-indexed reference
// Internal structure is also 0-indexed reference

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<=n-1;i++)
    {
        cin >> arr[i];
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

            int ans=INT_MAX;
            for (int j=l;j<=r;j++)
            {
                ans=min(ans,arr[j]);
            }
            cout << ans << endl;
        }
        else
        {
            // update
            int index,val;
            cin >> index >> val;
            arr[index]=val;
        }
    }

    return 0;
}