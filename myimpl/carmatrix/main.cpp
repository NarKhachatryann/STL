#include "matrix.h"

int main() {
    Matrix garage(2);
    garage.init();
    garage.print();
    garage.startAllEngines();
    garage.changeColorAll("Red");
    garage.print();
    std::cout << "Total cars in garage: " << garage.getCarCount() << std::endl;
    return 0;
}
