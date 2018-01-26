#pragma once

namespace ArduinoRGB{

class Microphone {
private:
    float filterFrequency = 1500;
    unsigned short int bassThreshold = 172;

public:
    Microphone (void);
    void init(void);
    float getMicLevel(void);
    bool hasBass(void);

public:
    float getFilterFrequency(void);
    void setFilterFrequency(float filterFrequency);
    void setBassThreshold(unsigned short int bassThreshold);

};
};
