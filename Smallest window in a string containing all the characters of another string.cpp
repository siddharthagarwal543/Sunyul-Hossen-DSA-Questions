//Problem link:https://leetcode.com/problems/minimum-window-substring/description/
#include <string>
#include <vector>
#include <limits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::vector<int> target(128, 0); // Store the frequency of characters in string t
        for (char c : t) {
            target[c]++;
        }

        int counter = t.length(); // Counter to track the number of characters needed to be covered
        int minLen = std::numeric_limits<int>::max(); // Length of the minimum window
        int start = 0; // Start index of the minimum window
        int left = 0; // Left pointer of the sliding window

        for (int right = 0; right < s.length(); right++) {
            if (target[s[right]] > 0) { // Found a character in t
                counter--;
            }
            target[s[right]]--; // Decrease the frequency of the character

            while (counter == 0) { // All characters in t are covered
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                target[s[left]]++; // Increase the frequency of the character
                if (target[s[left]] > 0) { // The character is needed
                    counter++;
                }

                left++; // Move the left pointer to find the next window
            }
        }

        return (minLen == std::numeric_limits<int>::max()) ? "" : s.substr(start, minLen);
    }
};
