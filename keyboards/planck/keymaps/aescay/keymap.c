/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _PLOVER,
  _ADJUST,
  _MOVE,
  _SYMBOLS,
  _NUMBERS,
  _WINDOW
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  PLOVER,
  EXT_PLV
};

enum tap_dance_declarations {
  TD_CAPS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty (aka Main)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  |Shift | GUI  |      | Symbl|Space |      |      |      | Nums |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    LCTL_T(KC_S),    LALT_T(KC_D),    LGUI_T(KC_F),    KC_G,    KC_H, RGUI_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), KC_SCLN, KC_QUOT,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    COLEMAK, KC_LCTL, KC_LALT, _______, TD(TD_CAPS), _______, OSL(_SYMBOLS), KC_SPC, _______, _______, _______, TO(_NUMBERS)
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Qwerty| Ctrl | Alt  |Window| Shift|      | Symbl|Space | Nums |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_TAB,  KC_A,    LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T),    KC_G,    KC_M, RGUI_T(KC_N), RALT_T(KC_E), RCTL_T(KC_I),    KC_O,    KC_QUOT,
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    QWERTY, XXXXXXX, XXXXXXX, TO(_WINDOW), TD(TD_CAPS), XXXXXXX, OSL(_SYMBOLS), KC_SPC, TO(_NUMBERS), XXXXXXX, XXXXXXX, XXXXXXX 
),

/* Move
 * ,-----------------------------------------------------------------------------------.
 * |      |      | ScrlL| MUp  | ScrlR|      | Back | PTab | NTab | Fwd  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | MLeft| MDown| MRigt|      | Left | Down | Up   |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | RClik| ScrlU| ScrlD|      | LClik| ACEL0| ACEL1| ACEL2|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Qwerty|      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = LAYOUT_planck_grid(
    _______, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, XXXXXXX, LGUI(KC_LBRACKET), LCTL(LSFT(KC_TAB)), RCTL(KC_TAB), LGUI(KC_RBRACKET), _______, _______,
    _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
    _______, XXXXXXX, KC_BTN2, KC_WH_U, KC_WH_D, XXXXXXX, KC_BTN1, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
    XXXXXXX, _______, _______, XXXXXXX, _______, TO(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      | !    |  @   | #    | $    | %    | ^    | &    | *    |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ~   | =    |  -   |  _   |  `   | \    | (    | )    | |    |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | {    | [    | ]    | }    |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Qwerty| Move |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR, XXXXXXX, XXXXXXX, _______,
    _______, KC_TILD, KC_EQL,  KC_MINS, KC_UNDS, KC_GRV,  KC_BSLASH, KC_LPRN, KC_RPRN, KC_PIPE, XXXXXXX, XXXXXXX, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, XXXXXXX, _______, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_QWERTY), TO(_MOVE), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Play | Prev | Next |      | +    | 7    | 8    | 9    | -    |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Vol- | Vol+ |      | *    | 4    | 5    | 6    | /    |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Disp-| Disp+|      |      | 1    | 2    | 3    | =    |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Qwerty|      |      | 0    | .    |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBERS] = LAYOUT_planck_grid(
    _______, XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, KC_PLUS, KC_7, KC_8, KC_9, KC_MINS, _______, 
    _______, XXXXXXX, XXXXXXX, KC__VOLDOWN, KC__VOLUP, XXXXXXX, KC_ASTR, KC_4, KC_5, KC_6, KC_SLSH, XXXXXXX, 
    XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, KC_1, KC_2, KC_3, KC_EQL, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_QWERTY), XXXXXXX, KC_0, KC_DOT, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Window Manager
 * ,-----------------------------------------------------------------------------------.
 * |      |      | Prev |  Up  | Next |      | TopL | TopR |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Left | Down |Right |      | BotL | BotR |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Qwerty|      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_WINDOW] = LAYOUT_planck_grid(
    _______, XXXXXXX, A(C(G(KC_LEFT))), A(C(KC_UP)), A(C(G(KC_RIGHT))), XXXXXXX, XXXXXXX, A(C(KC_U)), A(C(KC_I)), XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, A(C(KC_LEFT)), A(C(KC_DOWN)), A(C(KC_RIGHT)), XXXXXXX, XXXXXXX, A(C(KC_J)), A(C(KC_K)), XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_QWERTY), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        print("mode just switched to colemak\n");
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (clockwise) {
      muse_tempo+=1;
    } else {
      muse_tempo-=1;
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

