#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

// Функция для получения индекса левого потомка
bool getLeftChild(int parentIndex, int& childIndex, const std::vector<int>& arr) {
    int leftChildIndex = 2 * parentIndex + 1;
    if (leftChildIndex < arr.size()) {
        childIndex = leftChildIndex;
        return true;
    }
    return false;
}

// Функция для получения индекса правого потомка
bool getRightChild(int parentIndex, int& childIndex, const std::vector<int>& arr) {
    int rightChildIndex = 2 * parentIndex + 2;
    if (rightChildIndex < arr.size()) {
        childIndex = rightChildIndex;
        return true;
    }
    return false;
}

// Функция для получения индекса родителя
bool getParent(int childIndex, int& parentIndex, const std::vector<int>& arr) {
    if (childIndex > 0) {
        parentIndex = (childIndex - 1) / 2;
        return true;
    }
    return false;
}

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
    int currentIndex = 0;
    int level = 0;
    std::cout << "Вы находитесь здесь: " << level << " root " << arr[currentIndex] << "\n";

    std::string command;
    do {
        std::cout << "Введите команду: ";
        std::cin >> command;

        if (command == "up") {
            int parentIndex;
            if (getParent(currentIndex, parentIndex, arr)) {
                level--;
                currentIndex = parentIndex;
                std::cout << "Ок\n";
            }
            else {
                std::cout << "Ошибка! Отсутствует родитель\n";
            }
        }
        else if (command == "left") {
            int leftChildIndex;
            if (getLeftChild(currentIndex, leftChildIndex, arr)) {
                level++;
                currentIndex = leftChildIndex;
                std::cout << "Ок\n";
            }
            else {
                std::cout << "Ошибка! Отсутствует левый потомок\n";
            }
        }
        else if (command == "right") {
            int rightChildIndex;
            if (getRightChild(currentIndex, rightChildIndex, arr)) {
                level++;
                currentIndex = rightChildIndex;
                std::cout << "Ок\n";
            }
            else {
                std::cout << "Ошибка! Отсутствует правый потомок\n";
            }
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Такой команды нет. Попробуйте еще раз.\n";
        }

        std::cout << "Вы находитесь здесь: " << level << " ";
        if (currentIndex == 0) {
            std::cout << "root";
        }
        else {
            int parentIndex = (currentIndex - 1) / 2;
            if (currentIndex % 2 == 0) {
                std::cout << "right(" << arr[parentIndex] << ")";
            }
            else {
                std::cout << "left(" << arr[parentIndex] << ")";
            }
        }
        std::cout << " " << arr[currentIndex] << "\n";

    } while (command != "exit");

    return 0;
}
