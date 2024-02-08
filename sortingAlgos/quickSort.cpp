#include <thread>  // For std::this_thread::sleep_for
#include <chrono>  // For std::chrono::milliseconds
#include "headersAlgos/quickSort.hpp"

void QuickSort::sort(std::vector<int>& arr, int low, int high, sf::RenderWindow& window, sf::RectangleShape& rectangles) {
    if (low < high) {
        int pi = partition(arr, low, high, window, rectangles);
        sort(arr, low, pi - 1, window, rectangles);
        sort(arr, pi + 1, high, window, rectangles);
    }
}

int QuickSort::partition(std::vector<int>& arr, int low, int high, sf::RenderWindow& window, sf::RectangleShape& rectangles) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
            visualize(arr, window, rectangles);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    visualize(arr, window, rectangles);
    return i + 1;
}

void QuickSort::visualize(const std::vector<int>& arr, sf::RenderWindow& window, sf::RectangleShape& rectangles) {
    window.clear(sf::Color::White);
    for (size_t i = 0; i < arr.size(); ++i) {
        rectangles.setPosition(i * 10, 600 - arr[i]);
        window.draw(rectangles);
    }
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}
