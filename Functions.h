// imrime el vector del tipo de dato record
void printVector(vector<record> vec)
{
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].fecha << " ";
		cout << vec[i].hora << " ";
		cout << vec[i].entrada << " ";
		cout << vec[i].ubi << "\n";
	}
	cout << "\n";
}

// cargar datos de un archivo texto y guardar en un vector de la estructura record
void loadData(record &dataLoaded, vector<record> &vec, string txtFile)
{
	ifstream dataSuez(txtFile);
	while(dataSuez >> dataLoaded.fecha >> dataLoaded.hora >> dataLoaded.entrada >> dataLoaded.ubi)
	{
		dataLoaded.fechaInt = dateToInt(dataLoaded.fecha);
		dataLoaded.ubiStr = dataLoaded.ubi.substr(0, 3);
		vec.push_back(dataLoaded);
	}
	dataSuez.close();
}

// string a mayuscula se usa al pedir la entrada del ubi del usuario
void str_toupper(string &s) 
{
    transform(
		s.begin(), s.end(), s.begin(), 
		[](unsigned char c){ return toupper(c); }
	);
}

// condicion de ordenamiento
bool compare(record lhs, record rhs)
{
    if (lhs.ubiStr == rhs.ubiStr){
        return lhs.fechaInt < rhs.fechaInt;
    }
    return (lhs.ubi.compare(rhs.ubi) < 0);
}

// le pide al usuario un ubi para luego desplegar todas las opciones
void selectUbiBin(vector<record> vec, string ubiSelect)
{
	str_toupper(ubiSelect);
	vector<string> ubiStr;
	for (int i = 0; i < vec.size(); i++)
	{
		ubiStr.push_back(vec[i].ubiStr);
	}
	vector<string>::iterator low = lower_bound(ubiStr.begin(), ubiStr.end(), ubiSelect); 
	vector<string>::iterator up = upper_bound(ubiStr.begin(), ubiStr.end(), ubiSelect); 
	int pos = low - ubiStr.begin();
	if(ubiStr[pos].substr(0, 3) == ubiSelect)
	{
		cout << "Se encontro \n";
	}
	else
	{
		cout << "No se encontro\n";
	}

	int lower = (low - ubiStr.begin());
	int upper = (up - ubiStr.begin());

	cout << "UBI seleccionado: " << ubiSelect << "\n";
	for (int i = lower; i < upper; i++)
	{
		cout << vec[i].fecha << " ";
		cout << vec[i].hora << " ";
		cout << vec[i].entrada << " ";
		cout << vec[i].ubi << "\n";
	}
	cout << "\n";
}