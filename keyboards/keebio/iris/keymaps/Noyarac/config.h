/*
Copyright 2019 Danny Nguyen <danny@keeb.io>

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

#pragma once

#define MASTER_RIGHT

// #define RGBLIGHT_SPLIT // Ajoute des fonctionnalités de synchronization
// #define RGBLIGHT_SLEEP // Pour éteindre le clavier quand l'ordi est éteint.

#undef TAPPING_TERM
#define TAPPING_TERM 180
#define PERMISSIVE_HOLD
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// #define MK_3_SPEED
// #define MK_C_OFFSET_1 4
// #define MK_C_INTERVAL_1 4

// #define MOUSEKEY_INTERVAL 16
// #define MOUSEKEY_MOVE_DELTA 4
// #define MOUSEKEY_MAX_SPEED 4
// #define MOUSEKEY_TIME_TO_MAX_SPEED 16

#define MOUSEKEY_INERTIA
#define MOUSEKEY_DELAY 150
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 16
#define MOUSEKEY_TIME_TO_MAX 45
#define MOUSEKEY_FRICTION 12
#define MOUSEKEY_MOVE_DELTA 8

#define LAYER_LOCK_IDLE_TIMEOUT 60000  // Turn off after 60 seconds.
