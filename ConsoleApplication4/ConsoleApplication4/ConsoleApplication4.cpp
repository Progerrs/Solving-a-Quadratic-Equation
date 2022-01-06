// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <algorithm>

double Solving_the_quadratic_equation(int32_t first_coefficient, int32_t second_coefficient, int32_t third_coefficient);
int32_t Is_a_Number(std::string text);

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
                std::cout << "Первый коэффициент долже быть больше или равен нулю" << std::endl;
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
}

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
    int32_t digit;
    while (true)
    {
        std::cout << text;
        std::cin >> digit;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Вы ввели не число" << std::endl;
        }
        else {
            return digit;
        }
    }
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
