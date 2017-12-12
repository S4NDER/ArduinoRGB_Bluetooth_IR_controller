#pragma once

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

    unsigned char pin_red = 2;
    unsigned char pin_green = 3;
    unsigned char pin_blue = 4;
};
