bool isMatch(char *s, char *p) {
    int sLen = strlen(s);
    int pLen = strlen(p);

    // Create a DP table
    bool dp[sLen + 1][pLen + 1];

    // Initialize the DP table
    memset(dp, false, sizeof(dp)); // Initialize the entire table to false
    dp[0][0] = true; // Empty string matches empty pattern

    // Handle patterns like a* or a*b* or a*b*c*
    for (int j = 1; j <= pLen; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2]; // Patterns with '*' can match empty string
        }
    }

    // Fill the DP table
    for (int i = 1; i <= sLen; i++) {
        for (int j = 1; j <= pLen; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1]; // Match single character
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2]; // Match zero occurrence of the preceding element
                if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                    dp[i][j] |= dp[i - 1][j]; // Match one or more occurrences
                }
            }
        }
    }

    return dp[sLen][pLen]; // Return true if we have a match
}