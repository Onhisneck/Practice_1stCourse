#include <iostream>

int main() {
    int n;
    std::cin >> n;

    for (int q = 0; q < n; q++) {
        long long a, b, x, y;
        std::cin >> a >> b >> x >> y;

       
        long long pairsB = std::min(b, x);
        long long remainingX = x - pairsB;
        long long pairsA = std::min(a, remainingX + y);

        long long total = pairsB + pairsA;

        std::cout << total << std::endl;
    }

    return 0;
}
