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
/*#include "keymap_spanish.h"*/

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYM,
    LAYER_NUM,
    LAYER_NAV,
    LAYER_FUN,
};

// ES_NTIL

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

// MT modifiers
#define LALT_R LALT_T(KC_R)
#define RALT_I RALT_T(KC_I)
#define LCTL_S LCTL_T(KC_S)
#define RCTL_E RCTL_T(KC_E)
#define LS_T LSFT_T(KC_T)
#define RSFT_N RSFT_T(KC_N)
// tap-hold
#define Y_OR_ LT(0, KC_Y)
#define O_MINS LT(0, KC_O)
#define H_DOWN LT(0, KC_H)
#define COMMA_UP LT(0, KC_COMM)
#define C_LEFT LT(0, KC_C)
#define D_RIGHT LT(0, KC_D)

// combos
enum combo_events {
    ESC,
    NAV,
    CAPS_LOCK,
    BUFF_NEXT,
    BUFF_PREV,
    /*EMAIL,*/
    COMBO_LENGTH
};

const uint16_t PROGMEM esc_combo[]    = {LCTL_S, RCTL_E, COMBO_END};
const uint16_t PROGMEM to_nav_combo[] = {C_LEFT, COMMA_UP, COMBO_END};
const uint16_t PROGMEM buffer_prev[]  = {LALT_R, LS_T, COMBO_END};
const uint16_t PROGMEM buffer_next[]  = {RALT_I, RSFT_N, COMBO_END};
const uint16_t PROGMEM caps_word[]    = {KC_F, KC_U, COMBO_END};
const uint16_t PROGMEM email[]        = {KC_G, KC_M, COMBO_END};

uint16_t COMBO_LEN = COMBO_LENGTH;

combo_t key_combos[] = {
    [ESC] = COMBO_ACTION(esc_combo), [NAV] = COMBO_ACTION(to_nav_combo), [CAPS_LOCK] = COMBO_ACTION(caps_word), [BUFF_NEXT] = COMBO_ACTION(buffer_next), [BUFF_PREV] = COMBO_ACTION(buffer_prev),
    /*[EMAIL]= COMBO_ACTION(email),*/
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case ESC: {
            if (pressed) {
                tap_code16(KC_ESC);
            }
            break;
        }
        case NAV: {
            if (pressed) {
                layer_on(LAYER_NAV);
            }
            break;
        }
        case CAPS_LOCK: {
            if (pressed) {
                caps_word_on();
            }
            break;
        }
        // to be used in  vim to go to next buffer
        case BUFF_NEXT: {
            if (pressed) {
                SEND_STRING(":bn");
                tap_code16(KC_ENT);
            }
            break;
        }
        // to be used in  vim to go to previous buffer
        case BUFF_PREV: {
            if (pressed) {
                SEND_STRING(":bp");
                tap_code16(KC_ENT);
            }
            break;
        }
            /*case EMAIL: {*/
            /*if (pressed){*/
            /*SEND_STRING("neithanmo@gmail.com");*/
            /*}*/
            /*break;*/
        /*}*/
        default:
            break;
    }
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [LAYER_BASE] = LAYOUT_charybdis_3x5(
  // ╭───────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────────╮
       KC_Q,    KC_W,   KC_F,   KC_P,       KC_B,                    KC_J, KC_L,   KC_U,     Y_OR_,  KC_SCLN,
  // ├───────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────┤
       KC_A,    LALT_R, LCTL_S, LS_T,    KC_G,                       KC_M, RSFT_N, RCTL_E,   RALT_I, O_MINS,
  // ├───────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────┤
       KC_Z,    KC_X,   C_LEFT, D_RIGHT,    KC_V,                    KC_K, H_DOWN, COMMA_UP, KC_DOT, KC_SLSH,
  // ╰───────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────╯
        LT(LAYER_NUM, KC_ENT),  LT(LAYER_SYM, KC_TAB), KC_MEH,                     KC_LWIN, LT(LAYER_SYM,KC_SPC)
  // ╰───────────────────────────────────────────────────────╯                  ╰────────────────────────────────────╯
  ),

  [LAYER_SYM] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────╮
       KC_BSPC, KC_AT, KC_HASH, KC_DLR, KC_PERC,        KC_LBRC,    KC_LPRN,    KC_RPRN, KC_RBRC, KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       KC_TAB, KC_PEQL, KC_DQUO, KC_QUOT, KC_BSLS,     KC_AMPR,    KC_LCBR,    KC_RCBR, KC_ASTR, KC_ENT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────┤
       KC_TILD, KC_GRV, KC_LEFT, KC_RGHT, KC_PIPE,     KC_CIRC,    KC_DOWN,    KC_UP,   KC_EXLM, MO(LAYER_FUN),
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────╯
        KC_BSPC, XXXXXXX, XXXXXXX,                        KC_DEL, XXXXXXX
  //    ╰───────────────────────────╯                     ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭────────────────────────────────────────────────────────────╮
       KC_ESC, KC_WH_L, KC_PGUP, KC_PGDN, KC_WH_R,    KC_CUT,  KC_UNDO, LCTL(LSFT(KC_TAB)), RCTL(KC_TAB), KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
       KC_TAB, KC_BTN1, KC_WH_U, KC_WH_D, XXXXXXX,    XXXXXXX, KC_COPY, KC_PEGAR,           KC_REDO,      KC_ENT,
  // ├─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────┤
       XXXXXXX, KC_RCTL, KC_LEFT,  KC_RGHT, KC_DEL,   XXXXXXX, KC_DOWN, KC_UP,              KC_RALT,      MO(LAYER_FUN),
  // ╰─────────────────────────────────────────────┤ ├────────────────────────────────────────────────────────────╯
           TO(LAYER_BASE), KC_BTN2, XXXXXXX,                 KC_LALT, KC_ENT
  //     ╰───────────────────────────────────────╯       ╰──────────────────────╯
  ),

  [LAYER_NUM] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_ESC, KC_MPRV, KC_MPLY, KC_MNXT, KC_UNDS,    KC_MINS, KC_7,    KC_8,    KC_9,    KC_BSPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_TAB,   KC_MUTE, KC_VOLU, KC_VOLD, KC_DOT,   KC_PEQL, KC_4,    KC_5,    KC_6,    KC_SPC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_PSLS, KC_PAST, KC_BRIU,  KC_BRID, KC_PLUS,  KC_0,    KC_1,    KC_2,    KC_3,    KC_PLUS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
             XXXXXXX, KC_ENT, XXXXXXX,                   KC_LALT,    KC_DOT
  //        ╰───────────────────────────╯               ╰───────────────────────╯
  ),

  [LAYER_FUN] = LAYOUT_charybdis_3x5(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, KC_F7, KC_F8, KC_F9, KC_PSCR,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, KC_F4, KC_F5, KC_F6,  RESET,            XXXXXXX, KC_F10, KC_F11, KC_F12, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, KC_F1, KC_F2,  KC_F3,  XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
            TO(LAYER_BASE), XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX
  //      ╰───────────────────────────────────╯          ╰───────────────────────────────╯
  ),
};

// clang-format on
static bool process_tap_or_long_press_key(keyrecord_t* record, uint16_t long_press_keycode) {
    if (record->tap.count == 0) { // Key is being held.
        if (record->event.pressed) {
            register_code16(long_press_keycode);
        } else {
            unregister_code16(long_press_keycode);
        }
        return false; // Skip default handling.
    }
    return true; // Continue default handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case Y_OR_: // Y on tap and _ on long press.
            return process_tap_or_long_press_key(record, KC_UNDS);
        case O_MINS: // Comma on tap, Ctrl+C on long press.
            return process_tap_or_long_press_key(record, KC_MINS);
        case H_DOWN: // Comma on tap, Ctrl+C on long press.
            return process_tap_or_long_press_key(record, KC_DOWN);
        case COMMA_UP: // Comma on tap, Ctrl+C on long press.
            return process_tap_or_long_press_key(record, KC_UP);
        case D_RIGHT: // Comma on tap, Ctrl+C on long press.
            return process_tap_or_long_press_key(record, KC_RIGHT);
        case C_LEFT: // Comma on tap, Ctrl+C on long press.
            return process_tap_or_long_press_key(record, KC_LEFT);
    }

    return true;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    static char x = 0;
    static char y = 0;
    if (x != mouse_report.x && y != mouse_report.y) {
        x = mouse_report.x;
        y = mouse_report.y;
        if (!IS_LAYER_ON(LAYER_NAV)) layer_on(LAYER_NAV);
    }
    return mouse_report;
}
