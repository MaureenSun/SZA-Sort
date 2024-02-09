#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <thread>

class BubbleSort {
public:
    static void sort(std::vector<int>& arr, sf::RenderWindow& window, sf::RectangleShape& rectangles, void(*visualizeSort)(sf::RenderWindow&, const std::vector<int>&, sf::RectangleShape&)) ;
// no private becaues moved visualization to general file
};
