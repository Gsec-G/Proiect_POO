#include<iostream>
#include<string>
#include "Eveniment.h"
#include "Locatie.h"
#include "Bilet.h"
using namespace std;
int Bilet::contor_id_bilet = 1;
int Bilet::nr_total_bilete = 0;
int Bilet::bilete_vip = 0;

// clasa Bilet (  - zonele = 'A' , 'B', 'C', 'D' , cea din urma fiind cea VIP
//                - admite un maxim de 10 randuri si 30 de scaune
int main()
{
	Bilet a('D', 5, 4);
	Bilet b(a);
	Bilet c('A',6,6);
	//cout << c << a;
	//cout << a.getVip() << ' ' << a.getId_bilet()<<endl;
	//cout << c.getPret() << endl << b.getPret();
	Bilet d = a - c;
	cout << d;
	Locatie l1("Ministerul Jocurilor de Noroc", "Str.Garantarii nr.1",1500,50,2000,0);
	Locatie l2;
	//cout << l1 << l2 << l1.operator!();
	//cin >> l2;
	Locatie l3(l1);
	//cout << l3 << l2 ;
	char* c1 = new char[strlen("Petrecere privata") + 1];
	strcpy_s(c1, strlen("Petrecere Privata") + 1, (char*)"Petrecere Privata");
	int* i1 = new int[3];
	i1[0] = 14;
	i1[1] = 7;
	i1[2] = 2023;
	Bilet* bilete = new Bilet[3];
	bilete[0] = a;
	bilete[1] = c;
	bilete[2] = b;
	Eveniment e1(c1, 14, 30, i1, bilete, 3, l1);
	int zile = e1[2];
	cout << zile;
	//cout << e1;
	Eveniment e2;
	bool mai_mare = e2 < e1;
	cout << endl << mai_mare;
	//cin >> e2;
	//cout << e2;
	return 0;
}