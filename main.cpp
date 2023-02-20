#include <iostream>
using namespace std;

int main()
{
    int accuracy = 100;
    int digit_count = accuracy + 1;
    int remainders_length = digit_count * 10 / 3;
    int remainders[remainders_length];

    for (int remainder = 0; remainder < remainders_length; remainder++)
    {
        remainders[remainder] = 2;
    }
    int pi[digit_count];
    int new_digit;

    for (int digit_index = 0; digit_index < digit_count; digit_index++)
    {
        int transfer = 0;
        int sum = 0;
        for (int remainder_index = remainders_length - 1; remainder_index >= 0; remainder_index--)
        {
            int dividend = remainder_index;
            int divisor = dividend * 2 + 1;
            remainders[remainder_index] *= 10;
            sum = remainders[remainder_index] + transfer;
            int remainder = sum % divisor;

            remainders[remainder_index] = remainder;
            transfer = sum / divisor * dividend;
        }
        remainders[0] = sum % 10;
        new_digit = sum / 10;

        int digit_overflow_counter;
        if (new_digit == 9)
        {
            digit_overflow_counter++;
        }
        else if (new_digit == 10)
        {
            new_digit = 0;
            for (int digit_overflow_index = digit_index;
                 digit_overflow_index >= digit_index - digit_overflow_counter;
                 digit_overflow_index--)
            {
                if (pi[digit_overflow_index] == 9)
                {
                    pi[digit_overflow_index] = 0;
                }
                else
                {
                    pi[digit_overflow_index]++;
                }
            }
            digit_overflow_counter = 1;
        }
        else
        {
            digit_overflow_counter = 1;
        }

        pi[digit_index] = new_digit;
    }

    for (int decimal_point = 0; decimal_point < digit_count; decimal_point++)
    {
        if (decimal_point == 1)
        {
            cout << ',';
        }
        cout << pi[decimal_point];
    }
    cout << endl;
    return 0;
}