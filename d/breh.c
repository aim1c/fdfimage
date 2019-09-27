//
//  breh.c
//  d
//
//  Created by Alexander Volkov on 27/09/2019.
//  Copyright © 2019 Alexander Volkov. All rights reserved.
//

#include "libs/fract.h"

typedef struct	s_xy {
	double x;
	double y;
}				t_xy;

double abs_d(double a) {
	return (a > 0 ? (a) : (a * -1));
}


/*

 dx = x1 - x0
 dy = y1 - y0
 xi = 1
 if dx < 0
 xi = -1
 dx = -dx
 end if
 D = 2*dx - dy
 x = x0
 
 for y from y0 to y1
 plot(x,y)
 if D > 0
 x = x + xi
 D = D - 2*dy
 end if
 D = D + 2*dx
 
*/

void lineH(t_xy xy0, t_xy xy1) {
	double dx = xy1.x - xy0.x;
	double dy = xy1.y - xy0.y;
	int xi = 1;
	
	if (dx < 0) {
		
	}
}

void lineL(t_xy xy0, t_xy xy1) {
	
}


void lineBr(t_xy xy0, t_xy xy1) {
	if (abs_d(xy1.y - xy0.y) < abs_d(xy1.x - xy0.x)) {
		if (xy0.x > xy1.x) {
			
		} else {
			
		}
	} else {
		if (xy0.y > xy1.y) {
			
		} else {
			
		}
	}
}
