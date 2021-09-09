string inputTxtFile()
{
	string txtFile;
	cin >> txtFile;
	return txtFile;
}

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

// regresa un string con los primeros tres caracteres del ubi
string ubiToStart(string ubi)
{
	string ubiStart;
	for (int i = 0; i < 3; i++)
	{
		ubiStart += ubi[i];
	}
	return ubiStart;
}

// cargar datos de un archivo texto y guardar en un vector de la estructura record
void loadData(record &dataLoaded, vector<record> &vec, string txtFile)
{
	ifstream dataSuez(txtFile);
	while(dataSuez >> dataLoaded.fecha >> dataLoaded.hora >> dataLoaded.entrada >> dataLoaded.ubi)
	{
		dataLoaded.fechaInt = dateToInt(dataLoaded.fecha);
		dataLoaded.ubiStr = ubiToStart(dataLoaded.ubi);
		vec.push_back(dataLoaded);
	}
	dataSuez.close();
}

// string a mayuscula se usa al pedir la entrada del ubi del usuario
void str_toupper(string &s) 
{
    transform(
		s.begin(), s.end(), s.begin(), 
		[](unsigned char c){ return std::toupper(c); }
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
void selectUbi(vector<record> vec)
{
	string ubiUsuario;
	cout << "Seleccionar un UBI: ";
	cin >> ubiUsuario;
	str_toupper(ubiUsuario);
	vector<record> eleccion;
	for(int i = 0; i < vec.size(); i++)
	{
		if(vec[i].ubiStr == ubiUsuario)
		{
			eleccion.push_back(vec[i]);
		}
	}
	cout << "Ubi seleccionado: " << ubiUsuario << "\n";
	printVector(eleccion);
}
