#include <iostream>
#include <fstream>
#include <vector>

void depth (const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int vertex) {
    visited[vertex] = true;
    std::cout << vertex + 1 << " ";

    for (int i = 0; i < graph.size(); ++i) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            depth(graph, visited, i);
        }
    }
}

int main() {
    
    setlocale(LC_ALL, "Russian");
    
    std::ifstream inputFile("input.txt");

    int vertex;
    inputFile >> vertex;

    std::vector<std::vector<int>> graph(vertex, std::vector<int>(vertex));
    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            inputFile >> graph[i][j];
        }
    }

    std::vector<bool> visited(vertex, false);
    std::cout << "Порядок обхода вершин: ";

    for (int i = 0; i < vertex; ++i) {
        if (!visited[i]) {
            depth(graph, visited, i);
        }
    }

    return 0;
}