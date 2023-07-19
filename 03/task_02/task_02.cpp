#include <iostream>
#include <vector>

void quick_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = arr[left];

        int i = left, j = right;
        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        quick_sort(arr, left, j);
        quick_sort(arr, i, right);
    }
}

void print(std::vector<int>& arr, int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ", ";
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");


    int size_01 = 10;
    std::vector <int> arr_01 = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size_02 = 15;
    std::vector <int> arr_02 = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int size_03 = 18;
    std::vector <int> arr_03 = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    std::cout << "Исходный массив_01: ";
    print(arr_01, size_01);
    quick_sort(arr_01, 0, size_01 - 1);
    std::cout << std::endl;
    std::cout << "Отсортированный массив_01: ";
    print(arr_01, size_01);
    std::cout << std::endl;
    std::cout << "Исходный массив_02: ";
    print(arr_02, size_02);
    quick_sort(arr_02, 0, size_02 - 1);
    std::cout << std::endl;
    std::cout << "Отсортированный массив_02: ";
    print(arr_02, size_02);
    std::cout << std::endl;
    std::cout << "Исходный массив_03: ";
    print(arr_03, size_03);
    quick_sort(arr_03, 0, size_03 - 1);
    std::cout << std::endl;
    std::cout << "Отсортированный массив_03: ";
    print(arr_03, size_03);
    std::cout << std::endl;
    return 0;
}