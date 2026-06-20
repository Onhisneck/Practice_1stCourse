#include <iostream>
#include <vector>
#include <climits>

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::vector<int>> matrix(h, std::vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int minRow = INT_MAX, maxRow = INT_MIN;
    int minCol = INT_MAX, maxCol = INT_MIN;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (matrix[i][j] == 1) {
                minRow = std::min(minRow, i);
                maxRow = std::max(maxRow, i);
                minCol = std::min(minCol, j);
                maxCol = std::max(maxCol, j);
            }
        }
    }

    int top = minRow - 1;
    int left = minCol - 1;
    int bottom = maxRow + 1;
    int right = maxCol + 1;

    std::cout << top << " " << left << " " << bottom << " " << right << std::endl;

    return 0;
}
