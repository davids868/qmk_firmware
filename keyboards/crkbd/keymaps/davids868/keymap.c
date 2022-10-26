#include QMK_KEYBOARD_H

enum layers {
    LAYER0,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
    LAYER5,
    LAYER6,
};

#define A_S ALT_T(KC_S)
#define G_A GUI_T(KC_A)
#define G_SCLN GUI_T(KC_SCLN)

#define G_GRV GUI_T(KC_GRV)

#define S_SLSH LSFT_T(KC_SLSH)
#define CA_Z LCA_T(KC_Z)
#define S_ENT LSFT_T(KC_ENT)
#define C_BSPC RCTL_T(KC_BSPC)

#define CUT G(KC_X)
#define COPY G(KC_C)
#define PASTE G(KC_V)
#define UNDO G(KC_Z)
#define REDO LSG(KC_Z)

#define A_RGHT A(KC_RGHT)
#define A_LEFT A(KC_LEFT)
#define SA_RGHT LSA(KC_RGHT)
#define SA_LEFT LSA(KC_LEFT)

#define S_RGHT S(KC_RGHT)
#define S_LEFT S(KC_LEFT)
#define S_DOWN S(KC_DOWN)
#define S_UP S(KC_UP)
#define H_SPC HYPR_T(KC_SPC)

#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [LAYER0] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX,     G_A,     A_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,  G_SCLN, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX,    CA_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,  S_SLSH, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              XXXXXXX,   S_ENT,   H_SPC,     C_BSPC,  OSL(1), XXXXXXX
                                          //`--------------------------'  `---------------------------'
        ),
    [LAYER1] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,  KC_EQL, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX,   G_GRV, KC_UNDS, KC_LBRC, KC_LCBR, KC_LPRN,                      KC_RPRN, KC_RCBR, KC_RBRC, KC_BSLS, KC_PIPE, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT,                      KC_DQUO, XXXXXXX, XXXXXXX, XXXXXXX,   TO(3), XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              XXXXXXX,   TO(0),  KC_SPC,     C_BSPC,   OSL(2), XXXXXXX
                                          //`--------------------------'  `---------------------------'
        ),
    [LAYER2] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX, XXXXXXX, KC_MRWD, KC_MPLY, KC_MFFD, XXXXXXX,                      KC_PPLS,    KC_7,    KC_8,    KC_9, KC_PEQL, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, KC_LGUI, KC_LALT, KC_VOLD, KC_VOLU, XXXXXXX,                      KC_PMNS,    KC_4,    KC_5,    KC_6, KC_PDOT, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX,   RESET, XXXXXXX, KC_BRID, KC_BRIU, KC_PDOT,                         KC_0,    KC_1,    KC_2,    KC_3,   TO(3), XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              XXXXXXX,   TO(0),  KC_SPC,    KC_BSPC,   TO(1), XXXXXXX
                                          //`--------------------------'  `---------------------------'
        ),
    [LAYER3] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX,  KC_TAB,  A_RGHT,  A_RGHT,    REDO,    KC_Q,                         COPY,    UNDO,   TO(0), XXXXXXX,   PASTE, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, KC_LGUI, KC_LALT, KC_PGDN, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_ENT, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX,   TO(5), XXXXXXX, XXXXXXX,   TO(4),  A_LEFT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   TO(5), XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              XXXXXXX,   TO(0), KC_LSFT,    KC_BSPC,   TO(1), XXXXXXX
                                          //`--------------------------'  `---------------------------'
        ),
    [LAYER4] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX,  KC_TAB, SA_RGHT, SA_RGHT,    REDO,    KC_Q,                         COPY,    UNDO,   TO(0), XXXXXXX,   PASTE, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, KC_LGUI, KC_LALT, KC_PGDN, XXXXXXX, XXXXXXX,                       S_LEFT,  S_DOWN,    S_UP,  S_RGHT,  KC_ENT, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX,   TO(4), XXXXXXX, XXXXXXX,   TO(3), SA_LEFT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   TO(5), XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|

                                              XXXXXXX,   TO(0), KC_LSFT,    KC_BSPC,   TO(1), XXXXXXX
                                          //`--------------------------'  `---------------------------'
        ),
    [LAYER5] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  KC_ENT, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX,   MO(6), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2,   TO(3), XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|

                                              XXXXXXX,   TO(0), KC_LGUI,    KC_BSPC, _______,  XXXXXXX
                                          //`--------------------------'  `---------------------------'
        ),
    [LAYER6] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, XXXXXXX, KC_WH_R, KC_WH_U, KC_WH_L, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|

                                              XXXXXXX, XXXXXXX, _______,    XXXXXXX, XXXXXXX, XXXXXXX
                                          //`--------------------------'  `---------------------------'
        ),
    // clang-format on
};
