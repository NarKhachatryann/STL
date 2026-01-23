#include "animals.h"

class Amphibian : public Animal, public swimmer, public walker {
public:
    Amphibian(const std::string& name, double weight);
    void makeSound() const override;
    void swim() const override;
    void walk() const override;
};