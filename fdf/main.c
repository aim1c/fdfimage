//
//  main.c
//  fdf
//
//  Created by Frost atronach Snow bear on 27/09/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "libs/fract.h"

#define UNIQ_BPP 4

void printTab(t_cord *cord, t_lim *lim) {
	
	int xLim = (int)lim->x;
	int yLim = (int)lim->y;
	
	int row = -1;
	int elem = -1;
	
	while (++row < yLim - 1) {
		elem = -1;
		while (++elem < xLim) {
			t_cord new = cord[(elem + (row * xLim))];
			
			printf("[%.0f : %.0f]", new.x, new.y);
			printf("%3.0f", new.z);
		}
		printf("\n");
	}
}

static double abs_double(double a) {
	int i = -1;
	
	return (a < 0 ? (a * i) : (a));
}

static void iso(t_cord *cord)
{
	double previous_x;
	double previous_y;
	
	previous_x = cord->x;
	previous_y = cord->y;
	cord->x = (previous_x - previous_y) * cos(0.523599);
	cord->y = -cord->z + (previous_x + previous_y) * sin(0.523599);
	

}

void makeISO(t_cord *cord, t_lim *lim) {
	
	int row = -1;
	int elem;
	
	while (++row < lim->y - 1) {
		elem = -1;
		while (++elem < lim->x) {
			if (cord[(elem + (row * lim->x))].z != 0) {
				t_cord *current = &cord[(elem + (row * lim->x))];
				iso(current);
			}
		}
	}
}

void *getImage(t_img *imgSize, void *mlx, void *win, t_cord *cord) {
	void *img = mlx_new_image(mlx, imgSize->width, imgSize->height);
	imgSize->addr = mlx_get_data_addr(img, &imgSize->bpp, &imgSize->width, &imgSize->endian);
	t_lim *lim = imgSize->lim;
	int row = -1;
	int elem = -1;
	
	makeISO(cord, imgSize->lim);
	printTab(cord, lim);
	
	while (++row < lim->y - 1) {
		elem = -1;
		while (++elem < lim->x) {
			//if (cord[(elem + (row * lim->x))].z == 0) {
				if (elem + 1 < lim->x) {
					lineBr(cord[(elem + (row * lim->x))], cord[(elem + 1 + (row * lim->x))], imgSize);
				}
				if (row + 1 < lim->y - 1) {
					lineBr(cord[(elem + (row * lim->x))], cord[(elem + ((row + 1) * lim->x))], imgSize);
				}
			//}
		}
	}
	
	return img;
}

void mainGraphicsFunc(t_list *mainList, const char *title) {
	
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 1920, 1080, (char *)title);
	
	t_img *imgSize = malloc(sizeof(t_img));
	imgSize->bpp = 4;
	imgSize->endian = 0;
	imgSize->width = 1280;
	imgSize->height = 720;
	imgSize->lim = malloc(sizeof(t_lim));
	
	t_cord *cord = getCordArray(mainList, imgSize->lim);
	mainListRemover(mainList);
	printTab(cord, imgSize->lim);
	void *img = getImage(imgSize, mlx, win, cord);
	
	//
		mlx_put_image_to_window(mlx, win, img, (1280 - 720) / 2, (720 - 480) / 2);
	
	
	mlx_hook(win, 3, 0, key_press, cord);
	mlx_loop(mlx);
}

int main(int argc, const char **argv) {
	
	if (argc != 2) {
		ft_putendl("To many/not arguments");
		exit(EXIT_FAILURE);
	}
	
	int fd = openFile(argv[1]);
	t_list *mainList = readerFromFile(fd);
	//	checkReaderWork(mainList);
	mainGraphicsFunc(mainList, argv[1]);
	
	
	return 42;
}
