#include <iostream>
#include <string>

int find_substring_rabin_karp(std::string source, std::string substring) {
    int source_length = source.length();
    int substring_length = substring.length();

    if (source_length < substring_length)
        return -1;

    const int p = 18;
    const int mod = 100000;

    int substring_hash = 0;
    int current_hash = 0;
    int p_power = 1;
    
    //Рассчет хэша
    for (int i = 0; i < substring_length; ++i) {
        p_power = (p_power * p) % mod;
        substring_hash = (substring_hash * p + substring[i]) % mod;
        current_hash = (current_hash * p + source[i]) % mod;
    }
    //Поиск подстроки в строке
    for (int i = 0; i <= source_length - substring_length; ++i) {
        if (substring_hash == current_hash) {
            bool found = true;
            for (int j = 0; j < substring_length; ++j) {
                if (source[i + j] != substring[j]) {
                    found = false;
                    break;
                }
            }
            if (found)
                return i;
        }
        //Обновление хэша 
        if (i < source_length - substring_length) {
            current_hash = (current_hash * p - source[i] * p_power + source[i + substring_length]) % mod;
            if (current_hash < 0)
                current_hash += mod;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::string source;
    std::string substring;

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::getline(std::cin, source);

    while (true) {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::getline(std::cin, substring);

        if (substring == "exit") {
            int exit_index = find_substring_rabin_karp(source, substring);
            if (exit_index != -1) {
                std::cout << "Подстрока exit найдена по индексу " << exit_index << std::endl;
            }
            else {
                std::cout << "Подстрока exit не найдена" << std::endl;
            }
            break;
        }

        int index = find_substring_rabin_karp(source, substring);
        if (index != -1) {
            std::cout << "Подстрока " << substring << " найдена по индексу " << index << std::endl;
        }
        else {
            std::cout << "Подстрока " << substring << " не найдена" << std::endl;
        }
    }

    return 0;
}
