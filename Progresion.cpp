/*
 *  Tema     : Divide y Venceras
 *  Problema : Examen Junio 2016 (final)
 *  Fecha    : 11/08/16
 *  Autor    : Daniel Sanchez Alvarez
 */

#include <iostream>

using namespace std;

// Funcion recursiva que identifica el elemento que falta en una progresion y devuelve su valor
int progresion(int v[], int d, int iz, int dr){
	int medio = (iz + dr) / 2;
	if (v[medio] + d != v[medio + 1])
		// Caso base
		return v[medio] + d;;
	if (v[medio] == v[0] + d*medio)
		// El elemento que falta esta a la derecha de medio
		return progresion(v, d, medio + 1, dr);
	else
		// El elemento que falta esta a la izquierda de medio
		return progresion(v, d, iz, medio - 1);
}

// Funcion que recibe un vector v, su tamaño n y una diferencia d
//    Devuelve el valor de la progresion de diferencia d almacenada en v que falta
int progresion (int v[], int n, int d){
	return progresion(v, d, 0, n - 1);
}

int main(){
	int v[] = { 2,4,8,10,12,14 };
	cout << progresion(v, 6, 2) << endl;

	int w[] = { 17,20,23,26,29,32,35,38,44,47 };
	cout << progresion(w, 10, 3) << endl;

	int u[] = { 200,250,300,400,450,500,550 };
	cout << progresion(u, 7, 50) << endl;

	return 0;
}
