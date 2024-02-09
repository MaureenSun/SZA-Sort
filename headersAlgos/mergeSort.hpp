#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>  
#include <chrono>  

class MergeSort {
public:
    static void sort(std::vector<int>& arr, int l, int r, sf::RenderWindow& window, sf::RectangleShape& rectangles, void(*visualizeSort)(sf::RenderWindow&, const std::vector<int>&, sf::RectangleShape&));

private:
    static void merge(std::vector<int>& arr, int l, int m, int r, sf::RenderWindow& window, sf::RectangleShape& rectangles, void(*visualizeSort)(sf::RenderWindow&, const std::vector<int>&, sf::RectangleShape&));
};
