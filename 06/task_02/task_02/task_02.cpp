#include <iostream>
#include <string>
#include <cmath>

int real_string_hash(const std::string& s, int p, int n) {
    uint64_t hash = 0;
    for (int i = 0; i < s.length(); ++i) {
        hash += static_cast<int>(s[i]) * static_cast<int>(std::pow(p, i));
    }
    return hash % n;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int p, n;
    std::string text;
    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;

    std::cin.ignore();
    
    do {
        std::cout << "Введите строку: ";
        std::getline(std::cin, text);

        if (text == "exit") {
            break;
        }

        int hash = real_string_hash(text, p, n);
        std::cout << "Хэш строки " << text << " = " << hash << std::endl;
    } while (true);

    int exitHash = real_string_hash("exit", p, n);
    std::cout << "Хэш строки exit = " << exitHash << std::endl;

    return 0;
}
