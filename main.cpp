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
	vector<record> recordVec;

	// preguntamos por el nombre del archivo de texto
	string txtFile;
	cout << "Como se llama el archivo de texto? (ej. canal.txt): ";
	cin >> txtFile;

	// cargamos los datos
	loadData(dataSuez, recordVec, txtFile);

	// ordenamos datos dependiendo de los primeros tres caracteres del UBI
	// si es el mismo ubi, se ordena por fecha
	sort(recordVec.begin(), recordVec.end(), compare);

	// imprimimos el vector ordenado
	printVector(recordVec);

	// le pedimos al usuario que Ubi quiere ver y los imprimimos 
	string ubiUsuario;
	cout << "Seleccionar un UBI: ";
	cin >> ubiUsuario;
	selectUbi(recordVec, ubiUsuario);

	return 0;
}
