#include <vector>
#include <map>
#include <iostream>

using namespace std;
vector<int> getPopularityOrder(vector<vector<int>> song_preferences) {
    int n = song_preferences[0].size();
    map<int, map<int, int>> preferences;
    for (const auto& song : song_preferences) {
        for (int i = 0; i < song.size(); i++) {
            for (int j = i+1; j < song.size(); j++) {
                preferences[song[i]][song[j]]++;
            }
        }
    }
    vector<int> result = {0};
    for (int i = 1; i < n; i++) {
				int j = 0;
        for (j = 0; j < n && preferences[i.back()][i] >= n / 2; j++);
        result.insert(result.begin() + j, i);
    }
    return result;
}

int main() {
		vector<vector<int>> song_preferences = {
			{2,0,1},
			{0,2,1}, 
			{0,1,2},
			{2,1,0}
			// {0,1,3,2},
			// {0,2,3,1},
			// {1,0,3,2},
			// {2,1,0,3},
			// {0,3,1,2},
		};
		auto res = getPopularityOrder(song_preferences);
		for (int i : res) cout << i << " ";
}