#include "strings.hpp"

int manual_strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

void reverseString(char* str) {
    int length = manual_strlen(str);
    for (int i = 0; i < length / 2; ++i) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int isPalindrome(const char* str) {
    int left = 0;
    int right = manual_strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;  // Not a palindrome
        }
        ++left;
        --right;
    }
    return 1;  // Is a palindrome
}

void manual_strcpy(char* dest, const char* src, const size_t& dest_size) {
    if (dest_size <= 1) return; // No space to copy

    char* dest_end = dest + dest_size - 1; // Leave space for null terminator
    while (*src != '\0' && dest != dest_end) {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '\0';  // Null-terminate the destination string
}
