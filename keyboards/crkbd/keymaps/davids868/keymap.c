/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Elliot Powell  <@e11i0t23>

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
// #include "g/keymap_combo.h"

// Custom keycodes
enum custom_keycodes {
    KC_MAC_BASE = SAFE_RANGE,
    KC_LINUX_BASE,
    KC_TO_BASE
};

// Layer definitions
enum layers {
    _MAC_BASE = 0,
    _LINUX_BASE,
    _SYMBOLS,
    _NAV,
    _MEDIA1,
    _MEDIA2
};

const uint16_t PROGMEM jk_esc_combo[] = {CTL_T(KC_J), KC_K, COMBO_END};
const uint16_t PROGMEM uio_caps_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM ol_mins_combo[] = {KC_L, KC_O, COMBO_END};
const uint16_t PROGMEM thumbs_f18_combo[] = {ALL_T(KC_SPC), CTL_T(KC_BSPC), COMBO_END};
const uint16_t PROGMEM edge_boot_combo[] = {KC_EXLM, KC_EQL, COMBO_END};
const uint16_t PROGMEM uj_undo_combo[] = {KC_U, CTL_T(KC_J), COMBO_END};

// Mac-specific combos
const uint16_t PROGMEM df_tab_mac_combo[] = {LT(_NAV, KC_D), CTL_T(KC_F), COMBO_END};
const uint16_t PROGMEM pscln_quot_mac_combo[] = {KC_P, GUI_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM rf_again_mac_combo[] = {LT(_MEDIA2, KC_R), CTL_T(KC_F), COMBO_END};

// Linux-specific combos
const uint16_t PROGMEM df_tab_linux_combo[] = {LT(_NAV, KC_D), GUI_T(KC_F), COMBO_END};
const uint16_t PROGMEM pscln_quot_linux_combo[] = {KC_P, CTL_T(KC_SCLN), COMBO_END};
const uint16_t PROGMEM rf_again_linux_combo[] = {LT(_MEDIA2, KC_R), GUI_T(KC_F), COMBO_END};

combo_t key_combos[] = {
    COMBO(jk_esc_combo, KC_ESC),
    COMBO(uio_caps_combo, KC_CAPS),
    COMBO(ol_mins_combo, KC_MINS),
    COMBO(thumbs_f18_combo, KC_F18),
    COMBO(edge_boot_combo, QK_BOOT),
    COMBO(uj_undo_combo, LGUI(KC_Z)),

    // Mac combos (only active on Mac base layer)
    COMBO(df_tab_mac_combo, KC_TAB),
    COMBO(pscln_quot_mac_combo, KC_QUOT),
    COMBO(rf_again_mac_combo, LSG(KC_Z))
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────┬────────────────┬────────────────┬─────────────┬────────────────┬────────────┐   ┌─────────────┬──────────────┬────┬───┬──────────┬────┐
//    │ no │ LT(_MEDIA1, q) │ LT(_MEDIA1, w) │      e      │ LT(_MEDIA2, r) │     t      │   │      y      │      u       │ i  │ o │    p     │ no │
//    ├────┼────────────────┼────────────────┼─────────────┼────────────────┼────────────┤   ├─────────────┼──────────────┼────┼───┼──────────┼────┤
//    │ no │    GUI_T(a)    │    ALT_T(s)    │ LT(_NAV, d) │    CTL_T(f)    │     g      │   │      h      │   CTL_T(j)   │ k  │ l │ GUI_T(;) │ no │
//    ├────┼────────────────┼────────────────┼─────────────┼────────────────┼────────────┤   ├─────────────┼──────────────┼────┼───┼──────────┼────┤
//    │ no │    LCA_T(z)    │       x        │      c      │       v        │     b      │   │      n      │      m       │ ,  │ . │ SFT_T(/) │ no │
//    └────┴────────────────┴────────────────┼─────────────┼────────────────┼────────────┤   ├─────────────┼──────────────┼────┼───┴──────────┴────┘
//                                           │     no      │   SFT_T(ent)   │ ALL_T(spc) │   │ CTL_T(bspc) │ MO(_SYMBOLS) │ no │
//                                           └─────────────┴────────────────┴────────────┘   └─────────────┴──────────────┴────┘
[_MAC_BASE] = LAYOUT_split_3x6_3(
  XXXXXXX , LT(_MEDIA1, KC_Q) , LT(_MEDIA1, KC_W) , KC_E           , LT(_MEDIA2, KC_R) , KC_T          ,     KC_Y           , KC_U         , KC_I    , KC_O   , KC_P           , XXXXXXX,
  XXXXXXX , GUI_T(KC_A)       , ALT_T(KC_S)       , LT(_NAV, KC_D) , CTL_T(KC_F)       , KC_G          ,     KC_H           , CTL_T(KC_J)  , KC_K    , KC_L   , GUI_T(KC_SCLN) , XXXXXXX,
  XXXXXXX , LCA_T(KC_Z)       , KC_X              , KC_C           , KC_V              , KC_B          ,     KC_N           , KC_M         , KC_COMM , KC_DOT , SFT_T(KC_SLSH) , XXXXXXX,
                                                    XXXXXXX        , SFT_T(KC_ENT)     , ALL_T(KC_SPC) ,     CTL_T(KC_BSPC) , MO(_SYMBOLS) , XXXXXXX
),

//    ┌────┬────────────────┬────────────────┬─────────────┬────────────────┬────────────┐   ┌─────────────┬──────────────┬────┬───┬──────────┬────┐
//    │ no │ LT(_MEDIA1, q) │ LT(_MEDIA1, w) │      e      │ LT(_MEDIA2, r) │     t      │   │      y      │      u       │ i  │ o │    p     │ no │
//    ├────┼────────────────┼────────────────┼─────────────┼────────────────┼────────────┤   ├─────────────┼──────────────┼────┼───┼──────────┼────┤
//    │ no │    CTL_T(a)    │    ALT_T(s)    │ LT(_NAV, d) │    GUI_T(f)    │     g      │   │      h      │   GUI_T(j)   │ k  │ l │ CTL_T(;) │ no │
//    ├────┼────────────────┼────────────────┼─────────────┼────────────────┼────────────┤   ├─────────────┼──────────────┼────┼───┼──────────┼────┤
//    │ no │    LCA_T(z)    │       x        │      c      │       v        │     b      │   │      n      │      m       │ ,  │ . │ SFT_T(/) │ no │
//    └────┴────────────────┴────────────────┼─────────────┼────────────────┼────────────┤   ├─────────────┼──────────────┼────┼───┴──────────┴────┘
//                                           │     no      │   SFT_T(ent)   │ ALL_T(spc) │   │ CTL_T(bspc) │ MO(_SYMBOLS) │ no │
//                                           └─────────────┴────────────────┴────────────┘   └─────────────┴──────────────┴────┘
[_LINUX_BASE] = LAYOUT_split_3x6_3(
  XXXXXXX , LT(_MEDIA1, KC_Q) , LT(_MEDIA1, KC_W) , KC_E           , LT(_MEDIA2, KC_R) , KC_T          ,     KC_Y           , KC_U         , KC_I    , KC_O   , KC_P           , XXXXXXX,
  XXXXXXX , CTL_T(KC_A)       , ALT_T(KC_S)       , LT(_NAV, KC_D) , GUI_T(KC_F)       , KC_G          ,     KC_H           , GUI_T(KC_J)  , KC_K    , KC_L   , CTL_T(KC_SCLN) , XXXXXXX,
  XXXXXXX , LCA_T(KC_Z)       , KC_X              , KC_C           , KC_V              , KC_B          ,     KC_N           , KC_M         , KC_COMM , KC_DOT , SFT_T(KC_SLSH) , XXXXXXX,
                                                    XXXXXXX        , SFT_T(KC_ENT)     , ALL_T(KC_SPC) ,     CTL_T(KC_BSPC) , MO(_SYMBOLS) , XXXXXXX
),

//    ┌────┬─────┬─────┬────┬──────┬──────────┐   ┌────────────┬─────┬────┬────┬──────────┬────┐
//    │ no │  !  │  @  │ #  │  $   │    %     │   │     ^      │  &  │ *  │ -  │    =     │ no │
//    ├────┼─────┼─────┼────┼──────┼──────────┤   ├────────────┼─────┼────┼────┼──────────┼────┤
//    │ no │     │     │ [  │  {   │    (     │   │     )      │  }  │ ]  │ \  │    |     │ no │
//    ├────┼─────┼─────┼────┼──────┼──────────┤   ├────────────┼─────┼────┼────┼──────────┼────┤
//    │ no │  `  │ no  │ no │  no  │ mAC_BASE │   │ lINUX_BASE │ no  │ no │ no │ TO(_NAV) │ no │
//    └────┴─────┴─────┼────┼──────┼──────────┤   ├────────────┼─────┼────┼────┴──────────┴────┘
//                     │ no │ lsft │          │   │            │     │ no │
//                     └────┴──────┴──────────┘   └────────────┴─────┴────┘
[_SYMBOLS] = LAYOUT_split_3x6_3(
  XXXXXXX , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC     ,     KC_CIRC       , KC_AMPR , KC_ASTR , KC_MINS , KC_EQL   , XXXXXXX,
  XXXXXXX , _______ , _______ , KC_LBRC , KC_LCBR , KC_LPRN     ,     KC_RPRN       , KC_RCBR , KC_RBRC , KC_BSLS , KC_PIPE  , XXXXXXX,
  XXXXXXX , KC_GRV  , XXXXXXX , XXXXXXX , XXXXXXX , KC_MAC_BASE ,     KC_LINUX_BASE , XXXXXXX , XXXXXXX , XXXXXXX , TO(_NAV) , XXXXXXX,
                                XXXXXXX , KC_LSFT , _______     ,     _______       , _______ , XXXXXXX
),

//    ┌────┬─────┬─────┬────┬─────────┬─────┐   ┌──────┬──────┬────┬──────┬────┬────┐
//    │ no │ no  │ no  │ no │   no    │ no  │   │  no  │  no  │ no │  no  │ no │ no │
//    ├────┼─────┼─────┼────┼─────────┼─────┤   ├──────┼──────┼────┼──────┼────┼────┤
//    │ no │     │     │ no │   no    │ no  │   │ left │ down │ up │ rght │ no │ no │
//    ├────┼─────┼─────┼────┼─────────┼─────┤   ├──────┼──────┼────┼──────┼────┼────┤
//    │ no │ no  │ no  │ no │   no    │ no  │   │  no  │  no  │ no │  no  │ no │ no │
//    └────┴─────┴─────┼────┼─────────┼─────┤   ├──────┼──────┼────┼──────┴────┴────┘
//                     │ no │ tO_BASE │     │   │      │      │ no │
//                     └────┴─────────┴─────┘   └──────┴──────┴────┘
[_NAV] = LAYOUT_split_3x6_3(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , _______ , _______ , XXXXXXX , XXXXXXX    , XXXXXXX ,     KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX    , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                XXXXXXX , KC_TO_BASE , _______ ,     _______ , _______ , XXXXXXX
),

//    ┌────┬────┬──────┬──────┬────────────┬─────┐   ┌────┬─────┬────┬───┬────┬────┐
//    │ no │ no │ mprv │ mply │    mnxt    │ no  │   │ +  │  7  │ 8  │ 9 │ no │ no │
//    ├────┼────┼──────┼──────┼────────────┼─────┤   ├────┼─────┼────┼───┼────┼────┤
//    │ no │ no │  no  │ vold │    volu    │ no  │   │ -  │  4  │ 5  │ 6 │ no │ no │
//    ├────┼────┼──────┼──────┼────────────┼─────┤   ├────┼─────┼────┼───┼────┼────┤
//    │ no │ no │  no  │ bRID │    bRIU    │ no  │   │ 0  │  1  │ 2  │ 3 │ .  │ no │
//    └────┴────┴──────┼──────┼────────────┼─────┤   ├────┼─────┼────┼───┴────┴────┘
//                     │  no  │ SFT_T(ent) │ spc │   │ no │     │ no │
//                     └──────┴────────────┴─────┘   └────┴─────┴────┘
[_MEDIA1] = LAYOUT_split_3x6_3(
  XXXXXXX , XXXXXXX , KC_MPRV , KC_MPLY , KC_MNXT       , XXXXXXX ,     KC_PLUS , KC_7    , KC_8    , KC_9 , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , KC_VOLD , KC_VOLU       , XXXXXXX ,     KC_MINS , KC_4    , KC_5    , KC_6 , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , KC_BRID , KC_BRIU       , XXXXXXX ,     KC_0    , KC_1    , KC_2    , KC_3 , KC_DOT  , XXXXXXX,
                                XXXXXXX , SFT_T(KC_ENT) , KC_SPC  ,     XXXXXXX , _______ , XXXXXXX
),

//    ┌────┬──────┬──────┬──────┬────────────┬─────┐   ┌─────┬─────┬────┬───┬────┬────┐
//    │ no │ mprv │ mply │  no  │    mnxt    │ no  │   │  +  │  7  │ 8  │ 9 │ no │ no │
//    ├────┼──────┼──────┼──────┼────────────┼─────┤   ├─────┼─────┼────┼───┼────┼────┤
//    │ no │  no  │  no  │ vold │    volu    │ no  │   │  -  │  4  │ 5  │ 6 │ no │ no │
//    ├────┼──────┼──────┼──────┼────────────┼─────┤   ├─────┼─────┼────┼───┼────┼────┤
//    │ no │  no  │  no  │ bRID │    bRIU    │ no  │   │  0  │  1  │ 2  │ 3 │ .  │ no │
//    └────┴──────┴──────┼──────┼────────────┼─────┤   ├─────┼─────┼────┼───┴────┴────┘
//                       │  no  │ SFT_T(ent) │     │   │     │     │ no │
//                       └──────┴────────────┴─────┘   └─────┴─────┴────┘
[_MEDIA2] = LAYOUT_split_3x6_3(
  XXXXXXX , KC_MPRV , KC_MPLY , XXXXXXX , KC_MNXT       , XXXXXXX ,     KC_PLUS , KC_7    , KC_8    , KC_9 , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , KC_VOLD , KC_VOLU       , XXXXXXX ,     KC_MINS , KC_4    , KC_5    , KC_6 , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , KC_BRID , KC_BRIU       , XXXXXXX ,     KC_0    , KC_1    , KC_2    , KC_3 , KC_DOT  , XXXXXXX,
                                XXXXXXX , SFT_T(KC_ENT) , _______ ,     _______ , _______ , XXXXXXX
)
};

// Custom keycode processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MAC_BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC_BASE);
            }
            return false;

        case KC_LINUX_BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_LINUX_BASE);
            }
            return false;

        case KC_TO_BASE:
            if (record->event.pressed) {
                layer_clear();  // Clear all layer states, returning to default layer
            }
            return false;
    }
    return true;
}

