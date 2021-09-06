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

int monthToInt(string month)
{
	if (month == "jan")
	{
		return 1;
	}
	else if (month == "feb")
	{
		return 2;
	}
	else if (month == "mar")
	{
		return 3;
	}
	else if (month == "apr")
	{
		return 4;
	}
	else if (month == "may")
	{
		return 5;
	}
	else if (month == "jun")
	{
		return 6;
	}
	else if (month == "jul")
	{
		return 7;
	}
	else if (month == "aug")
	{
		return 8;
	}
	else if (month == "sep")
	{
		return 9;
	}
	else if (month == "oct")
	{
		return 10;
	}
	else if (month == "nov")
	{
		return 11;
	}
	return 12;
}

int dateToInt(string date)
{
	int salida = 0;
	int temp = 0;
	int i = 0;
	while(date[i] != '-')
	{
		temp *= 10;
		temp += (date[i] - '0');
		i++;
	}
	salida += temp;
	i++;

	string month;
	while (date[i] != '-')
	{
		month += date[i];
		i++;
	}
	salida += monthToInt(month) * 100;
	i++;

	temp = 0;
	while(i < date.length())
	{
		temp *= 10;
		temp += (date[i] - '0');
		i++;
	}
	salida += (temp * 10000);
	return salida;

}

struct registro
{
	string fecha;
	string hora;
	char entrada;
	string ubi;
	int fechaInt;
	int ubiInt;
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
		cout << vec[i].ubiInt << "\n";
	}
	cout << "\n";
}

void whereIsSameDate(vector<registro> Data)
{
	for(int i = 0; i < Data.size() - 1; i++)
	{
		for (int j = i + 1; j < Data.size(); j++)
		{
			if (Data[i].ubi == Data[j].ubi)
			{
				cout << i << " " << j << "\n";
			}
		}
	}
}

void sortByUbi(vector<registro> &Data, int &numComp)
{
	for(int i = 0; i < Data.size() - 1; i++)
	{
		for (int j = i + 1; j < Data.size(); j++)
		{
			numComp++;
			if (Data[i].ubi > Data[j].ubi)
			{
				std::swap(Data[i], Data[j]);
			}
			else if (Data[i].ubi == Data[j].ubi)
			{
				if (Data[i].fechaInt > Data[j].fechaInt)
				{
					std::swap(Data[i], Data[j]);
				}
			}
		}
	}
}


int ubiToInt(string ubi)
{
	string ubiLast = " ";
	int result = 0;
	for (int i = 3; i < ubi.length(); i++)
	{
		cout << ubi[i] << " ";
		ubiLast += ubi[i];
	}
	cout << "\n";
	result += ubiLast[0] * 10;
	result += ubiLast[1];
	cout << result << "\n";
	return result;
}

int main()
{
	struct registro DataSuez;
	vector<registro> mivec;
	int comparisons = 0;

	ifstream dataSuez("suez1.txt");
	while(dataSuez >> DataSuez.fecha >> DataSuez.hora >> DataSuez.entrada >> DataSuez.ubi)
	{
		DataSuez.fechaInt = dateToInt(DataSuez.fecha);
		DataSuez.ubiInt = ubiToInt(DataSuez.ubi);
		mivec.push_back(DataSuez);
	}
	dataSuez.close();

	printVector(mivec);

	sortByUbi(mivec, comparisons);
	cout << "Number of comparisons: " << comparisons << "\n";
	cout << "Sorted vector\n";
	printVector(mivec);

	return 0;
}
