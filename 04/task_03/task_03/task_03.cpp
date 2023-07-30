#include <iostream>
#include <string>

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

void remove_to_dynamic_array(int* arr, int& logical_size, int& actual_size) {
    std::string answer;
    int* arr_02;
    while (true) {
        std::string answer;
        std::cout << "Удалить первый элемент? (Введите \"yes\" или \"no\"): ";
        std::cin >> answer;

        if (answer == "no") {
            break;
        }

        if (logical_size == 0) {
            std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!";
            break;
        }
        
        if (logical_size > actual_size / 3) {
            --logical_size;
            for (int i = 0; i < logical_size; i++) {
                arr[i] = arr[i + 1];
            }
            print_dynamic_array(arr, logical_size, actual_size);
        }
        else if (logical_size - 1 <= actual_size / 3) {
            arr_02 = new int[actual_size / 3];
            actual_size /= 3;
            --logical_size;
            for (int i = 0; i < logical_size; i++) {
                arr_02[i] = arr[i + 1];
            }
            delete[] arr;
            arr = arr_02;
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
    remove_to_dynamic_array(arr, logical_size, actual_size);
    return 0;
}