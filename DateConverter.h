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