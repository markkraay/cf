#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

bool valid(vector<ll>&& prefix_sums, int n) {
	int k = prefix_sums.size();
	if (k == 1) return true;
	vector<ll> v(n);
	int j = n - 1;
	for (int i = k - 1; i >= 1; i--, j--) { // First check if the prefix sums are weakly increasing
		v[j] = prefix_sums[i] - prefix_sums[i-1];
	}
	while (j >= 0) {
		v[j] = v[j+1];
		prefix_sums[0] -= v[j];
		j--;
	}
	v[0] += prefix_sums[0];
	return is_sorted(v.begin(), v.end());
}

void test() {
	cout << (valid({1,2,3,4,5}, 5) ? "YES" : "NO") << endl;
	cout << (valid({-6,-5,-3,0}, 7) ? "YES" : "NO") << endl;
	cout << (valid({2,3,4}, 3) ? "YES" : "NO") << endl;
	cout << (valid({3,4}, 3) ? "YES" : "NO") << endl;
}

int main() {
	ll t,n,k,tmp;
	cin >> t;
	while (t) {
		cin >> n >> k;
		vector<ll> prefix_sums(k,0);
		for (int i = 0; i < k; i++) {
			cin >> prefix_sums[i];
		}
		cout << (valid(move(prefix_sums), n) ? "YES" : "NO") << endl;
		t--;
	}
}