#include <cassert>
#include <gtest/gtest.h>
#include <iostream>
#include "strings.hpp"

TEST(StringsTest, Length) {
    ASSERT_EQ(manual_strlen("Hello"), 5);
    ASSERT_EQ(manual_strlen(""), 0);
    ASSERT_EQ(manual_strlen("Hello, World!"), 13);
}

TEST(StringsTest, Reverse) {
    char str1[] = "Hello";
    reverseString(str1);
    ASSERT_STREQ(str1, "olleH");

    char str2[] = "A man, a plan, a canal, Panama";
    reverseString(str2);
    ASSERT_STREQ(str2, "amanaP ,lanac a ,nalp a ,nam A");
}

TEST(StringsTest, IsPalindrome) {
    ASSERT_TRUE(isPalindrome("racecar"));
    ASSERT_FALSE(isPalindrome("hello"));
    // Note: The current implementation of isPalindrome does not ignore spaces and punctuation
    ASSERT_FALSE(isPalindrome("A man, a plan, a canal, Panama"));
}

TEST(StringsTest, ManualStrcpy) {
    char dest[100];
    manual_strcpy(dest, "Hello", sizeof(dest)/sizeof(dest[0]));
    ASSERT_STREQ(dest, "Hello");
}

TEST(StringsTest, ManualStrcpySmallBuffer) {
    char dest[5]; // Not enough space for "Hello" + null terminator
    manual_strcpy(dest, "Hello", sizeof(dest)/sizeof(dest[0]));
    // This will cause undefined behavior, but we can check if the first 4 characters are copied
    ASSERT_EQ(dest[0], 'H');
    ASSERT_EQ(dest[1], 'e');
    ASSERT_EQ(dest[2], 'l');
    ASSERT_EQ(dest[3], 'l');
}
