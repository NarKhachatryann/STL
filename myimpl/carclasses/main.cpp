#include <iostream>
#include "car.h"

int main() {
    Mercedes myMercedes("w124 E500", "4", "RWD", "Black", "Gasoline");
    std::cout << std::endl;
    myMercedes.print();
    myMercedes.engine(true);
    myMercedes.change_color("Red");
    myMercedes.print();
    std::cout << std::endl;
    myMercedes.engine(false);
    std::cout << std::endl;

    BMW myBMW("M3 E92", "6", "RWD", "Blue", "Gasoline");
    std::cout << std::endl;
    myBMW.print();
    myBMW.engine(true);
    myBMW.change_color("White");
    myBMW.print();
    std::cout << std::endl;
    myBMW.engine(false);
    std::cout << std::endl;

    Audi myAudi("A4 B8", "4", "AWD", "Gray", "Gasoline");
    std::cout << std::endl;
    myAudi.print();
    myAudi.engine(true);
    myAudi.change_color("Silver");
    myAudi.print();
    std::cout << std::endl;
    myAudi.engine(false);
    std::cout << std::endl;
}