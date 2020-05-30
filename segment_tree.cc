#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

vector<long long> a;
vector<long long> tree;
vector<long long> lazy;

long long merge(long long a, long long b) {
	return min(a, b);
}

void push(int l, int r, int ind) {
	if (lazy[ind] != 0) {
		tree[ind] += lazy[ind];

		if (l != r) {
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] += lazy[ind];
		}
		else a[l] = tree[ind];

		lazy[ind] = 0;
	}
}

void build(int l, int r, int ind) {
	if (l == r) {
		tree[ind] = a[l];
		return;
	}

	int mid((l + r) >> 1);
	build(l, mid, 2 * ind);
	build(mid + 1, r, 2 * ind + 1);
	tree[ind] = merge(tree[2 * ind], tree[2 * ind + 1]);
}

void update(int ul, int ur, long long uv, int l, int r, int ind) {
	push(l, r, ind);

	if (ur < l or r < ul) return;

	if (ul <= l and r <= ur) {
		lazy[ind] += uv;
		push(l, r, ind);
		return;
	}

	int mid((l + r) >> 1);
	update(ul, ur, uv, l, mid, 2 * ind);
	update(ul, ur, uv, mid + 1, r, 2 * ind + 1);
	tree[ind] = merge(tree[2 * ind], tree[2 * ind + 1]);
}

int query(int ql, int qr, int l, int r, int ind) {
	push(l, r, ind);

	if (qr < l or r < ql) return INT_MAX;

	if (ql <= l and r <= qr) return tree[ind];

	int mid((l + r) >> 1);
	return merge(query(ql, qr, l, mid, 2 * ind), query(ql, qr, mid + 1, r, 2 * ind + 1));
}

int main() {

	int n, q; cin >> n >> q;
	a.resize(n, 0);
	tree.resize(4 * n + 1, 0);
	lazy.resize(4 * n + 1, 0);

	for (int i = 0; i <= n - 1; i++) cin >> a[i];

	build(0, n - 1, 1);

	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int l, r, inc; cin >> l >> r >> inc;
			update(l, r, inc, 0, n - 1, 1);
		}
		else {
			int l, r; cin >> l >> r;
			cout << query(l, r, 0, n - 1, 1) << "\n";
		}
	}

	return 0;
}
