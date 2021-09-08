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

void str_toupper(std::string &s) 
{
    std::transform(
		s.begin(), s.end(), s.begin(), 
		[](unsigned char c){ return std::toupper(c); }
	);
}