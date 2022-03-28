/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

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
  DANCE_4,
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


static tap dance_state_quit = {
    .is_press_action = true,
    .step = 0
};

static tap dance_state_mins = {
    .is_press_action = true,
    .step = 0
};

static tap dance_state_tab = {
    .is_press_action = true,
    .step = 0
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, TD(DANCE_1),    KC_W,  KC_F,  KC_P, KC_B,                       KC_J, KC_L,   KC_U, TD(DANCE_2),  KC_SCLN,  KC_PMNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_A,    LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), TD(DANCE_4),   KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I),     TD(DANCE_3),  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_Z, KC_X,  TD(DANCE_5),     TD(DANCE_6),         KC_V,      KC_K, TD(DANCE_7), TD(DANCE_8),      KC_DOT,           KC_SLSH,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DEL,KC_ENT,  TO(LAYER_SYM),     KC_BSPC,KC_SPC, TO(LAYER_NUM)
                                      //`--------------------------'  `--------------------------'

  ),

  [LAYER_SYM] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       XXXXXXX,KC_ESC, KC_AT, KC_HASH, KC_DLR, KC_PERC,        KC_LBRC,    KC_LPRN,    KC_RPRN, KC_RBRC, KC_BSPC,XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       XXXXXXX,KC_TAB, KC_PEQL, KC_DQUO, KC_QUOT, KC_BSLS,     KC_AMPR,    KC_LCBR,    KC_RCBR, KC_ASTR, KC_SPC,XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       XXXXXXX,KC_TILD, KC_GRV, KC_LEFT, KC_RGHT, KC_PIPE,     KC_CIRC,    KC_DOWN,    KC_UP,   KC_EXLM, TO(4),XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
                         TO(0), KC_ENT, TO(2),         KC_LALT, TO(3), XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────╮
       XXXXXXX,KC_ESC, XXXXXXX, KC_WH_R, KC_WH_L, XXXXXXX,    KC_CUT,  KC_UNDO, LCTL(LSFT(KC_TAB)), RCTL(KC_TAB), KC_BSPC,XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
       XXXXXXX,KC_TAB, KC_BTN1, KC_WH_U, KC_WH_D, XXXXXXX,    KC_PGUP, KC_COPY, KC_PEGAR,           KC_REDO,      KC_ENT,XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
       XXXXXXX,XXXXXXX, XXXXXXX, KC_LEFT,  KC_RGHT, KC_DEL,   KC_PGDN, KC_DOWN, KC_UP,              XXXXXXX,      TO(4),XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────╯
                         TO(LAYER_BASE), KC_BTN2,TO(LAYER_SYM), KC_LALT, TO(LAYER_NUM), XXXXXXX
  //                   ╰───────────────────────────╯           ╰──────────────────╯
  ),

  [LAYER_NUM] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX,KC_ESC, KC_MPRV, KC_MPLY, KC_MNXT, KC_UNDS,    KC_MINS, KC_7,    KC_8,    KC_9,    KC_BSPC,XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX,KC_TAB,   KC_MUTE, KC_VOLD, KC_VOLU, KC_DOT,   KC_PEQL, KC_4,    KC_5,    KC_6,    KC_SPC,XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX,KC_PSLS, KC_PAST, KC_BRID,  KC_BRIU, KC_PLUS,  KC_0,    KC_1,    KC_2,    KC_3,    TO(LAYER_FUN),XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         TO(0), KC_ENT, TO(LAYER_SYM),     KC_LALT, TO(LAYER_NAV), XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_FUN] = LAYOUT_split_3x6_3(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX,KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX,KC_F5,   KC_F6, KC_F7, KC_F8,  RESET,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX,KC_F1, KC_F2, KC_F3,  KC_F4,  XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, TO(3),XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         TO(0), XXXXXXX, XXXXXXX,     TO(1), TO(2),XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};

void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_1_dance_step(qk_tap_dance_state_t *state);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_2_dance_step(qk_tap_dance_state_t *state);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_3_dance_step(qk_tap_dance_state_t *state);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_4_dance_step(qk_tap_dance_state_t *state);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

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
    dance_state_quit.step = dance_1_dance_step(state);
    switch (dance_state_quit.step) {
        case SINGLE_TAP: register_code16(KC_Q); break;
        case SINGLE_HOLD: register_code16(KC_ESC); break;
        case DOUBLE_TAP: register_code16(KC_Q); register_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Q); register_code16(KC_Q);
        case DOUBLE_HOLD: tap_code16(KC_ESC); register_code16(KC_ESC);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    /*wait_ms(10);*/
    switch (dance_state_quit.step) {
        case SINGLE_TAP: unregister_code16(KC_Q); break;
        case SINGLE_HOLD: unregister_code16(KC_ESC); break;
        case DOUBLE_TAP: unregister_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Q); register_code16(KC_Q);break;
        case DOUBLE_HOLD: tap_code16(KC_ESC); register_code16(KC_ESC);
    }
    dance_state_quit.step = 0;
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


void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_G);
        tap_code16(KC_G);
        tap_code16(KC_G);
    }
    if(state->count > 3) {
        tap_code16(KC_G);
    }
}

uint8_t dance_4_dance_step(qk_tap_dance_state_t *state) {
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
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state_tab.step = dance_4_dance_step(state);
    switch (dance_state_tab.step) {
        case SINGLE_TAP: register_code16(KC_G); break;
        case SINGLE_HOLD: register_code16(KC_TAB); break;
        case DOUBLE_HOLD: register_code16(KC_TAB); break;
        case DOUBLE_TAP: register_code16(KC_G); register_code16(KC_G); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_G); register_code16(KC_G);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    /*wait_ms(10);*/
    switch (dance_state_tab.step) {
        case SINGLE_TAP: unregister_code16(KC_G); break;
        case SINGLE_HOLD: unregister_code16(KC_TAB); break;
        case DOUBLE_HOLD: register_code16(KC_TAB); break;
        case DOUBLE_TAP: unregister_code16(KC_G); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_G); break;
    }
    dance_state_tab.step = 0;
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
    [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
    [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
    [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
    [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
    [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
    [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
    [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
};



#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}


void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case LAYER_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case LAYER_SYM:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case LAYER_NAV:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
        case LAYER_NUM:
            oled_write_ln_P(PSTR("Number"), false);
            break;
        case LAYER_FUN:
            oled_write_ln_P(PSTR("Function"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
