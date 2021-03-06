// imrime el vector del tipo de dato record O(n)
void printVector(vector<record> vec, int start, int finish)
{
	for(int i = start; i < finish; i++)
	{
		cout << vec[i].fecha << " ";
		cout << vec[i].hora << " ";
		cout << vec[i].entrada << " ";
		cout << vec[i].ubi << "\n";
	}
	cout << "\n";
}

// cargar datos de un archivo texto y guardar en un vector de la estructura record 
// complejidad: O(n)
void loadData(record &dataLoaded, vector<record> &vec, string txtFile)
{
	ifstream dataSuez(txtFile);
	while(dataSuez >> dataLoaded.fecha >> dataLoaded.hora >> dataLoaded.entrada >> dataLoaded.ubi)
	{
		vec.push_back(dataLoaded);
	}
	dataSuez.close();
}

// string a mayuscula se usa al pedir la entrada del ubi del usuario 
// complejidad: O(n)
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
    if (lhs.ubi == rhs.ubi)
	{
        return dateToInt(lhs.fecha) < dateToInt(rhs.fecha);
    }
    return (lhs.ubi.compare(rhs.ubi) < 0);
}

// toma el ubi del usuario como parametro para luego desplegar todas las opciones
void selectUbi(vector<record> vec, string ubiSelect)
{
	str_toupper(ubiSelect);
	vector<string> ubiVec;
	for (int i = 0; i < vec.size(); i++)
	{
		ubiVec.push_back(vec[i].ubi.substr(0, 3));
	}
	// O(log n) + 1 
	vector<string>::iterator low = lower_bound(ubiVec.begin(), ubiVec.end(), ubiSelect); 
	vector<string>::iterator up = upper_bound(ubiVec.begin(), ubiVec.end(), ubiSelect); 
	int pos = low - ubiVec.begin();
	if(ubiVec[pos] == ubiSelect)
	{
		cout << "Se encontro \n";
	}
	else
	{
		cout << "No se encontro\n";
	}

	int lower = (low - ubiVec.begin());
	int upper = (up - ubiVec.begin());

	cout << "UBI seleccionado: " << ubiSelect << "\n";
	printVector(vec, lower, upper);
}