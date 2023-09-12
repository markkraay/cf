#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int lines, n, tmp;
    cin >> lines;
    while (lines) {
        cin >> n;
        int max1, max2, min1, min2;
        max1 = max2 = numeric_limits<int>::min();
        min1 = min2 = numeric_limits<int>::max();
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (tmp >= max1) {
                max2 = max1;
                max1 = tmp;
            } else if (tmp > max2) max2 = tmp;
            if (tmp <= min1) {
                min2 = min1;
                min1 = tmp;
            } else if (tmp < min2) min2 = tmp;
        }
        printf("%d\n", max1 + max2 - min1 - min2);
        lines--;
    }
}
