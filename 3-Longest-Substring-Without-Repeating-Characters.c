// A solution that employs the sliding window technique along with an array that
// functions as a hash table to keep track of characters and their indices.

#define ALPHABET_SIZE 256

int lengthOfLongestSubstring(char* s) {
    int charIndex[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        charIndex[i] = -1; // Initialize to -1 for all ASCII characters.
    }

    int maxLength = 0; // Length of longest substring found.
    int startIdx = 0;  // Start index of the current substring.

    for (int i = 0; s[i] != '\0'; i++) {
        char currentChar = s[i];

        // If the character is found in the substring, move the start index.
        if (charIndex[currentChar] >= startIdx) {
            startIdx = charIndex[currentChar] + 1;
        }

        // Update the latest index of the character.
        charIndex[currentChar] = i;

        // Calculate the length of the current substring.
        int substringLength = i - startIdx + 1;

        // Check if the substring is the longest one found.
        if (substringLength > maxLength) {
            maxLength = substringLength;
        }
    }

    return maxLength;
}