#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <utility>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char const *argv[])
{
	int r=atoi(argv[1]);
	srand(r);

	int n = 1+(r-1)*20; cout << n << "\n";
	vector<int> a(n, 0);
	for (int i = 0; i <= n - 1; i++) cout << (a[i] = rand(1, 1e9)) << " ";
	cout << "\n";

	int q = (20 * n) / 100; cout << q << "\n";

	while (q--) {
		int type = rand(1, 2); cout << type << " ";

		if (type == 1) {
			int l = rand(0, (n-1) /16);
			int r = rand((15*(n-1))/16, n - 1);
			cout << l << " " << r << "\n";
		}
		else {
			int i = rand(0, n - 1);
			int v = rand(max(1, (15 * a[i]) / 16), a[i]);
			a[i] = v;
			cout << i << " " << v << "\n";
		}
	}
	return 0;
}