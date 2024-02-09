#include "headersAlgos/bubbleSort.hpp"
#include <thread>  
#include <chrono> 
#include <iostream> 

void BubbleSort::sort(std::vector<int>& arr, sf::RenderWindow& window, sf::RectangleShape& rectangles) {
    int n = arr.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
                visualize(arr, window, rectangles);
            }
        }
    } while (swapped);
}

void BubbleSort::visualize(const std::vector<int>& arr, sf::RenderWindow& window, sf::RectangleShape& rectangles) {
    window.clear(sf::Color::White);
    for (size_t i = 0; i < arr.size(); ++i) {
        rectangles.setPosition(i * 10, 600 - arr[i]);
        window.draw(rectangles);
    }
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}
