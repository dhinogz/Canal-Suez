#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::ifstream;
using std::sort;
using std::toupper;
using std::transform;

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

	// cargamos los datos
	loadData(dataSuez, registroVec);

	// ordenamos datos dependiendo de los primeros tres caracteres del UBI
	// si es el mismo ubi, se ordena por fecha
	sort(registroVec.begin(), registroVec.end(), compare);

	// imprimimos el vector ordenado
	printVector(registroVec);

	// le pedimos al usuario que Ubi quiere ver y los imprimimos 
	selectUbi(registroVec);

	return 0;
}
