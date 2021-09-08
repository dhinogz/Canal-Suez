#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::ifstream;
using std::sort;

struct registro
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
	struct registro DataSuez;
	vector<registro> registroVec;
	int comparisons = 0;

	ifstream dataSuez("suez.txt");
	while(dataSuez >> DataSuez.fecha >> DataSuez.hora >> DataSuez.entrada >> DataSuez.ubi)
	{
		DataSuez.fechaInt = dateToInt(DataSuez.fecha);
		DataSuez.ubiStr = ubiToStart(DataSuez.ubi);
		registroVec.push_back(DataSuez);
	}
	dataSuez.close();

	//printVector(registroVec);

	sortByUbi(registroVec, comparisons);
	cout << "Number of comparisons: " << comparisons << "\n";
	cout << "Sorted vector\n";
	//printVector(registroVec);

	string ubiUsuario;
	cout << "Seleccionar un UBI: ";
	cin >> ubiUsuario;
	vector<registro> eleccion;
	for(int i = 0; i < registroVec.size(); i++)
	{
		if(registroVec[i].ubiStr == ubiUsuario)
		{
			eleccion.push_back(registroVec[i]);
		}
	}
	cout << "Ubi seleccionado: " << ubiUsuario << "\n";

	printVector(eleccion);

	return 0;
}
