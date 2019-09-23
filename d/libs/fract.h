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


typedef struct	s_img_size {
	int			width;
	int			height;
	int			bpp;
	int			endian;
	size_t		lineString;
}				t_img_size;

typedef struct	s_cord {
	
	double		x;
	double		y;
	double		z;
	int			isNewLine;
	int			isBottomLine;
	struct		s_cord	*next;
}				t_cord;


int key_press(int keycode, void *param);


// MARK: - DATA FREE

void mainListRemover(t_list *mainList);
void ccordRemover(t_cord *cord);

//

// MARK: - READER

t_list	*readerFromFile(int fd);
int		openFile(const char *filename);

//

// MARK: - SANDBOX

void	checkReaderWork(t_list *head);
void	checkCord(t_cord *mainCoord);

//

#endif /* fract_h */
