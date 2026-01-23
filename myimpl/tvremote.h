class tvremote {
public:
    tvremote();
    virtual void power() = 0;
    virtual void volumeUp() = 0;
    virtual void volumeDown() = 0;
    virtual void channelUp() = 0;
    virtual void channelDown() = 0;
    virtual void mute() = 0;
    virtual void setChannel(int channel) = 0;
};