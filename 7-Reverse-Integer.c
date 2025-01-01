int reverse(int x) {
    long long result = 0; // Use long long because result might overflow an int.
    
    while (x != 0) {
        result =
            result * 10 + x % 10; // Get the last digit and add to the result.
        x /= 10;                  // Truncate away the last digit from x.
    }
    
    // Check for overflow.
    if (result > INT_MAX || result < INT_MIN) {
        return 0; // Return 0 if overflow occurs.
    } else {
        return (int)result; // Convert back to int before returning.
    }
}
