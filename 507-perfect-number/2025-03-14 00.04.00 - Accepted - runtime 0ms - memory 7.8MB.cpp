class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false; // Perfect numbers are greater than 1

        int sum = 1; // 1 is always a divisor
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) { // Avoid adding the square root twice
                    sum += num / i;
                }
            }
        }
        return sum == num;
    }
};
