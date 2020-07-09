

#ifndef DinamikBellekYonetimi_H  //ifndef, define ve endif  �ni�lemci direktifleri Polinom S�n�f� tan�m�n�n projenin 
#define DinamikBellekYonetimi_H //birden fazla dosyas� i�erisinde kullan�m�n�n nesne kodu (object code) b�nyesinde tekrar�n� engeller.
#include <climits>             //say�sal s�n�flar

class DinamikBellekYonetimi // S�n�f ad�
{
	public:  //public ve fonksiyonlar�
		bool GizemliMatrisMi(int**, int, int);
		int SansliMatrisElemanlarininSayisi(int**, int, int);
	private: //private ve fonksiyonlar�
		bool ButunElemanlariFarkliMi(int**, int, int); // Matrisin b�t�n elemanlar�n�n farkl� olup olmad���n� d�ner
		int SatirTopla(int**, int, int);		// Matrisin istenilen sat�r�n�n toplam�n� d�ner
		int SutunTopla(int**, int, int);		// Matrisin istenilen s�tununun toplam�n� d�ner
		int KosegenTopla(int**, int, int);	// Matrisin istenilen k��egeninin toplam�n� d�ner
		void SatirMinMax(int**, int, int, int*, int*);	// Matrisin istenilen sat�r�n�n max ve min de�erleri indexlerini bulur, pointer ile ge�irilen de�i�kenlere yazar
		void SutunMinMax(int**, int, int, int*, int*);	// Matrisin istenilen s�tununun max ve min de�erleri indexlerini bulur, pointer ile ge�irilen de�i�kenlere yazar
};
#endif
