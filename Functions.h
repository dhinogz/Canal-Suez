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

string ubiToStart(string ubi)
{
	string ubiStart;
	for (int i = 0; i < 3; i++)
	{
		ubiStart += ubi[i];
	}
	return ubiStart;
}

void str_toupper(string &s) 
{
    transform(
		s.begin(), s.end(), s.begin(), 
		[](unsigned char c){ return std::toupper(c); }
	);
}

bool compare(record lhs, record rhs)
{
    if (lhs.ubiStr == rhs.ubiStr){
        return lhs.fechaInt < rhs.fechaInt;
    }
    return (lhs.ubi.compare(rhs.ubi) < 0);
}

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

void loadData(record &DataLoaded, vector<record> &vec)
{
	ifstream dataSuez("suez.txt");
	while(dataSuez >> DataLoaded.fecha >> DataLoaded.hora >> DataLoaded.entrada >> DataLoaded.ubi)
	{
		DataLoaded.fechaInt = dateToInt(DataLoaded.fecha);
		DataLoaded.ubiStr = ubiToStart(DataLoaded.ubi);
		vec.push_back(DataLoaded);
	}
	dataSuez.close();
}