#include "Calculator.hpp"


double Calculator::MaxDouble = std::numeric_limits<double>::max(); // 1.7976931348623157E308
double Calculator::MinDouble = std::numeric_limits<double>::lowest(); // -1.7976931348623157E308

void Calculator::setInputs() {
    std::cin >> input1;
    std::cin >> input2;
}

void Calculator::setInput() {
    std::cin >> input1;
}

void Calculator::inputAdd() noexcept {
    setInputs();
    try {
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);
        if (MaxDouble - num1 < num2) { // num1 + num2 > MaxDouble
            throw std::out_of_range("out_of_range");
        }
        if (MinDouble - num1 > num2) { // num1 + num2 < MinDouble
            throw std::out_of_range("out_of_range");
        }
        std::cout << num1 << " + " << num2 << " = " << Calculator::add(num1, num2) << std::endl;
    } catch(const std::logic_error& ex) {
        std::cout << ex.what() << std::endl;
    }
}

void Calculator::inputSub() noexcept {
    setInputs();
    try {
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);
        if (MaxDouble + num2 < num1) { // num1 - num2 > MaxDouble
            throw std::out_of_range("out_of_range");
        }
        if (MinDouble + num2 > num1) { // num1 - num2 < MinDouble
            throw std::out_of_range("out_of_range");
        }
        std::cout << num1 << " - " << num2 << " = " << Calculator::sub(num1, num2) << std::endl;
    } catch(const std::logic_error& ex) {
        std::cout << ex.what() << std::endl;
    }
}


void Calculator::inputMul() noexcept {
    setInputs();
    try {
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);
        if (MaxDouble / num2 < num1) { // num1 * num2 > MaxDouble
            throw std::out_of_range("out_of_range");
        }
        if (MinDouble / num2 > num1) { // num1 * num2 < MinDouble
            throw std::out_of_range("out_of_range");
        }
        std::cout << num1 << " * " << num2 << " = " << Calculator::mul(num1, num2) << std::endl;
    } catch(const std::logic_error& ex) {
        std::cout << ex.what() << std::endl;
    }
}


void Calculator::inputDiv() noexcept {
    setInputs();
    try {
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);
        if (num2 == 0) {
            throw std::invalid_argument("invalid_argument");
        }
        if (MaxDouble * num2 < num1) { // num1 / num2 > MaxDouble
            throw std::out_of_range("out_of_range");
        }
        if (MinDouble * num2 > num1) { // num1 / num2 < MaxDouble
            throw std::out_of_range("out_of_range");
        }
        std::cout << num1 << " / " << num2 << " = " << Calculator::div(num1, num2) << std::endl;
    } catch(const std::logic_error& ex) {
        std::cout << ex.what() << std::endl;
    }
}

void Calculator::inputSqrt() noexcept {
    setInput();
    try {
        double num = std::stod(input1);
        if (num < 0) {
            throw std::invalid_argument("invalid_argument");
        }
        std::cout << "sqrt(" << num << ") = " << Calculator::sqrt(num) << std::endl;
    } catch(const std::logic_error& ex) {
        std::cout << ex.what() << std::endl;
    }
}

void Calculator::inputLog() noexcept {
    setInput();
    try {
        double num = std::stod(input1);
        if (num <= 0) {
            throw std::invalid_argument("invalid_argument");
        }
        std::cout << "log" << num << " = " << Calculator::log(num) << std::endl;
    } catch(const std::logic_error& ex) {
        std::cout << ex.what() << std::endl;
    }
}

void Calculator::menu() {
    bool exit = true;
    int input = 0;
    while (exit != false) {
        std::cout << "0: exit\n"
                  << "1: add\n"
                  << "2: sub\n"
                  << "3: mul\n"
                  << "4: div\n"
                  << "5: sqrt\n"
                  << "6: log\n";
        try {
            std::cin >> input;
            if (input < 0 || input > 6) {
                throw std::invalid_argument("invalid_argument");
            }
            switch (input) {
                case 0:
                    return;
                case 1:
                    inputAdd();
                    break;
                case 2:
                    inputSub();
                    break;
                case 3:
                    inputMul();
                    break;
                case 4:
                    inputDiv();
                    break;
                case 5:
                    inputSqrt();
                    break;
                case 6:
                    inputLog();
                    break;
                default:
                    break;
            } 
        } catch(const std::invalid_argument& ex) {
            std::cout << ex.what() << std::endl;
        }
    }
}