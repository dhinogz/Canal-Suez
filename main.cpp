#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::ifstream;

struct registro
{
	string fecha;
	string hora;
	char entrada;
	int fechaInt;
};

int main()
{
	struct registro DataSuez;
	/*
	ifstream dataSuez("suze.txt");
	while(dataSuez >> DataSuez.fecha >> DataSuez.hora >> DataSuez.entrada)
	{
		cout << "Tomando registro\n";
	}
	dataSuez.close();
	*/
	return 0;

}