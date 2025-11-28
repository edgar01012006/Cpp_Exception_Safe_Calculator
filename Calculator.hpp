#include <limits>
#include <iostream>
#include <stdlib.h>
#include <string>

class Calculator {
    public:
        static double add(double num1, double num2) { return num1 + num2; }
        static double sub(double num1, double num2) { return num1 - num2; }
        static double mul(double num1, double num2) { return num1 * num2; }
        static double div(double num1, double num2) { return num1 / num2; }

        void inputAdd() noexcept;
        void inputSub() noexcept;
        void inputMul() noexcept;
        void inputDiv() noexcept;

        void menu();

        void setInputs();

    private:
        std::string input1;
        std::string input2;
};