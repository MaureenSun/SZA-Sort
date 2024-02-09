#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include <chrono>

// Function to visualize the sorting process using SFML
void visualize(const std::vector<int>& arr, sf::RenderWindow& window, sf::RectangleShape& rectangles) {
    window.clear(sf::Color::White);
    for (size_t i = 0; i < arr.size(); ++i) {
        rectangles.setPosition(i * 10, 600 - arr[i]);
        window.draw(rectangles);
    }
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

#endif // VISUALIZATION_HPP
