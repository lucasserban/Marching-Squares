#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "init_contur.h"
#include "command.h"

#define RESIZE 4
#define VAL_SAM 4
#define SIGMA 200

int main(void)
{
	char format[3], command[12];
	int **rgb_value,  **grid_matrix, **pattern;
	int error = 0, grid_exists = 0, max_val, width, height;
	if (allocate_matrix(4, 4, &pattern)) {
		printf("Alocare esuata");
		return 1;
	}
	fgets(command, 12, stdin);
	while (strncmp(command, "EXIT", 4) != 0) {
		if (strncmp(command, "READ", 4) == 0) {
			if (grid_exists) {
				finish(height / VAL_SAM + 1, &grid_matrix);
				grid_exists = 0;
			}
			switch (read(format, &width, &height, &max_val, &rgb_value)) {
			case 3:
				printf("Eroare: eroare citire pixeli\n");
				error = 1; break;
			case 2:
				printf("Eroare: trebuie sa fie P3\n");
				error = 1; break;
			case 1:
				printf("Eroare: valoare pixel necorespunzatoare\n");
				error = 1; break;
			case -1:
				printf("Alocare esuata");
				return 1;
			default:
				printf("Imagine citita cu succes [%d-%d]\n", width, height);
			}
			if (error)
				break;
		} else if (strncmp(command, "WRITE", 5) == 0) {
			write(format, height, width, max_val);
			print_matrix(height, width, rgb_value);
		} else if (strncmp(command, "RESIZE", 6) == 0) {
			if (resize(&rgb_value, &height, &width)) {
				printf("Alocare esuata");
				return 1;
			}
			printf("Imagine redimensionata cu succes [%d-%d]\n", height, width);
		} else if (strncmp(command, "GRID", 4) == 0) {
			printf("Grid calculat cu succes [%d-%d]\n",
				   (height / VAL_SAM), (width / VAL_SAM));
			if (grid(&height, &width, &rgb_value, &grid_matrix)) {
				printf("Alocare esuata");
				return 1;
			}
			print_grid(&grid_matrix, height, width);
			grid_exists = 1;
		} else if (strncmp(command, "INIT_CONTUR", 11) == 0) {
			init_contur(&pattern, -1);
		} else if (strncmp(command, "MARCH", 5) == 0) {
			if (grid_exists == 0) {
				if (grid(&height, &width, &rgb_value, &grid_matrix)) {
					printf("Alocare esuata");
					return 1;
				}
				grid_exists = 1;
			}
			printf("Marching Squares aplicat cu succes [%d-%d]\n",
				   height, width);
			if (march(&height, &width, &grid_matrix, &pattern, &rgb_value)) {
				printf("Alocare esuata");
				return 1;
			}
		}
		fgets(command, 12, stdin);
	}
	finish(4, &pattern);
	finish(height, &rgb_value);
	if (grid_exists)
		finish(height / VAL_SAM + 1, &grid_matrix);
	/*Daca nici una dintre erori nu au fost intalnite
	atunci afisam mesajul respectiv*/
	if (error == 0)
		printf("Gigel a terminat\n");

	return 0;
}
