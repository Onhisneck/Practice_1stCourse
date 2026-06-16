#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            std::cin >> triangle[i][j];
        }
    }

    // dp[i][j] — минимальная сумма пути от вершины до ячейки (i, j)
    std::vector<std::vector<int>> dp(n);
    // from[i][j] — из какого столбца пришли в ячейку (i, j)
    std::vector<std::vector<int>> from(n);

    for (int i = 0; i < n; i++) {
        dp[i].resize(i + 1, INT_MAX);
        from[i].resize(i + 1, -1);
    }

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            // В ячейку (i, j) можно попасть из (i-1, j-1) или (i-1, j)
            if (j > 0 && dp[i - 1][j - 1] != INT_MAX) {
                int candidate = dp[i - 1][j - 1] + triangle[i][j];
                if (candidate < dp[i][j]) {
                    dp[i][j] = candidate;
                    from[i][j] = j - 1;
                }
            }
            if (j < i && dp[i - 1][j] != INT_MAX) {
                int candidate = dp[i - 1][j] + triangle[i][j];
                if (candidate < dp[i][j]) {
                    dp[i][j] = candidate;
                    from[i][j] = j;
                }
            }
        }
    }

    // Найти минимум в последней строке
    int minSum = INT_MAX;
    int endCol = -1;
    for (int j = 0; j < n; j++) {
        if (dp[n - 1][j] < minSum) {
            minSum = dp[n - 1][j];
            endCol = j;
        }
    }

    // Восстановить путь
    std::vector<int> path;
    int col = endCol;
    for (int row = n - 1; row >= 0; row--) {
        path.push_back(triangle[row][col]);
        if (row > 0) {
            col = from[row][col];
        }
    }

    std::reverse(path.begin(), path.end());

    // Вывод результата
    std::cout << minSum << std::endl;
    for (int i = 0; i < (int)path.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << path[i];
    }
    std::cout << std::endl;

    return 0;
}
