#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class QuickSort {
public:
    static void sort(std::vector<int>& arr, int low, int high, sf::RenderWindow& window, sf::RectangleShape& rectangles);

private:
    static int partition(std::vector<int>& arr, int low, int high, sf::RenderWindow& window, sf::RectangleShape& rectangles);
    static void visualize(const std::vector<int>& arr, sf::RenderWindow& window, sf::RectangleShape& rectangles);
};
