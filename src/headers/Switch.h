#pragma once

#define ON  on()
#define OFF off()

namespace ArduinoRGB{

class Switch {
private:
    bool switchState;

public:
    Switch (void);
    void on(void);
    void off(void);
    bool getState(void);
};
};
