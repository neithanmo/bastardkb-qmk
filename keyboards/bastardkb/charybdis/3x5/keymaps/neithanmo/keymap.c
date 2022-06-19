/*
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

enum combo_events {
  ESC,
  COMBO_LENGTH
};

const uint16_t PROGMEM esc_combo[] = {LCTL_T(KC_S), RCTL_T(KC_E), COMBO_END};

uint16_t COMBO_LEN = COMBO_LENGTH;

combo_t key_combos[] = {
  [ESC] = COMBO_ACTION(esc_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case ESC:
      if (pressed) {
        tap_code16(KC_ESC);
      }
      break;
  }
}


enum tap_dance_codes {
  DANCE_2,
  DANCE_3,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
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


static tap dance_state_mins = {
    .is_press_action = true,
    .step = 0
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [LAYER_BASE] = LAYOUT_charybdis_3x5(
  // ╭───────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────────╮
       KC_Q,    KC_W,  KC_F,  KC_P,                KC_B,             KC_J, KC_L,         KC_U,         TD(DANCE_2),      KC_SCLN,
  // ├───────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────┤
      KC_A,    LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,   KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I),     TD(DANCE_3),
  // ├───────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────┤
      KC_Z, KC_X,  TD(DANCE_5),     TD(DANCE_6),         KC_V,      KC_K, TD(DANCE_7), TD(DANCE_8),      KC_DOT,           KC_SLSH,
  // ╰───────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────╯
        LT(LAYER_NUM, KC_ENT), KC_LWIN, KC_TAB,                   TO(LAYER_NAV), LT(LAYER_SYM,KC_SPC)
  // ╰───────────────────────────────────────────────────────╯   ╰────────────────────────────────────╯
  ),

  [LAYER_SYM] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       KC_ESC, KC_AT, KC_HASH, KC_DLR, KC_PERC,        KC_LBRC,    KC_LPRN,    KC_RPRN, KC_RBRC, KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       KC_TAB, KC_PEQL, KC_DQUO, KC_QUOT, KC_BSLS,     KC_AMPR,    KC_LCBR,    KC_RCBR, KC_ASTR, KC_SPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       KC_TILD, KC_GRV, KC_LEFT, KC_RGHT, KC_PIPE,     KC_CIRC,    KC_DOWN,    KC_UP,   KC_EXLM, TO(4),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
        TO(LAYER_BASE), KC_ENT, TO(LAYER_NUM),             KC_LALT, XXXXXXX
  //    ╰──────────────────────────────────────╯          ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────╮
       KC_ESC, KC_WH_L, KC_PGUP, KC_PGDN, KC_WH_R,    KC_CUT,  KC_UNDO, LCTL(LSFT(KC_TAB)), RCTL(KC_TAB), KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
       KC_TAB, KC_BTN1, KC_WH_U, KC_WH_D, XXXXXXX,    XXXXXXX, KC_COPY, KC_PEGAR,           KC_REDO,      KC_ENT,
  // ├─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, KC_LEFT,  KC_RGHT, KC_DEL,   XXXXXXX, KC_DOWN, KC_UP,              XXXXXXX,      TO(LAYER_FUN),
  // ╰─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────╯
           TO(LAYER_BASE), KC_BTN2,TO(LAYER_SYM),         KC_LALT, TO(LAYER_NUM)
  //     ╰───────────────────────────────────────╯       ╰──────────────────────╯
  ),

  [LAYER_NUM] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_ESC, KC_MPRV, KC_MPLY, KC_MNXT, KC_UNDS,    KC_MINS, KC_7,    KC_8,    KC_9,    KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_TAB,   KC_MUTE, KC_VOLU, KC_VOLD, KC_DOT,   KC_PEQL, KC_4,    KC_5,    KC_6,    KC_SPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_PSLS, KC_PAST, KC_BRIU,  KC_BRID, KC_PLUS,  KC_0,    KC_1,    KC_2,    KC_3,    TO(LAYER_FUN),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         TO(LAYER_BASE), KC_ENT, TO(LAYER_SYM),     KC_LALT, TO(LAYER_NAV)
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_FUN] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_F5,   KC_F6, KC_F7, KC_F8,  RESET,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_F1, KC_F2, KC_F3,  KC_F4,  XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, TO(LAYER_NUM),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         TO(LAYER_BASE), XXXXXXX, XXXXXXX,     TO(LAYER_SYM), TO(LAYER_NAV)
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on


void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_2_dance_step(qk_tap_dance_state_t *state);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_3_dance_step(qk_tap_dance_state_t *state);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_5_dance_step(qk_tap_dance_state_t *state);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_6_dance_step(qk_tap_dance_state_t *state);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_7_dance_step(qk_tap_dance_state_t *state);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_8_dance_step(qk_tap_dance_state_t *state);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_9_dance_step(qk_tap_dance_state_t *state);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);


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
        case DOUBLE_HOLD: tap_code16(KC_UNDS); register_code16(KC_UNDS); break;
        case DOUBLE_TAP: register_code16(KC_Y); register_code16(KC_Y); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Y); register_code16(KC_Y);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    /*wait_ms(10);*/
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_Y); break;
        case SINGLE_HOLD: unregister_code16(KC_UNDS); break;
        case DOUBLE_HOLD: tap_code16(KC_UNDS); register_code16(KC_UNDS); break;
        case DOUBLE_TAP: unregister_code16(KC_Y); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Y); break;
    }
    dance_state.step = 0;
}

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if(state->count > 3) {
        tap_code16(KC_O);
    }
}

uint8_t dance_3_dance_step(qk_tap_dance_state_t *state) {
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
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state_mins.step = dance_3_dance_step(state);
    switch (dance_state_mins.step) {
        case SINGLE_TAP: register_code16(KC_O); break;
        case SINGLE_HOLD: register_code16(KC_MINS); break;
        case DOUBLE_HOLD: tap_code16(KC_MINS); register_code16(KC_MINS); break;
        case DOUBLE_TAP: register_code16(KC_O); register_code16(KC_O); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_O); register_code16(KC_O);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    /*wait_ms(10);*/
    switch (dance_state_mins.step) {
        case SINGLE_TAP: unregister_code16(KC_O); break;
        case SINGLE_HOLD: unregister_code16(KC_MINS); break;
        case DOUBLE_HOLD: tap_code16(KC_MINS); register_code16(KC_MINS); break;
        case DOUBLE_TAP: unregister_code16(KC_O); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_O); break;
    }
    dance_state_mins.step = 0;
}

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 3) {
		tap_code16(KC_C);
		tap_code16(KC_C);
		tap_code16(KC_C);
	}
	if(state->count > 3) {
		tap_code16(KC_C);
	}
}

uint8_t dance_5_dance_step(qk_tap_dance_state_t *state) {
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
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_5_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_C); break;
        case SINGLE_HOLD: register_code16(KC_LEFT); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT); break;
        case DOUBLE_TAP: register_code16(KC_C); register_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_C); register_code16(KC_C);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
	/*wait_ms(10);*/
	switch (dance_state.step) {
		case SINGLE_TAP: unregister_code16(KC_C); break;
		case SINGLE_HOLD: unregister_code16(KC_LEFT); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT); break;
		case DOUBLE_TAP: unregister_code16(KC_C); break;
		case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
	}
	dance_state.step = 0;
}

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_D);
        tap_code16(KC_D);
        tap_code16(KC_D);
    }
    if(state->count > 3) {
        tap_code16(KC_D);
    }
}

uint8_t dance_6_dance_step(qk_tap_dance_state_t *state) {
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
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_6_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_D); break;
        case SINGLE_HOLD: register_code16(KC_RGHT); break;
        case DOUBLE_HOLD: register_code16(KC_RGHT); break;
        case DOUBLE_TAP: register_code16(KC_D); register_code16(KC_D); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_D); register_code16(KC_D);
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    /*wait_ms(10);*/
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_D); break;
        case SINGLE_HOLD: unregister_code16(KC_RGHT); break;
        case DOUBLE_HOLD: register_code16(KC_RGHT); break;
        case DOUBLE_TAP: unregister_code16(KC_D); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_D); break;
    }
    dance_state.step = 0;
}

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_H);
        tap_code16(KC_H);
        tap_code16(KC_H);
    }
    if(state->count > 3) {
        tap_code16(KC_H);
    }
}

uint8_t dance_7_dance_step(qk_tap_dance_state_t *state) {
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
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_7_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_H); break;
        case SINGLE_HOLD: register_code16(KC_DOWN); break;
        case DOUBLE_HOLD: register_code16(KC_DOWN); break;
        case DOUBLE_TAP: register_code16(KC_H); register_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_H); register_code16(KC_H);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    /*wait_ms(10);*/
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_H); break;
        case SINGLE_HOLD: unregister_code16(KC_DOWN); break;
        case DOUBLE_HOLD: register_code16(KC_DOWN); break;
        case DOUBLE_TAP: unregister_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_H); break;
    }
    dance_state.step = 0;
}

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMM);
        tap_code16(KC_COMM);
        tap_code16(KC_COMM);
    }
    if(state->count > 3) {
        tap_code16(KC_COMM);
    }
}

uint8_t dance_8_dance_step(qk_tap_dance_state_t *state) {
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
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_8_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_COMM); break;
        case SINGLE_HOLD: register_code16(KC_UP); break;
        case DOUBLE_HOLD: register_code16(KC_UP); break;
        case DOUBLE_TAP: register_code16(KC_COMM); register_code16(KC_COMM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMM); register_code16(KC_COMM);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    /*wait_ms(10);*/
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_COMM); break;
        case SINGLE_HOLD: unregister_code16(KC_UP); break;
        case DOUBLE_HOLD: register_code16(KC_UP); break;
        case DOUBLE_TAP: unregister_code16(KC_COMM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMM); break;
    }
    dance_state.step = 0;
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
    [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
    [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
    [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
    [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
    [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
};

