#ifndef KEYBOARD_AND_CLICK_H
#define KEYBOARD_AND_CLICK_H
#include <windows.h>

#define DELAY 100

void click(int x, int y);
void scroll_down(int ticks);
void scroll_up(int ticks);
void press_key(WORD key);
COLORREF get_pixel_color(int x, int y);


#endif  