#include "titan.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//layer 0 - Ewen's Default
	LAYOUT(
		         KC_UP,            KC_H, KC_B,                LT(7, KC_MUTE), 
		KC_LEFT, KC_DOWN, KC_RGHT, 
		KC_ESC, KC_ENT, 
		KC_A, KC_S, KC_D, KC_F, 
		KC_UP,
		KC_Z, KC_X, KC_C, KC_V),
//layer 1 - Phoebe's Default
	LAYOUT(
		         KC_W,             KC_B, KC_N,                LT(7, KC_TAB), 
		KC_A, KC_S, KC_D, 
		KC_ESC, KC_ENT, 
		KC_Y, KC_U, KC_I, KC_O, 
		KC_SPACE,
		KC_H, KC_J, KC_K, KC_L),
//layer 2 - Arrows instead of WASD		
	LAYOUT(
		         KC_UP,            KC_TRNS, KC_TRNS,          KC_TRNS, 
		KC_LEFT, KC_DOWN, KC_RIGHT, 
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//layer 3 - QWER/1234 instead of right hand actions (League of Legends etc.)
	LAYOUT(
		         KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, 
		KC_1, KC_2, KC_3, KC_4, 
		KC_TRNS,
		KC_Q, KC_W, KC_E, KC_R),
//layer 4 - TouhouPad v2 Emulation
	LAYOUT(
		         KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_LSFT, KC_Z, KC_TRNS, 
		KC_ESC, KC_ENT, 
		KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, 
		KC_X, 
		KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS),
//layer 5 - RESERVED
	LAYOUT(
		         KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//layer 6 - RESERVED
	LAYOUT(
		         KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//layer 7 - LAYER SWITCHING
	LAYOUT(
		         KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, 
		TG(2), TG(3), KC_TRNS, KC_TRNS,
		TG(1), 		
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
      return false; /* Don't process further events if user function exists and returns false */
    }
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_WH_U, 10);
        } else {
            tap_code_delay(KC_WH_D, 10);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_WH_U, 10);
        } else {
            tap_code_delay(KC_WH_D, 10);
        }
    }
    return true;
}

void matrix_init_user(void) {
}
