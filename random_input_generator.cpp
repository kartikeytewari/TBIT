// This file generates random test cases
// using the time(NULL) variable of UNIX style OS
// Running it at diffrent times will create diffrent
// results because of the dynamic seed value

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max_range 100000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    ll n,q;
    // n is the number of data polls
    // q is the number of queries
    cin >> n >> q;

    
    srand(time(NULL));
    // generating random data polls
    cout << n << endl;
    for (ll i=0;i<=n-1;i++)
    {
        ll temp=(rand()%max_range)+1;
        cout << temp << " ";
    }
    cout << endl;


    cout << q << endl;
    // genrerating queries
    // id=1 implies update query
    // id=2 implies range query
    // l and r are 0-indexed
    for (ll i=0;i<=q-1;i++)
    {
        ll id=(rand()%2)+1;

        if (id==1)
        {
            ll l=(rand()%n);
            ll r=(rand()%n);
            // new_val is the new val of data point from indices l to r
            ll new_val=(rand()%max_range)+1;
            cout << id << " " << min(l,r) << " " << max(l,r) << " " << new_val << endl;   
        }
        else
        {
            ll l=(rand()%n);
            ll r=(rand()%n);
            cout << id << " " << min(l,r) << " " << max(l,r) << endl;
        }
    }

    return 0;
}