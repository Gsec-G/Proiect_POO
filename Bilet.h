#pragma once
#include<iostream>
#include<string>
using namespace std;
class Bilet
{
private:

	const int id_bilet;
	static int contor_id_bilet;
	char zona;
	//static int* rand;
	//static int nr_randuri;
	int rand;
	int scaun;
	int pret;
	static int nr_total_bilete;
	static int bilete_vip;
	bool VIP;

public:
	Bilet() :id_bilet(contor_id_bilet)
	{
		this->zona = ' ';
		this->scaun = 0;
		this->rand = 0;
	/*	this->rand = nullptr;
		this->nr_randuri = 0;*/
		this->pret = 0;
		this->VIP = false;
		nr_total_bilete++;
		contor_id_bilet++;

	}
	Bilet(char zona, int rand, int scaun) :id_bilet(contor_id_bilet)
	{
		if (zona == 'A' || zona == 'B' || zona == 'C')
		{
			this->zona = zona;
			this->pret = 15;
			this->VIP = false;
		}
		else if (zona == 'D')
		{
			this->zona = zona;
			this->pret = 60;
			this->VIP = true;
			bilete_vip++;
		}
		else
		{
			this->zona = ' ';
			this->VIP = false;
			this->pret = 0;
		}

		/*if (nr_randuri > 0 && rand != nullptr)
		{
			this->rand = new int[nr_randuri];
			for(int i =0;i<nr_randuri;i++)
			{
				this->rand[i] = rand[i];
			}
			this->nr_randuri = nr_randuri;
		}
		else
		{
			this->nr_randuri = 0;
			this->rand = nullptr;
		}*/
		if (rand > 0 && rand <11 && scaun < 31 &&scaun > 0)
		{
			this->rand = rand;
			this->scaun = scaun;
		}
		else
		{
			this->scaun = 0;
			this->rand = 0;
		}
		nr_total_bilete++;
		contor_id_bilet++;
	}

	Bilet(const Bilet& copie):id_bilet(contor_id_bilet)
	{
		nr_total_bilete++;
		contor_id_bilet++;
		if (copie.zona == 'D')
			bilete_vip++;
		this->pret = copie.pret;
		this->VIP = copie.VIP;
		this->rand = copie.rand;
		this->scaun = copie.scaun;
		/*this->nr_randuri = copie.nr_randuri;
		this->rand = new int[copie.nr_randuri];
		for (int i = 0; i < copie.nr_randuri; i++)
		{
			this->rand[i] = copie.rand[i];
		}*/
		this->zona = copie.zona;

	}

	~Bilet() { nr_total_bilete--; };

	int getId_bilet(){ return this->id_bilet; }
	char getZona() { return this->zona; }
	/*int* getRand()
	{
		int* copie = new int[this->nr_randuri];
		for (int i = 0; i < this->nr_randuri; i++)
		{
			copie[i] = this->rand[i];
		}
		return copie;
	}*/
	int getRand() { return this->rand; }
	/*int getNr_randuri() { return this->nr_randuri; }*/
	int getScaun() { return this->scaun; }
	int getNr_total_bilete() { return nr_total_bilete; }
	int getBilete_vip() { return bilete_vip; }
	int getVip() { return this->VIP; }
	int getPret() { return this->pret; }

	void setZona(char zona) 
	{
		if (zona != this->zona)
		{
			if (zona == 'A' || zona == 'B' || zona == 'C')
			{
				this->zona = zona;
				this->rand = 0;
				this->scaun = 0;
			}
			if (zona == 'D')
			{
				bilete_vip++;
				this->VIP = true;
				this->zona = zona;
				this->rand = 0;
				this->scaun = 0;
			}
			else
			{
				this->zona = ' ';
				this->VIP = false;
				this->pret = 0;
			}
		}
	}
	void setPret(int discount)
	{
		if (discount > 0 && discount < 101)
		{
			this->pret = this->pret - this->pret * discount / 100;
		}
	}
	static int Locuri_Non_VIP() { return nr_total_bilete - bilete_vip; }
	void Schimb_zona_si_locul(char zona,int rand, int scaun)
	{
		if (this->zona == 'D' && (zona == 'A' || zona == 'B' || zona == 'C'))
		{
	        this->zona = zona;
			this->VIP = false;
			this->pret = 15;
			/*if (nr_randuri > 0 && rand != nullptr)
			{
				this->rand = new int[nr_randuri];
				for (int i = 0; i < nr_randuri; i++)
				{
					this->rand[i] = rand[i];
				}
				this->nr_randuri = nr_randuri;
			}*/
		}
		else if ( (this->zona == 'A' || this->zona == 'B' || this->zona == 'C') && zona == 'D')
		{
			bilete_vip++;
			this->zona = zona;
			this->VIP = true;
			this->pret = 60;
			/*if (nr_randuri > 0 && rand != nullptr)
			{
				this->rand = new int[nr_randuri];
				for (int i = 0; i < nr_randuri; i++)
				{
					this->rand[i] = rand[i];
				}
				this->nr_randuri = nr_randuri;
			}*/
		}
		else
		{
			this->zona = ' ';
			this->VIP = false;
			this->pret = 0;
		}
		if (rand > 0 && rand < 11 && scaun < 31 && scaun > 0)
		{
			this->rand = rand;
			this->scaun = scaun;
		}
		else
		{
			this->scaun = 0;
			this->rand = 0;
		}
	}
	float Suma_incasarilor_vector_bilete(Bilet* Bilete, int nr_bilete)
	{
		float x = 0;
		for(int i=0;i< nr_bilete;i++)
			x += Bilete[i].pret;
		return x;
	}
	static void Schimba_nr_total_bilete(int nr)
	{
		if(nr > 0)
		nr_total_bilete = nr;
	}
	Bilet& operator=(Bilet copie)
	{
		if (this == &copie) return *this;
		if (copie.zona == 'A' || copie.zona == 'B' || copie.zona == 'C')
		{
			this->zona = copie.zona;
			this->VIP = false;
		}
		if (copie.zona == 'D')
		{
			bilete_vip++;
			this->VIP = true;
			this->zona = copie.zona;
		}
		else
		{
			this->VIP = false;
			this->zona = ' ';
		}
		if (copie.pret >= 0)
			this->pret = copie.pret;
		else this->pret = 0;

		if (copie.rand > 0 && copie.rand < 11 && copie.scaun < 31 && copie.scaun > 0)
		{
			this->rand = copie.rand;
			this->scaun = copie.scaun;
		}
		else
		{
			this->scaun = 0;
			this->rand = 0;
		}
		/*if (this->rand != nullptr)
		{
			delete[] this->rand;
			this->rand = nullptr;
		}
		if (copie.nr_randuri > 0 && copie.rand != nullptr)
		{
			this->rand = new int[copie.nr_randuri];
			for (int i = 0; i < copie.nr_randuri; i++)
			{
				this->rand[i] = copie.rand[i];
			}
			this->nr_randuri = copie.nr_randuri;
		}
		else
		{
			this->nr_randuri = 0;
			this->rand = nullptr;
		}*/
		return *this;
	}
	friend istream& operator>>(istream& in, Bilet& copie)
	{
		cout << "Rand( 1 - 10 ): ";
		in >> copie.rand;
		while (copie.rand > 30 || copie.rand < 1)
		{
			cout << "Rand( 1 - 10 ): ";
			in >> copie.rand;
		}
		cout << "Scaun( 1 - 30 ): ";
		in >> copie.scaun;
		while (copie.scaun > 10 || copie.scaun < 1)
		{
			cout << "Scaun( 1 - 30 ): ";
			in >> copie.scaun;
		}
		cout << "Zona  A, B, C sau D(VIP): ";
		char buff;
		in >> buff;

		while ( !(buff == 'A' || buff == 'B' || buff == 'C' || buff == 'D') )
		{
			cout << "Zona  A, B, C sau D(VIP): ";
			in >> buff;
		}

		if (buff == 'A' || buff == 'B' || buff == 'C')
		{
			copie.zona = buff;
			copie.VIP = 0;
			copie.pret = 15;
		}
		else if (buff == 'D')
		{
			copie.zona = buff;
			copie.VIP = 1;
			copie.pret = 60;
		}
		else
		{
			copie.zona = ' ';
			copie.VIP = 0;
			copie.pret = 0;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, Bilet copie)
	{
		out << "ID Bilet: " << copie.id_bilet << endl;
		out << "Zona: " << copie.zona << endl;
		out << "Ocupa locul: " << endl << "Randul: " << copie.rand << " " << "Scaunul: " << copie.scaun << endl;
		out << "Pretul: " << copie.pret <<endl;
		if (copie.VIP == true)
			out << "Biletul este VIP" << endl;
		else
			out << "Biletul nu este VIP" << endl;
		return out;
	}

	Bilet operator+(Bilet b1)
	{
		Bilet copie = *this;
		copie.pret = pret + b1.pret;
		return copie;
	}
	Bilet operator-(Bilet b1)
	{
		Bilet copie = *this;
		copie.pret = pret - b1.pret;
		if (copie.pret < 0)
			copie.pret = 0;
		return copie;
	}
};