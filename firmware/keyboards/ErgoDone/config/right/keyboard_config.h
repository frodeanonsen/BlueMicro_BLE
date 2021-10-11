/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef KEYBOARD_CONFIG_H
#define KEYBOARD_CONFIG_H
#include "hardware_config.h"

#define KEYBOARD_SIDE RIGHT
// CHANGE THIS FOR THE KEYBOARD TO MATCH WHAT IS BEING FLASHED. OPTIONS: LEFT  RIGHT  SINGLE

#define DEVICE_NAME_R                         "ErgoDone_R"                          /**< Name of device. Will be included in the advertising data. */
#define DEVICE_NAME_L                        "ErgoDone_L"                          /**< Name of device. Will be included in the advertising data. */
#define DEVICE_NAME_M                         "ErgoDone"                          /**< Name of device. Will be included in the advertising data. */

#define DEVICE_MODEL                        "ErgoDone_V1"                          /**< Name of device. Will be included in the advertising data. */

#define MANUFACTURER_NAME                   "anonsen.org"                      /**< Manufacturer. Will be passed to Device Information Service. */



#if KEYBOARD_SIDE == RIGHT
#define KEYMAP( \
            k0D, k0C, k0B, k0A, k09, k08, k07, \
            k1D, k1C, k1B, k1A, k19, k18, k17, \
                 k2D, k2C, k2B, k2A, k29, k28, \
            k3D, k3C, k3B, k3A, k39, k38, k37, \
                      k4D, k4C, k4B, k4A, k49, \
      k5C,k5B,                                 \
      k5A,                                     \
      k57,k58,k59                              \
) \
{ \
    { k07,   k08, k09, k0A, k0B, k0C,   k0D }, \
    { k17,   k18, k19, k1A, k1B, k1C,   k1D }, \
    { k28,   k29, k2A, k2B, k2C, k2D,   KC_NO }, \
    { k37,   k38, k39, k3A, k3B, k3C,   k3D }, \
    { k49,   k4A, k4B, k4C, k4D, KC_NO, KC_NO }, \
    { KC_NO, k57, k58, k59, k5A, k5B,   k5C  } \
}
#else
#define KEYMAP( \
      k00,k01,k02,k03,k04,k05,k06,    \
      k10,k11,k12,k13,k14,k15,k16,    \
      k20,k21,k22,k23,k24,k25,        \
      k30,k31,k32,k33,k34,k35,k36,    \
      k40,k41,k42,k43,k44,            \
                            k55,k56,  \
                                k54,  \
                        k53,k52,k51   \
) \
{ \
    { k00,   k01, k02, k03, k04, k05,   k06 },   \
    { k10,   k11, k12, k13, k14, k15,   k16 },   \
    { k20,   k21, k22, k23, k24, k25,   KC_NO }, \
    { k30,   k31, k32, k33, k34, k35,   k36 },   \
    { k40,   k41, k42, k43, k44, KC_NO, KC_NO }, \
    { KC_NO, k51, k52, k53, k54, k55,   k56 }    \
}
#endif

#endif /* KEYBOARD_CONFIG_H */
