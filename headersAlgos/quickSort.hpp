#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class QuickSort {
public:
    static void sort(std::vector<int>& arr, int low, int high, sf::RenderWindow& window, sf::RectangleShape& rectangles, void(*visualizeSort)(sf::RenderWindow&, const std::vector<int>&, sf::RectangleShape&));

private:
    static int partition(std::vector<int>& arr, int low, int high, sf::RenderWindow& window, sf::RectangleShape& rectangles);
};
