#ifndef KEYBOARD_AND_CLICK_H
#define KEYBOARD_AND_CLICK_H

// --- Lettres ---
#define KEY_A 0
#define KEY_B 1
#define KEY_C 2
#define KEY_D 3
#define KEY_E 4
#define KEY_F 5
#define KEY_G 6
#define KEY_H 7
#define KEY_I 8
#define KEY_J 9
#define KEY_K 10
#define KEY_L 11
#define KEY_M 12
#define KEY_N 13
#define KEY_O 14
#define KEY_P 15
#define KEY_Q 16
#define KEY_R 17
#define KEY_S 18
#define KEY_T 19
#define KEY_U 20
#define KEY_V 21
#define KEY_W 22
#define KEY_X 23
#define KEY_Y 24
#define KEY_Z 25
 
// --- Chiffres (rangee du haut) ---
#define KEY_0 26
#define KEY_1 27
#define KEY_2 28
#define KEY_3 29
#define KEY_4 30
#define KEY_5 31
#define KEY_6 32
#define KEY_7 33
#define KEY_8 34
#define KEY_9 35
 
// --- Touches de fonction ---
#define KEY_F1 36
#define KEY_F2 37
#define KEY_F3 38
#define KEY_F4 39
#define KEY_F5 40
#define KEY_F6 41
#define KEY_F7 42
#define KEY_F8 43
#define KEY_F9 44
#define KEY_F10 45
#define KEY_F11 46
#define KEY_F12 47
#define KEY_F13 48
#define KEY_F14 49
#define KEY_F15 50
#define KEY_F16 51
#define KEY_F17 52
#define KEY_F18 53
#define KEY_F19 54
#define KEY_F20 55
#define KEY_F21 56
#define KEY_F22 57
#define KEY_F23 58
#define KEY_F24 59
 
// --- Fleches directionnelles ---
#define KEY_LEFT 60
#define KEY_RIGHT 61
#define KEY_UP 62
#define KEY_DOWN 63
 
// --- Touches de controle / modificateurs ---
#define KEY_LSHIFT 64
#define KEY_RSHIFT 65
#define KEY_LCONTROL 66
#define KEY_RCONTROL 67
#define KEY_LALT 68
#define KEY_RALT 69
#define KEY_LWIN 70
#define KEY_RWIN 71
#define KEY_APPS 72
#define KEY_CAPSLOCK 73
#define KEY_NUMLOCK 74
#define KEY_SCROLLLOCK 75
 
// --- Touches speciales ---
#define KEY_ESCAPE 76
#define KEY_TAB 77
#define KEY_SPACE 78
#define KEY_ENTER 79
#define KEY_BACKSPACE 80
#define KEY_INSERT 81
#define KEY_DELETE 82
#define KEY_HOME 83
#define KEY_END 84
#define KEY_PAGEUP 85
#define KEY_PAGEDOWN 86
#define KEY_PRINTSCREEN 87
#define KEY_PAUSE 88
#define KEY_MENU 89
 
// --- Pave numerique ---
#define KEY_NUMPAD0 90
#define KEY_NUMPAD1 91
#define KEY_NUMPAD2 92
#define KEY_NUMPAD3 93
#define KEY_NUMPAD4 94
#define KEY_NUMPAD5 95
#define KEY_NUMPAD6 96
#define KEY_NUMPAD7 97
#define KEY_NUMPAD8 98
#define KEY_NUMPAD9 99
#define KEY_NUMPAD_ADD 100
#define KEY_NUMPAD_SUBTRACT 101
#define KEY_NUMPAD_MULTIPLY 102
#define KEY_NUMPAD_DIVIDE 103
#define KEY_NUMPAD_DECIMAL 104
#define KEY_NUMPAD_ENTER 105
 
// --- Ponctuation / symboles (disposition US/OEM) ---
#define KEY_SEMICOLON 106      // ;
#define KEY_EQUAL 107          // =
#define KEY_COMMA 108          // ,
#define KEY_MINUS 109          // -
#define KEY_PERIOD 110         // .
#define KEY_SLASH 111          // /
#define KEY_GRAVE 112          // `
#define KEY_LBRACKET 113       // [
#define KEY_BACKSLASH 114      // backslash
#define KEY_RBRACKET 115       // ]
#define KEY_APOSTROPHE 116     // '
 
// --- Touches multimedia (optionnel) ---
#define KEY_VOLUME_MUTE 117
#define KEY_VOLUME_UP 118
#define KEY_VOLUME_DOWN 119
#define KEY_MEDIA_NEXT 120
#define KEY_MEDIA_PREV 121
#define KEY_MEDIA_STOP 122
#define KEY_MEDIA_PLAYPAUSE 123
 
// ============================================================


#define DELAY 100

#define GetRedValue(c) (c & 0xFF)
#define GetGreenValue(c) (c & 0xFF00)
#define GetBlueValue(c) (c & 0xFF0000)

#define KEY_A 0

typedef unsigned short key_code;

typedef unsigned int color;

void sleep_ms(int delay);

void click(int x, int y);
short is_clicked(void);
void move_mouse(int x, int y);
short is_mouse_moved(int duration);
void scroll_down(int ticks);
void scroll_up(int ticks);
void release_key(key_code key);
void hold_key(key_code key);
void press_key(key_code key);
short is_key_pressed(key_code key);
color get_pixel_color(int x, int y);

#endif  