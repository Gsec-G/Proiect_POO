#pragma once
#include<iostream>
#include<string>
using namespace std;
class Locatie
{
private:

	string nume_locatie;
	string adresa;
	int nr_locuri_parcare;
	int nr_locuri_VIP;
	int capacitate_maxima_spectatori;
	bool locatie_in_aer_liber;

public:

	Locatie()
	{
		this->nume_locatie = "";
		this->adresa = "";
		this->nr_locuri_parcare = 0;
		this->nr_locuri_VIP = 0;
		this->capacitate_maxima_spectatori = 0;
		this->locatie_in_aer_liber = false;

	}
	Locatie(string nume_locatie, string adresa , int nr_locuri_parcare, int nr_locuriVIP, int capacitate_maxima_spectatori,bool locatie_in_aer_liber)
	{
		this->nume_locatie = nume_locatie;
		this->adresa = adresa;
		if (nr_locuri_parcare > nr_locuri_VIP && nr_locuri_parcare >= 0)
			this->nr_locuri_parcare = nr_locuri_parcare;
		else
			this->nr_locuri_parcare = 0;
		if (nr_locuriVIP < nr_locuri_parcare && nr_locuriVIP >= 0)
			this->nr_locuri_VIP = nr_locuriVIP;
		else
			this->nr_locuri_VIP = 0;
		if (capacitate_maxima_spectatori > 0 && capacitate_maxima_spectatori >= this->nr_locuri_VIP)
			this->capacitate_maxima_spectatori = capacitate_maxima_spectatori;
		else
			this->capacitate_maxima_spectatori = 0;
		this->locatie_in_aer_liber = locatie_in_aer_liber;
	}
	Locatie(const Locatie& copie)
	{
		this->nume_locatie = copie.nume_locatie;
		this->adresa = copie.adresa;
		this->nr_locuri_parcare = copie.nr_locuri_parcare;
		this->nr_locuri_VIP = copie.nr_locuri_VIP;
		this->capacitate_maxima_spectatori = copie.capacitate_maxima_spectatori;
		this->locatie_in_aer_liber = copie.locatie_in_aer_liber;
	}
	~Locatie() {}

	string getAdresa() { return this->adresa; }
	string getNume_locatie() { return this->nume_locatie; }
	int getNr_locuri_parcare() { return this->nr_locuri_parcare; }
	int getNr_locuri_VIP() { return this->nr_locuri_VIP; }
	int getCapacitate_maxima_spectatori() { return this->capacitate_maxima_spectatori; }
	bool getLocatie_in_aer_liber() { return locatie_in_aer_liber; }

	void setAdresa(string adresa) { this->adresa = adresa; }
	void setNume_locatie(string nume_locatie) { this->nume_locatie = nume_locatie; }
	void setNr_locuri_parcare(int nr)
	{
		if (nr >= 0)
			this->nr_locuri_parcare = nr;
	}
	void setNr_locuri_VIP(int nr_vip)
	{
		if (nr_vip < this->capacitate_maxima_spectatori && nr_vip >= 0)
			this->nr_locuri_VIP = nr_vip;
	}
	void setCapacitate_maxima_spectatori(int capacitate)
	{
		if (capacitate > 0 && capacitate >= this->nr_locuri_VIP)
			this->capacitate_maxima_spectatori = capacitate;
	}
	void setLocatie_in_aer_liber(bool locatie) { this->locatie_in_aer_liber = locatie; }

	int Capacitate_locatie_NonVIP() { return (this->capacitate_maxima_spectatori - this->nr_locuri_VIP); }

	void Adauga_locuri_aer_liber(int nr_incrementare_locuri_parcare)
	{
		if (this->locatie_in_aer_liber == true)
			this->nr_locuri_parcare += nr_incrementare_locuri_parcare; 
	}
	Locatie& operator=(Locatie copie)
	{
		if (this == &copie)return *this;
		if (copie.nr_locuri_parcare >= 0)
			this->nr_locuri_parcare = copie.nr_locuri_parcare;
		else this->nr_locuri_parcare = 0;
		this->nume_locatie = copie.nume_locatie;
		this->adresa = copie.adresa;
		this->nr_locuri_VIP = copie.nr_locuri_VIP;
		this->locatie_in_aer_liber = copie.locatie_in_aer_liber;
		this->capacitate_maxima_spectatori = copie.capacitate_maxima_spectatori;
		return *this;
	}
	friend istream& operator>>(istream& in, Locatie& copie)
	{
		cout << "Nume Locatie: ";
		in >> copie.nume_locatie;

		cout << "Adresa: ";
		in >> copie.adresa;

		cout << "Numar Locuri Parcare: ";
		in >> copie.nr_locuri_parcare;

		while (copie.nr_locuri_parcare < 0)
		{
			cout << "Numar Locuri Parcare: ";
			in >> copie.nr_locuri_parcare;
		}

		cout << "Capacitate maxima locatie: ";
		in >> copie.capacitate_maxima_spectatori;
		cout << "Numar Locuri VIP: ";
		in >> copie.nr_locuri_VIP;
		while (copie.capacitate_maxima_spectatori < copie.nr_locuri_VIP || copie.capacitate_maxima_spectatori < 0)
		{
			cout << "Capacitate maxima locatie: ";
			in >> copie.capacitate_maxima_spectatori;
			cout << "Numar Locuri VIP: ";
			in >> copie.nr_locuri_VIP;
		}
		cout << "Locatie in aer liber( 0 - NU , 1 - DA ): ";
		in >> copie.locatie_in_aer_liber;
		while (copie.locatie_in_aer_liber != 0 && copie.locatie_in_aer_liber != 1)
		{
			cout << "Locatie in aer liber( 0 - NU , 1 - DA ): ";
			in >> copie.locatie_in_aer_liber;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, Locatie copie)
	{
		out << "Nume locatie: " << copie.nume_locatie << endl;
		out << "Adresa locatie: " << copie.adresa << endl;
		out << "Numar locuri parcare: " << copie.nr_locuri_parcare << endl;
		out << "Capacitate maxima spectatori: " << copie.capacitate_maxima_spectatori << endl;
		out << "Numar locuri VIP: " << copie.nr_locuri_VIP << endl;
		if (copie.locatie_in_aer_liber == true)
			out << "Locatia este in aer liber." << endl;
		else
			out << "Locatie nu este in aer liber." << endl;
		out << endl;
		return out;
	}
	bool operator!()
	{
		if (this->capacitate_maxima_spectatori > 0)
			return true;
		return false;
	}
	operator int()
	{
		return capacitate_maxima_spectatori;
	}
};


