#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class MergeSort {
public:
    static void sort(std::vector<int>& arr, int l, int r, sf::RenderWindow& window, sf::RectangleShape& rectangles);

private:
    static void merge(std::vector<int>& arr, int l, int m, int r, sf::RenderWindow& window, sf::RectangleShape& rectangles);
    static void visualize(const std::vector<int>& arr, sf::RenderWindow& window, sf::RectangleShape& rectangles);
};
