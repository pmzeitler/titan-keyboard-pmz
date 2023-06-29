#include "titan.h"


enum custom_keycodes {
    Z1R_L_OSL = SAFE_RANGE,
    Z1R_R_OSL,
	THP_TURBO_FIRE,
};

bool thp_turbo_down = false;
uint16_t thp_turbo_timer = 0;

const uint16_t PROGMEM THP_TURBO_RATE = 50;

enum combos {
  MOUSE_BOTH,
  COLUMN_BT,
  COLUMN_MD,
  COLUMN_PL,
  COLUMN_FN,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM mouseboth_combo[] = {KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM bt_combo[] = {KC_B, KC_T, COMBO_END};
const uint16_t PROGMEM md_combo[] = {KC_M, KC_D, COMBO_END};
const uint16_t PROGMEM pl_combo[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM fn_combo[] = {KC_F, KC_N, COMBO_END};

combo_t key_combos[] = {
  [MOUSE_BOTH] = COMBO(mouseboth_combo, KC_BTN3),
  [COLUMN_BT] = COMBO(bt_combo, KC_Z),
  [COLUMN_MD] = COMBO(md_combo, KC_X),
  [COLUMN_PL] = COMBO(pl_combo, KC_C),
  [COLUMN_FN] = COMBO(fn_combo, KC_V),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//layer 0 - Ewen's Default
	LAYOUT(
		         KC_UP,            KC_H, KC_B,                LT(15, KC_MUTE), 
		KC_LEFT, KC_DOWN, KC_RGHT, 
		KC_ESC, KC_ENT, 
		KC_A, KC_S, KC_D, KC_F, 
		KC_UP,
		KC_Z, KC_X, KC_C, KC_V),
//layer 1 - Phoebe's Default
	LAYOUT(
		         KC_W,             KC_B, KC_N,                LT(15, KC_TAB), 
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
		KC_LSFT, KC_Z, THP_TURBO_FIRE, 
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
//layer 7 - RESERVED
	LAYOUT(
		         KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//layer 8 - RESERVED
	LAYOUT(
		         KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//layer 9 - RESERVED
	LAYOUT(
		         KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//layer 10 - RESERVED
	LAYOUT(
		         KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//layer 11 - RESERVED
	LAYOUT(
		         KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//layer 12 - RESERVED
	LAYOUT(
		         KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//layer 13 - RESERVED
	LAYOUT(
		         KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//layer 14 - Zelda 1 Randomizer Tracker
	LAYOUT(
		         KC_MS_U,          KC_BTN1, KC_BTN2,          KC_TRNS,
		KC_MS_L, KC_MS_D, KC_MS_R, 
		KC_TRNS, KC_TRNS, 
		KC_B,    KC_M,    KC_P,    KC_F, 
		MO(16), 
		KC_T,    KC_D,    KC_L, KC_N),
//layer 15 - LAYER SWITCHING
	LAYOUT(
		         TG(14),          KC_TRNS, KC_TRNS,          KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, 
		TG(2), TG(3), TG(4), KC_TRNS,
		TG(1), 		
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
//layer 16 - Z1R - Alternate
	LAYOUT(
		         KC_Q ,          KC_Y, KC_U,          KC_TRNS,
		KC_E, KC_W, KC_R, 
		KC_TRNS, KC_TRNS, 
		KC_A, KC_S, KC_G, KC_H,
		KC_TRNS, 		
		KC_J, KC_K, KC_I, KC_O),
		
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case Z1R_L_OSL:
	
		break;
	case Z1R_R_OSL:
	
		break;
	case THP_TURBO_FIRE:
		if (record->event.pressed) {
			if (!thp_turbo_down) {
				thp_turbo_down = true;
				tap_code(KC_Z);
				thp_turbo_timer = timer_read();
			}
		} else {
			if (thp_turbo_down) {
				thp_turbo_down = false;
			}
		}
		break;
	}
	return true;
}


void matrix_init_user(void) {
}

void matrix_scan_user(void) { // The very important timer.
  if (thp_turbo_down) {
    if (timer_elapsed(thp_turbo_timer) > THP_TURBO_RATE) {
      tap_code(KC_Z);
      thp_turbo_timer = timer_read();
    }
  }
}

