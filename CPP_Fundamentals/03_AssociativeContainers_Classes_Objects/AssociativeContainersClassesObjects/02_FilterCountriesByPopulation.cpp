/*
* Write a program, make a Class Country.
* For given numbers the program should filter the countries by POPULATION
* only if the population is EQUAL to the country population.
*/
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Country
{
private:
	string name;	// Country name.
	string capital; // Capital name.
	int population; // In millions.

public:
	Country(string name, string capital, int population)
	{
		this->name = name;
		this->capital = capital;
		this->population = population;
	}

	int getPopulation() { return this->population; }

	string toString()
	{
		ostringstream outputStream;
		outputStream << this->name << " -> " << this->capital;

		return outputStream.str();
	}
};

typedef vector<Country> Countries;

Countries filterCountries(Countries countries, int population);
void printCountriesInfo(Countries countries);

void filterCountriesByPopulation()
{
	Countries countries;
	int countriesCount;
	cout << "How many countries you want to input?" << endl;
	cin >> countriesCount;

	while (countriesCount--)
	{
		// Takes country, capital and population from input until countryCount gets to 0.
		string countryName, capitalName;
		int countryPopulation;

		cout << "Enter Country -> ";
		cin >> countryName;
		cout << "Enter Capital -> ";
		cin >> capitalName;
		cout << "Enter Population -> ";
		cin >> countryPopulation;

		// Creates country and adds it to the countries vector.
		Country country = Country(countryName, capitalName, countryPopulation);
		countries.push_back(country);
	}

	int population;
	cout << "Which is the population (millions) that you want to filter?" << endl;
	cin >> population;

	countries = filterCountries(countries, population);

	cout << "The countries with population " << population << " millions are: " << endl;
	printCountriesInfo(countries);
}

// Returns vector of all countries with equal given population.
Countries filterCountries(Countries countries, int population)
{
	Countries filteredCountries;

	for (Country currentCountry : countries)
	{
		if (currentCountry.getPopulation() == population)
		{
			filteredCountries.push_back(currentCountry);
		}
	}

	return filteredCountries;
}

// Prints all countries toString().
void printCountriesInfo(Countries countries)
{
	for (Country currentCountry : countries)
	{
		cout << currentCountry.toString() << endl;
	}
}