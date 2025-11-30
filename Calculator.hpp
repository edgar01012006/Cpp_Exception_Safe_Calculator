#include <limits>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>


class Calculator {
    public:
        static double add(double num1, double num2) noexcept { return num1 + num2; }
        static double sub(double num1, double num2) noexcept { return num1 - num2; }
        static double mul(double num1, double num2) noexcept { return num1 * num2; }
        static double div(double num1, double num2) noexcept { return num1 / num2; }
        static double sqrt(double num) noexcept { return std::sqrt(num); }
        static double log(double num) noexcept { return std::log(num); }

        void inputAdd() noexcept;
        void inputSub() noexcept;
        void inputMul() noexcept;
        void inputDiv() noexcept;
        void inputSqrt() noexcept;
        void inputLog() noexcept;

        void menu();

        void setInputs();
        void setInput();

    private:
        std::string input1;
        std::string input2;

        static double MaxDouble;
        static double MinDouble;

};
