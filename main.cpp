#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Main loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear(sf::Color::White);

        // Draw something
        // (For now, let's just display a white window)

        // Display the window contents
        window.display();
    }

    return 0;
}
