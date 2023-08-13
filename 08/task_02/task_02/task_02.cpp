#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

// Функция для чтения матрицы из файла
std::vector<std::vector<int>> ArrFromFile() {
    
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл." << std::endl;
        exit(1);
    }
    
    int size;
    inputFile >> size;

    std::vector<std::vector<int>> arr(size, std::vector<int>(size, 0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inputFile >> arr[i][j];
        }
    }

    return arr;
}

// Рекурсивная функция для выполнения обхода в глубину
void dfs(const std::vector<std::vector<int>>& arr, int vertex, std::vector<bool>& visited, std::stack<int>& resultStack) {
    visited[vertex] = true;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[vertex][i] == 1 && !visited[i]) {
            dfs(arr, i, visited, resultStack);
        }
    }
    resultStack.push(vertex);
}

// Функция для выполнения топологической сортировки
std::vector<int> topologicalSort(const std::vector<std::vector<int>>& arr) {
    int size = arr.size();
    std::vector<bool> visited(size, false);
    std::stack<int> resultStack;

    for (int i = 0; i < size; ++i) {
        if (!visited[i]) {
            dfs(arr, i, visited, resultStack);
        }
    }

    std::vector<int> result;
    while (!resultStack.empty()) {
        result.push_back(resultStack.top());
        resultStack.pop();
    }

    return result;
}

int main() {
    
    setlocale(LC_ALL, "Russian");
    
    std::vector<std::vector<int>> adjacencyArray = ArrFromFile();

    std::vector<int> sortedVertices = topologicalSort(adjacencyArray);

    std::cout << "Топологический порядок вершин:";
    for (int vertex : sortedVertices) {
        std::cout << " " << (vertex + 1);
    }
    std::cout << std::endl;

    return 0;
}
