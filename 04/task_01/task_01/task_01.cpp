#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; i++)
    {
        if (i < logical_size)
        {
            std::cout << arr[i] << " ";
        }
        if (i >= logical_size)
        {
            std::cout << "_" << " ";
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    std::cout << "Введите фактичеcкий размер массива: ";
    int actual_size;
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива: ";
    int logical_size;
    std::cin >> logical_size;
    if (logical_size > actual_size)
    {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!";
        return 0;
    }
    int* arr = new int[actual_size];
    for (int i = 0; i < logical_size; i++)
    {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }
    print_dynamic_array(arr, logical_size, actual_size);
    delete arr;
    return 0;
}