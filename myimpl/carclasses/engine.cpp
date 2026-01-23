#include <iostream>
#include <thread>
#include <chrono>
#include "engine.h"

Engine::Engine() : m_running(false) {}

void Engine::start() {
    if (!m_running) {
        std::cout << "Engine starting..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        m_running = true;
        std::cout << "Engine is now running." << std::endl;
    } else {
        std::cout << "Engine is already running." << std::endl;
    }
}

void Engine::stop() {
    if (m_running) {
        std::cout << "Engine stopping..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        m_running = false;
        std::cout << "Engine is now stopped." << std::endl;
    } else {
        std::cout << "Engine is already stopped." << std::endl;
    }
}

bool Engine::isRunning() const {
    return m_running;
}

Engine::~Engine() {
    if (m_running) {
        stop();
    }
    std::cout << "Engine destroyed." << std::endl;
}