#include "amphibian.h"

Amphibian::Amphibian(const std::string& name, double weight) : Animal(name, weight) {}

void Amphibian::makeSound() const {
    std::cout << m_name << " the amphibian croaks." << std::endl;
}

void Amphibian::swim() const {
    std::cout << m_name << " is swimming." << std::endl;
}

void Amphibian::walk() const {
    std::cout << m_name << " is walking." << std::endl;
}