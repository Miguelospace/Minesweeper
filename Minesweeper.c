/*
   .______    __    __       _______.  ______     ___      .___  ___.  __  .__   __.      ___           _______.
   |   _  \  |  |  |  |     /       | /      |   /   \     |   \/   | |  | |  \ |  |     /   \         /       |
   |  |_)  | |  |  |  |    |   (----`|  ,----'  /  ^  \    |  \  /  | |  | |   \|  |    /  ^  \       |   (----`
   |   _  <  |  |  |  |     \   \    |  |      /  /_\  \   |  |\/|  | |  | |  . `  |   /  /_\  \       \   \
   |  |_)  | |  `--'  | .----)   |   |  `----./  _____  \  |  |  |  | |  | |  |\   |  /  _____  \  .----)   |
   |______/   \______/  |_______/     \______/__/     \__\ |__|  |__| |__| |__| \__| /__/     \__\ |_______/
   */
// Este trabajo debe de ser compilado en Zinjai para un mejor funconamiento
// Buscaminas versión 1.3
// 30/11/2020
// Miguel Angel García

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int filas = 0;
int columnas = 0;
int vidas = 3;
int banderas = 5;
int matriz[5][5];
int op;
//int xa,ya;
//***********************************************************
// Significado del contenido de la matríz dentro de la lógica
// Número 0 = Oculto
// Número 6 = Bandera
// Número 7 = Espacio abierto con mina
// Número 8 = Espacio sin mina
// Número 9 = Espacio con mina
//************************************************************
void llenaunos() {
	matriz[0][0] = 8;
	matriz[0][1] = 8;
	matriz[0][2] = 8;
	matriz[0][3] = 8;
	matriz[0][4] = 8;
	matriz[1][0] = 8;
	matriz[1][1] = 8;
	matriz[1][2] = 8;
	matriz[1][3] = 8;
	matriz[1][4] = 8;
	matriz[2][0] = 8;
	matriz[2][1] = 8;
	matriz[2][2] = 8;
	matriz[2][3] = 8;
	matriz[2][4] = 8;
	matriz[3][0] = 8;
	matriz[3][1] = 8;
	matriz[3][2] = 8;
	matriz[3][3] = 8;
	matriz[3][4] = 8;
	matriz[4][0] = 8;
	matriz[4][1] = 8;
	matriz[4][2] = 8;
	matriz[4][3] = 8;
	matriz[4][4] = 8;
}

int numeroaleatorioparalamina(int recibe) {
	int valor = 0;
	valor = rand() % recibe;
	return valor;
}

void generamina() {

	printf("\n");
	printf("Mapa\n");
	for (int i = 1; i < 6; i++)
	{
		int x, y;
		x = numeroaleatorioparalamina(5);
		y = numeroaleatorioparalamina(5);
		//printf("%d, %d\n", y, x);
		// 2
		matriz[x][y] = 9;
	}
}

void dibujamaya() {
	//int m;
	for (filas = 0; filas < 5; filas++) {
		for (columnas = 0; columnas < 5; columnas++) {
			printf("| %d ", matriz[filas][columnas]);
			//printf("| X ");
		}
		printf("|\n\n");
	}
	/*
	   for (m = 0; m <= 5; m++) {
	   printf("----");
	   if (m == 5) {
	   printf("-");
	   }
	   }
	   */
	printf("\n");
}

void PregCoordMuestra() {
	int xa, ya;
	int contador = 0;
	printf("A continuación vas a ingresar las coordenadas de la casilla que deseas abrir en un rango de 0 a 4\n");
	printf("Ingresa el renglón: ");
	fflush(stdin);
	scanf("%d", &xa);
	printf("Ingresa la columna: ");
	fflush(stdin);
	scanf("%d", &ya);
	if (matriz[xa][ya] == 8)
		printf("\nEspacio sin mina\n");
	else if (matriz[xa][ya] == 9) {
		printf("\nEspacio con mina\n");
		matriz[xa][ya] = 7;
		vidas = vidas - 1;
		if (vidas == 0) {
			op = 4;
			printf("\nJuego terminado");
		}
	}

	/*printf("\n%d, %d", xa,ya);*/

	// Para la esquina superior izquierda
	if (xa == 0) {
		if (ya == 0) {
			printf("\n SI Matriz [%d][%d]= %d\n", xa, ya, matriz[xa][ya]);
			if (matriz[1][0] == 9)
				contador++;
			if (matriz[0][1] == 9)
				contador++;
			if (matriz[1][1] == 9)
				contador++;
			printf("\nLa pista de 0,0 = %d\n", contador);
			if (matriz[xa][ya] != 7)
				matriz[xa][ya] = contador;
		}

		// Parte centro superior
		if (ya >= 1 && ya <= 3) {
			printf("\n CSup Matriz [%d][%d]= %d\n", xa, ya, matriz[xa][ya]);
			if (matriz[xa][ya - 1] == 9)
				contador++;
			if (matriz[xa + 1][ya - 1] == 9)
				contador++;
			if (matriz[xa + 1][ya] == 9)
				contador++;
			if (matriz[xa + 1][ya + 1] == 9)
				contador++;
			if (matriz[xa][ya + 1] == 9)
				contador++;
			if (matriz[xa][ya] != 7)
				matriz[xa][ya] = contador;
			printf("\nLa pista = %d\n", contador);
		}

		// Esquina superior derecha
		if (ya == 4) {
			printf("\n ESD Matriz [%d][%d]= %d\n", xa, ya, matriz[xa][ya]);
			if (matriz[0][3] == 9 || matriz[1][3] == 9 || matriz[1][4] == 9)
				contador++;
			printf("\nLa pista de 0,4 = %d", contador);
			if (matriz[xa][ya] != 7)
				matriz[xa][ya] = contador;
		}
	}

	// Parte centro izquierda
	if ((xa >= 1) && (xa <= 3)) {
		if (ya == 0) {
			printf("\n CIzq Matriz [%d][%d]= %d\n", xa, ya, matriz[xa][ya]);
			if (matriz[xa][ya - 1] == 9)
				contador++;
			if (matriz[xa + 1][ya - 1] == 9)
				contador++;
			if (matriz[xa + 1][ya] == 9)
				contador++;
			if (matriz[xa + 1][ya + 1] == 9)
				contador++;
			if (matriz[xa][ya + 1] == 9)
				contador++;
			if (matriz[xa][ya] != 7)
				matriz[xa][ya] = contador;
			printf("\nLa pista de = %d\n", contador);
		}

		// Parte centro derecha
		if (ya == 4) {
			printf("\n CDer Matriz [%d][%d]= %d\n", xa, ya, matriz[xa][ya]);
			if (matriz[xa][ya - 1] == 9)
				contador++;
			if (matriz[xa + 1][ya - 1] == 9)
				contador++;
			if (matriz[xa + 1][ya] == 9)
				contador++;
			if (matriz[xa + 1][ya + 1] == 9)
				contador++;
			if (matriz[xa][ya + 1] == 9)
				contador++;
			if (matriz[xa][ya] != 7)
				matriz[xa][ya] = contador;
			printf("\nLa pista de = %d\n", contador);
		}
	}

	// Parte centro inferior
	if (xa == 4) {
		if ((ya >= 1) && (ya <= 3)) {
			printf("\n CInf Matriz [%d][%d]= %d\n", xa, ya, matriz[xa][ya]);
			if (matriz[xa][ya - 1] == 9)
				contador++;
			if (matriz[xa + 1][ya - 1] == 9)
				contador++;
			if (matriz[xa + 1][ya] == 9)
				contador++;
			if (matriz[xa + 1][ya + 1] == 9)
				contador++;
			if (matriz[xa][ya + 1] == 9)
				contador++;
			if (matriz[xa][ya] != 7)
				matriz[xa][ya] = contador;
			printf("\nLa pista de = %d\n", contador);
		}

		// Esquina inferior derecha
		if (ya == 0) {
			printf("\n EID Matriz [%d][%d]= %d\n", xa, ya, matriz[xa][ya]);
			if (matriz[3][0] == 9 || matriz[3][1] == 9 || matriz[4][1] == 9)
				contador++;
			printf("\nLa pista de 4,0 = %d\n", contador);
			if (matriz[xa][ya] != 7)
				matriz[xa][ya] = contador;
		}

		// Esquina inferior izquierda
		if (ya == 4) {
			printf("\n EII Matriz [%d][%d]= %d\n", xa, ya, matriz[xa][ya]);
			if (matriz[0][3] == 9 || matriz[1][3] == 9 || matriz[1][4] == 9)
				contador++;
			printf("\nLa pista de 4,4 = %d\n", contador);
			if (matriz[xa][ya] != 7)
				matriz[xa][ya] = contador;
		}
	}

	// Casillas centrales
	if (((xa >= 1) && (xa <= 3)) && ((ya >= 1) && (ya <= 3))) {
		printf("\n-Matriz [%d][%d]= %d\n", xa, ya, matriz[xa][ya]);
		if (matriz[xa - 1][ya - 1] == 9)
			contador++;
		if (matriz[xa - 1][ya] == 9)
			contador++;
		if (matriz[xa - 1][ya + 1] == 9)
			contador++;
		if (matriz[xa][ya + 1] == 9)
			contador++;
		if (matriz[xa + 1][ya + 1] == 9)
			contador++;
		if (matriz[xa + 1][ya] == 9)
			contador++;
		if (matriz[xa + 1][ya - 1] == 9)
			contador++;
		if (matriz[xa][ya - 1] == 9)
			contador++;
		printf("\nLa pista de %d,%d = %d\n", xa, ya, contador);
		if (matriz[xa][ya] != 7)
			matriz[xa][ya] = contador;
	}
}

void pintamapita() {
	char equis = 178;
	//printf("\nAndo en pintamapita\n"); Esto era una prueba para comprobar la entrada del programa a este lugar
	for (filas = 0; filas < 5; filas++) {
		printf("+---+---+---+---+---+\n");
		for (columnas = 0; columnas < 5; columnas++)
		{
			if (matriz[filas][columnas] == 8 || matriz[filas][columnas] == 9)
				//printf("| %d ", matriz[filas][columnas]);
				printf("| %c ", equis);
			if (matriz[filas][columnas] >= 1 && matriz[filas][columnas] <= 5)
				printf("| %d ", matriz[filas][columnas]);
			if (matriz[filas][columnas] == 0)
				printf("|   ");
			if (matriz[filas][columnas] == 7)
			{
				printf("| M ");
			}
			if (matriz[filas][columnas] == 6)
			{
				printf("| B ");
			}
		}
		printf("|\n");
	}
	printf("+---+---+---+---+---+\n");
	printf("\nTienes %d vidas\n", vidas);
	printf("\nTe quedan %d banderas\n\n", banderas);
}

void pintamapita2() {
	char equis = 178;
	for (filas = 0; filas < 5; filas++) {
		printf("+---+---+---+---+---+\n");
		for (columnas = 0; columnas < 5; columnas++) {
			if (matriz[filas][columnas] == 7 && matriz[filas][columnas] == 9)
				//printf("| %d ", matriz[filas][columnas]);
				printf("| %c ", equis);
			if (matriz[filas][columnas] >= 1 && matriz[filas][columnas] <= 5)
				printf("| %d ", matriz[filas][columnas]);
			if (matriz[filas][columnas] == 0)
				printf("|   ");
			if (matriz[filas][columnas] == 9)
				printf("| M ");
			if (matriz[filas][columnas] == 8)
				printf("|   ");
			if (matriz[filas][columnas] == 7)
			{
				printf("| m ");
			}
			if (matriz[filas][columnas] == 6)
			{
				printf("| B ");
			}
		}
		printf("|\n");
	}
	printf("+---+---+---+---+---+\n");
	op = 4;
}

int menu() {
	int op;
	/*
	   [1] elegir el renglón y columna para poner bandera (hasta 5 banderas).
	   [2] elegir el renglón y columna para destapar celda.
	   [3] destapar todas las celdas y ver si le atinaste con las banderas (lugar donde había minas).
	   [4] Salir (6 puntos).
	   */
	printf("Elegir el renglón y columna para poner bandera (hasta 5 banderas)                          [ 1 ]\n");
	printf("Elegir el renglón y columna para destapar celda                                            [ 2 ]\n");
	printf("Destapar todas las celdas y ver si le atinaste con las banderas (lugar donde había minas)  [ 3 ]\n");
	printf("Salir                                                                                      [ 4 ]\n");
	printf("Ingresa la opcion que deseas que se realice: ");
	scanf("%d", &op);
	return op;
}

void mapacubiertoperoenfuncion() {
	// Esta función también los cubría pero creo que es más funcional sin que los pinte, aunque el nombre ya se le quedó
	llenaunos();
	generamina();
	//dibujamaya();
	//pintamapita();
}

void mayabanderas() {
	int xa, ya;

	pintamapita();
	printf("\nA continuación vas a ingresar las coordenadas de la casilla que deseas marcar con una bandera en un rango de 0 a 4\n");
	printf("Ingresa el renglón: ");
	fflush(stdin);
	scanf("%d", &xa);
	printf("Ingresa la columna: ");
	fflush(stdin);
	scanf("%d", &ya);
	if (banderas > 0) {
		banderas = banderas - 1;
		matriz[xa][ya] = 6;
	}
	pintamapita();
}

int main() {
	srand(time(NULL));
	printf("-----------------------------Buscaminas-----------------------------\n\n");
	mapacubiertoperoenfuncion();
	do {
		op = menu();
		switch (op)
		{
			case 1: //dibujamaya();
				mayabanderas();
				break;
			case 2:
				//dibujamaya();
				pintamapita();
				PregCoordMuestra();
				//dibujamaya();
				pintamapita();
				//mapacubiertoperoenfuncion();
				break;
			case 3:
				//dibujamaya();
				if (matriz[filas][columnas] == 9)
					printf("| M ");
				if (matriz[filas][columnas] == 6)
					printf("| B ");
				pintamapita2();
				break;
			case 4:
				break;
			default:
				printf("La opcion no está en el menú");
		}
	} while (op != 4);
	printf("Juego terminado\n");
	printf("\nTrabajo realizado por Miguel y Orlando\n");

	return 0;
}

