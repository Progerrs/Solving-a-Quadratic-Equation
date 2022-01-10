#include "Header.h"


double Solving_the_quadratic_equation(int32_t first_coefficient, int32_t second_coefficient, int32_t third_coefficient)
{
    double discriminant = 0;
    double answer = 0;
    double temp = 0;
    discriminant = pow(second_coefficient, 2) - 4 * first_coefficient * third_coefficient;
    if (discriminant == 0)
    {
        answer = second_coefficient / (static_cast<double>(2) * first_coefficient);
        return answer;
    }
    else if (discriminant > 0) {
        temp = (-second_coefficient - sqrt(discriminant)) / (static_cast<double>(2) * first_coefficient);
        answer = (-second_coefficient + sqrt(discriminant)) / (static_cast<double>(2) * first_coefficient);
        return answer > temp ? answer : temp;
    }
    else {
        std::cout << "Нет действительных корней, но есть комплекстные";
        std::cout << std::endl;
        std::cout << "x1 = " << std::setprecision(3) << -second_coefficient / (static_cast<double>(2) * first_coefficient) << " - i * " << sqrt(abs(discriminant)) / (static_cast<double>(2) * first_coefficient);
        std::cout << std::endl;
        std::cout << "x2 = " << std::setprecision(3) << -second_coefficient / (static_cast<double>(2) * first_coefficient) << " + i * " << sqrt(abs(discriminant)) / (static_cast<double>(2) * first_coefficient);
        std::cout << std::endl;
        return 0;
    }
}

int32_t Is_a_Number(std::string text)
{
    std::string digits_mayby = "";
    bool is_number = true;
    bool first = true;
    while (true)
    {
        is_number = true;
        first = true;
        std::cout << text;
        std::cin >> digits_mayby;
        for (char var : digits_mayby)
        {
            if (isdigit(var) || (var == '-' && first))
            {
                first = false;
                continue;
            }
            else
            {
                std::cout << "Вы ввели не число!" << std::endl;
                is_number = false;
                break;
            }
        }
        if (is_number) {
            return std::stoi(digits_mayby);
        }
        else {
            continue;
        }
    }
}