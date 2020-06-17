#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;
    pair<int,int> arr[n];
    for (int i=0;i<=n-1;i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i=0;i<=n-1;i++)
    {
        cout << arr[i].first << " " << arr[i].second << endl;
    }

    return 0;
}