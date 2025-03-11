#include <stdio.h>
/*Pentru printarea sabloanelor la comanda
INIT_CONTUR*/
void print_init_contur(int **pattern)
{
	printf("P3\n4 4\n255\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d %d %d\n", pattern[i][j], pattern[i][j], pattern[i][j]);
		}
	}
}

/*Am facut o functie pentru fiecare sablon in parte*/
void pattern_1(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			(*pattern)[i][j] = 0;
		}
	}
}

void pattern_2(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i == 2 && j == 0) || (i == 3 && j == 1)) {
				(*pattern)[i][j] = 255;
			} else if (i == 3 && j == 0) {
				(*pattern)[i][j] = 180;
			}
		}
	}
}

void pattern_3(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i == 2 && j == 3) || (i == 3 && j == 2)) {
				(*pattern)[i][j] = 255;
			} else if (i == 3 && j == 3) {
				(*pattern)[i][j] = 180;
			} else {
				(*pattern)[i][j] = 0;
			}
		}
	}
}

void pattern_4(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 2) {
				(*pattern)[i][j] = 255;
			} else if (i == 3) {
				(*pattern)[i][j] = 180;
			} else {
				(*pattern)[i][j] = 0;
			}
		}
	}
}

void pattern_5(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i == 0 && j == 2) || (i == 1 && j == 3)) {
				(*pattern)[i][j] = 255;
			} else if (i == 0 && j == 3) {
				(*pattern)[i][j] = 180;
			} else {
				(*pattern)[i][j] = 0;
			}
		}
	}
}

void pattern_6(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i == 2 && j == 0) || (i == 3 && j == 1)) {
				(*pattern)[i][j] = 255;
			} else if (i == 3 && j == 0) {
				(*pattern)[i][j] = 180;
			} else if ((i == 0 && j == 2) || (i == 1 && j == 3)) {
				(*pattern)[i][j] = 255;
			} else if (i == 0 && j == 3) {
				(*pattern)[i][j] = 180;
			} else {
				(*pattern)[i][j] = 0;
			}

		}
	}
}

void pattern_7(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 2) {
				(*pattern)[i][j] = 255;
			} else if (j == 3) {
				(*pattern)[i][j] = 180;
			} else {
				(*pattern)[i][j] = 0;
			}
		}
	}
}

void pattern_8(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i == 0 && j == 1) || (i == 1 && j == 0)) {
				(*pattern)[i][j] = 255;
			} else if (i == 0 && j == 0) {
				(*pattern)[i][j] = 0;
			} else {
				(*pattern)[i][j] = 180;
			}
		}
	}
}

void pattern_9(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i == 0 && j == 1) || (i == 1 && j == 0)) {
				(*pattern)[i][j] = 255;
			} else if (i == 0 && j == 0) {
				(*pattern)[i][j] = 180;
			} else {
				(*pattern)[i][j] = 0;
			}
		}
	}
}

void pattern_10(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 1) {
				(*pattern)[i][j] = 255;
			} else if (j == 3 || j == 2) {
				(*pattern)[i][j] = 0;
			} else {
				(*pattern)[i][j] = 180;
			}
		}
	}
}

void pattern_11(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i == 2 && j == 3) || (i == 3 && j == 2)) {
				(*pattern)[i][j] = 255;
			} else if (i == 3 && j == 3) {
				(*pattern)[i][j] = 180;
			} else if ((i == 0 && j == 1) || (i == 1 && j == 0)) {
				(*pattern)[i][j] = 255;
			} else if (i == 0 && j == 0) {
				(*pattern)[i][j] = 180;
			} else {
				(*pattern)[i][j] = 0;
			}
		}
	}
}

void pattern_12(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i == 0 && j == 2) || (i == 1 && j == 3)) {
				(*pattern)[i][j] = 255;
			} else if (i == 0 && j == 3) {
				(*pattern)[i][j] = 0;
			} else {
				(*pattern)[i][j] = 180;
			}
		}
	}
}

void pattern_13(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == 1) {
				(*pattern)[i][j] = 255;
			} else if (i == 0) {
				(*pattern)[i][j] = 180;
			} else {
				(*pattern)[i][j] = 0;
			}
		}
	}
}

void pattern_14(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i == 2 && j == 3) || (i == 3 && j == 2)) {
				(*pattern)[i][j] = 255;
			} else if (i == 3 && j == 3) {
				(*pattern)[i][j] = 0;
			} else {
				(*pattern)[i][j] = 180;
			}
		}
	}
}

void pattern_15(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if ((i == 2 && j == 0) || (i == 3 && j == 1)) {
				(*pattern)[i][j] = 255;
			} else if (i == 3 && j == 0) {
				(*pattern)[i][j] = 0;
			} else {
				(*pattern)[i][j] = 180;
			}
		}
	}
}

void pattern_16(int ***pattern)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			(*pattern)[i][j] = 255;
		}
	}
}

/*Functia principala a comenzii INIT_CONTUR care
printeaza fiecare sablon in parte*/
void init_contur_show_pattern(int ***pattern)
{
	pattern_1(pattern);
	print_init_contur(*pattern);
	pattern_2(pattern);
	print_init_contur(*pattern);
	pattern_3(pattern);
	print_init_contur(*pattern);
	pattern_4(pattern);
	print_init_contur(*pattern);
	pattern_5(pattern);
	print_init_contur(*pattern);
	pattern_6(pattern);
	print_init_contur(*pattern);
	pattern_7(pattern);
	print_init_contur(*pattern);
	pattern_8(pattern);
	print_init_contur(*pattern);
	pattern_9(pattern);
	print_init_contur(*pattern);
	pattern_10(pattern);
	print_init_contur(*pattern);
	pattern_11(pattern);
	print_init_contur(*pattern);
	pattern_12(pattern);
	print_init_contur(*pattern);
	pattern_13(pattern);
	print_init_contur(*pattern);
	pattern_14(pattern);
	print_init_contur(*pattern);
	pattern_15(pattern);
	print_init_contur(*pattern);
	pattern_16(pattern);
	print_init_contur(*pattern);
}

/*Aceasta functie ne ajuta pentru comanda march
cand stocam un sablon in matricea din functia march*/
void init_contur(int ***pattern, int pat_num)
{
	pattern_1(pattern);
	if (pat_num == 0) {
		return;
	}
	pattern_2(pattern);
	if (pat_num == 1) {
		return;
	}
	pattern_3(pattern);
	if (pat_num == 2) {
		return;
	}
	pattern_4(pattern);
	if (pat_num == 3) {
		return;
	}
	pattern_5(pattern);
	if (pat_num == 4) {
		return;
	}
	pattern_6(pattern);
	if (pat_num == 5) {
		return;
	}
	pattern_7(pattern);
	if (pat_num == 6) {
		return;
	}
	pattern_8(pattern);
	if (pat_num == 7) {
		return;
	}
	pattern_9(pattern);
	if (pat_num == 8) {
		return;
	}
	pattern_10(pattern);
	if (pat_num == 9) {
		return;
	}
	pattern_11(pattern);
	if (pat_num == 10) {
		return;
	}
	pattern_12(pattern);
	if (pat_num == 11) {
		return;
	}
	pattern_13(pattern);
	if (pat_num == 12) {
		return;
	}
	pattern_14(pattern);
	if (pat_num == 13) {
		return;
	}
	pattern_15(pattern);
	if (pat_num == 14) {
		return;
	}
	pattern_16(pattern);
	if (pat_num == 15) {
		return;
	}
	if (pat_num == -1) {
		init_contur_show_pattern(pattern);
	}
}
