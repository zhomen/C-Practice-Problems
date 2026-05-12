#include <cassert>
#include <gtest/gtest.h>
#include <iostream>
#include "arrays.hpp"

TEST(ArraysTest, ReverseArray) {
    int arr[] = {1, 2, 3, 4, 5};
    int expected[] = {5, 4, 3, 2, 1};
    reverse(arr, 5);
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(arr[i], expected[i]);
    }
}

TEST(ArraysTest, MinMaxArray) {
    int arr[] = {3, 1, 4, 1, 5, 9};
    int min, max;
    minMax(arr, 6, min, max);
    ASSERT_EQ(min, 1);
    ASSERT_EQ(max, 9);
}

TEST(ArraysTest, MinMaxSingleElement) {
    int arr[] = {42};
    int min, max;
    minMax(arr, 1, min, max);
    ASSERT_EQ(min, 42);
    ASSERT_EQ(max, 42);
}

TEST(ArraysTest, MinMaxEmptyArray) {
    int* arr = nullptr;
    int min = 0, max = 0;
    minMax(arr, 0, min, max);
    // For an empty array, we expect min and max to remain unchanged
    ASSERT_EQ(min, 0);
    ASSERT_EQ(max, 0);
}

TEST(ArraysTest, MinMaxDuplicates) {
    int arr[] = {2, 2, 2, 2, 2};
    int min, max;
    minMax(arr, 5, min, max);
    ASSERT_EQ(min, 2);
    ASSERT_EQ(max, 2);
}

TEST(ArraysTest, RemoveDuplicates) {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int size = 7;
    removeDuplicates(arr, size);
    int expected[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < size; ++i) {
        ASSERT_EQ(arr[i], expected[i]);
    }
}

TEST(ArraysTest, RemoveDuplicatesAllSame) {
    int arr[] = {1, 1, 1, 1, 1};
    int size = 5;
    removeDuplicates(arr, size);
    int expected[] = {1};
    ASSERT_EQ(arr[0], expected[0]);
}

TEST(ArraysTest, RotateArray) {
    int arr[] = {1, 2, 3, 4, 5};
    rotate(arr, 5, 2);
    int expected[] = {4, 5, 1, 2, 3};
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(arr[i], expected[i]);
    }
}

TEST(ArraysTest, RotateArrayNegative) {
    int arr[] = {1, 2, 3, 4, 5};
    rotate(arr, 5, -2);
    int expected[] = {3, 4, 5, 1, 2};
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(arr[i], expected[i]);
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}