int myAtoi(char* s) {
    size_t i = 0;
    bool isPositive = true;
    long long result = 0;

    // Skip leading whitespace.
    while (s[i] == ' ') {
        i++;
    }

    // Check for the sign.
    if (s[i] == '-') {
        isPositive = false;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // Convert the characters to an integer.
    while (isdigit(s[i])) {
        int digit = s[i] - '0';
        result = result * 10 + digit;
        i++;

        // Check for overflow/underflow.
        if (result > (INT_MAX)) {
            return isPositive ? INT_MAX : INT_MIN;
        }
    }

    if (isPositive) {
        return result;
    } else {
        return -result;
    }
}
