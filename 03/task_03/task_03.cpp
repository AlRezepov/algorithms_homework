#include <iostream>
#include <vector>

void counting_sort(std::vector<int>& arr) {
    int max_val = *std::max_element(arr.begin(), arr.end());
    int min_val = *std::min_element(arr.begin(), arr.end());

    int range = max_val - min_val + 1;

    std::vector<int> count(range, 0);

    for (int num : arr) {
        count[num - min_val]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    std::vector<int> output(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }
    arr = output;
}

void print(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << ", ";
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");


    std::vector <int> arr_01 = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    std::vector <int> arr_02 = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
    std::vector <int> arr_03 = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };
    std::cout << "Исходный массив_01: ";
    print(arr_01);
    counting_sort(arr_01);
    std::cout << std::endl;
    std::cout << "Отсортированный массив_01: ";
    print(arr_01);
    std::cout << std::endl;
    std::cout << "Исходный массив_02: ";
    print(arr_02);
    counting_sort(arr_02);
    std::cout << std::endl;
    std::cout << "Отсортированный массив_02: ";
    print(arr_02);
    std::cout << std::endl;
    std::cout << "Исходный массив_03: ";
    print(arr_03);
    counting_sort(arr_03);
    std::cout << std::endl;
    std::cout << "Отсортированный массив_03: ";
    print(arr_03);
    std::cout << std::endl;
    return 0;
}