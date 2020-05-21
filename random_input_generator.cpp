#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

long long rand(long long a, long long b) {
	return a + rand() % (b - a + 1);
}

int main(int argc, char const *argv[])
{
	srand(atoi(argv[1]));

	int n = rand(2, 20), q = rand(1, 20);
	cout << n << " " << q << endl;

	for (int i = 0; i <= n - 1; i++) cout << rand(1, 100) << " ";
	cout << endl;

	while (q--) {
		int type = rand(1, 2); cout << type << " ";

		if (type == 1) {
			int l = rand(0, n - 2), r = rand(l, n - 1), inc = rand(1, 100);
			cout << l << " " << r << " " << inc << endl;
		}
		else {
			int l = rand(0, n - 2), r = rand(l, n - 1);
			cout << l << " " << r << endl;
		}
	}
	return 0;
}
