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
#include "g/keymap_combo.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────┬──────────┬──────────┬──────────┬────────────┬────────────┐   ┌─────────────┬──────────┬────┬───┬───┬────┐
//    │ no │ LT(3, q) │    w     │    e     │     r      │     t      │   │      y      │    u     │ i  │ o │ p │ no │
//    ├────┼──────────┼──────────┼──────────┼────────────┼────────────┤   ├─────────────┼──────────┼────┼───┼───┼────┤
//    │ no │ GUI_T(a) │ ALT_T(s) │ LT(2, d) │  CTL_T(f)  │     g      │   │      h      │ CTL_T(j) │ k  │ l │ ; │ no │
//    ├────┼──────────┼──────────┼──────────┼────────────┼────────────┤   ├─────────────┼──────────┼────┼───┼───┼────┤
//    │ no │    z     │    x     │    c     │     v      │     b      │   │      n      │    m     │ ,  │ . │ / │ no │
//    └────┴──────────┴──────────┼──────────┼────────────┼────────────┤   ├─────────────┼──────────┼────┼───┴───┴────┘
//                               │    no    │ SFT_T(ent) │ ALL_T(spc) │   │ CTL_T(bspc) │  OSL(1)  │ no │
//                               └──────────┴────────────┴────────────┘   └─────────────┴──────────┴────┘
[0] = LAYOUT_split_3x6_3(
  XXXXXXX , LT(3, KC_Q) , KC_W        , KC_E        , KC_R          , KC_T          ,     KC_Y           , KC_U        , KC_I    , KC_O   , KC_P    , XXXXXXX,
  XXXXXXX , GUI_T(KC_A) , ALT_T(KC_S) , LT(2, KC_D) , CTL_T(KC_F)   , KC_G          ,     KC_H           , CTL_T(KC_J) , KC_K    , KC_L   , KC_SCLN , XXXXXXX,
  XXXXXXX , KC_Z        , KC_X        , KC_C        , KC_V          , KC_B          ,     KC_N           , KC_M        , KC_COMM , KC_DOT , KC_SLSH , XXXXXXX,
                                        XXXXXXX     , SFT_T(KC_ENT) , ALL_T(KC_SPC) ,     CTL_T(KC_BSPC) , OSL(1)      , XXXXXXX
),

//    ┌────┬───┬────┬────┬───────┬─────┐   ┌─────┬─────┬────┬────┬───────┬────┐
//    │ no │ ! │ @  │ #  │   $   │  %  │   │  ^  │  &  │ *  │ -  │   =   │ no │
//    ├────┼───┼────┼────┼───────┼─────┤   ├─────┼─────┼────┼────┼───────┼────┤
//    │ no │ ` │ no │ [  │   {   │  (  │   │  (  │  }  │ ]  │ \  │   |   │ no │
//    ├────┼───┼────┼────┼───────┼─────┤   ├─────┼─────┼────┼────┼───────┼────┤
//    │ no │ ~ │ no │ no │  no   │ no  │   │ no  │ no  │ no │ no │ TO(2) │ no │
//    └────┴───┴────┼────┼───────┼─────┤   ├─────┼─────┼────┼────┴───────┴────┘
//                  │ no │ TO(0) │ spc │   │     │     │ no │
//                  └────┴───────┴─────┘   └─────┴─────┴────┘
[1] = LAYOUT_split_3x6_3(
  XXXXXXX , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,     KC_CIRC , KC_AMPR , KC_ASTR , KC_MINS , KC_EQL  , XXXXXXX,
  XXXXXXX , KC_GRV  , XXXXXXX , KC_LBRC , KC_LCBR , KC_LPRN ,     KC_LPRN , KC_RCBR , KC_RBRC , KC_BSLS , KC_PIPE , XXXXXXX,
  XXXXXXX , KC_TILD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , TO(2)   , XXXXXXX,
                                XXXXXXX , TO(0)   , KC_SPC  ,     KC_TRNS , _______ , XXXXXXX
),

//    ┌────┬───┬────┬────┬───────┬─────┐   ┌──────┬──────┬────┬──────┬────┬────┐
//    │ no │ ! │ @  │ #  │   $   │  q  │   │  ^   │  &   │ *  │  -   │ =  │ no │
//    ├────┼───┼────┼────┼───────┼─────┤   ├──────┼──────┼────┼──────┼────┼────┤
//    │ no │ ` │ no │ [  │   {   │  (  │   │ left │ down │ up │ rght │ no │ no │
//    ├────┼───┼────┼────┼───────┼─────┤   ├──────┼──────┼────┼──────┼────┼────┤
//    │ no │ ~ │ no │ no │  no   │ no  │   │  no  │  no  │ no │  no  │ no │ no │
//    └────┴───┴────┼────┼───────┼─────┤   ├──────┼──────┼────┼──────┴────┴────┘
//                  │ no │ TO(0) │ spc │   │      │      │ no │
//                  └────┴───────┴─────┘   └──────┴──────┴────┘
[2] = LAYOUT_split_3x6_3(
  XXXXXXX , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_Q    ,     KC_CIRC , KC_AMPR , KC_ASTR , KC_MINS , KC_EQL  , XXXXXXX,
  XXXXXXX , KC_GRV  , XXXXXXX , KC_LBRC , KC_LCBR , KC_LPRN ,     KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , XXXXXXX , XXXXXXX,
  XXXXXXX , KC_TILD , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                XXXXXXX , TO(0)   , KC_SPC  ,     KC_TRNS , _______ , XXXXXXX
),

//    ┌────┬────┬──────┬──────┬────────────┬─────┐   ┌────┬─────┬────┬───┬────┬────┐
//    │ no │ no │ mprv │ mply │    mnxt    │ no  │   │ +  │  7  │ 8  │ 9 │ no │ no │
//    ├────┼────┼──────┼──────┼────────────┼─────┤   ├────┼─────┼────┼───┼────┼────┤
//    │ no │ no │  no  │ vold │    volu    │ no  │   │ -  │  5  │ 5  │ 6 │ no │ no │
//    ├────┼────┼──────┼──────┼────────────┼─────┤   ├────┼─────┼────┼───┼────┼────┤
//    │ no │ no │  no  │ bRID │    bRIU    │ no  │   │ 0  │  1  │ 2  │ 3 │ .  │ no │
//    └────┴────┴──────┼──────┼────────────┼─────┤   ├────┼─────┼────┼───┴────┴────┘
//                     │  no  │ SFT_T(ent) │ spc │   │ no │     │ no │
//                     └──────┴────────────┴─────┘   └────┴─────┴────┘
[3] = LAYOUT_split_3x6_3(
  XXXXXXX , XXXXXXX , KC_MPRV , KC_MPLY , KC_MNXT       , XXXXXXX ,     KC_PLUS , KC_7    , KC_8    , KC_9 , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , KC_VOLD , KC_VOLU       , XXXXXXX ,     KC_MINS , KC_5    , KC_5    , KC_6 , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , KC_BRID , KC_BRIU       , XXXXXXX ,     KC_0    , KC_1    , KC_2    , KC_3 , KC_DOT  , XXXXXXX,
                                XXXXXXX , SFT_T(KC_ENT) , KC_SPC  ,     XXXXXXX , _______ , XXXXXXX
)
};
