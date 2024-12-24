bool isPalindrome(int x) {
    if (x < 0)
    {
        return false;   // Negative numbers are never palindromes.
    }

    int original = x;
    long reversed = 0;
    while (x != 0)
    {
        int remainder = x % 10;
        reversed = reversed * 10 + remainder;
        x /= 10;
    }

    return original == reversed;
}