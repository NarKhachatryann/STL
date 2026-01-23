#include <iostream>

double fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double kelvin(double celsius) {
    return celsius + 273.15;
}

int main() {
    double celsius;
    std::cout << "Enter Celsius temperature: ";
    std::cin >> celsius;

    int count = 0;
    std::cout << "Enter 1 to convert to Fahrenheit or enter 2 to convert to Kelvin: ";
    std::cin >> count;
    
    switch (count)
    {
    case 1:
        std::cout << "Fahrenheit: " << fahrenheit(celsius) << std::endl;
        break;
    case 2:
        std::cout << "Kelvin: " << kelvin(celsius) << std::endl;
        break;

    default:
        break;
    }

    return 0;
}