#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> answers;

    for (int q = 0; q < n; q++) {
        long long a, b, x, y;
        std::cin >> a >> b >> x >> y;


        long long pairsB = std::min(b, x);

        long long remainingX = x - pairsB;
        long long pairsA = std::min(a, remainingX + y);

        answers.push_back(pairsB + pairsA);
    }

    // Выводим все ответы в одну строку через пробел
    for (int i = 0; i < (int)answers.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << answers[i];
    }
    std::cout << std::endl;

    return 0;
}
