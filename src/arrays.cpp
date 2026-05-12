#include "arrays.hpp"

/// @brief Reverses the elements of an array.
/// @param arr Pointer to the array to reverse.
/// @param size The size of the array.
void reverse(int* arr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

/// @brief Finds the minimum and maximum elements in an array.
/// @param arr Pointer to the array to search.
/// @param size The size of the array.
/// @param min Reference to store the minimum value.
/// @param max Reference to store the maximum value.
void minMax(int* arr, int size, int& min, int& max) {
    if (size <= 0) return;
    min = max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
}

/// @brief Removes duplicate elements from a sorted array.
/// @param arr Pointer to the array to modify.
/// @param size Reference to the size of the array.
void removeDuplicates(int* arr, int& size) {
    if (size <= 0) return;

    int* end = arr + size;
    int* current = arr + 1;

    while (current < end) {
        if (*current != *arr) {
            *(++arr) = *current;
        }
        ++current;
    }
    size = arr - (end - size);
}

/// @brief Rotates the elements of an array to the right by k positions.
/// @param arr Pointer to the array to rotate.
/// @param size The size of the array.
/// @param k The number of positions to rotate.
void rotate(int* arr, int size, int k) {
    k = k % size; // Handle cases where k > size
    if (k < 0) k += size; // Handle negative rotations

    reverse(arr, size);
    reverse(arr, k);
    reverse(arr + k, size - k);
}