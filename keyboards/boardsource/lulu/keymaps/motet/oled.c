/*
 * Copyright 2025 Jo Yoshida <jo@motet.org>
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

#ifdef OLED_ENABLE

#include "oled.h"
#include "luna.h"
#include "ocean_dream.h"

void render_oled_master(void) {
	/* Motet logo */
	oled_set_cursor(0,0);
	oled_write_raw_P(logo_motet, sizeof(logo_motet));

	/* macOS or Windows */
	oled_set_cursor(0,5);
	
	if (keymap_config.swap_lctl_lgui) {
		oled_write_raw_P(logo_windows, sizeof(logo_windows));
	} else {
		oled_write_raw_P(logo_macos, sizeof(logo_macos));
	}

 	/* current layer */	
	oled_set_cursor(0,8);
	
	switch (get_highest_layer(layer_state)) {
		case 0:
			oled_write(" COL ", false);
			break;
		case 1:
			oled_write(" LOW ", false);
			break;
		case 2:
			oled_write(" RAI ", false);
			break;
		case 3:
			oled_write(" ADJ ", false);
			break;
		default:
			oled_write(" ??? ", false);
	}
	
	 /* wpm */
	int wpm = get_current_wpm();	// do not use Luna's wpm set in oled_task_user
	
	char wpm_str[6];
	wpm_str[3] = '\0';
	wpm_str[2] = '0' + wpm % 10;
	wpm_str[1] = '0' + (wpm /= 10) % 10;
	wpm_str[0] = '0' + wpm / 10;
	oled_set_cursor(1,9);
	oled_write(wpm_str, false);
	oled_set_cursor(1,10);
	oled_write("wpm", false);

	/* caps lock */
	oled_set_cursor(0,11);
	oled_write(led_usb_state.caps_lock ? "CPSLK" : "     ", false);
	
	render_luna(0,13);
}

void render_oled_slave(void) {
	# ifdef OCEAN_DREAM_ENABLE
	render_stars();
	#endif	
}

void oled_render_boot(bool bootloader) {
	oled_clear();
	
	for (int i = 0; i < 16; i++) {
		oled_set_cursor(0, i);
		
		if (bootloader) {
			oled_write_P(PSTR(" F/W "), false);
		 } else {
			oled_write_P(PSTR("Boot"), false);
		}
	}
	
	oled_render_dirty(true);
}

bool shutdown_user(bool jump_to_bootloader) {
	oled_render_boot(jump_to_bootloader);
	return false;
}

#endif                  