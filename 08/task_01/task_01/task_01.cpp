#include <iostream>
#include <fstream>
#include <vector>

int main() {
    
    setlocale(LC_ALL, "Russian");

    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    int size;
    inputFile >> size;

    // Создаем матрицу из файла
    std::vector<std::vector<int>> arr (size, std::vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inputFile >> arr[i][j];
        }
    }

    // Выводим граф на консоль
    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << ": ";
        bool hasEdges = false;

        for (int j = 0; j < size; ++j) {
            if (arr[i][j] == 1) {
                if (hasEdges) {
                    std::cout << " ";
                }
                std::cout << j + 1;
                hasEdges = true;
            }
        }

        if (!hasEdges) {
            std::cout << "нет";
        }

        std::cout << std::endl;
    }

    return 0;
}