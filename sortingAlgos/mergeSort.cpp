#include "headersAlgos/mergeSort.hpp"
#include "visualization.hpp" // Include the visualization header

// Function is responsible for sorting given vector 
// Recursively returns array into two halves, sorts them separately, and merges sorted halves
void MergeSort::sort(std::vector<int>& arr, int l, int r, sf::RenderWindow& window, sf::RectangleShape& rectangles, void(*visualizeSort)(sf::RenderWindow&, const std::vector<int>&, sf::RectangleShape&)) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    sort(arr, l, m, window, rectangles, visualizeSort);
    sort(arr, m + 1, r, window, rectangles, visualizeSort);
    merge(arr, l, m, r, window, rectangles, visualizeSort);
}


void MergeSort::merge(std::vector<int>& arr, int l, int m, int r, sf::RenderWindow& window, sf::RectangleShape& rectangles, void(*visualizeSort)(sf::RenderWindow&, const std::vector<int>&, sf::RectangleShape&)) {
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

        visualize(arr, window, rectangles); // Utilize the visualize function from visualization.hpp
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
