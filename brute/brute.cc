// input/output is given on 0-indexed reference
// Internal structure is also 0-indexed reference

#include <vector>
#include <iostream>
#include <iomanip>
#include <climits>
#include <time.h>
#include <cmath>
using namespace std;
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int main()
{
    clock_t z = clock();

    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr[i];
    }

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

            int ans = INT_MAX;
            for (int j = l; j <= r; j++)
            {
                ans = min(ans, arr[j]);
            }
            // cout << ans << endl;
        }
        else
        {
            // update
            int index, val;
            cin >> index >> val;
            arr[index] = val;
        }
    }
    cout << n << " " << (int)(((double)(clock() - z) / CLOCKS_PER_SEC)*1e6)<< "\n";
    return 0;
}