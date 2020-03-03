#pragma once
const enum  standartKeys {
	key_Q = 113, key_W = 119, key_E = 101, key_R = 114, key_T = 116, key_Y = 121, key_U = 117, key_I = 105, key_O = 111, key_P = 112, key_LeftBracket = 91, key_RightBracket = 93,
	key_A = 97, key_S = 115, key_D = 100, key_F = 102, key_G = 103, key_H = 104, key_J = 106, key_K = 107, key_L = 108, key_Semicolon = 59, key_Quotes = 39,
	key_Z = 122, key_X = 120, key_C = 99, key_V = 118, key_B = 98, key_N = 110, key_M = 109, key_triangularArrowLeft = 44, key_triangularArrowRight = 46, key_SLASH = 47,
	key_ENTER = 13, key_SPACE = 32, key_TILDA = 96, key_TAB = 9, key_BACKSPACE = 8, key_BACKSLASH = 92
};
//0 to enter Special
const enum specialsKeysPlus0 {
	key_F1 = 59, key_F2, key_F3, key_F4, key_F5, key_F6, key_F7, key_F8, key_F9, key_F10
};
//224 to enter Special
const enum specialKeysPlus224 {
	key_LeftArrow = 75, key_RightArrow = 77, key_UpArrow = 72, key_DownArrow = 80, key_F11 = 133, key_F12 = 134

};

int keyHandler();