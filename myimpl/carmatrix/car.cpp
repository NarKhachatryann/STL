#include "car.h"
#include <iostream>
#include <chrono>
#include <thread>

car::car(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel)
    : m_model(model), m_pistons(pistons), m_drive(drive), m_color(color), m_fuel(fuel), m_engine(false) {
    std::cout << "Car created!" << std::endl;
    ++count;
}

car::car(const car& other) {
    m_engine = other.m_engine;
    m_model = other.m_model;
    m_pistons = other.m_pistons;
    m_drive = other.m_drive;
    m_color = other.m_color;
    m_fuel = other.m_fuel;

    ++count;
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

car& car::operator=(car&& other) {
    if (this != &other) {
        m_engine = other.m_engine;
        m_model = std::move(other.m_model);
        m_pistons = std::move(other.m_pistons);
        m_drive = std::move(other.m_drive);
        m_color = std::move(other.m_color);
        m_fuel = std::move(other.m_fuel);

        other.m_engine = false;
    }

    return *this;
}

car::car(car&& other) {
    m_engine = other.m_engine;
    m_model = std::move(other.m_model);
    m_pistons = std::move(other.m_pistons);
    m_drive = std::move(other.m_drive);
    m_color = std::move(other.m_color);
    m_fuel = std::move(other.m_fuel);

    other.m_engine = false;
}

void car::change_color(std::string color) {
    m_color = color;
}

int car::get_count() {
    return count;
}

int car::count = 0;

void car::print() {
    std::cout << "Car model: " << m_model << std::endl;
    std::cout << "Number of Pistons of the Car: " << m_pistons << std::endl;
    std::cout << "Car Drive: " << m_drive << std::endl;
    std::cout << "Color: " << m_color << std::endl;
    std::cout << "Fuel type: " << m_fuel << std::endl;
    if (m_engine) {
        std::cout << "The Engine is running" << std::endl;
    } else {
        std::cout << "The engine is turned off" << std::endl;
    }
}

void car::engine(bool engine) {
    if (engine && m_engine) {
        std::cout << "The Engine is already running" << std::endl;
    } else if (!m_engine && engine) {
        std::cout << "The engine starts..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        m_engine = true;
        std::cout << "The Engine is running" << std::endl;
    } else if (m_engine && !engine) {
        std::cout << "The engine turns off" << std::endl;
        m_engine = false;
    }
}

std::string car::get_model() const {
    return m_model;
}

car::~car() {
    std::cout << "Car is deleted" << std::endl;
    --count;
}