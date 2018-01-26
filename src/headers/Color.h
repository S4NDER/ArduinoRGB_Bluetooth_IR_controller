#pragma once
#define OFF setColor (0, 0, 0)
#define RED setColor(255, 0, 0)
#define GREEN setColor(0, 255, 0)
#define BLUE setColor(0, 0, 255)
#define WHITE setColor(255, 255, 255)
#define ORANGE setColor(255, 90, 0)
#define DARK_YELLOW setColor(204, 204, 0)
#define YELLOW setColor(255, 130, 0)
#define STRAW_YELLOW setColor(255, 206, 0)

#define PEA_GREEN setColor(44, 255, 22)
#define CYAN setColor(0, 255, 255)
#define LIGHT_BLUE setColor(0, 147, 255)
#define SKY_BLUE setColor(51, 197, 255)

#define DARK_BLUE setColor(0, 0, 139)
#define DARK_PINK setColor(137, 31, 202)
#define PINK setColor(137, 0, 142)
#define PURPLE setColor(255, 0, 142)

namespace ArduinoRGB{

class Color {
private:
    float red;
    float green;
    float blue;

public:
    Color (void);
    Color (float red, float green, float blue);

    void setColor (float red, float green, float blue);

    float getRed(void);
    float getGreen(void);
    float getBlue(void);

private:
    void setRed(float red);
    void setGreen(float green);
    void setBlue(float blue);
};
};
