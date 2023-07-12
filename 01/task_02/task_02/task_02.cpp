#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int search(std::vector <int>& arr, int point) {
        int left = 0;
        int right = arr.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= point) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return arr.size() - left;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector <int> arr;
    int size;
    std::cout << "Введите размер массива от 10 до 20: ";
    std::cin >> size;
    while (size < 10 || size > 20)
    {
        std::cout << "Вы ввели неверное значение. Введите размер массива от 10 до 20: ";
        std::cin >> size;
    }
    srand(time(nullptr));
    for (int i = 0; i < size-1; ++i) {
        arr.push_back(rand() % 100);
    }
    std::sort(arr.begin(), arr.end());
    std::cout << "Ваш массив: ";
    for (int i = 0; i < size-1; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    int point;
    std::cout << "Введите точку отсчета: ";
    std::cin >> point;
    std::cout << "Количество элементов в массиве больших, чем " << point << ": " << search(arr, point);
    return 0;
}