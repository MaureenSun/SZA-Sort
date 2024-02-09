#include "headersAlgos/bubbleSort.hpp"
#include "visualization.hpp" // Include the visualization header

// In BUBBLESORT.cpp
void BubbleSort::sort(std::vector<int>& arr, sf::RenderWindow& window, sf::RectangleShape& rectangles, void(*visualizeSort)(sf::RenderWindow&, const std::vector<int>&, sf::RectangleShape&)) {
    int n = arr.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
                visualizeSort(window, arr, rectangles); // Call the visualizeSort function
            }
        }
    } while (swapped);
}
