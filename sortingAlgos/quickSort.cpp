#include "headersAlgos/quickSort.hpp"
#include "visualization.hpp" // Include the visualization header

void QuickSort::sort(std::vector<int>& arr, int low, int high, sf::RenderWindow& window, sf::RectangleShape& rectangles, void(*visualizeSort)(sf::RenderWindow&, const std::vector<int>&, sf::RectangleShape&)) {
    if (low < high) {
        int pi = partition(arr, low, high, window, rectangles);
        sort(arr, low, pi - 1, window, rectangles, visualizeSort); // Pass the function pointer without invoking it
        sort(arr, pi + 1, high, window, rectangles, visualizeSort); 
    }
}

int QuickSort::partition(std::vector<int>& arr, int low, int high, sf::RenderWindow& window, sf::RectangleShape& rectangles) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
            visualize(arr, window, rectangles); // Utilize the visualize function from visualization.hpp
        }
    }

    std::swap(arr[i + 1], arr[high]);
    visualize(arr, window, rectangles); // Utilize the visualize function from visualization.hpp
    return i + 1;
}
