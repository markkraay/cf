#include <vector>
#include <utility>
#include <functional>
#include <iostream>
#include <algorithm>

using namespace std;
using ull = unsigned long long;
using v = vector<ull>;

ull calculateDistance(v&& distances, size_t k) {
	if (distances.empty()) return 0;
	sort(distances.rbegin(), distances.rend());
	ull distance = 0;
	for (auto i = 0; i < distances.size(); i += k) {
		distance += 2 * distances[i];
	}
	return distance;
}

ull calculateDistance(v&& l, v&& r, size_t k) {
	auto l_distance = calculateDistance(forward<v>(l), k);
	auto r_distance = calculateDistance(forward<v>(r), k);
	auto l_first = l.empty() ? numeric_limits<ull>::min() : l[0];
	auto r_first = r.empty() ? numeric_limits<ull>::min() : r[0];
	return l_distance + r_distance - max(l_first, r_first);
}

void test() {
	// cout << calculateDistance({}, {1,2,3,4,5}, 1) << endl;
	// cout << calculateDistance({5,10,15}, {6,5,8,3,7,4}, 3) << endl;
	// cout << calculateDistance({}, {2,2,3,3,3}, 3) << endl;
	// cout << calculateDistance({}, {1000000000,1000000000,1000000000,1000000000}, 2) << endl;
}

int main() {
	ull t,n;
	int tmp;
	size_t k;
	cin >> t;
	while (t) {
		t--;
		cin >> n >> k;
		v right_distances;
		v left_distances;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			if (tmp < 0) left_distances.push_back(-tmp);
			else right_distances.push_back(tmp);
		}
		auto distance = calculateDistance(move(left_distances), move(right_distances), k);
		cout << distance << endl;
	}
}