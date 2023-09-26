#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

void max_conseq_subsequences(vector<int> const&& nums) {
	unordered_map<int, int> seen; // Maps the start of a subsequence to the end of the subsequence
	int max_subsequence = 1;
	int start = nums[0];
	for (int i : nums) {
		if (seen.contains(i-1)) {
			int mappedValue = seen[i-1];
			if (seen.contains(i)) {
				seen[i] = min(seen[i], mappedValue);
			} else {
				seen[i] = mappedValue;
			}
			seen.erase(i-1);
			int length = i - mappedValue + 1;
			if (length > max_subsequence) {
				max_subsequence = length;
				start = mappedValue;
			}
		} else {
			seen.insert({i, i});
		}
	}
	cout << max_subsequence << endl;
	for (int i = 0; i < nums.size() && max_subsequence >= 0; i++) {
		if (nums[i] == start) {
			cout << i + 1 << " ";
			start++;
			max_subsequence--;
		}
	}
}

void test() {
	vector<int> nums = {10,9,8,7};
	// vector<int> nums = {3,3,4,7,5,6,8};
	// vector<int> nums = {6,7,8,3,4,5,9,10,11};
	// vector<int> nums = {3,3,4,7,5,6,8};
	// vector<int> nums = {3,3,4,7,5,6,8};
	vector<int> memo(nums.size(), -1);
	max_conseq_subsequences(move(nums));
}

int main() {
	int n;
	cin >> n;
	vector<int> inputs(n);
	for (int i = 0; i < n; i++) {
		cin >> inputs[i];
	}
	max_conseq_subsequences(move(inputs));
}