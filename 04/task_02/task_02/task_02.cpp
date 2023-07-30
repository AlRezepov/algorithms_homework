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
    std::cout << std::endl;
}

void append_to_dynamic_array (int* arr, int& logical_size, int& actual_size) {
    int new_element = 1;
    int* arr_02;
    while (true)
    {
        std::cout << "Введите элемент для добавления (введите 0 для завершения): ";
        std::cin >> new_element;
        if (new_element == 0)
        {
            break;
        }
        if (logical_size < actual_size)
        {
            arr[logical_size] = new_element;
            ++logical_size;
            print_dynamic_array(arr, logical_size, actual_size);
        }
        else if (logical_size == actual_size)
        {
            arr_02 = new int[actual_size * 2];
            actual_size *= 2;
            for (int i = 0; i < logical_size; i++)
            {
                arr_02[i] = arr[i];
            }
            delete[] arr;
            arr = arr_02;
            arr[logical_size] = new_element;
            ++logical_size;
            print_dynamic_array(arr, logical_size, actual_size);
        }
    }
    std::cout << "Спасибо! Ваш ";
    print_dynamic_array(arr, logical_size, actual_size);
    delete[] arr;
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
    append_to_dynamic_array(arr, logical_size, actual_size);
    return 0;
}