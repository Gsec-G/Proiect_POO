#pragma once
#include<iostream>
#include<string>
#include "Locatie.h"
#include "Bilet.h"

class Eveniment
{
private:

	Locatie locatie;
	Bilet* bilet;
	int numar_vector_bilete;
	char* nume_eveniment;
	int ora_eveniment;
	int minut_eveniment;
	int* data_eveniment;

public:

	Eveniment()
	{
		
		this->nume_eveniment = new char[1];
		strcpy_s(this->nume_eveniment, 1, "");
		this->ora_eveniment = 0;
		this->minut_eveniment = 0;
		this->data_eveniment = nullptr;
		this->bilet = nullptr;
		this->locatie = Locatie();
		this->numar_vector_bilete = 0;
	}
	Eveniment(char* nume_eveniment, int ora_eveniment,int minut_eveniment, int* data_eveniment,Bilet* bilet,int numar_vector_bilete, Locatie locatie)
	{
		if (bilet != nullptr && numar_vector_bilete >= 0)
		{
			this->bilet = bilet;
			this->numar_vector_bilete = numar_vector_bilete;
		}
		else
		{
			this->bilet = nullptr;
			this->numar_vector_bilete = 0;
		}
		this->locatie = locatie;
		if (nume_eveniment != nullptr)
		{
			this->nume_eveniment = new char[strlen(nume_eveniment) + 1];
			strcpy_s(this->nume_eveniment, strlen(nume_eveniment) + 1, nume_eveniment);
		}
		else
		{
			this->nume_eveniment = new char[1];
			strcpy_s(this->nume_eveniment, 1, "");
		}
		if (ora_eveniment <= 24 && ora_eveniment >= 0 && minut_eveniment >= 0 && minut_eveniment <= 60)
		{
			this->ora_eveniment = ora_eveniment;
			this->minut_eveniment = minut_eveniment;
		}
		else
		{
			this->ora_eveniment = 0;
			this->minut_eveniment = 0;
		}
		if (data_eveniment != nullptr)
		{
			delete[] this->data_eveniment;
			this->data_eveniment = new int[3];
			if (data_eveniment[0] <= 31 && data_eveniment[0] >= 0)
				this->data_eveniment[0] = data_eveniment[0];
			if (data_eveniment[1] <= 12 && data_eveniment[1] >= 0)
				this->data_eveniment[1] = data_eveniment[1];
			if (data_eveniment[2] >= 2022)
				this->data_eveniment[2] = data_eveniment[2];
		}
		else this->data_eveniment = nullptr;

	}
	~Eveniment()
	{
		delete[] this->nume_eveniment;
		this->nume_eveniment = nullptr;
		delete[] this->data_eveniment;
		this->data_eveniment = nullptr;
		delete[] this->bilet;
		this->bilet = nullptr;
	}
	Eveniment(const Eveniment& copie)
	{
		this->nume_eveniment = new char[strlen(copie.nume_eveniment) + 1];
		strcpy_s(this->nume_eveniment, strlen(copie.nume_eveniment) + 1, copie.nume_eveniment);
		this->ora_eveniment = copie.ora_eveniment;
		this->minut_eveniment = copie.minut_eveniment;
		if (copie.data_eveniment != nullptr)
		{
			this->data_eveniment = new int[3];
			this->data_eveniment[0] = copie.data_eveniment[0];
			this->data_eveniment[1] = copie.data_eveniment[1];
			this->data_eveniment[2] = copie.data_eveniment[2];
		}
		else this->data_eveniment = nullptr;
		this->bilet = new Bilet[copie.numar_vector_bilete];
		for (int i = 0; i < copie.numar_vector_bilete; i++)
			this->bilet = copie.bilet;
		this->numar_vector_bilete = copie.numar_vector_bilete;
	}

	char* getNume_eveniment()
	{
		char* copie = new char[strlen(this->nume_eveniment) + 1];
		strcpy_s(copie, strlen(this->nume_eveniment) + 1, this->nume_eveniment);
		return copie; 
	}
	int getOra_eveniment() { return this->ora_eveniment; }
	int getMinut_eveniment() { return this->minut_eveniment; }
	int* getData_eveniment()
	{
		if(this->data_eveniment != nullptr)
		{ 
			int* copie = new int[3];
			copie[0] = this->data_eveniment[0];
			copie[1] = this->data_eveniment[1];
			copie[2] = this->data_eveniment[2];
			return copie;
		}
		else
		return nullptr;
	}
	Locatie getLocatie() { return this->locatie; }
	Bilet* getBilet() 
	{
		Bilet* copie = new Bilet[numar_vector_bilete];
		for (int i = 0; i < this->numar_vector_bilete; i++)
			copie[i] = this->bilet[i];
			return copie; 
	}
	int getNumar_vector_bilete() { return this->numar_vector_bilete; }

	void setLocatie(Locatie locatie)
	{
		this->locatie = locatie;
	}
	void setBilet_si_numar_vector_bilete(Bilet* bilet,int numar_vector_bilete)
	{
		if (bilet != nullptr && numar_vector_bilete > 0)
		{
			if (this->bilet != nullptr)
			{
				delete[] this->bilet;
				this->bilet = nullptr;
			}
			this->bilet = new Bilet[numar_vector_bilete];
			for (int i = 0; i < numar_vector_bilete; i++)
				this->bilet[i] = bilet[i];
			this->numar_vector_bilete = numar_vector_bilete;
		}
	}
	void setNume_Eveniment(const char* nume_eveniment)
	{
		if (nume_eveniment != nullptr)
		{
			if (this->nume_eveniment != nullptr)
			{
				delete[] this->nume_eveniment;
				this->nume_eveniment = nullptr;
			}
			this->nume_eveniment = new char[strlen(nume_eveniment) + 1];
			strcpy_s(this->nume_eveniment, strlen(nume_eveniment) + 1, nume_eveniment);
		}
	}
	void setOra_eveniment(int ora_eveniment)
	{
		this->ora_eveniment = ora_eveniment;

	}
	void setMinut_evenment(int minut_eveniment)
	{
		this->minut_eveniment = minut_eveniment;
	}
	void setData_eveniment(int* data_eveniment)
	{
		if (data_eveniment != nullptr)
		{
			if (this->data_eveniment != nullptr)
			{
				delete[] this->data_eveniment;
				this->data_eveniment = nullptr;
			}
			this->data_eveniment = new int[3];
			this->data_eveniment[0] = data_eveniment[0];
			this->data_eveniment[1] = data_eveniment[1];
			this->data_eveniment[2] = data_eveniment[2];
		}
	}
	Eveniment& operator=(Eveniment copie)
	{
			if (this == &copie)return *this;
			if (copie.bilet != nullptr && copie.numar_vector_bilete > 0)
			{
				if (this->bilet != nullptr)
				{
					delete[] this->bilet;
					this->bilet = nullptr;
				}
				this->bilet = new Bilet[copie.numar_vector_bilete];
				for (int i = 0; i < copie.numar_vector_bilete; i++)
					this->bilet[i] = bilet[i];
				this->numar_vector_bilete = copie.numar_vector_bilete;
			}
			this->locatie = locatie;
			if (this->nume_eveniment)
			{
				delete[] this->nume_eveniment;
				this->nume_eveniment = nullptr; 
			}
			this->nume_eveniment = new char[strlen(copie.nume_eveniment) + 1];
			strcpy_s(this->nume_eveniment, strlen(copie.nume_eveniment) + 1, copie.nume_eveniment);
			this->ora_eveniment = copie.ora_eveniment;
			this->minut_eveniment = copie.minut_eveniment;

			if (this->data_eveniment)
			{
				delete[] this->data_eveniment;
				this->data_eveniment = nullptr;
			}
			if (copie.data_eveniment != nullptr)
			{
				this->data_eveniment = new int[3];
				this->data_eveniment[0] = copie.data_eveniment[0];
				this->data_eveniment[1] = copie.data_eveniment[1];
				this->data_eveniment[2] = copie.data_eveniment[2];
			}
			else this->data_eveniment = nullptr;
		return *this;
	}
	void schimba_data_si_ora(int* data_eveniment, int ora_eveniment, int minut_eveniment)
	{
		if (data_eveniment != nullptr)
		{
			if (this->data_eveniment)
			{
				delete[] this->data_eveniment;
				this->data_eveniment = nullptr;
			}
			this->data_eveniment = new int[3];
			this->data_eveniment[0] = data_eveniment[0];
		    this->data_eveniment[1] = data_eveniment[1];
			this->data_eveniment[2] = data_eveniment[2];
		}
		this->ora_eveniment = ora_eveniment;
		this->minut_eveniment = minut_eveniment;
	}

	int Nr_incasari_peste_5000(Eveniment* eveniment, int nr_eveniment)
	{
		if (eveniment != nullptr && nr_eveniment > 0)
		{
			int nr = 0;
			for(int i = 0 ; i < nr_eveniment ; i++ )
			{
				int numar_vector = 0;
				numar_vector = eveniment[i].getNumar_vector_bilete(); 
				Bilet* bilet = new Bilet[numar_vector];
				bilet = eveniment->getBilet();

				for (int j = 0; j < numar_vector; j++)
				{
					if (bilet[j].Suma_incasarilor_vector_bilete(bilet, numar_vector) > 5000)
						nr++;
				}
				delete[] bilet;
					
			}
			return nr;
		}
	}
	friend istream& operator>>(istream& in, Eveniment& copie) 
	{
		cout << "Nume eveniment: ";
		string buffer;
		in >> ws;
		getline(in, buffer);
		if (copie.nume_eveniment != nullptr)
			delete[] copie.nume_eveniment;
		copie.nume_eveniment = new char[buffer.length() + 1];
		strcpy_s(copie.nume_eveniment, buffer.length() + 1, buffer.c_str());

		cout  << "Ora eveniment( 0-24 ): ";
		in >> copie.ora_eveniment;
		while(copie.ora_eveniment > 24 || copie.ora_eveniment < 0)
		{
			cout << "Ora eveniment( 0-24 ): ";
			in >> copie.ora_eveniment;
		}
		cout << "Minut Eveniment( 0-60 ): ";
		in >> copie.minut_eveniment;
		while (copie.minut_eveniment > 60 || copie.minut_eveniment < 0)
		{
			cout << "Minut Eveniment( 0-60 ): ";
			in >> copie.minut_eveniment;
		}

		if (copie.data_eveniment == nullptr)
			copie.data_eveniment = new int[3];
		cout << "Introduceti ziua evenimentului( 1-31 ): ";
		in >> copie.data_eveniment[0];
		while (copie.data_eveniment[0] > 31 || copie.data_eveniment[0] < 1)
		{
			cout << "Introduceti ziua evenimentului( 1-31 ): ";
			in >> copie.data_eveniment[0];
		}
		cout << "Introduceti luna evenimentului( 1-12 ): ";
		in >> copie.data_eveniment[1];
		while (copie.data_eveniment[1] > 12 || copie.data_eveniment[0] < 1)
		{
			cout << "Introduceti luna evenimentului( 1-12 ): ";
			in >> copie.data_eveniment[1];
		}
		cout << "Introduceti anul evenimentului( 2022+ ): ";
		in >> copie.data_eveniment[2];
		while (copie.data_eveniment[2] < 2022)
		{
			cout << "Introduceti anul evenimentului( 2022+ ): ";
			in >> copie.data_eveniment[2];
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, Eveniment copie)
	{
		if (copie.locatie.getCapacitate_maxima_spectatori() != 0)
			out << endl << "Locatia: " << endl << copie.locatie << endl;
		else
			out << endl << "Locatia nu este disponibila." << endl;

		if (copie.numar_vector_bilete > 0 && copie.bilet != nullptr)
		{
			out << "Numar bilete: " << copie.numar_vector_bilete << endl << endl;
			for (int i = 0; i < copie.numar_vector_bilete; i++)
				out << "Biletul " << i << ":" << endl << copie.bilet[i] << endl;
		}
		else
			out << "Biletele nu sunt disponibile." << endl;
		if (copie.nume_eveniment != nullptr)
			out <<"Nume eveniment: " <<  copie.nume_eveniment << endl;
		out << "Ora eveniment: " << copie.ora_eveniment << ":" << copie.minut_eveniment << endl;
		if (copie.data_eveniment != nullptr)
		{
			out << "Data eveniment: " << copie.data_eveniment[0] << " - " << copie.data_eveniment[1] << " - " << copie.data_eveniment[2] << endl;
		}
		return out;
	}
	int operator[](int index)
	{
		if (index >= 0 && index < 3)
		{
			return this->data_eveniment[index];
		}
		else return -1;
	}
	bool operator>(Eveniment e1)
	{
		if ((this->ora_eveniment > e1.ora_eveniment) || (this->ora_eveniment == e1.ora_eveniment && this->minut_eveniment > e1.minut_eveniment))
			return true;
		return false;
	}
	bool operator<(Eveniment e1)
	{
		if ((this->ora_eveniment > e1.ora_eveniment) || (this->ora_eveniment == e1.ora_eveniment && this->minut_eveniment > e1.minut_eveniment))
			return false;
		return true;
	}
};