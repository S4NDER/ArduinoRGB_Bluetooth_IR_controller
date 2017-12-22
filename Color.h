#pragma once
#define OFF set_color (0, 0, 0)
#define RED set_color(255, 0, 0)
#define GREEN set_color(0, 255, 0)
#define BLUE set_color(0, 0, 255)
#define WHITE set_color(255, 255, 255)
#define ORANGE set_color(255, 90, 0)
#define DARK_YELLOW set_color(204, 204, 0)
#define YELLOW set_color(255, 130, 0)
#define STRAW_YELLOW set_color(255, 206, 0)

#define PEA_GREEN set_color(44, 255, 22)
#define CYAN set_color(0, 255, 255)
#define LIGHT_BLUE set_color(0, 147, 255)
#define SKY_BLUE set_color(51, 197, 255)

#define DARK_BLUE set_color(0, 0, 139)
#define DARK_PINK set_color(137, 31, 202)
#define PINK set_color(137, 0, 142)
#define PURPLE set_color(255, 0, 142)

class Color {
private:
    float red;
    float green;
    float blue;

public:
    Color (void);
    Color (float red, float green, float blue);

    void set_color (float red, float green, float blue);

    float get_red(void);
    float get_green(void);
    float get_blue(void);

private:
    void set_red(float red);
    void set_green(float green);
    void set_blue(float blue);
};
