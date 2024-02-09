#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "headersAlgos/bubbleSort.hpp"
#include "headersAlgos/mergeSort.hpp"
#include "headersAlgos/quickSort.hpp"

// Function to display the array in the console
void displayArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

// Function to visualize the sorting process using SFML
void visualizeSort(sf::RenderWindow& window, const std::vector<int>& arr, sf::RectangleShape& rectangles) {
    window.clear(sf::Color::White);
    for (size_t i = 0; i < arr.size(); ++i) {
        rectangles.setPosition(i * 10, 600 - arr[i]);
        rectangles.setSize(sf::Vector2f(10, arr[i])); // Set the size of the rectangle based on the array element
        window.draw(rectangles); // Draw the rectangle
    }
    window.display(); // Display the updated window
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
    sf::RectangleShape rectangles(sf::Vector2f(10, 0)); // Rectangle shape for visualization

    // Display the initial array
    std::cout << "Initial array: ";
    displayArray(data);

    // Choose sorting algorithm
    std::cout << "Choose sorting algorithm:\n";
    std::cout << "1. Bubble Sort\n";
    std::cout << "2. Merge Sort\n";
    std::cout << "3. Quick Sort\n";
    int choice;
    std::cin >> choice;

    // Perform sorting based on the user's choice
    switch (choice) {
        case 1:
            BubbleSort::sort(data, window, rectangles, visualizeSort);
            break;
        case 2:
            MergeSort::sort(data, 0, data.size() - 1, window, rectangles, visualizeSort);
            break;
        case 3:
            QuickSort::sort(data, 0, data.size() - 1, window, rectangles, visualizeSort);
            break;
        default:
            std::cout << "Invalid choice.\n";
            return 1;
    }

    // Display the sorted array
    std::cout << "Sorted array: ";
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
