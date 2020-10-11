vector<int> plusOne(vector<int>& digits) {
    int len = digits.size();
    int i = len - 1;
    while ( i >= 0) {
        digits[i]++;
        digits[i] %= 10;
        if (digits[i] != 0) return digits;
        --i;
    }
    // digits.insert(digits.begin(), 1);
    digits[0] = 1;
    digits.push_back(0);
    return digits;
}