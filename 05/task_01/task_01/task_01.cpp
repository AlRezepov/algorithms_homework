#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>


void print_pyramid(int size, std::vector <int>& arr) {
    std::cout << "Пирамида:\n";
    for (int i = 0; i < arr.size() / 2; i++) {
        //Корень пирамиды
        if (i == 0)
        {
            std::cout << "Level: " << i << " root " << arr[0] << "\n";
        }
        //Создание и инициализация вектора для хранения информации об уровнях пирамиды
        std::vector <int> level;
        int j = 0;
        while (j < std::sqrt(size))
        {
            for (int k = 0; k < std::pow(2, j); k++)
            {
                if (k < size)
                {
                    level.push_back(j + 1);
                }
            }
            j++;
        }
        //Проверка на выход за пределы вектора
        if (2 * i + 1 == arr.size() - 1) {
            std::cout << "Level: " << level[i] << " left " << "(" << arr[i] << ")" << " = " << arr[2 * i + 1] << "\n";
            break;
        }
        //Построение пирамиды
        std::cout << "Level: " << level[i] << " left " << "(" << arr[i] << ")" << " = " << arr[2 * i + 1] << "\n";
        std::cout << "Level: " << level[i] << " right " << "(" << arr[i] << ")" << " = " << arr[2 * i + 2] << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::srand(std::time(0));

    // Рандомно выбирается размер вектора от 3 до 20
    int size = 3 + rand() % 18;

    // Создание вектора   
    std::vector <int> arr(size);

    // Заполнение вектора случайными числами от 0 до 99 и его вывод в консоль
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Запуск функции вывода пирамиды в консоль
    print_pyramid(size, arr);
    return 0;
}