#include <iostream>
#include <chrono>
#include <thread>
#include "car.h"


car::car(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel)
    : m_model(model), m_pistons(pistons), m_drive(drive), m_color(color), m_fuel(fuel) {
        m_engine = Engine();
    std::cout << "Car created!" << std::endl;
}

car::car(const car& other) {
    m_engine = other.m_engine;
    m_model = other.m_model;
    m_pistons = other.m_pistons;
    m_drive = other.m_drive;
    m_color = other.m_color;
    m_fuel = other.m_fuel;
}

car& car::operator=(const car& other) {
    if (this != &other) {
        m_engine = other.m_engine;
        m_model = other.m_model;
        m_pistons = other.m_pistons;
        m_drive = other.m_drive;
        m_color = other.m_color;
        m_fuel = other.m_fuel;
    }
    return *this;
}

void car::change_color(std::string color) {
    m_color = color;
}

void car::print() {
    std::cout << "Car model: " << m_model << std::endl;
    std::cout << "Number of Pistons of the Car: " << m_pistons << std::endl;
    std::cout << "Car Drive: " << m_drive << std::endl;
    std::cout << "Color: " << m_color << std::endl;
    std::cout << "Fuel type: " << m_fuel << std::endl;
    if (m_engine.isRunning()) {
        std::cout << "The Engine is running" << std::endl;
    } else {
        std::cout << "The engine is turned off" << std::endl;
    }
}

void car::engine(bool engine) {
    if (engine && m_engine.isRunning()) {
        std::cout << "The Engine is already running" << std::endl;
        m_engine.start();
    } else if (!m_engine.isRunning() && engine) {
        std::cout << "The engine starts..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        m_engine.start();
        std::cout << "The Engine is running" << std::endl;
    } else if (m_engine.isRunning() && !engine) {
        std::cout << "The engine turns off" << std::endl;
        m_engine.stop();
    }
}

car::~car() {
    std::cout << "Car is deleted" << std::endl;
}

Mercedes::Mercedes(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel)
    : car(model, pistons, drive, color, fuel) {
    std::cout << "Mercedes is created" << std::endl;
}

Mercedes::~Mercedes() {
    std::cout << "Mercedes is deleted" << std::endl;
}

BMW::BMW(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel)
    : car(model, pistons, drive, color, fuel) {
    std::cout << "BMW is created" << std::endl;
}

BMW::~BMW() {
    std::cout << "BMW is deleted" << std::endl;
}

Audi::Audi(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel)
    : car(model, pistons, drive, color, fuel) {
    std::cout << "Audi is created" << std::endl;
}

Audi::~Audi() {
    std::cout << "Audi is deleted" << std::endl;
}