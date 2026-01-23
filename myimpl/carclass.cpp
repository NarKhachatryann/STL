#include <iostream>
#include <string>
#include <chrono>
#include <thread>

class car {
    private:
    bool m_engine;
    std::string m_model;
    std::string m_pistons;
    std::string m_drive;
    std::string m_color;
    std::string m_fuel;

    public:
    car(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel) : m_model(model), m_pistons(pistons),
    m_drive(drive), m_color(color), m_fuel(fuel), m_engine(false) {
        std::cout << "Car created!" << std::endl;
    }
    
    car(const car& other) {
        m_engine = other.m_engine;
        m_model = other.m_model;
        m_pistons = other.m_pistons;
        m_drive = other.m_drive;
        m_color = other.m_color;
        m_fuel = other.m_fuel;
    }

    car& operator= (const car& other) {
        if(this != &other) {
            m_engine = other.m_engine;
            m_model = other.m_model;
            m_pistons = other.m_pistons;
            m_drive = other.m_drive;
            m_color = other.m_color;
            m_fuel = other.m_fuel;
        }
        return *this;
    }

    void change_color(std::string color) {
        m_color = color;
    }

    void print() {
        std::cout << "Car model: " << m_model << std::endl;
        std::cout << "Number of Pistons of the Car: " << m_pistons << std::endl;
        std::cout << "Car Drive: " << m_drive << std::endl;
        std::cout << "Color: " << m_color << std::endl;
        std::cout << "Fuel type: " << m_fuel << std::endl;
        if(m_engine) {
            std::cout << "The Engine is running" << std::endl;
        } else {
            std::cout << "The engine is turned off" << std::endl;
        }
    }

    void engine(bool engine) {
        if(engine && m_engine) {
            std::cout << "The Engine is already running" << std::endl;
            m_engine = true;
        } else if(!m_engine && engine) {
            std::cout << "The engine starts..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            m_engine = true;
            std::cout << "The Engine is running" << std::endl;
        } else if(m_engine && !engine) {
            std::cout << "The engine turns off" << std::endl;
        }
    }

    ~car() {
        std::cout << "Car is deleted" << std::endl;
    }
};

int main() {
    car mercedes("W124", "4", "RWD", "Black", "Benzine");
    mercedes.print();
    mercedes.engine(true);
    mercedes.change_color("Red");
    mercedes.print();
    mercedes.engine(false);
    return 0;
}