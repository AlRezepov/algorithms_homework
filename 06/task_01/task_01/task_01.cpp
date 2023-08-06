#include <iostream>
#include <string>

int simple_string_hash(const std::string& s) {
    int hash = 0;
    for (char c : s) {
        hash += static_cast<int>(c);
    }
    return hash;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    std::string text;
    do {
        std::cout << "Введите строку: ";
        std::getline(std::cin, text);
        if (text == "exit") {
            break;
        }
        int hash = simple_string_hash(text);
        std::cout << "Наивный хэш строки " << text << " = " << hash << std::endl;
    } while (true);

    int exitHash = simple_string_hash("exit");
    std::cout << "Наивный хэш строки exit = " << exitHash << std::endl;

    return 0;
}