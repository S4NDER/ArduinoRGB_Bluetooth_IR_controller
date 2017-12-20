#pragma once
#define OFF set_color (0, 0, 0)
#define RED set_color(255, 0, 0)
#define GREEN set_color(0, 255, 0)
#define BLUE set_color(0, 0, 255)
#define WHITE set_color(255, 255, 255)
#define ORANGE set_color(255, 165, 0)
#define DARK_YELLOW set_color(204, 204, 0)
#define YELLOW set_color(255, 255, 0)
#define STRAW_YELLOW set_color(204, 230, 0)

#define PEA_GREEN set_color(0, 255, 127)
#define CYAN set_color(0, 255, 255)
#define LIGHT_BLUE set_color(173, 216, 230)
#define SKY_BLUE set_color(0, 191, 255)

#define DARK_BLUE set_color(0, 0, 139)
#define DARK_PINK set_color(199, 21, 133)
#define PINK set_color(255, 20, 147)
#define PURPLE set_color(128, 0, 128)

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
