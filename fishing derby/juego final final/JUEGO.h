//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
#include<iostream>
#include <conio.h>
#include"gameover.h"
#include"winner.h"
using namespace std;
using namespace System;
//Inicio seccion controles
const char arriba = 72; //flecha arriba
const char abajo = 80; //flecha abajo
const char derecha = 77; //flecha derecha
const char izquierda = 75; //flecha izquierda
const char espacio = 32; //tecla espacio
						 //fin seccion controles
						 //inicializacion de estructuras
struct pez
{
	int limite_izquierdo = 10;
	int limite_derecho = 97;
	int posx;
	int posy;
	int filas = 7;
	int columnas = 8;
	int direccion = 101;
	bool perteneceflujo = true;
	bool verdadchoque = false;
};
struct tibu
{
	int limite_izquierdo = 10;
	int limite_derecho = 90;
	int posx;
	int posy;
	int filas = 10;
	int columnas = 14;
	int direccion = 101;
};
struct hilo
{
	int posx;
	int posy;
	int getx;
	int longitud;
}hilito;
struct caña
{
	int posx;
	int posy;
	int longitud;
}cañita;
//fin de inicializacion de estructuras
void posicion(int x, int y) {
	Console::SetCursorPosition(y, x);
}
void  cargapezderecha(int **dinamica) {
	int pez[7][8] = {
		{ 6,3,3,3,3,3,3,3 },
		{ 6,6,3,3,6,6,3,3 },
		{ 3,6,3,6,6,6,6,3 },
		{ 3,3,6,6,6,6,6,6 },
		{ 3,6,3,6,6,6,6,3 },
		{ 6,6,3,3,6,6,3,3 },
		{ 6,3,3,3,3,3,3,3 } };
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			dinamica[i][j] = pez[i][j];
		}
	}
}
void  cargapezizquierda(int **dinamica) {
	int pez[7][8] = {
		{ 3,3,3,3,3,3,3,6 },
		{ 3,3,6,6,3,3,6,6 },
		{ 3,6,6,6,6,3,6,3 },
		{ 6,6,6,6,6,6,3,3 },
		{ 3,6,6,6,6,3,6,3 },
		{ 3,3,6,6,3,3,6,6 },
		{ 3,3,3,3,3,3,3,6 } };
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			dinamica[i][j] = pez[i][j];
		}
	}
}
void cargatibuderecha(int **dinamica) {
	int tiburon[10][14] = {
		{ 8,3,3,3,8,8,8,8,3,3,3,3,3,3 },
		{ 8,8,3,3,3,8,8,8,8,3,3,3,3,3 },
		{ 3,8,8,3,8,8,8,8,8,8,8,8,8,3 },
		{ 3,3,8,8,8,8,8,8,8,8,8,8,8,8 },
		{ 3,3,3,8,8,8,8,8,8,8,8,8,8,8 },
		{ 3,3,3,8,8,8,8,8,8,8,8,8,3,3 },
		{ 3,3,8,8,8,8,8,8,8,8,8,8,3,3 },
		{ 3,8,8,3,8,8,8,8,8,8,8,8,8,8 },
		{ 8,8,3,3,3,3,8,8,8,3,3,3,3,3 },
		{ 8,3,3,3,3,8,8,8,3,3,3,3,3,3 } };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			dinamica[i][j] = tiburon[i][j];
		}
	}
}
void cargatibuizquierda(int **dinamica) {
	int tiburon[10][14] = {
		{ 3,3,3,3,3,3,8,8,8,8,3,3,3,8 },
		{ 3,3,3,3,3,8,8,8,8,3,3,3,8,8 },
		{ 3,8,8,8,8,8,8,8,8,8,3,8,8,3 },
		{ 8,8,8,8,8,8,8,8,8,8,8,8,3,3 },
		{ 8,8,8,8,8,8,8,8,8,8,8,3,3,3 },
		{ 3,3,8,8,8,8,8,8,8,8,8,3,3,3 },
		{ 3,3,8,8,8,8,8,8,8,8,8,8,3,3 },
		{ 8,8,8,8,8,8,8,8,8,8,3,8,8,3 },
		{ 3,3,3,3,3,8,8,8,3,3,3,3,8,8 },
		{ 3,3,3,3,3,3,8,8,8,3,3,3,3,8 } };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			dinamica[i][j] = tiburon[i][j];
		}
	}
}
void cargahilo(char **dinamica, int longitud, int posx, int posy) {
	for (int i = 0; i < longitud; i++)
	{
		dinamica[i][0] = char(219);
	}
}
void cargacaña(char **dinamica, int longitud, int posx, int posy) {
	for (int i = 0; i < longitud; i++)
	{
		dinamica[0][i] = char(219);
	}
}
void crea_matriz(char **matriz, int filas, int columnas) {
	for (int i = 0; i < filas; i++)
	{
		matriz[i] = new char[columnas];
	}
}
void crea_matriz1(int **matriz, int filas, int columnas) {
	for (int i = 0; i < filas; i++)
	{
		matriz[i] = new int[columnas];
	}
}
void libera_matriz(char **matriz, int filas) {
	for (int i = 0; i < filas; i++)
	{
		delete matriz[i];
	}
}
void libera_matriz1(int **matriz, int filas) {
	for (int i = 0; i < filas; i++)
	{
		delete matriz[i];
	}
}
void pinta_matriz1(int **dinamica, int filas, int columnas, int posx, int posy) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			Console::ForegroundColor = ConsoleColor(dinamica[i][j]);
			posicion(posx + i, posy + j);
			cout << char(219);
		}
	}
}
void pinta_matriz(char **dinamica, int filas, int columnas, int posx, int posy) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			Console::ForegroundColor = ConsoleColor(2);
			posicion(posx + i, posy + j);
			cout << dinamica[i][j];
		}
	}
}
void pinta_matriz2(char **dinamica, int filas, int columnas, int posx, int posy) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			Console::ForegroundColor = ConsoleColor(12);
			posicion(posx + i, posy + j);
			cout << dinamica[i][j];
		}
	}
}
void borra_matriz(int **dinamica, int filas, int columnas, int posx, int posy) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			posicion(posx + i, posy + j);
			cout << " ";
		}
	}
}
void borra_matriz1(char **dinamica, int filas, int columnas, int posx, int posy) {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			posicion(posx + i, posy + j);
			cout << " ";
		}
	}
}
void mueve_pez_derecha(int **dinamica, int filas, int columnas, int cantidad, pez *pescadito, int i) {
	cargapezderecha(dinamica);
	borra_matriz(dinamica, filas, columnas, pescadito[i].posx, pescadito[i].posy);
	pescadito[i].posy++;
	pinta_matriz1(dinamica, filas, columnas, pescadito[i].posx, pescadito[i].posy);
}
void mueve_pez_izquierda(int **dinamica, int filas, int columnas, int cantidad, pez *pescadito, int i) {
	cargapezizquierda(dinamica);
	borra_matriz(dinamica, filas, columnas, pescadito[i].posx, pescadito[i].posy);
	pescadito[i].posy--;
	pinta_matriz1(dinamica, filas, columnas, pescadito[i].posx, pescadito[i].posy);
}
void mueve_tibu_derecha(int **dinamica, int filas, int columnas, int cantidad, tibu *tiburoncin, int i) {
	cargatibuderecha(dinamica);
	borra_matriz(dinamica, filas, columnas, tiburoncin[i].posx, tiburoncin[i].posy);
	tiburoncin[i].posy++;
	pinta_matriz1(dinamica, filas, columnas, tiburoncin[i].posx, tiburoncin[i].posy);
}
void mueve_tibu_izquierda(int **dinamica, int filas, int columnas, int cantidad, tibu *tiburoncin, int i) {
	cargatibuizquierda(dinamica);
	borra_matriz(dinamica, filas, columnas, tiburoncin[i].posx, tiburoncin[i].posy);
	tiburoncin[i].posy--;
	pinta_matriz1(dinamica, filas, columnas, tiburoncin[i].posx, tiburoncin[i].posy);
}
void oceano() {
	Console::BackgroundColor = ConsoleColor(3);
	for (int i = 0; i < 62; i++)
	{
		for (int j = 0; j < 105; j++)
		{
			if (i == 0 && j<10)
			{
				posicion(24 + i, 0 + j);
				cout << char(219);
				Console::ForegroundColor = ConsoleColor(0);

			}
			else
			{
				posicion(24 + i, 0 + j);
				cout << char(219);
				Console::ForegroundColor = ConsoleColor(3);
			}
		}
	}
}
void muelle() {
	for (int i = 0; i < 62; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((j == 2 || j == 3 || j == 6 || j == 7) && i > 0)
			{
				posicion(24 + i, 0 + j);
				cout << char(219);
				Console::ForegroundColor = ConsoleColor(0);
			}
			if (i == 1)
			{
				posicion(24 + i, 0 + j);
				cout << char(219);
				Console::ForegroundColor = ConsoleColor(0);
			}
		}
	}
}
void cielo(int cielo, int sol) {
	int cieloo[24][80] =
	{ { cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,cielo,cielo,cielo,sol,cielo,cielo,cielo,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,cielo,cielo,sol,cielo },
	{ cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,15,cielo,cielo,sol,sol,cielo,cielo,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,cielo,sol,sol,cielo },
	{ cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,15,15,15,cielo,cielo,sol,sol,cielo,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,cielo,sol },
	{ cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,15,15,15,15,15,cielo,cielo,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,cielo,sol,sol },
	{ cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,15,15,15,cielo,4,4,cielo,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,cielo,sol,sol,cielo },
	{ cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,cielo,cielo,15,15,15,15,15,15,15,15,15,cielo,4,cielo,cielo,cielo,cielo,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,cielo,cielo },
	{ cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,cielo,cielo,4,4,cielo,cielo,cielo,cielo,cielo,4,4,cielo,cielo,cielo,cielo,15,15,15,15,15,15,15,cielo,4,4,cielo,cielo,cielo,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,cielo,cielo,cielo },
	{ cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,cielo,cielo,cielo,4,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,cielo,4,4,cielo,cielo,cielo,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,cielo,cielo,cielo,cielo },
	{ cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,cielo,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,4,cielo,cielo,cielo,sol,sol,cielo,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,cielo,cielo,cielo },
	{ cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,sol,sol,cielo,cielo,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,cielo,cielo },
	{ cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,sol,sol,cielo,cielo,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,sol,cielo,sol,sol,cielo },
	{ cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,cielo,cielo,cielo,cielo,cielo,cielo,4,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,sol,cielo,cielo,sol,sol,cielo,cielo,sol,sol,cielo,sol,sol,cielo,sol,sol,cielo,cielo,cielo,sol,sol },
	{ 13,cielo,cielo,13,13,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,cielo,cielo,cielo,cielo,4,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,cielo,cielo,cielo,cielo,cielo,4,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,sol,sol,cielo,cielo,sol,sol,cielo,cielo,cielo,sol,sol,cielo,sol,sol,cielo,cielo,cielo,sol },
	{ 13,13,13,13,13,13,13,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,cielo,cielo,4,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,cielo,cielo,cielo,4,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,sol,sol,cielo,cielo,sol,sol,cielo,cielo,cielo,cielo,cielo,sol,sol,cielo,sol,sol,cielo,cielo,cielo },
	{ cielo,cielo,13,13,13,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,4,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,cielo,4,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,sol,cielo,cielo,cielo,sol,cielo,cielo,cielo,cielo,cielo,cielo,cielo,sol,sol,cielo,sol,cielo,cielo,cielo },
	{ cielo,cielo,13,13,13,13,13,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,4,4,4,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,sol,cielo,cielo,cielo,cielo,cielo },
	{ cielo,cielo,13,13,13,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo },
	{ cielo,13,13,13,cielo,cielo,13,13,13,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo },
	{ cielo,13,13,13,cielo,13,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo },
	{ cielo,13,13,13,13,cielo,cielo,13,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo },
	{ cielo,13,13,13,cielo,cielo,13,13,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo },
	{ cielo,13,13,13,cielo,13,13,13,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo },
	{ cielo,13,13,13,13,13,cielo,13,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo },
	{ cielo,cielo,13,13,13,cielo,cielo,13,13,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo,cielo } };
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			Console::ForegroundColor = ConsoleColor(cieloo[i][j]);
			posicion(i, j);
			cout << char(219);
		}

	}
	for (int i = 0; i < 24; i++)
	{
		for (int j = 80; j < 105; j++)
		{
			Console::ForegroundColor = ConsoleColor(cielo);
			posicion(i, j);
			cout << char(219);
		}
	}
}
void jugar() {
	Console::CursorVisible = false;
	Console::SetWindowSize(105, 88);
	int cantidad_pez, cantidad_tibu, guardar_sector, puntaje, nivel, cronometro, vidas;
	int gh = 0;
	int hg = 30;
	int cielito = 11;
	int solsito = 6;
	char tecla;
	cronometro = 150;
	puntaje = 0;
	vidas = 3;
	nivel = 1;
	bool permitir_choque = true;
	bool tiempo = true;
	bool mover_derecha = true;
	hilito.posx = 18;
	hilito.posy = 11;
	cañita.posx = 17;
	cañita.posy = 9;
	hilito.longitud = 1;
	cañita.longitud = 3;
	hilito.getx = hilito.posx;
	pez *pescadito = new pez[10];
	tibu *tiburoncin = new tibu[3];
	int sectores[7];
	sectores[0] = 25;
	sectores[1] = 39;
	sectores[2] = 47;
	sectores[3] = 55;
	sectores[4] = 63;
	sectores[5] = 71;
	sectores[6] = 79;
	int **tiburon = new int*[10];
	crea_matriz1(tiburon, 10, 14);
	int **pez = new int *[7];
	crea_matriz1(pez, 7, 8);
	char **hilo = new char*[hilito.longitud];
	crea_matriz(hilo, hilito.longitud, 1);
	char **caña = new char*[1];
	crea_matriz(caña, 1, cañita.longitud);
	cargahilo(hilo, hilito.longitud, hilito.posx, hilito.posy);
	cargacaña(caña, cañita.longitud, cañita.posx, cañita.posy);

	while (true)
	{
		Random v;
		for (int i = 0; i < 10; i++)
		{
			pescadito[i].posx = sectores[v.Next(1, 6)];
		}
		for (int i = 0; i < 10; i++) {
			bool vale;
			do {
				pescadito[i].posy = v.Next(12, 80);
				vale = false;
				for (int k = 0; k < i; k++)
				{
					if ((pescadito[i].posy + 8 >= pescadito[k].posy && pescadito[i].posy <= pescadito[k].posy + 8) && (pescadito[i].posx + 7 >= pescadito[k].posx && pescadito[i].posx <= pescadito[k].posx + 7))vale = true;
				}
			} while (vale);
		}
		for (int i = 0; i < 3; i++)
		{
			tiburoncin[i].posx = sectores[0];
		}
		for (int i = 0; i < 3; i++) {
			bool vale;
			do {
				tiburoncin[i].posy = v.Next(12, 80);
				vale = false;
				for (int k = 0; k < i; k++)
				{
					if ((tiburoncin[i].posy + 14 >= tiburoncin[k].posy && tiburoncin[i].posy <= tiburoncin[k].posy + 14) && (tiburoncin[i].posx + 10 >= tiburoncin[k].posx && tiburoncin[i].posx <= tiburoncin[k].posx + 10))vale = true;
				}
			} while (vale);
		}
		oceano();
		muelle();
		cielo(cielito, solsito);
		do
		{
			Console::ForegroundColor = ConsoleColor(4);
			gh++;
			if (gh%hg == 0)
			{
				cronometro--;
			}
			posicion(4, 85);
			cout << "            ";
			posicion(4, 85);
			cout << "Puntaje: " << puntaje;
			posicion(5, 85);
			cout << "            ";
			posicion(6, 85);
			cout << "            ";
			posicion(6, 85);
			cout << "Tiempo: " << cronometro;
			if (cronometro == 0)
			{
				vidas--;
				cronometro = 150;
				puntaje = 0;
				break;
			}
			posicion(7, 85);
			cout << "            ";
			posicion(8, 85);
			cout << "            ";
			posicion(8, 85);
			cout << "Vidas: " << vidas;
			posicion(9, 85);
			cout << "            ";
			posicion(10, 85);
			cout << "            ";
			posicion(10, 85);
			cout << "Nivel: " << nivel;
			if (puntaje >= 100 && puntaje <= 199)
			{
				nivel = 2;
				if (tiempo == true)
				{
					cronometro = 150;
					cielito = 6;
					solsito = 14;
					cielo(cielito, solsito);
					tiempo = false;
				}
				hg = 25;

			}
			if (puntaje >= 200 && puntaje <= 299)
			{
				nivel = 3;
				if (tiempo == false)
				{
					cronometro = 150;
					cielito = 8;
					solsito = 0;
					cielo(cielito, solsito);
					tiempo = true;
				}
				hg = 20;
			}
			if (nivel == 1)
			{
				cantidad_pez = 6;
				cantidad_tibu = 1;
			}
			if (nivel == 2)
			{
				cantidad_pez = 8;
				cantidad_tibu = 2;
			}
			if (nivel == 3)
			{
				cantidad_pez = 10;
				cantidad_tibu = 3;
			}
			//inicio sector tiburones
			for (int i = 0; i < cantidad_tibu; i++)
			{
				if (tiburoncin[i].posy == tiburoncin[i].limite_izquierdo)
				{
					tiburoncin[i].direccion = 101;//voltea a la derecha
				}
				if (tiburoncin[i].direccion == 101)
				{
					mueve_tibu_derecha(tiburon, tiburoncin[i].filas, tiburoncin[i].columnas, cantidad_tibu, tiburoncin, i);
				}
				if (tiburoncin[i].posy == tiburoncin[i].limite_derecho)
				{
					tiburoncin[i].direccion = 0;//voltea a la izquierda
				}
				if (tiburoncin[i].direccion == 0)
				{
					mueve_tibu_izquierda(tiburon, tiburoncin[i].filas, tiburoncin[i].columnas, cantidad_tibu, tiburoncin, i);
				}
			}
			//fin seccion tiburones
			//inicio seccion peces
			for (int i = 0; i < cantidad_pez; i++)
			{
				if (pescadito[i].perteneceflujo == true)
				{
					if (pescadito[i].verdadchoque == true)
					{
						mover_derecha = false;
						borra_matriz(pez, 7, 8, pescadito[i].posx, pescadito[i].posy);
						pescadito[i].posx = hilito.getx;
						if (pescadito[i].posy == pescadito[i].limite_izquierdo)
						{
							pescadito[i].direccion = 101;//voltea a la derecha
						}
						if (pescadito[i].direccion == 101)
						{
							mueve_pez_derecha(pez, pescadito[i].filas, pescadito[i].columnas, cantidad_pez, pescadito, i);
						}
						if (pescadito[i].posy == pescadito[i].limite_derecho)
						{
							pescadito[i].direccion = 0;//voltea a la izquierda
						}
						if (pescadito[i].direccion == 0)
						{
							mueve_pez_izquierda(pez, pescadito[i].filas, pescadito[i].columnas, cantidad_pez, pescadito, i);
						}
						if (pescadito[i].posx == 24 || pescadito[i].posx == 25)
						{
							mover_derecha = true;
							pescadito[i].perteneceflujo = false;
							borra_matriz(pez, 7, 8, pescadito[i].posx, pescadito[i].posy);
							permitir_choque = true;
							pescadito[i].verdadchoque = false;
							if (guardar_sector == 39 || guardar_sector == 47)
							{
								puntaje += 2;
							}
							if (guardar_sector == 55 || guardar_sector == 63)
							{
								puntaje += 4;
							}
							if (guardar_sector == 71 || guardar_sector == 79)
							{
								puntaje += 6;
							}
							pescadito[i].posx = sectores[v.Next(1, 6)];
							pescadito[i].posy = v.Next(20, 80);
							pescadito[i].limite_derecho = 97;
							pescadito[i].limite_izquierdo = 10;
							pescadito[i].perteneceflujo = true;
						}
						for (int k = 0; k < cantidad_tibu; k++)
						{
							if ((pescadito[i].posy + 8 >= tiburoncin[k].posy && pescadito[i].posy <= tiburoncin[k].posy + 14) && (pescadito[i].posx + 7 >= tiburoncin[k].posx && pescadito[i].posx <= tiburoncin[k].posx + 10))
							{
								mover_derecha = true;
								pescadito[i].perteneceflujo = false;
								borra_matriz(pez, 7, 8, pescadito[i].posx, pescadito[i].posy);
								permitir_choque = true;
								pescadito[i].verdadchoque = false;
								pescadito[i].posx = sectores[v.Next(1, 6)];
								pescadito[i].posy = v.Next(20, 80);
								pescadito[i].limite_derecho = 97;
								pescadito[i].limite_izquierdo = 10;
								pescadito[i].perteneceflujo = true;
							}
						}
					}
					else
					{
						if (pescadito[i].posy == pescadito[i].limite_izquierdo)
						{
							pescadito[i].direccion = 101;//voltea a la derecha
						}
						if (pescadito[i].direccion == 101)
						{
							mueve_pez_derecha(pez, pescadito[i].filas, pescadito[i].columnas, cantidad_pez, pescadito, i);
						}
						if (pescadito[i].posy == pescadito[i].limite_derecho)
						{
							pescadito[i].direccion = 0;//voltea a la izquierda
						}
						if (pescadito[i].direccion == 0)
						{
							mueve_pez_izquierda(pez, pescadito[i].filas, pescadito[i].columnas, cantidad_pez, pescadito, i);
						}
					}
				}

			}
			//fin seccion peces
			//inicio seccion hilo
			if (_kbhit())
			{
				tecla = _getch();
				if (tecla == abajo)
				{
					borra_matriz1(hilo, hilito.longitud, 1, hilito.posx, hilito.posy);
					hilito.longitud++;
					if (hilito.longitud > 68)
					{
						hilito.longitud = 68;
					}
					hilito.getx++;
					if (hilito.getx > 85)
					{
						hilito.getx = 85;
					}
					crea_matriz(hilo, hilito.longitud, 1);
					cargahilo(hilo, hilito.longitud, hilito.posx, hilito.posy);
					pinta_matriz(hilo, hilito.longitud, 1, hilito.posx, hilito.posy);
				}
				if (tecla == arriba)
				{
					borra_matriz1(hilo, hilito.longitud + 1, 1, hilito.posx, hilito.posy);
					hilito.longitud--;
					if (hilito.longitud < 1)
					{
						hilito.longitud = 1;
					}
					hilito.getx--;
					if (hilito.getx < 18)
					{
						hilito.getx = 18;
					}
					crea_matriz(hilo, hilito.longitud, 1);
					cargahilo(hilo, hilito.longitud, hilito.posx, hilito.posy);
					pinta_matriz(hilo, hilito.longitud, 1, hilito.posx, hilito.posy);
					for (int i = 0; i < 7; i++)
					{
						Console::ForegroundColor = ConsoleColor(cielito);
						posicion(i + 17, hilito.posy);
						cout << char(219);
					}
				}
				if (mover_derecha == true)
				{
					if (tecla == derecha)
					{
						borra_matriz1(caña, 1, cañita.longitud, cañita.posx, cañita.posy);
						borra_matriz1(hilo, hilito.longitud + 1, 1, hilito.posx, hilito.posy);
						if (hilito.posy == 104)
						{
							hilito.posy = 104;
						}
						else
						{
							hilito.posy++;
						}
						cañita.longitud++;
						if (cañita.longitud > 97)
						{
							cañita.longitud = 97;
						}
						crea_matriz(caña, 1, cañita.longitud);
						cargacaña(caña, cañita.longitud, cañita.posx, cañita.posy);
						cargahilo(hilo, hilito.longitud, hilito.posx, hilito.posy);
						pinta_matriz2(caña, 1, cañita.longitud, cañita.posx, cañita.posy);
						pinta_matriz(hilo, hilito.longitud, 1, hilito.posx, hilito.posy);
						for (int i = 0; i < 7; i++)
						{
							Console::ForegroundColor = ConsoleColor(cielito);
							posicion(i + 17, hilito.posy - 1);
							cout << char(219);
						}
					}
					if (tecla == izquierda)
					{
						borra_matriz1(caña, 1, cañita.longitud, cañita.posx, cañita.posy);
						borra_matriz1(hilo, hilito.longitud + 1, 1, hilito.posx, hilito.posy);
						hilito.posy--;
						if (hilito.posy < 11)
						{
							hilito.posy = 11;
						}
						cañita.longitud--;
						if (cañita.longitud < 3)
						{
							cañita.longitud = 3;
						}
						crea_matriz(caña, 1, cañita.longitud);
						cargacaña(caña, cañita.longitud, cañita.posx, cañita.posy);
						cargahilo(hilo, hilito.longitud, hilito.posx, hilito.posy);
						pinta_matriz2(caña, 1, cañita.longitud, cañita.posx, cañita.posy);
						pinta_matriz(hilo, hilito.longitud, 1, hilito.posx, hilito.posy);
						for (int i = 0; i < 7; i++)
						{
							Console::ForegroundColor = ConsoleColor(cielito);
							posicion(i + 17, hilito.posy + 1);
							cout << char(219);
						}
					}
				}
				if (tecla == espacio)
				{
					borra_matriz1(hilo, hilito.longitud + 2, 1, hilito.posx, hilito.posy);
					hilito.longitud -= 2;
					hilito.getx -= 2;
					crea_matriz(hilo, hilito.longitud, 1);
					cargahilo(hilo, hilito.longitud, hilito.posx, hilito.posy);
					pinta_matriz(hilo, hilito.longitud, 1, hilito.posx, hilito.posy);
					for (int i = 0; i < 7; i++)
					{
						Console::ForegroundColor = ConsoleColor(cielito);
						posicion(i + 17, hilito.posy);
						cout << char(219);
					}
				}
			}
			//fin seccion hilo
			//inicio seccion choques
			if (permitir_choque == true)
			{
				for (int i = 0; i < cantidad_pez; i++)
				{
					if ((pescadito[i].posy + 8 >= hilito.posy && pescadito[i].posy <= hilito.posy + 1) && (pescadito[i].posx + 7 >= hilito.getx && pescadito[i].posx <= hilito.getx))
					{
						guardar_sector = pescadito[i].posx;
						pescadito[i].verdadchoque = true;
						pescadito[i].limite_derecho = hilito.posy;
						if (pescadito[i].limite_derecho > 97)
						{
							pescadito[i].limite_derecho = 97;
						}
						pescadito[i].limite_izquierdo = hilito.posy - 7;
						if (pescadito[i].limite_izquierdo < 10)
						{
							pescadito[i].limite_izquierdo = 10;
						}
						permitir_choque = false;
					}
				}
			}
			//fin seccion choques
			pinta_matriz(hilo, hilito.longitud, 1, hilito.posx, hilito.posy);
			pinta_matriz2(caña, 1, cañita.longitud, cañita.posx, cañita.posy);
		} while (true);
		if (puntaje >= 300)
		{
			break;
		}
		if (vidas == 0)
		{
			break;
		}
	}
	libera_matriz(caña, 1);
	libera_matriz(hilo, hilito.longitud);
	libera_matriz1(pez, 7);
	libera_matriz1(tiburon, 10);
	system("CLS");
	if (vidas == 0)
	{
		looser();
	}
	else
	{
		win();
	}
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
	//PONER EL TAMAÑO DE FUENTE DE LA CONSOLA EN FUENTES DE MAPAS DE BITS 8X8
}