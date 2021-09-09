#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>

using namespace std;

struct record
{
	string fecha;
	string hora;
	char entrada;
	string ubi;
	int fechaInt;
	string ubiStr;
};

#include "DateConverter.h"
#include "Functions.h"

int main()
{
	// declaramos el struct de registro junto con un vector
	struct record dataSuez;
	vector<record> registroVec;

	// preguntamos por el nombre del archivo de texto
	string txtFile;
	cout << "Como se llama el archivo de texto? (ej. canal.txt): ";
	cin >> txtFile;

	// cargamos los datos
	loadData(dataSuez, registroVec, txtFile);

	// ordenamos datos dependiendo de los primeros tres caracteres del UBI
	// si es el mismo ubi, se ordena por fecha
	sort(registroVec.begin(), registroVec.end(), compare);

	// imprimimos el vector ordenado
	printVector(registroVec);

	// le pedimos al usuario que Ubi quiere ver y los imprimimos 
	selectUbi(registroVec);

	return 0;
}
