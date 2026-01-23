#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

class car {
    private:
    bool m_engine;
    std::string m_model;
    std::string m_pistons;
    std::string m_drive;
    std::string m_color;
    std::string m_fuel;

    public:
    car() : m_engine(false), m_model(""), m_pistons(""), m_drive(""), m_color(""), m_fuel("") {}

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

    car(car&& other) noexcept
        : m_engine(other.m_engine),
          m_model(std::move(other.m_model)),
          m_pistons(std::move(other.m_pistons)),
          m_drive(std::move(other.m_drive)),
          m_color(std::move(other.m_color)),
          m_fuel(std::move(other.m_fuel)) {}

    void init(std::string model, std::string pistons, std::string drive, std::string color, std::string fuel) {
        m_model = model;
        m_pistons = pistons;
        m_drive = drive;
        m_color = color;
        m_fuel = fuel;
        m_engine = false;
        std::cout << "Car created!" << std::endl;
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

    car& operator= (car&& other) noexcept {
        if(this != &other) {
            m_engine = other.m_engine;
            m_model = std::move(other.m_model);
            m_pistons = std::move(other.m_pistons);
            m_drive = std::move(other.m_drive);
            m_color = std::move(other.m_color);
            m_fuel = std::move(other.m_fuel);
        }
        return *this;
    }

    bool operator== (const car& other) const {
        return (m_model == other.m_model &&
                m_pistons == other.m_pistons &&
                m_drive == other.m_drive &&
                m_color == other.m_color &&
                m_fuel == other.m_fuel);
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

class parking {
    private:
    std::vector<car> m_cars;
    int m_capacity;

    parking(int capacity = 0) : m_capacity(capacity) {}

    public:

    static parking& getInstance(int capacity = 0) {
        static parking instance(capacity);
        return instance;
    }

    void init(int capacity) {
        m_capacity = capacity;
        m_cars.clear();
        
    }

    template<typename... Args>
    bool addcar(Args&&... args) {
        if (m_cars.size() < m_capacity) {
            m_cars.emplace_back(std::forward<Args>(args)...);
            return true;
        }
        std::cout << "Parking is full!\n";
        return false;
    }


    bool removecar(const car& oldcar) {
        for(auto it = m_cars.begin(); it != m_cars.end(); ++it) {
            if(*it == oldcar) {
                m_cars.erase(it);
                return true;
            }
        }
        return false;
    }
};

int main() {
    auto p = parking::getInstance(2);
    p.init(2);

    p.addcar("ModelX", "4", "AWD", "Red", "Electric");
    p.addcar("ModelY", "4", "AWD", "Blue", "Electric");
    p.addcar("ModelZ", "6", "RWD", "Black", "Electric");

    return 0;
}