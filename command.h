#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESIZE 4
#define VAL_SAM 4
#define SIGMA 200

//Functie pentru alocarea matricilor in mod dinamic
int allocate_matrix(int height, int width, int ***matrix)
{
	*matrix = (int **)malloc(height * sizeof(int *));
	if (!*matrix) {
		return 1;
	}
	for (int i = 0; i < height; i++) {
		(*matrix)[i] = (int *)malloc(width * sizeof(int));
		if (!(*matrix)[i]) {
			return 1;
		}
	}
	return 0;
}

//Functia printeaza grid ul
void print_grid(int ***grid, int height, int width)
{
	for (int i = 0; i < height / VAL_SAM; i++) {
		for (int j = 0; j < width / VAL_SAM; j++) {
			printf("%d ", (*grid)[i][j]);
		}
		printf("\n");
	}
}

/*Aceasta functie elibereaza memoria care a fost
alocata dinamic intr-o matrice*/
void finish(int height, int ***matrix)
{
	for (int i = 0; i < height; i++) {
		free((*matrix)[i]);
	}

	free(*matrix);
}

//Scaneaza o matrice pe care o aloca dinamic
int scan_matrix(int height, int width, int ***matrix, int max_val)
{
	int eroare = 0;
	if (allocate_matrix(height, 3 * width, matrix)) {
		return -1;
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < 3 * width; j++) {
			scanf("%d", &(*matrix)[i][j]);
			if ((*matrix)[i][j] > max_val && eroare == 0) {
				eroare = 1;
			}
		}
	}

	if (eroare) {
		finish(height, matrix);
		return 1;
	}

	return 0;
}

//Printez matrciea care reprezinta imaginea
void print_matrix(int height, int width, int **matrix)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%d ", matrix[i][3 * j]);
			printf("%d ", matrix[i][3 * j + 1]);
			printf("%d\n", matrix[i][3 * j + 2]);
		}
	}
}

/*Functia princiala a comenzii READ*/
int read(char *format, int *width, int *height, int *max_val, int ***matrix)
{
	static int cnt_read = 1;
	/*Daca reutilizam functia READ eliberez memoria matricei originale
	pentru a nu avea scurgeri de memorie, iar dupa aceea o aloc din nou
	dinamic*/
	if (cnt_read > 1) {
		finish(*height, matrix);
	}
	cnt_read++;
	fgets(format, 3, stdin);
	getchar();
	scanf("%d%d", height, width);
	scanf("%d", max_val);
	/*Eliberez matricea deoarece cand refolosesc comanda READ
	pentru a nu avea scurgeri de memorie eliberez matricea veche nemaiavand
	nevoie de aceasta*/
	int eroare = 0;
	if (allocate_matrix(*height, 3 * (*width), matrix)) {
		return -1;
	}

	for (int i = 0; i < *height; i++) {
		for (int j = 0; j < 3 * (*width); j++) {
			/*Daca functia scanf nu returneaza 1 inseamna ca
			nu s-au introdus cati pixeli aveam nevoie si returneaza 3*/
			if (scanf("%d", &(*matrix)[i][j]) != 1) {
				return 3;
			}

			if ((*matrix)[i][j] > *max_val && eroare == 0) {
				eroare = 1;
			}
		}
	}

	if (strcmp(format, "P3") != 0) {
		//daca formatul nu este "P3", returneaza 2
		return 2;
	}

	if (eroare) {
		/*daca cel putin o VAL_SAM dintr-un pixel nu este in
		limita valorii maxime, returneaza 1 si elibereaza memoria
		matricei pentru a putea pune valori noi*/
		return 1;
	}

	//daca nu exista nicio eroare returneaza 0
	return 0;
}

//Functia principala a comenzii WRITE
void write(char *format, int height, int lenght, int max_val)
{
	printf("%s\n", format);
	printf("%d %d\n", height, lenght);
	printf("%d\n", max_val);
}

//Functia principala a comenzii RESIZE
int resize(int ***matrix, int *height, int *width)
{
	*height *= RESIZE;
	*width *= RESIZE;
	//Alocarea memoriei pentru noua matrice redimensionata
	int **aux_matrix;
	if (allocate_matrix(*height, 3 * (*width), &aux_matrix)) {
		return 1;
	}

	for (int i = 0; i < *height / RESIZE; i++) {
		for (int j = 0; j < *width / RESIZE; j++) {
			//Pixelul din imaginea originala
			int red = (*matrix)[i][3 * j];
			int gren = (*matrix)[i][3 * j + 1];
			int blue = (*matrix)[i][3 * j + 2];

			//Acum multiplicam pixelul in matricea redimensionata
			for (int k = 0; k < RESIZE; k++) {
				for (int q = 0; q < RESIZE; q++) {
					aux_matrix[i * RESIZE + k][3 * (j * RESIZE + q)] = red;
					aux_matrix[i * RESIZE + k][3 * (j * RESIZE + q) + 1] = gren;
					aux_matrix[i * RESIZE + k][3 * (j * RESIZE + q) + 2] = blue;
				}
			}
		}
	}
	//aloc memorie matriciei originale
	finish((*height) / RESIZE, matrix);
	if (allocate_matrix(*height, 3 * (*width), matrix)) {
		return 1;
	}

	for (int i = 0; i < *height; i++) {
		for (int j = 0; j < 3 * (*width); j++) {
			(*matrix)[i][j] = aux_matrix[i][j];
		}
	}

	finish(*height, &aux_matrix);
	return 0;
}

//Functia principala a comenzii GRID
int grid(int *height, int *width, int ***matrix, int ***grid_mat)
{
	//Initializez matricea grid
	*grid_mat = (int **)malloc(((*height) / VAL_SAM + 1) * sizeof(int *));
	if (!grid_mat) {
		return 1;
	}
	for (int i = 0; i < (*height) / VAL_SAM + 1; i++) {
		(*grid_mat)[i] = (int *)malloc(((*width) / VAL_SAM + 1) * sizeof(int));
		if (!(*grid_mat)[i]) {
			return 1;
		}
	}
	/*Calculez luminozitatea fiecarui pixel*/
	for (int i = 0; i < *height; i++) {
		for (int j = 0; j < *width; j++) {
			(*matrix)[i][j] = (*matrix)[i][3 * j];
			(*matrix)[i][j] += (*matrix)[i][3 * j + 1];
			(*matrix)[i][j] += (*matrix)[i][3 * j + 2];
			(*matrix)[i][j] /= 3;
		}
	}
	//cate patrate are pe o latura domeniul D dupa definirea lor
	for (int i = 0; i <= *height ; i++) {
		for (int j = 0; j <= *width; j++) {
			int grid_value = 0;
			int left_up = 0, right_up = 0, left_down = 0;
			int right_down = 0, middle = 0, cnt_pixel = 0;
			if ((i % 4 == 0) && (j % 4 == 0)) {
				if (i + 1 < *height && j + 1 < *width) {
					right_down = (*matrix)[i + 1][j + 1];
					cnt_pixel++;
				}

				if (i + 1 < *height && j - 1 > 0) {
					left_down = (*matrix)[i + 1][j - 1];
					cnt_pixel++;
				}

				if (i - 1 > 0 && j + 1 < *width) {
					right_up = (*matrix)[i - 1][j + 1];
					cnt_pixel++;
				}

				if (i - 1 > 0 && j - 1 > 0) {
					left_up = (*matrix)[i - 1][j - 1];
					cnt_pixel++;
				}

				if (i < *height && j < *width) {
					middle = (*matrix)[i][j];
					cnt_pixel++;
				}
				grid_value = left_down + left_up;
				grid_value += right_down + right_up + middle;
				grid_value /= cnt_pixel;
				if (grid_value > SIGMA) {
					grid_value = 0;
				} else {
					grid_value = 1;
				}

				(*grid_mat)[i / 4][j / 4] = grid_value;
			}
		}
	}
	return 0;
}

/*functia de mai jos am creat-o pentru march, care ma ajuta cand convertesc
valorile a 4 noduri din grid in binar si apoi cu ajutorul functiei in zecimal*/
int binar_to_decimal(int nr)
{
	int decimal = 0;
	int power = 1;
	while (nr != 0) {
		decimal += (nr % 10) * power;
		power *= 2;
		nr /= 10;
	}
	return decimal;
}

//Functia principala a comenzii MARCH
int march(int *height, int *width, int ***grid, int ***pattern, int ***matrix)
{
	/*realoc dinamic o matricea*/
	finish(*height, matrix);

	if (allocate_matrix(*height, 3 * (*width), matrix)) {
		return 1;
	}
	/*initializez numarul care reprezinta march_number a cate
	4 in 4 noduri din grid pentru a putea face march*/
	int march_number = 0;
	for (int i = 0; i < (*height) / VAL_SAM; i++) {
		for (int j = 0; j < (*width) / VAL_SAM; j++) {
			march_number = (*grid)[i][j] * 1000 + (*grid)[i][j + 1] * 100;
			march_number += (*grid)[i + 1][j + 1] * 10 + (*grid)[i + 1][j];
			//il convertim in numar zecimal
			march_number = binar_to_decimal(march_number);
			/*Pun in matricea pattern, unul din cele 16 sabloane
			care depind de march_number*/
			init_contur(pattern, march_number);
			for (int p = i * 4; p < i * 4 + 4; p++) {
				for (int q = j * 4; q < j * 4 + 4; q++) {
					(*matrix)[p][3 * q] = (*pattern)[p % 4][q % 4];
					(*matrix)[p][3 * q + 1] = (*pattern)[p % 4][q % 4];
					(*matrix)[p][3 * q + 2] = (*pattern)[p % 4][q % 4];
				}
			}
		}
	}
	return 0;
}
