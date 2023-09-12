#include <iostream>
#include <unordered_set>
#include <numeric>
#include <vector>

using namespace std;

using ll = unsigned long long;

void thor(vector<vector<ll>>& unread, unordered_set<ll>& seen, vector<ll>& actions, ll& a_idx, int action, ll x, ll t) {
	switch (action) {
		case 1:
			unread[x].push_back(t);
			seen.insert(t);
			actions.push_back(t);
			break;
		case 2:
			for (int timestamp : unread[x]) {
				seen.erase(timestamp);
			}
			unread[x].clear();
			break;
		case 3:
			while (a_idx < x) {
				seen.erase(actions[a_idx]);
				a_idx++;
			}
		default:
			break;
	}
	cout << seen.size() << endl;
}

void testDriver(int applications, vector<pair<int, int>> messages) {
	vector<vector<ll>> unread(applications + 1);
	unordered_set<ll> seen;
	vector<ll> actions;
	ll start_q = 0;
	for (ll i = 0; i < (ll)messages.size(); i++) {
		auto msg = messages[i];
		thor(unread, seen, actions, start_q, msg.first, msg.second, i);
	}
}

// void test() {
// 	testDriver(3, {
// 		{1, 3}, {1, 1}, {1, 2}, {2, 3}, 
// 	});
// 	cout << endl;
// 	testDriver(4, {
// 		{1,2}, {1,4}, {1,2}, {3,3}, {1,3}, {1,3}
// 	});
// 	cout << endl;
// }

int main() {
	// test();
	ll applications, t, action, x;
	cin >> applications >> t;
	vector<vector<ll>> unread(applications + 1);
	unordered_set<ll> seen;
	vector<ll> actions;
	ll start_q = 0;
	while (t) {
		cin >> action >> x;
		thor(unread, seen, actions, start_q, action, x, t);
		t--;
	}
}