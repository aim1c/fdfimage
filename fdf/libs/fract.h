//
//  fract.h
//  d
//
//  Created by Alexander Volkov on 19/09/2019.
//  Copyright © 2019 Alexander Volkov. All rights reserved.
//

#ifndef fract_h
#define fract_h

#include <unistd.h>
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "cord.h"
#include "bresenhamline.h"


typedef struct	s_cord {
	
	double		x;
	double		y;
	double		z;
}				t_cord;

size_t		checkCountOfElements(t_list *head);

typedef struct	s_xy {
	double x;
	double y;
}				t_xy;


typedef struct	s_lim {
	size_t		x;
	size_t		y;
}				t_lim;

typedef struct	s_img {
	int bpp;
	int endian;
	int width;
	int height;
	t_lim	*lim;
	char	*addr;
}				t_img;


t_cord 		*getCordArray(t_list *main, t_lim *lim);
void		lineBr(t_cord xy0, t_cord xy1, t_img *img);
void putPixel(double x, double y, t_img *img);


int key_press(int keycode, void *param);


// MARK: - DATA FREE

void mainListRemover(t_list *mainList);
void ccordRemover(t_cord *cord);

//

// MARK: - READER

t_list	*readerFromFile(int fd);
int		openFile(const char *filename);
t_cord	*getCordList(t_list *list, size_t lstsize);


//

// MARK: - SANDBOX

void	checkReaderWork(t_list *head);
void	checkCord(t_cord *mainCoord);

//

#endif /* fract_h */
