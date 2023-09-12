#include <vector>
#include <iostream>
#include <limits>

using namespace std;
using ll = long long;

ll canDestroy(vector<ll> const& attack_times, ll k, ll h) {
	for (size_t i = 0; i < attack_times.size() - 1; i++) {
		h -= min(attack_times[i] + k, attack_times[i+1]) - attack_times[i];
	}
	h -= k;
	return h;
}

ll findMinimumK(vector<ll> && attack_times, ll h) {
	ll l = 1;
	ll r = h;
	ll k;
	ll min_diff = numeric_limits<ll>::min();
	while (l <= r) {
		ll m = (l + r) / 2;
		ll result = canDestroy(attack_times, m, h);
		if (result < 0) {
			if (result > min_diff) {
				k = m;
				min_diff = result;
			}
			r = m - 1; // We killed the monster, but overshot... try decreasing the range
		}
		else if (result > 0) l = m + 1; // We did not kill the monster, try increasing the range
		else return m; // We killed the monster with minimum k
	}
	return k;
}

void test() {
	cout << findMinimumK({1, 5}, 5) << endl;
	cout << findMinimumK({2, 4, 10}, 10) << endl;
	cout << findMinimumK({1, 2, 4, 5, 7}, 3) << endl;
	cout << findMinimumK({3, 25, 64, 1337}, 1000) << endl;
}

int main() {
	// test();
	int trials, n;
	ll h;
	cin >> trials;
	while (trials) {
		cin >> n >> h;
		vector<ll> attacks(n);
		for (int i = 0; i < n; i++) {
			cin >> attacks[i];
		}
		cout << findMinimumK(std::move(attacks), h) << endl;
		trials--;
	}
}