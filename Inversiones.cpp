/*
 *  Tema     : Divide y Venceras
 *  Problema : Examen Junio 2013
 *  Fecha    : 11/08/16
 *  Autor    : Daniel Sanchez Alvarez
 */

#include <iostream>

using namespace std;

// Ordena los valores de v entre iz y dr
// Para ello mezcla las dos trozos del vector que ya estan ordenadas, siendo
//    dichas trozos iz a m y m + 1 a dr
// Devuelve cuantas inversiones habia en v entre iz y dr
int merge(int v[], int iz, int m, int dr) {
	int *u = new int[dr - iz + 1];
	int i, j, k;
	int inversiones = 0;

	// copio v a u
	for (k = iz; k <= dr; k++)
		u[k - iz] = v[k]; // - iz por el desplazamiento

	// Copio u en v, recorriendo las dos mitades de u (que ya estan ordenadas)
	//    y copiando en orden creciente
	// i recorre primera mitad y j la segunda. k recorre v
	i = 0; j = m - iz + 1; k = iz; // Inicializción para el bucle
	while ((i <= m - iz) && (j <= dr - iz)) {
		if (u[i] <= u[j]) {
			// El elemento de la primera mitad es menor o igual la copio en v y avanzo su indice
			v[k] = u[i];
			i++;
		}
		else {
			// El elemento de la segunda mitad es menor, la copio en v y avanzo su indice
			// Ademas contabilizo una inversion por todos los elementos que me
			//    quedaban por recorrer en la primera mitad, ya que todos son
			//    mayores que el valor que estoy colocando en v.
			v[k] = u[j];
			j++;
			inversiones += (m - iz + 1 - i);
		}
		k++; // El indice de v avanza siempre
	}

	// Copio los valores que se han quedado sin copiar de una de las dos mitades
	// Solo uno de estos dos bucles se ejecuta en funcion del cual no haya acabado
	while (i <= m - iz) {
		v[k] = u[i];
		i++;
		k++;
	}

	while (j <= dr - iz) {
		v[k] = u[j];
		j++;
		k++;
	}

	delete[] u; // Libero memoria
	return inversiones;
}

// Funcion recursiva que ordena v entre iz y dr y devuelve el numero de inversiones
//    que ha realizado para ordenarlo.
int mergeSort(int v[], int iz, int dr) {
	int inversiones = 0;
	if (iz < dr) {
		// Caso general, en el caso base (iz = dr) no hace nada y devuelve 0
		int m = (iz + dr) / 2;
		inversiones =  mergeSort(v, iz, m);  // Mitad izquierda
		inversiones += mergeSort(v, m + 1, dr); // Mitad derecha
		inversiones += merge(v, iz, m, dr); // Mezclo las mitades
	}
	return inversiones;
}

int main() {
	int v[] = { 1, 20, 6, 4, 5 };
	cout << mergeSort(v, 0, 4) << endl;

	int w[] = { 6, 9, 1, 14, 8, 12, 3, 2 };
	cout << mergeSort(w, 0, 7) << endl;

	return 0;
}
