#pragma once

class Microphone {
private:
    float filterFrequency = 500;

public:
    Microphone (void);
    void init(void);
    float getMicLevel(void);
    float getBassLevel(void);

public:
    float getFilterFrequency(void);
    void setFilterFrequency(float filterFrequency);

};
