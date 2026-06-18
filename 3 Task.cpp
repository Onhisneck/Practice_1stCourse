#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<long long> snow(n + 1, 0);

    for (int q = 0; q < k; q++) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int i, x;
            std::cin >> i >> x;
            snow[i] += x;
        } else {
            int u, r;
            std::cin >> u >> r;

            long long sum = 0;
            for (int i = u; i <= r; i++) {
                sum += snow[i];
            }
            std::cout << sum << std::endl;
        }
    }

    return 0;
}
