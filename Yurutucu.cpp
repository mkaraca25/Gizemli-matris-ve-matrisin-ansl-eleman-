
#include <iostream> //cin cout
#include "DinamikBellekYonetimi.h"   //DinamikBellekYonetimi k�t�phanem

using namespace std;
void matrisiYaz(int** matris, int satir, int sutun) //matrisi yazd�rma fonksiyonu
{
	for (int i = 0; i < satir; ++i) { 
	  for (int j = 0; j < sutun; ++j) {
	    cout << "\t" << matris[i][j];
	  }
	  cout << endl;
	}
}
void matrisiSil(int** matris, int satir)  //matrisi silme fonksiyonu
{
    // Her sat�r� sil
    for(int i = 0; i < satir; ++i) {
        delete[] matris[i];   
    }
    // Pointer dizisini sil
    delete[] matris;
}
int main(int argc, char** argv)
{
	setlocale(LC_ALL,"Turkish"); //T�rk�e karakterlerin g�z�kmesi i�in
	
	// Test olarak kullan�lacak de�erler
	int gizemliMatrisDegerleri[3][3] = {{2,7,6},{9,5,1},{4,3,8}};
	int sansliMatrisDegerleri[3][3] = {{3,7,8},{9,11,13},{15,16,17}};

	////////////////////////////// Dizi 1 ///////////////////////////////////////
	// kullan�c�dan matris boyutlar�n� al
	int satir1,sutun1,satir2,sutun2; 
	cout << "1. dinamik integer dizinin boyutlar�n� s�tun,sat�r �eklinde giriniz (Test i�in 3,3 giriniz): ";
	cin >> satir1;
	cin.ignore(1, ','); //de�erlerin aras�na , koyma i�lemi
	cin >> sutun1;
	
	// dinamik integer dizilerini olu�tur
	int **dinamikDizi1 = new int*[satir1]; // int pointerlara i�aret eden dinamik dizi
	for (int i = 0; i < satir1; ++i) 
	  dinamikDizi1[i] = new int[sutun1];
	  
	// Satir ve sutun say�s� 3 i�in test de�erleri otomatik olarak atan�r. Di�er giri�ler i�in matrisin
	// elemanlar� kullanc�dan teker teker al�n�r
	if(satir1 == 3 && sutun1 == 3)
	{
		for (int i = 0; i < satir1; ++i) {   // her sat�r i�in
		  for (int j = 0; j < sutun1; ++j) { // her sutun i�in
		    dinamikDizi1[i][j] = gizemliMatrisDegerleri[i][j];
		  }
		}
	}
	else
	{
		cout << "1. matrisin elemanlar�n� giriniz. (Teker teker veya aralar�nda 1 bo�luk b�rakarak.): ";
		for (int i = 0; i < satir1; ++i) {   // her sat�r i�in
		  for (int j = 0; j < sutun1; ++j) { // her sutun i�in
		    cin >> dinamikDizi1[i][j];
		  }
		}	
	}
	
	////////////////////////////// Dizi 2 ////////////////////////////////////////
	
	cout << "2. dinamik integer dizinin boyutlar�n� s�tun,sat�r �eklinde giriniz (Test i�in 3,3 giriniz): ";
	cin >> satir2;
	cin.ignore(1, ',');
	cin >> sutun2;
	
	// dinamik integer dizilerini olu�tur
	int **dinamikDizi2 = new int*[satir2]; // int pointerlara i�aret eden dinamik dizi
	for (int i = 0; i < satir2; ++i) 
	  dinamikDizi2[i] = new int[sutun2];
	  
	// Satir ve sutun say�s� 3 i�in test de�erleri otomatik olarak atan�r. Di�er giri�ler i�in matrisin
	// elemanlar� kullanc�dan teker teker al�n�r
	if(satir2 == 3 && sutun2 == 3)
	{
		for (int i = 0; i < satir2; ++i) {   // her sat�r i�in
		  for (int j = 0; j < sutun2; ++j) { // her sutun i�in
		    dinamikDizi2[i][j] = sansliMatrisDegerleri[i][j];
		  }
		}
	}
	else
	{
		cout << "2. matrisin elemanlar�n� giriniz. (Teker teker veya aralar�nda 1 bo�luk b�rakarak.): ";
		for (int i = 0; i < satir2; ++i) {   // her sat�r i�in
		  for (int j = 0; j < sutun2; ++j) { // her sutun i�in
		    cin >> dinamikDizi2[i][j];
		  }
		}	
	}		
	
	// dinamik bellek y�netimi nesnesi olu�tur
	DinamikBellekYonetimi* dby = new DinamikBellekYonetimi();

	// Matrisleri ve sonu�lar� ekrana bas
		// 1. dinamik dizi gizemli matris mi diye kontrol et
	cout << endl << "1. Dinamik Dizi: " << endl;
	matrisiYaz(dinamikDizi1,satir1,sutun1);
	if(dby->GizemliMatrisMi(dinamikDizi1,satir1,sutun1))
		cout << endl << "1. Dinamik Dizi bir Gizemli Matristir.";
	else
		cout << endl << "1. Dinamik Dizi bir Gizemli Matris de�ildir.";
		// 2. dinamik dizinin �ansl� matris elemanlar�n�n say�s�n� hesapla
	cout << endl << endl << "2. Dinamik Dizi: " << endl;
	matrisiYaz(dinamikDizi2,satir2,sutun2);
	cout << endl << "2. Dinamik Dizinin �ansl� Elemanlar�n�n Say�s� = " << dby->SansliMatrisElemanlarininSayisi(dinamikDizi2,satir2,sutun2) << endl;
	
	// dinamik dizileri sil
	matrisiSil(dinamikDizi1,satir1);
	matrisiSil(dinamikDizi2,satir2);
	return 0;
}

