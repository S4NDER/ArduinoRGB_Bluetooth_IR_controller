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
    unsigned char red;
    unsigned char green;
    unsigned char blue;

public:
    Color (void);
    Color (unsigned char red, unsigned char green, unsigned char blue);

    void set_color (unsigned char red, unsigned char green, unsigned char blue);

    unsigned char get_red(void);
    unsigned char get_green(void);
    unsigned char get_blue(void);

private:
    void set_red(unsigned char red);
    void set_green(unsigned char green);
    void set_blue(unsigned char blue);
};
