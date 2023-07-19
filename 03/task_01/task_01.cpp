#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int middle, int right) {
    int size_left = middle - left + 1;
    int size_right = right - middle;

    std::vector<int> temp_left(size_left);
    std::vector<int> temp_right(size_right);

    for (int i = 0; i < size_left; i++) {
        temp_left[i] = arr[left + i];
    }
    for (int j = 0; j < size_right; j++) {
        temp_right[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < size_left && j < size_right) {
        if (temp_left[i] <= temp_right[j]) {
            arr[k] = temp_left[i];
            i++;
        }
        else {
            arr[k] = temp_right[j];
            j++;
        }
        k++;
    }

    while (i < size_left) {
        arr[k] = temp_left[i];
        i++;
        k++;
    }
    while (j < size_right) {
        arr[k] = temp_right[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
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
    merge_sort(arr_01, 0, size_01 - 1);
    std::cout << std::endl;
    std::cout << "Отсортированный массив_01: ";
    print(arr_01, size_01);
    std::cout << std::endl;
    std::cout << "Исходный массив_02: ";
    print(arr_02, size_02);
    merge_sort(arr_02, 0, size_02 - 1);
    std::cout << std::endl;
    std::cout << "Отсортированный массив_02: ";
    print(arr_02, size_02);
    std::cout << std::endl;
    std::cout << "Исходный массив_03: ";
    print(arr_03, size_03);
    merge_sort(arr_03, 0, size_03 - 1);
    std::cout << std::endl;
    std::cout << "Отсортированный массив_03: ";
    print(arr_03, size_03);
    std::cout << std::endl;
    return 0;
}