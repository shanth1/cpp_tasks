#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

float get_discriminant(float a, float b, float c)
{
    return b * b - 4 * a * c;
}

void print_root(string root_name, float root_value)
{
    cout << root_name << " = " << root_value << endl;
}

void solve_quadratic_equation(float a, float b, float c)
{
    float discriminant, x1;
    discriminant = get_discriminant(a, b, c);
    if (discriminant > 0)
    {
        float x1 = (-b + sqrt(discriminant)) / (2 * a);
        float x2 = (-b - sqrt(discriminant)) / (2 * a);
        print_root("x1", x1);
        print_root("x2", x2);
    }
    else if (discriminant == 0)
    {
        float x1 = -b / (2 * a);
        print_root("x1", x1);
    }
    else
    {
        cout << "no real roots" << endl;
    }
}

float get_coefficient_from_console(char coefficient_name)
{
    float coefficient;
    cout << "Enter " << coefficient_name << " coefficient: ";
    cin >> coefficient;
    return coefficient;
}

int main()
{
    float a = get_coefficient_from_console('a');
    float b = get_coefficient_from_console('b');
    float c = get_coefficient_from_console('c');

    solve_quadratic_equation(a, b, c);
    return 0;
}