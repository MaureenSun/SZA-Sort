#include "headersAlgos/mergeSort.hpp"

void MergeSort::sort(std::vector<int>& arr, int l, int r, sf::RenderWindow& window, sf::RectangleShape& rectangles) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    sort(arr, l, m, window, rectangles);
    sort(arr, m + 1, r, window, rectangles);
    merge(arr, l, m, r, window, rectangles);
}

void MergeSort::merge(std::vector<int>& arr, int l, int m, int r, sf::RenderWindow& window, sf::RectangleShape& rectangles) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }

        visualize(arr, window, rectangles);
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
        visualize(arr, window, rectangles);
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
        visualize(arr, window, rectangles);
    }
}

void MergeSort::visualize(const std::vector<int>& arr, sf::RenderWindow& window, sf::RectangleShape& rectangles) {
    window.clear(sf::Color::White);
    for (size_t i = 0; i < arr.size(); ++i) {
        rectangles.setPosition(i * 10, 600 - arr[i]);
        window.draw(rectangles);
    }
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}
