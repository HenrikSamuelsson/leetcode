/**
 * Finds longest common prefix among a list of strings.
 *
 * \param strs List of strings
 * \param strsSize Number or strings in the list
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    // Start by assuming the first string itself is the longest common prefix.
    char* prefix = strs[0];

    // Loop through each string besides the first.
    for (int i = 1; i < strsSize; i++) {
        // Compare the current prefix with the current string
        int j = 0;
        while (prefix[j] != '\0' && 
               strs[i][j] != '\0' &&
               prefix[j] == strs[i][j]) {
            j++;
        }

        // Update the prefix to the common part between all the strings.
        prefix[j] = '\0';
    }

    return prefix;
}