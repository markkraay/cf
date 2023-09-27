#include <vector>
#include <iostream>
#include <cstring>
#include <unordered_set>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
	char a;
	char b;
	int w;
};

int cost[26][26];
bool vis[26];
void solution(string const& s1, string const& s2, vector<Edge> const&& edges) {
	if (s1.size() != s2.size()) {
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) cost[i][j] = i == j ? 0 : 1e9;
	for (const auto& e : edges) {
		cost[e.a - 'a'][e.b - 'a'] = min(e.w, cost[e.a - 'a'][e.b - 'a']);
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k < 26; k++) {
				cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
			}
		}
	}
	int res = 0;
	string result;
	for (int i = 0; i < s1.size(); i++) {
		int cost_to_convert = 1e9;
		int convert_char = -1;
		for (int j = 0; j < 26; j++) {
			int current_cost = cost[s1[i]-'a'][j] + cost[s2[i]-'a'][j];
			if (current_cost < cost_to_convert) {
				cost_to_convert = current_cost;
				convert_char = j;
			}
		}
		if (convert_char == -1) {
			cout << -1 << endl;
			return;
		}
		result.push_back(convert_char + 'a');
		res += cost_to_convert;
	}
	cout << res << endl << result << endl;
}

void test() {
	solution("uayd", "uxxd", {
		{'a', 'x', 8},
		{'x', 'y', 13},
		{'d', 'c', 3},
	});
	solution("a", "b", {
		{'a', 'b', 2},
		{'a', 'b', 2},
		{'b', 'a', 5},
	});
}

int main() {
	string s1, s2;
	int n, w;
	char a, b;
	cin >> s1;
	cin >> s2;
	cin >> n;
	vector<Edge> edges;
	while (n--) {
		cin >> a >> b >> w;
		edges.push_back(Edge{a, b, w});
	}
	solution(s1, s2, move(edges));
}