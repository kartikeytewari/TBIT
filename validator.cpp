// this is a brute force approach based validator
// to check the output generated from our codebase of
// persistent segment tree and fenwick tree
// it also benchmarks the performonce of the brute force approach
// this is for the min value

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);


    // handiling data points
    // n is the total number of data polls
    // arr is the array that stores them
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i=0;i<=n-1;i++)
    {
        cin >> arr[i];
    }

    // handling queries
    // q is the total number of queries
    ll q;
    cin >> q;
    for (ll i=0;i<=q-1;i++)
    {
        ll id;
        cin >> id;

        if (id==1)
        {
            // id=1 implies update query
            ll l,r,new_val;
            cin >> l >> r >> new_val;
            for (ll j=l;j<=r;j++)
            {
                arr[j]=arr[j]+new_val;
            }
        }
        else
        {
            // id=2 implies range query
            ll l,r;
            cin >> l >> r;

            ll ans_min=LLONG_MAX;
            for (ll j=l;j<=r;j++)
            {
                ans_min=min(ans_min,arr[j]);
            }
            cout << ans_min << endl;
        }
    }

    return 0;
}
