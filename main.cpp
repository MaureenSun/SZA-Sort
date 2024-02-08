#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "headersAlgos/bubbleSort.hpp"
#include "headersAlgos/mergeSort.hpp"
#include "headersAlgos/quickSort.hpp"


void displayArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    // Get array input from the user
    std::cout << "Enter the array elements separated by spaces (e.g., 5 2 8 1): ";
    std::vector<int> data;
    int num;
    while (std::cin >> num) {
        data.push_back(num);
    }

    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sort Visualization");
    sf::RectangleShape rectangles(sf::Vector2f(10, 0));

    // Display the initial array
    displayArray(data);

    // Choose sorting algorithm
    std::cout << "Choose sorting algorithm:\n";
    std::cout << "1. Bubble Sort\n";
    std::cout << "2. Merge Sort\n";
    std::cout << "3. Quick Sort\n";
    int choice;
    std::cin >> choice;

    // Perform sorting based on user's choice
    switch (choice) {
        case 1:
            BubbleSort::sort(data, window, rectangles);
            break;
        case 2:
            MergeSort::sort(data, 0, data.size() - 1, window, rectangles);
            break;
        case 3:
            QuickSort::sort(data, 0, data.size() - 1, window, rectangles);
            break;
        default:
            std::cout << "Invalid choice.\n";
            return 1;
    }

    // Display the sorted array
    displayArray(data);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
