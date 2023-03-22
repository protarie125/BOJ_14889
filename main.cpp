#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vi isChecked;
auto mn = numeric_limits<int>::max();
void calcDiff(int n, const vvi& s) {
	auto t1 = int{ 0 };
	auto t2 = int{ 0 };
	for (auto i = 0; i < n; ++i) {
		for (auto j = i + 1; j < n; ++j) {
			if (isChecked[i] && isChecked[j]) {
				t1 += s[i][j];
				t1 += s[j][i];
			}

			if (!isChecked[i] && !isChecked[j]) {
				t2 += s[i][j];
				t2 += s[j][i];
			}
		}
	}

	const auto& diff = abs(t1 - t2);
	if (diff < mn) {
		mn = diff;
	}
}

void solve(int idx, int ct, int n, const vvi& s) {
	if (n / 2 == ct) {
		calcDiff(n, s);
		return;
	}

	for (auto i = idx; i < n; ++i) {
		if (isChecked[i]) {
			continue;
		}

		isChecked[i] = true;
		solve(i + 1, ct + 1, n, s);
		isChecked[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; cin >> n;
	auto s = vvi(n, vi(n));
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			cin >> s[i][j];
		}
	}

	isChecked = vi(n, false);
	solve(0, 0, n, s);

	cout << mn;

	return 0;
}