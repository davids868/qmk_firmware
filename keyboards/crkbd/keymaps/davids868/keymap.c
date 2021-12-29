#include QMK_KEYBOARD_H

enum layers {
    LAYER0,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
};

#define A_D LALT_T(KC_D)
#define G_F LGUI_T(KC_F)
#define G_J RGUI_T(KC_J)
#define A_K RALT_T(KC_K)
#define A_Z LCA_T(KC_Z)
#define S_ENT LSFT_T(KC_ENT)
#define C_BSPC RCTL_T(KC_BSPC)

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [LAYER0] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX,    KC_A,    KC_S,     A_D,     G_F,    KC_G,                         KC_H,     G_J,     A_K,    KC_L, KC_SCLN, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX,     A_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              XXXXXXX,   S_ENT,  KC_SPC,     C_BSPC,   TO(1), XXXXXXX
                                          //`--------------------------'  `---------------------------'
        ),
    [LAYER1] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX,  KC_GRV, KC_UNDS, KC_LBRC, KC_LCBR, KC_LPRN,                      KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS, KC_PIPE, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT,                      KC_DQUO, XXXXXXX, XXXXXXX, XXXXXXX,   TO(3), XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              XXXXXXX,   TO(0),  KC_SPC,     C_BSPC,   TO(2), XXXXXXX
                                          //`--------------------------'  `---------------------------'
        ),
    [LAYER2] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX, XXXXXXX, KC_MRWD, KC_MPLY, KC_MFFD, XXXXXXX,                      KC_PPLS,    KC_7,    KC_8,    KC_9, KC_PEQL, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX,                      KC_PMNS,    KC_4,    KC_5,    KC_6, KC_PDOT, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX,   RESET, XXXXXXX, KC_BRID, KC_BRIU, KC_PDOT,                         KC_0,    KC_1,    KC_2,    KC_3,   TO(3), XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              XXXXXXX,   TO(0),  KC_SPC,    KC_BSPC,   TO(1), XXXXXXX
                                          //`--------------------------'  `---------------------------'
        ),
    [LAYER3] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX,  KC_TAB, XXXXXXX, KC_MS_U, XXXXXXX,    KC_Q,                      XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, KC_BSPC, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_ENT, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX,   MO(3), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              XXXXXXX,   TO(0), KC_LGUI,    KC_BSPC, _______, XXXXXXX
                                          //`--------------------------'  `---------------------------'
        ),
    [LAYER4] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|

                                              XXXXXXX, XXXXXXX, _______,    XXXXXXX, XXXXXXX, XXXXXXX
                                          //`--------------------------'  `---------------------------'
        ),
    // clang-format on
};
