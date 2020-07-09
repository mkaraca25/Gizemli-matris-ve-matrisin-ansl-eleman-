
#include "DinamikBellekYonetimi.h"  //DinamikBellekYonetimi k�t�phanem

//////////////////////////////// Public Fonksiyonlar ////////////////////////

bool DinamikBellekYonetimi::GizemliMatrisMi(int** matris, int satir, int sutun) 
{
	// Kare Matris mi diye kontrol et
	if(satir != sutun)
		return false;
	
	// b�t�n elemanlar� farkl� m� diye kontrol et
	if(not ButunElemanlariFarkliMi(matris, satir, sutun))
		return false;
	// b�t�n elemanlar�n 1 ve n^2 aras�nda oldu�unu kontrol et
	for(int i = 0; i < satir; i++)
	{
		int minIndex, maxIndex;
		SatirMinMax(matris, sutun, i, &minIndex, &maxIndex);
		if(matris[i][minIndex] < 1 || matris[i][maxIndex] > satir*satir)
			return false;
	}
	
	int M = satir*(satir*satir + 1) / 2;//projede verilen fonksiyon 
	
	// B�t�n sat�rlar�n toplam�n�n M'e e�it olup olmad���n� kontrol et
	for(int i = 0; i < satir; i++)
	{
		if (SatirTopla(matris, sutun, i) != M)
			return false;
	}

	// B�t�n sutunlarin toplam�n�n M'e e�it olup olmad���n� kontrol et
	for(int i = 0; i < sutun; i++)
	{
		if (SutunTopla(matris, satir, i) != M)
			return false;
	}

	// B�t�n kosegenlerin toplam�n�n M'e e�it olup olmad���n� kontrol et
	for(int i = 0; i < 2; i++)
	{
		if (KosegenTopla(matris, satir, i) != M)
			return false;
	}
	
	// B�t�n bu kontrollerden ge�ebildiyse matris bir gizemli matristir	
	return true;
}

int DinamikBellekYonetimi::SansliMatrisElemanlarininSayisi(int** matris, int satir, int sutun)
{
	
	// Kare Matris mi diye kontrol et
	if(satir != sutun)
		return 0;
		
	// b�t�n elemanlar� farkl� m� diye kontrol et
	if(not ButunElemanlariFarkliMi(matris, satir, sutun))
		return 0; 
		
	int sansliMatrisElemanlari = 0;
	
	/*
	Her sat�rdaki minimum eleman� bul. E�er o eleman bulundu�u s�tundaki maximum elemansa
	sansl� matris elemanlar� say�s�n� bir artt�r.
	*/
	for(int i = 0; i<satir; i++)
	{
		int satirMinIndex, satirMaxIndex;
		int sutunMinIndex, sutunMaxIndex;
		SatirMinMax(matris, sutun, i, &satirMinIndex, &satirMaxIndex);
		SutunMinMax(matris, satir, satirMinIndex, &sutunMinIndex, &sutunMaxIndex);
		if(sutunMaxIndex == i)
			sansliMatrisElemanlari++;
	}
	
	return sansliMatrisElemanlari;
	
}

///////////////////////////////// Private Fonksiyonlar /////////////////////////////////

bool DinamikBellekYonetimi::ButunElemanlariFarkliMi(int** matris, int satir, int sutun)
{
/*
	Bu fonksiyon matristeki her eleman�, �ncesinde kalan elemanlarla kar��la�t�rarak 
	matrisin b�t�n elemanlar�n�n birbirinden farkl� olup olmad���n� bulur
*/
	
    int i, j;

    for(i = 1; i < satir*sutun; i++) {
        for(j = 0; j < i; j++) {
            if (matris[i / sutun][i % sutun] == matris[j / sutun][j % sutun]) return false;
        }
    }

    return true; 
}

int DinamikBellekYonetimi::SatirTopla(int** matris, int sutunUzunlugu, int istenilenSatir) //sat�rlar� toplama 
{
	int toplam = 0;
    for(int i = 0; i < sutunUzunlugu; i++) {
        toplam += matris[istenilenSatir][i];
    }
    return toplam; 
}

int DinamikBellekYonetimi::SutunTopla(int** matris, int satirUzunlugu, int istenilenSutun) //sut�nlar� toplama
{
	int toplam = 0;
    for(int i = 0; i < satirUzunlugu; i++) {
        toplam += matris[i][istenilenSutun];
    }
    return toplam; 
}

int DinamikBellekYonetimi::KosegenTopla(int** matris, int satirUzunlugu, int istenilenKosegen) //k��egenleri toplama
{
	int toplam = 0;
    if(istenilenKosegen == 0)
    {
    	for(int i = 0; i<satirUzunlugu; i++)
    	{
    		toplam += matris[i][i];
		}
	}
	else
	{
    	for(int i = 0; i<satirUzunlugu; i++)
    	{
    		toplam += matris[i][satirUzunlugu - 1 - i];
		}	
	}
    return toplam; 
}

void DinamikBellekYonetimi::SatirMinMax(int** matris, int sutunUzunlugu, int istenilenSatir, int* minIndex, int* maxIndex) // sat�rlar�n min max durumu
{

	int min = INT_MAX;
	int max = INT_MIN;
	
	for(int i=0; i < sutunUzunlugu; i++)
	{
		if(matris[istenilenSatir][i] < min)
		{
			min = matris[istenilenSatir][i];
			*minIndex = i;
		}
		if(matris[istenilenSatir][i] > max)
		{
			max = matris[istenilenSatir][i];
			*maxIndex = i;
		}
	}
}

void DinamikBellekYonetimi::SutunMinMax(int** matris, int satirUzunlugu, int istenilenSutun, int* minIndex, int* maxIndex) // sut�nlar�n min max durumu
{
	int min = INT_MAX;
	int max = INT_MIN;
	
	for(int i=0; i < satirUzunlugu; i++)
	{
		if(matris[i][istenilenSutun] < min)
		{
			min = matris[i][istenilenSutun];
			*minIndex = i;
		}
		if(matris[i][istenilenSutun] > max)
		{
			max = matris[i][istenilenSutun];
			*maxIndex = i;
		}
	} 
}


