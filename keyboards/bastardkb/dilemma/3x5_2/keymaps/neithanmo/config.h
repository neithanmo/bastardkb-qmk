/**
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#pragma once

#ifdef VIA_ENABLE
/* Via configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 8
#endif // VIA_ENABLE

/**
 * Configure the global tapping term (default: 200ms).
 * If you have a lot of accidental mod activations, crank up the tapping term.
 *
 * See docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-term
 */
#ifndef TAPPING_TERM
#    define TAPPING_TERM 280
#endif // TAPPING_TERM
//
#define PERMISSIVE_HOLD

#define IGNORE_MOD_TAP_INTERRUPT
// #define HOLD_ON_OTHER_KEY_PRESS
#define TAPPING_FORCE_HOLD
#define RETRO_TAPPING
#define ONESHOT_TAP_TOGGLE 2 /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000

// disable trackpad taps
// #define CIRQUE_PINNACLE_TAPPING_TERM 0

/**
 * Enable rapid switch from tap to hold.  Disable auto-repeat when pressing key
 * twice, except for one-shot keys.
 *
 * See docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-force-hold
 */
// #define TAPPING_FORCE_HOLD

/*
 * Tap-or-Hold decision modes.
 *
 * Note that the following flags behave differently when combined (ie. when 2 or
 * more are enabled).
 *
 * See bit.ly/tap-or-hold for a visual explanation of the following tap-or-hold
 * decision modes.
 */

/**
 * Faster tap-hold trigger.
 *
 * Without `PERMISSIVE_HOLD`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 e🠕 Mod(a)🠕 ➞ ae
 * With `PERMISSIVE_HOLD`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 e🠕 Mod(a)🠕 ➞ Mod+e
 *
 * See docs.qmk.fm/using-qmk/software-features/tap_hold#permissive-hold
 */
// #define PERMISSIVE_HOLD

/**
 * Prevent normal rollover on alphas from accidentally triggering mods.
 *
 * Ignores key presses that interrupt a mod-tap.  Must-have for Home Row mod.
 *
 * Without `IGNORE_MOD_TAP_INTERRUPT`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 Mod(a)🠕 e🠕 ➞ Mod+e
 * With `IGNORE_MOD_TAP_INTERRUPT`, within `TAPPING_TERM`:
 *   Mod(a)🠗 e🠗 Mod(a)🠕 e🠕 ➞ ae
 *
 * See docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
 */
// #define IGNORE_MOD_TAP_INTERRUPT

/** Dilemma-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Flip horizontal direction for drag-scroll.
#    define DILEMMA_DRAGSCROLL_REVERSE_X
// #define DILEMMA_DRAGSCROLL_REVERSE_Y
#endif // POINTING_DEVICE_ENABLE

#define COMBO_MUST_HOLD_MODS
#define COMBO_TERM 60

#define COMBO_ONLY_FROM_LAYER 0
