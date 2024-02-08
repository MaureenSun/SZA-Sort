#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <thread>

class BubbleSort {
public:
    static void sort(std::vector<int>& arr, sf::RenderWindow& window, sf::RectangleShape& rectangles);

private:
    static void visualize(const std::vector<int>& arr, sf::RenderWindow& window, sf::RectangleShape& rectangles);
};
