#include <iostream>
#include <vector>
#include <limits>
#include <array>
#include <unordered_map>
#include <string>

double maxP(int castings, int points, double probability, std::vector<std::array<double, 6>> const& probabilities) {
    if (points == 0) return probability;
    if (points < 0) return 0;
    if (castings <= 0) return 0;
    double max_probability = 0;
    for (std::size_t i = 0; i < probabilities.size(); i++) {
        for (std::size_t j = 0; j < 6; j++) {
            max_probability = std::max(max_probability, maxP(castings - 1, points - j, probability*probabilities[i][j], probabilities));
        }
    }
    return max_probability;
}

double championshipProbability(int pointsNeeded, int castings, const std::vector<std::array<double, 6>> &probabilities) {
    return maxP(castings, pointsNeeded, 1.0, probabilities);
}

int main() {
	std::vector<std::array<double, 6>> ps = {
		{0.1,0.1,0.2,0.2,0.3,0.1},
		{0.0,0.3,0.15,0.45,0.1,0.0},
		{0.4,0.1,0.1,0.1,0.1,0.2}
	};
	std::cout << championshipProbability(8, 2, ps) << std::endl;
}