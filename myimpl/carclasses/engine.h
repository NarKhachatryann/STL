class Engine {
private:
    bool m_running;

public:
    Engine();
    void start();
    void stop();
    bool isRunning() const;
    ~Engine();
};