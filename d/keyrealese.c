//
//  keyrealese.c
//  d
//
//  Created by Alexander Volkov on 19/09/2019.
//  Copyright © 2019 Alexander Volkov. All rights reserved.
//

#include "fract.h"

int key_press(int keycode, void *param) {
	if (keycode == 53) {
		ccordRemover((t_cord *)param);
		exit(EXIT_FAILURE);
	}
	return 1;
}
