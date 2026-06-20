#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string s;
    std::cin >> s;

    bool valid = true;

    // Проверяем длину
    if (s.length() != 6) {
        valid = false;
    } else {
        // Позиция 0: заглавная буква
        if (!std::isupper(s[0])) valid = false;

        // Позиции 1, 2, 3: цифры
        if (!std::isdigit(s[1])) valid = false;
        if (!std::isdigit(s[2])) valid = false;
        if (!std::isdigit(s[3])) valid = false;

        // Позиции 4, 5: заглавные буквы
        if (!std::isupper(s[4])) valid = false;
        if (!std::isupper(s[5])) valid = false;
    }

    std::cout << (valid ? "Yes" : "No") << std::endl;

    return 0;
}eturn 0;
}
