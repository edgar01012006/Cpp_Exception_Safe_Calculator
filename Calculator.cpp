#include "Calculator.hpp"

void Calculator::setInputs() {
    std::cin >> input1;
    std::cin >> input2;
}

void Calculator::inputAdd() noexcept {
    setInputs();
    try {
        double MaxDouble = std::numeric_limits<double>::max(); // 1.7976931348623157E308
        double MinDouble = std::numeric_limits<double>::min(); // 2.2250738585072014E-308
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);
        if (MaxDouble - num1 < num2) {
            throw std::out_of_range("out_of_range");
        }
        if (MinDouble - num1 < num2) {
            throw std::out_of_range("out_of_range");
        }
        std::cout << num1 << " + " << num2 << " = " << Calculator::add(num1, num2) << std::endl;
    } catch(const std::invalid_argument& ex) {
        std::cout << ex.what() << std::endl;
    } catch(const std::out_of_range& ex) {
        std::cout << ex.what() << std::endl;
    }
    return;
}

void Calculator::inputSub() {

}

/*
void Calculator::inputMul();
void Calculator::inputDiv();
*/

void Calculator::menu() {
    bool exit = true;
    int input = 0;
    while (exit != false) {
        std::cout << "0: exit\n"
                  << "1: add\n"
                  << "2: sub\n"
                  << "3: mul\n"
                  << "4: div\n";
        try {
            std::cin >> input;
            if (input < 0 || input > 4) {
                throw std::invalid_argument("invalid_argument");
            }
            switch (input) {
                case 0:
                    return;
                case 1:
                    inputAdd();
                case 2:
                    inputSub();
                case 3:
                    //inputMul();
                case 4:
                    //inputDiv();
                default:
                    break;
            } 
        } catch(const std::invalid_argument& ex) {
            std::cout << ex.what() << std::endl;
        }
    }
}