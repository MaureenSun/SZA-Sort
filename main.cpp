#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "bubbleSort.h"
#include "mergeSort.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sort Visualization");

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100, 600);

    std::vector<int> data;
    for (int i = 0; i < 80; ++i) {
        data.push_back(dis(gen));
    }

    sf::RectangleShape rectangles(sf::Vector2
