#include <iostream> 
#include "DinamikBellekYonetimi.h"
#include <cstdlib>
#include <ctime>
using namespace std;
int main(int argc, char** argv)
{
	setlocale(LC_ALL,"Turkish");//T�rk�e karakterlerin g�z�kmesi i�in
	int satir,sutun,m;
	DinamikBellekYonetimi *nesnePtr=new DinamikBellekYonetimi; // Yeni bir pointer deklare ediyoruz.
	cin>>satir>>sutun;// Kullan�c�dan sat�r ve s�tun isteyip atama i�lemini yap�yoruz.
	int **matrisPtr=new int*[satir];
	Fonksiyon1(matrisPtr,satir,sutun)=m;
	for(int i=0;i=m;i++)//T�m �artlar� sa�lay�p geriye true d�nd�r�yor ise
	{
		if(m==true)
		cout<<"Matris gizemli bir matristir.n";
		else if(m==false)
		cout<<"Matris gizemli bir matris de�ildir.n";
          //Kare matris de�ilse program� sonland�r.
        else
		cout<<"L�tfen sat�r ve s�tun say�s�n� e�it giriniz.n ";//return false;
		
	    delete [] matrisPtr;// Olu�turdu�umuz pointerleri silme i�lemi.
	    delete  nesnePtr;
	}
	return 0;
}

