#include "animals.h"

Animal::Animal(const std::string& name, double weight) : m_name(name), m_weight(weight) {}
std::string Animal::getName() const { return m_name; }

Animal::Animal(Animal&& other) noexcept : m_name(std::move(other.m_name)), m_weight(std::move(other.m_weight)) {}

Animal& Animal::operator= (Animal&& other) noexcept {
    if (this != &other) {
        m_name = std::move(other.m_name);
        m_weight = std::move(other.m_weight);
    }
    return *this;
}

bool Animal::operator< (const Animal& other) const {
    return m_weight < other.m_weight;
}

bool Animal::operator== (const Animal& other) const {
    return m_weight == other.m_weight;
}

bool Animal::operator> (const Animal& other) const {
    return m_weight > other.m_weight;
}

double Animal::getWeight() const {
    return m_weight;
}

Dog::Dog(const std::string& name, const std::string& breed, const std::string& color,
         double height, double weight, int age)
    : Animal(name,weight), m_breed(breed), m_color(color),
      m_height(height), m_age(age), sound("Woof!") {}

void Dog::makeSound() const { std::cout << sound << std::endl; }

Cat::Cat(const std::string& name, const std::string& breed, const std::string& color,
         double height, double weight, int age)
    : Animal(name,weight), m_breed(breed), m_color(color),
      m_height(height), m_age(age), sound("Meow!") {}

void Cat::makeSound() const { std::cout << sound << std::endl; }

Bird::Bird(const std::string& name, const std::string& breed, const std::string& color,
           double height, double weight, int age)
    : Animal(name,weight), m_breed(breed), m_color(color),
      m_height(height), m_age(age), sound("Chirik!") {}

void Bird::makeSound() const { std::cout << sound << std::endl; }

Fish::Fish(const std::string& name, const std::string& breed, const std::string& color,
           double height, double weight, int age)
    : Animal(name,weight), m_breed(breed), m_color(color),
      m_height(height), m_age(age), sound("Blub!") {}

void Fish::makeSound() const { std::cout << sound << std::endl; }

Horse::Horse(const std::string& name, const std::string& breed, const std::string& color,
             double height, double weight, int age)
    : Animal(name,weight), m_breed(breed), m_color(color),
      m_height(height), m_age(age), sound("Neigh!") {}

void Horse::makeSound() const { std::cout << sound << std::endl; }

Snake::Snake(const std::string& name, const std::string& breed, const std::string& color,
             double height, double weight, int age)
    : Animal(name,weight), m_breed(breed), m_color(color),
      m_height(height), m_age(age), sound("Shhhh!") {}

void Snake::makeSound() const { std::cout << sound << std::endl; }

void checkifanimal(Animal *obj) {
	if(dynamic_cast<Animal*>(obj)) {
		std::cout << "It's an animal!" << std::endl;
	} else {
		std::cout << "It's not an animal!" << std::endl;
	}
}