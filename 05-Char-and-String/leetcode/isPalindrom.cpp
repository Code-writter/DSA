
#include <iostream>
#include <string>
#include <cctype> // Required for isalnum() and tolower()


bool isPalindrome(std::string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        // Move the left pointer forward until it finds an alphanumeric character.
        while (left < right && !std::isalnum(s[left])) {
            left++;
        }

        // Move the right pointer backward until it finds an alphanumeric character.
        while (left < right && !std::isalnum(s[right])) {
            right--;
        }

        // Compare the two characters (case-insensitive).
        if (std::tolower(s[left]) != std::tolower(s[right])) {
            return false; // Characters don't match.
        }

        // Move pointers towards the center.
        left++;
        right--;
    }

    return true; // All characters matched.
}