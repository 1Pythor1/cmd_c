#include "keyboard_and_click.h"
#include "../cmds_core/timer_clock/timer_clock.h"
#include <windows.h>

const WORD KeyToVK[124] = {
    // --- Lettres (0-25) ---
    /* KEY_A  0  */ 0x41,
    /* KEY_B  1  */ 0x42,
    /* KEY_C  2  */ 0x43,
    /* KEY_D  3  */ 0x44,
    /* KEY_E  4  */ 0x45,
    /* KEY_F  5  */ 0x46,
    /* KEY_G  6  */ 0x47,
    /* KEY_H  7  */ 0x48,
    /* KEY_I  8  */ 0x49,
    /* KEY_J  9  */ 0x4A,
    /* KEY_K  10 */ 0x4B,
    /* KEY_L  11 */ 0x4C,
    /* KEY_M  12 */ 0x4D,
    /* KEY_N  13 */ 0x4E,
    /* KEY_O  14 */ 0x4F,
    /* KEY_P  15 */ 0x50,
    /* KEY_Q  16 */ 0x51,
    /* KEY_R  17 */ 0x52,
    /* KEY_S  18 */ 0x53,
    /* KEY_T  19 */ 0x54,
    /* KEY_U  20 */ 0x55,
    /* KEY_V  21 */ 0x56,
    /* KEY_W  22 */ 0x57,
    /* KEY_X  23 */ 0x58,
    /* KEY_Y  24 */ 0x59,
    /* KEY_Z  25 */ 0x5A,
 
    // --- Chiffres (26-35) ---
    /* KEY_0  26 */ 0x30,
    /* KEY_1  27 */ 0x31,
    /* KEY_2  28 */ 0x32,
    /* KEY_3  29 */ 0x33,
    /* KEY_4  30 */ 0x34,
    /* KEY_5  31 */ 0x35,
    /* KEY_6  32 */ 0x36,
    /* KEY_7  33 */ 0x37,
    /* KEY_8  34 */ 0x38,
    /* KEY_9  35 */ 0x39,
 
    // --- Touches de fonction (36-59) ---
    /* KEY_F1  36 */ 0x70,
    /* KEY_F2  37 */ 0x71,
    /* KEY_F3  38 */ 0x72,
    /* KEY_F4  39 */ 0x73,
    /* KEY_F5  40 */ 0x74,
    /* KEY_F6  41 */ 0x75,
    /* KEY_F7  42 */ 0x76,
    /* KEY_F8  43 */ 0x77,
    /* KEY_F9  44 */ 0x78,
    /* KEY_F10 45 */ 0x79,
    /* KEY_F11 46 */ 0x7A,
    /* KEY_F12 47 */ 0x7B,
    /* KEY_F13 48 */ 0x7C,
    /* KEY_F14 49 */ 0x7D,
    /* KEY_F15 50 */ 0x7E,
    /* KEY_F16 51 */ 0x7F,
    /* KEY_F17 52 */ 0x80,
    /* KEY_F18 53 */ 0x81,
    /* KEY_F19 54 */ 0x82,
    /* KEY_F20 55 */ 0x83,
    /* KEY_F21 56 */ 0x84,
    /* KEY_F22 57 */ 0x85,
    /* KEY_F23 58 */ 0x86,
    /* KEY_F24 59 */ 0x87,
 
    // --- Fleches (60-63) ---
    /* KEY_LEFT  60 */ 0x25,
    /* KEY_RIGHT 61 */ 0x27,
    /* KEY_UP    62 */ 0x26,
    /* KEY_DOWN  63 */ 0x28,
 
    // --- Modificateurs (64-75) ---
    /* KEY_LSHIFT     64 */ 0xA0,
    /* KEY_RSHIFT     65 */ 0xA1,
    /* KEY_LCONTROL   66 */ 0xA2,
    /* KEY_RCONTROL   67 */ 0xA3,
    /* KEY_LALT       68 */ 0xA4,
    /* KEY_RALT       69 */ 0xA5,
    /* KEY_LWIN       70 */ 0x5B,
    /* KEY_RWIN       71 */ 0x5C,
    /* KEY_APPS       72 */ 0x5D,
    /* KEY_CAPSLOCK   73 */ 0x14,
    /* KEY_NUMLOCK    74 */ 0x90,
    /* KEY_SCROLLLOCK 75 */ 0x91,
 
    // --- Touches speciales (76-89) ---
    /* KEY_ESCAPE     76 */ 0x1B,
    /* KEY_TAB        77 */ 0x09,
    /* KEY_SPACE      78 */ 0x20,
    /* KEY_ENTER      79 */ 0x0D,
    /* KEY_BACKSPACE  80 */ 0x08,
    /* KEY_INSERT     81 */ 0x2D,
    /* KEY_DELETE     82 */ 0x2E,
    /* KEY_HOME       83 */ 0x24,
    /* KEY_END        84 */ 0x23,
    /* KEY_PAGEUP     85 */ 0x21,
    /* KEY_PAGEDOWN   86 */ 0x22,
    /* KEY_PRINTSCREEN 87 */ 0x2C,
    /* KEY_PAUSE      88 */ 0x13,
    /* KEY_MENU       89 */ 0x12,
 
    // --- Pave numerique (90-105) ---
    /* KEY_NUMPAD0         90  */ 0x60,
    /* KEY_NUMPAD1         91  */ 0x61,
    /* KEY_NUMPAD2         92  */ 0x62,
    /* KEY_NUMPAD3         93  */ 0x63,
    /* KEY_NUMPAD4         94  */ 0x64,
    /* KEY_NUMPAD5         95  */ 0x65,
    /* KEY_NUMPAD6         96  */ 0x66,
    /* KEY_NUMPAD7         97  */ 0x67,
    /* KEY_NUMPAD8         98  */ 0x68,
    /* KEY_NUMPAD9         99  */ 0x69,
    /* KEY_NUMPAD_ADD      100 */ 0x6B,
    /* KEY_NUMPAD_SUBTRACT 101 */ 0x6D,
    /* KEY_NUMPAD_MULTIPLY 102 */ 0x6A,
    /* KEY_NUMPAD_DIVIDE   103 */ 0x6F,
    /* KEY_NUMPAD_DECIMAL  104 */ 0x6E,
    /* KEY_NUMPAD_ENTER    105 */ 0x0D, // identique a VK_RETURN, distingue via le flag "extended" en raw input
 
    // --- Ponctuation OEM (106-116) ---
    /* KEY_SEMICOLON   106 */ 0xBA, // ;
    /* KEY_EQUAL       107 */ 0xBB, // =
    /* KEY_COMMA       108 */ 0xBC, // ,
    /* KEY_MINUS       109 */ 0xBD, // -
    /* KEY_PERIOD      110 */ 0xBE, // .
    /* KEY_SLASH       111 */ 0xBF, // /
    /* KEY_GRAVE       112 */ 0xC0, // `
    /* KEY_LBRACKET    113 */ 0xDB, // [
    /* KEY_BACKSLASH   114 */ 0xDC, // \ (backslash)
    /* KEY_RBRACKET    115 */ 0xDD, // ]
    /* KEY_APOSTROPHE  116 */ 0xDE, // '
 
    // --- Multimedia (117-123) ---
    /* KEY_VOLUME_MUTE     117 */ 0xAD,
    /* KEY_VOLUME_UP       118 */ 0xAF,
    /* KEY_VOLUME_DOWN     119 */ 0xAE,
    /* KEY_MEDIA_NEXT      120 */ 0xB0,
    /* KEY_MEDIA_PREV      121 */ 0xB1,
    /* KEY_MEDIA_STOP      122 */ 0xB2,
    /* KEY_MEDIA_PLAYPAUSE 123 */ 0xB3,
};

short is_clicked(void){
    return (unsigned short)GetAsyncKeyState(VK_LBUTTON) >> 15;
}
short is_key_pressed(key_code key){
    return (unsigned short)GetAsyncKeyState(KeyToVK[key]) >> 15;
}
void sleep_ms(int delay){
    Sleep(delay);
}

void move_mouse(int x, int y){
    SetCursorPos(x, y);
}
short anym_mouse_moved(void* ctx){
    POINT start, current;
    start = *(POINT*)ctx;
    GetCursorPos(&current);

    return !(start.x == current.x && start.y == current.y);
}
short is_mouse_moved(int duration){
    POINT start;
    GetCursorPos(&start);

    return wait_expression(anym_mouse_moved, &start, duration);
}

void click(int x, int y){
    INPUT inputs[2] = {0};

    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    SetCursorPos(x, y);

    SendInput(2, inputs, sizeof(INPUT));
}

void scroll_up(int ticks){
    INPUT input = {0};

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    input.mi.mouseData = ticks * WHEEL_DELTA;

    SendInput(1, &input, sizeof(INPUT));
}
void scroll_down(int ticks){
    INPUT input = {0};

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    input.mi.mouseData = -ticks * WHEEL_DELTA;

    SendInput(1, &input, sizeof(INPUT));
}
void hold_key(key_code key){
    INPUT input = {0};

    input.type = INPUT_KEYBOARD;
    input.ki.wVk = KeyToVK[key];

    SendInput(1, &input, sizeof(INPUT));
}
void release_key(key_code key){
    INPUT input = {0};

    input.type = INPUT_KEYBOARD;
    input.ki.wVk = KeyToVK[key];
    input.ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(1, &input, sizeof(INPUT));
}
void press_key(key_code key){
    hold_key(key);
    release_key(key);
}
color get_pixel_color(int x, int y){
    HDC hdc = GetDC(NULL);
    COLORREF color_w = GetPixel(hdc, x, y);
    ReleaseDC(NULL, hdc);

    return color_w;
}