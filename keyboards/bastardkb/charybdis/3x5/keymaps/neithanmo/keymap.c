/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif  // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYM,
    LAYER_NAV,
    LAYER_NUM,
    LAYER_FUN,
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)

#define CTL_BSP CTL_T(KC_BSPC)
#define SFT_SPC SFT_T(KC_SPC)
#define GUI_ENT GUI_T(KC_ENT)

#define KC_COPY LCTL(KC_C)
#define KC_CUT LCTL(KC_X)
#define KC_PEGAR LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(KC_Y)

enum tap_dance_codes {
  DANCE_1,
  DANCE_2,
  DANCE_3,
};

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_charybdis_3x5(
  // ╭───────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────────╮
          TD(DANCE_1),    KC_W,  KC_F,  KC_P,                KC_B,   KC_J, KC_L,         KC_U,         TD(DANCE_2),      KC_SCLN,
  // ├───────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────┤
          KC_A,    LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,   KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I),     KC_O,
  // ├───────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────┤
          KC_Z,    KC_X,         KC_C,         KC_D,         KC_V,   KC_K, KC_H,         KC_COMM,      KC_DOT,           KC_SLSH,
  // ╰───────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────╯
                            KC_ENT, KC_DEL,   TO(1),                     KC_BSPC, KC_SPC
  //                      ╰───────────────────────────╯               ╰──────────────────╯
  ),

  [LAYER_SYM] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       KC_ESC, KC_AT, KC_HASH, KC_DLR, KC_PERC,        KC_LBRC,    KC_LPRN,    KC_RPRN, KC_RBRC, KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       KC_TAB, KC_PEQL, KC_DQUO, KC_QUOT, KC_BSLS,     KC_AMPR,    KC_LCBR,    KC_RCBR, KC_ASTR, KC_ENT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       KC_TILD, KC_GRV, KC_LEFT, KC_RGHT, KC_PIPE,     KC_CIRC,    KC_DOWN,    KC_UP,   KC_EXLM, TO(4),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                         TO(0), KC_DEL, TO(2),         KC_LALT, TO(3)
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────╮
       KC_ESC, XXXXXXX, KC_WH_R, KC_WH_L, XXXXXXX,    KC_CUT,  KC_UNDO, LCTL(LSFT(KC_TAB)), RCTL(KC_TAB), KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
       KC_TAB, KC_BTN1, KC_WH_U, KC_WH_D, XXXXXXX,    KC_PGUP, KC_COPY, KC_PEGAR,           KC_REDO,      KC_ENT,
  // ├─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, KC_LEFT,  KC_RGHT, KC_DEL,   KC_PGDN, KC_DOWN, KC_UP,              XXXXXXX,      TO(4),
  // ╰─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────╯
                         TO(0), KC_BTN2, TO(3),       KC_LALT, TO(1)
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NUM] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_ESC, KC_MPRV, KC_MPLY, KC_MNXT, KC_UNDS,    KC_MINS, KC_7,    KC_8,    KC_9,    KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_TAB,   KC_MUTE, KC_VOLD, KC_VOLU, KC_PDOT,  KC_PEQL, KC_4,    KC_5,    KC_6,    KC_ENT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_PSLS, KC_PAST, KC_BRID,  KC_BRIU, KC_PLUS,  KC_0,    KC_1,    KC_2,    KC_3,    TO(2),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         TO(0), XXXXXXX, XXXXXXX,     KC_LALT, TO(1)
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_FUN] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_F5,   KC_F6, KC_F7, KC_F8,  RESET,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_F1, KC_F2, KC_F3,  KC_F4,  XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, TO(3),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         TO(0), XXXXXXX, XXXXXXX,     TO(1), TO(2)
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_1_dance_step(qk_tap_dance_state_t *state);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_2_dance_step(qk_tap_dance_state_t *state);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_Q);
		tap_code16(KC_Q);
		tap_code16(KC_Q);
	}
	if(state->count > 3) {
		tap_code16(KC_Q);
	}
}

uint8_t dance_1_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_1_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_Q); break;
		case SINGLE_HOLD: register_code16(KC_ESC); break;
		case DOUBLE_TAP: register_code16(KC_Q); register_code16(KC_Q); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_ESC); register_code16(KC_ESC);
	}
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_Q); break;
		case SINGLE_HOLD: unregister_code16(KC_ESC); break;
		case DOUBLE_TAP: unregister_code16(KC_Q); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESC); break;
	}
	dance_state.step = 0;
}

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_Y);
		tap_code16(KC_Y);
		tap_code16(KC_Y);
	}
	if(state->count > 3) {
		tap_code16(KC_Y);
	}
}

uint8_t dance_2_dance_step(qk_tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed) return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted) return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else return DOUBLE_TAP;
	}
	return MORE_TAPS;
}
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
	dance_state.step = dance_2_dance_step(state);
	switch (dance_state.step) {
		case SINGLE_TAP: register_code16(KC_Y); break;
		case SINGLE_HOLD: register_code16(KC_UNDS); break;
		case DOUBLE_TAP: register_code16(KC_Y); register_code16(KC_Y); break;
		case DOUBLE_SINGLE_TAP: tap_code16(KC_Y); register_code16(KC_Y);
	}
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
	wait_ms(10);
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_Y); break;
		case SINGLE_HOLD: unregister_code16(KC_UNDS); break;
		case DOUBLE_TAP: unregister_code16(KC_Y); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_Y); break;
	}
	dance_state.step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};
