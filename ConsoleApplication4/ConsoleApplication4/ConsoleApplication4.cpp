#include <algorithm>
#include "Header.h"


int main()
{   
    setlocale(LC_ALL, "Russian");
    std::string answer_continue = "";
    double answer = 0;
    int32_t first_coefficient = 0;
    int32_t second_coefficient = 0;
    int32_t third_coefficient = 0;
    int32_t digit = 0;
    do {
        first_coefficient = Is_a_Number("Введите первый коэффициент: ");
        while (true)
        {
            if (first_coefficient == 0) {
                std::cout << "Первый коэффициент долже быть больше или меньше нуля" << std::endl;
                first_coefficient = Is_a_Number("Введите первый коэффициент: ");
            }
            else {
                break;
            }
        }
        second_coefficient = Is_a_Number("Введите второй коэффициент: ");
        third_coefficient = Is_a_Number("Введите третьи коэффициент: ");
        digit = Is_a_Number("Введите количество цифре после запятой: ");
        while (true)
        {
            if (digit > 0 && digit < 10) {
                break;
            }
            else {
                std::cout << "количество цифре после запятой должно быть больше нуле и меньше десяти" << std::endl;
                digit = Is_a_Number("Введите количество цифре после запятой: ");
            }
        }
        answer = Solving_the_quadratic_equation(first_coefficient, second_coefficient, third_coefficient);


        std::cout << std::setprecision(digit) << "Ответ: " << answer << std::endl;
        std::cout << "Если вы хотите продолжить - напишите yes, если нет введите лубую другую строку: ";
        std::cin >> answer_continue;
        std::transform(answer_continue.begin(), answer_continue.end(), answer_continue.begin(), tolower);
    } while (answer_continue == "yes");

    return 0;
}
