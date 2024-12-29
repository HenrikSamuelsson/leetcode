char* longestPalindrome(char* s) {
    const int n = strlen(s);

    if (n == 0) {
        return \\;
    }

    // Create a table to store whether substring s[i..j] is a palindrome,
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    int start = 0;     // Starting index of the longest palindrome.
    int maxLength = 1; // Length of the longest palindrome.

    // Every single character is a palindrome.
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Check for 2-character palindrom substrings.
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    // Check for substrings longer than 2 characters.
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1; // Ending index of the substring.

            // Check if the current substring is a palindrome.
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;
                start = i;
                maxLength = length;
            }
        }
    }

    // Extract the longest palindrome substring.
    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, s + start, maxLength);
    result[maxLength] = '\\0'; // Null-terminate the result.
    return result;
}
