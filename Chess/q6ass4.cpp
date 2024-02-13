#include <iostream>
using namespace std;

void maxFrequencyOfNumber(int num, int& digit, int& maxFreq) {
    int freq[10] = { 0 }; // array to store frequency of each digit (0-9)

    while (num > 0) {
        int d = num % 10; // extract the last digit
        freq[d]++; // increment its frequency
        num /= 10; // remove the last digit
    }

    digit = 0; // initialize digit and maxFreq to 0
    maxFreq = 0;

    for (int i = 0; i < 10; i++) {
        if (freq[i] > maxFreq) {
            digit = i;
            maxFreq = freq[i];
        }
    }
}

int main() {
    int num, digit, maxFreq;
    cout << "Enter a positive integer: ";
    cin >> num;

    maxFrequencyOfNumber(num, digit, maxFreq);

    cout << "The digit with maximum frequency in " << num << " is " << digit << " (frequency = " << maxFreq << ").\n";

    return 0;
}
