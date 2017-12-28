#pragma once

class Microphone {
private:
    float filterFrequency = 1500;

public:
    Microphone (void);
    void init(void);
    float getMicLevel(void);
    bool hasBass(void);

public:
    float getFilterFrequency(void);
    void setFilterFrequency(float filterFrequency);

};
