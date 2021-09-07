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

#include "DateConverter.h"

struct registro
{
	string fecha;
	string hora;
	char entrada;
	string ubi;
	int fechaInt;
	string ubiStr;
};

void printVector(vector<registro> vec)
{
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].fecha << " ";
		cout << vec[i].hora << " ";
		cout << vec[i].entrada << " ";
		cout << vec[i].ubi << " ";
		cout << vec[i].fechaInt << " ";
		cout << vec[i].ubiStr << "\n";
	}
	cout << "\n";
}

void sortByUbi(vector<registro> &data, int &numComp)
{
	for(int i = 0; i < data.size() - 1; i++)
	{
		for (int j = i + 1; j < data.size(); j++)
		{
			numComp++;
			if (data[i].ubiStr > data[j].ubiStr)
			{
				std::swap(data[i], data[j]);
			}
			else if (data[i].ubiStr == data[j].ubiStr)
			{
				if (data[i].fechaInt > data[j].fechaInt)
				{
					std::swap(data[i], data[j]);
				}
			}
		}
	}
}

string ubiToStart(string ubi)
{
	string ubiStart;
	for (int i = 0; i < 3; i++)
	{
		ubiStart += ubi[i];
	}
	return ubiStart;
}

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
