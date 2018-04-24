#include <iostream> 
#include <stdlib.h> 
#include <time.h> 
#include <string>   



using namespace std;

class hesap{
	
	private:
		string isim;
		string soyisim;
		int bakiye = 0;
	public:
	hesap(string isim, string soyisim, int bakiye){
		
		this->isim=isim;
		this->soyisim=soyisim;
		this->bakiye=bakiye;
		
	}
	
	string getIsim(){
		return isim;
	}
	void setIsim(string x){
		isim = x;
	}
	
	string getSoyisim(){
		return soyisim;
	}
	void setSoyisim(string x){
		soyisim = x;
	}
	
	int getBakiye(){
		return bakiye;
	}
	void setBakiye(int x){
	     bakiye = x;
	}
	
};

void islemleriBastir(){
	string tahta = "\n"
		"Secenekler : \n"
		"0- Bakiye Sorgula \n"
		"1- Islemleri bastir \n"
		"2- Kirmizi\n"
		"3- Siyah\n"
		"4- Cift\n"
		"5- Tek\n"
		"6- 1 ~ 12 \n"
		"7- 13 ~ 22 \n"
		"8- 23 ~ 36 \n"
		"9- 1 ~ 18 \n"
		"10- 19 ~ 36 \n"
		"11- 1 den 36 ya kadar olan herhangi bir sayi \n"
		"12- Cikis \n"
		"13- Bakiye yukle \n"
		"Islem numaralarina gore yapmak istediginiz islemi seciniz . . . \n";
		
		
		cout<<tahta<<endl;
}




int main(){
	
	string a, b;
	int c;
	cout<<"Hesap Aciniz : \n"<<"Adiniz : \n"<< "Soyadiniz : \n"<<"Bakiyeniz : \n";
	cin>>a>>b>>c;
	
	
	hesap insan1(a,b,c);
	
	cout<<"\n"<<insan1.getIsim()<<endl;
	cout<<insan1.getSoyisim()<<endl;
	cout<<insan1.getBakiye()<<endl;
	
	int bakiye = insan1.getBakiye();
	
	
	islemleriBastir();
	
	while(true){
		
		x:// buraya �u yollardan geliniyor (para y�kleme) (bakiye < bahis sorgusu) ()
			
				if ( bakiye <= 0 ){ //bu sorgu oyuncu bahisini yap�p "-" ye d��erse oyundan ��kmak i�in yap�lmaktad�r
			
			cout<<"Bakiyeniz kalmamistir oyundan cikiyorsunuz ... "<<endl;
			return false;
			
		}
		
			
			srand(time(NULL));
	    int rnd_sayi=rand()%36;
			
		
		
		int secim = 0;
		int bahis = 1;
		
		
		
		
		
		cout<<"Bir islem seciniz : ";
		cin>>secim;
		
		
		if (secim == 0){  // 0, 1, 12 se�imlerinin buraya konmas�n�n nedeni akabinde istenen bahis miktar�n�n mant�ksal olarak gereksiz kalmas�d�r.
		                  // bu sayede oyuncunun oyundan ��kmak istedi�inde, bakiye sorgulad���nda, i�lemleri bast�rd���nda bahis girmesi mant�ksal hatas� �nlenmi�tir.
				cout<<"Bakiyeniz : "<<bakiye<<endl ; 
				continue;
			}
			else if(secim == 1){
				islemleriBastir();
				continue;
			}
			else if(secim == 12){
				
				cout<<"Oyundan Cikiyorsunuz ... "<<endl;
				
				return false;
				
			}
			else if(secim == 13 ){
				
				int ekMiktar;
				
				cout<<"Eklemek istediginiz miktari giriniz : ";
				cin>>ekMiktar;
				
				bakiye = ekMiktar + bakiye;
				
				cout<<"Paraniz basariyla yuklendi Yeni Bakiyeniz : "<<bakiye<<endl;
				
				goto x;
				
			}
			
			
		cout<<"Bahisi giriniz : "<<endl;
		cin>>bahis;
		
		
		
		cout<<"Bahisiniz Isleme alinmistir. Bakiye asimi durumu kontrol ediliyor ... Bakiye : "<<bakiye<<endl;
		
		if(bakiye < bahis){
			
			               //bu sorgu girilmek istenen bahisin bakiyeden b�y�k olmas� durumunda yeni bahis istemek i�in yap�lmaktad�r
			
			cout<<"Bakiyenizin Uzerinde bahis giremezsiniz. Mevcut Bakiyeniz : "<<bakiye<<endl;
			
			goto x;
		}
		
		bakiye = bakiye - bahis;
		
		cout<<"Bakiyeniz yeterlidir . . ."<<endl;
		
		if ( bakiye < 0 ){
			
			cout<<"Bakiyeniz kalmamistir oyundan cikiyorsunuz ... "<<endl;
			return false;
			
		}
		
		if ( secim == 11){     //11. se�ene�i ana kodun �st�ne koymam�n sebebi bir sonraki ad�mda gelen say�n�n bast�r�lacak olmas�d�r. 
				               //oyuncu gelen sayiyi g�rd�kten sonra 1 den 36 ya kadar olan bir sayi girilmesi istenirse kaybetme �ans� kalmaz. 
				               
				y://buraya sadece yanlis islem sorgusundan gelinmektedir
				int sayiSec;
				cout<<"1 den 36 ya kadar bir sayi seciniz"<<endl;
				cin>>sayiSec;
				
				if( sayiSec < 0 || sayiSec > 36 ){
					
					cout<<"yanlis islem girnizin lUtfen tekrar deneyiniz : "<<endl;
					goto y;
					
				}
				else if( sayiSec == rnd_sayi )
				{
					bakiye = bakiye + ( bahis * 35 );
					
					cout<<"Kazandiniz yeni bakiyeniz : "<<bakiye<<endl;
					
					cout<<" gelen sayi = "<<rnd_sayi<<endl;
					
					continue;
				}
				else{
					
					cout<<" Kaybettiniz Bakiyeniz : "<<bakiye<<endl;
					
					cout<<" gelen sayi = "<<rnd_sayi<<endl;
					
					continue;
				}
				}
			
			cout<<" gelen sayi = "<<rnd_sayi<<endl;
			
			
			if( secim == 2 ){
				              // burada k�rm�z� olan say�lar tek tek girilmi� ve "veya(or)" operat�r�yle kontrol edilmektedir
				
				if( rnd_sayi == 1||rnd_sayi ==3||rnd_sayi ==5||rnd_sayi ==7||rnd_sayi ==9||rnd_sayi ==12||rnd_sayi ==14||rnd_sayi ==16||rnd_sayi==18||rnd_sayi ==19||rnd_sayi ==21||rnd_sayi ==23||rnd_sayi ==25||rnd_sayi ==27||rnd_sayi ==30||rnd_sayi ==32||rnd_sayi ==34||rnd_sayi ==36 ){
					
					bakiye = bakiye + (2 * bahis);
					
					cout<<"Kazandiniz Yeni bakiyeniz : "<<bakiye<<endl;
					continue;
					
				}
				
					else{
					
					cout<<"Kaybettiniz Yeni bakiyeniz : "<<bakiye<<endl;
					continue;
				}
				
				
				
			}
			else if(secim == 3){
				               // burada siyah olan say�lar tek tek girilmi� ve "veya(or)" operat�r�yle kontrol edilmektedir
				
				if( rnd_sayi == 2||rnd_sayi ==4||rnd_sayi ==6||rnd_sayi ==8||rnd_sayi ==10||rnd_sayi ==11||rnd_sayi ==13||rnd_sayi ==15||rnd_sayi ==17||rnd_sayi ==20||rnd_sayi ==22||rnd_sayi ==24||rnd_sayi ==26||rnd_sayi==28||rnd_sayi ==29||rnd_sayi ==31||rnd_sayi ==33||rnd_sayi ==35 ){
					
					bakiye = bakiye + (2 * bahis);
					
					cout<<"Kazandiniz Yeni bakiyeniz : "<<bakiye<<endl;
					continue;
					
				}
				
					else{
					
					cout<<"Kaybettiniz Yeni bakiyeniz : "<<bakiye<<endl;
					continue;
				}
				
				
			}
			else if( secim == 4){
				
				                 //Burada �ift say� gelme olas�l��� kontrol edilmi�tir
				
				if( rnd_sayi % 2 == 0 ){
					
					bakiye = bakiye + (2 * bahis);
					
					cout<<"Kazandiniz Yeni bakiyeniz : "<<bakiye<<endl;
					continue;
					
				}else{
					
						cout<<"Kaybettiniz Yeni bakiyeniz : "<<bakiye<<endl;
					continue;
					
				}
				
				
			}
			else if ( secim == 5 ){
				
				                   //Burada tek say� gelme olas�l��� kontrol edilmi�tir
				
				if ( rnd_sayi % 2 == 1 ){
					
					bakiye = bakiye + (2 * bahis);
					
					cout<<"Kazandiniz Yeni bakiyeniz : "<<bakiye<<endl;
					continue;
					
				}else{
					
						cout<<"Kaybettiniz Yeni bakiyeniz : "<<bakiye<<endl;
					continue;
					
				}
				
				
			}
			
			else if( secim == 6 ){
				                  
				                  //burada gelen say�n�n 1 ve 12 aras�nda olup olmad��� sorgulanmaktad�r
				
				if( rnd_sayi >= 1 && rnd_sayi <= 12 ){
					
					bakiye = bakiye + (bahis * 3);
					
					cout<<"Kazandiniz Yeni bakiyeniz : "<<bakiye<<endl;
					
					continue;
				
				}
				else{
					cout<<"Kaybettiniz Yeni Bakiyeniz : "<<bakiye<<endl;
					continue;
				}
				
			}
			
			else if( secim == 7 ){
				                
				                  //burada gelen say�n�n 13 ve 22 aras�nda olup olmad��� sorgulanmaktad�r
				
				if( rnd_sayi >= 13 && rnd_sayi <= 22 ){
					
					bakiye = bakiye + (bahis * 3);
					
					cout<<"Kazandiniz Yeni bakiyeniz : "<<bakiye<<endl;
					
					continue;
				
				}
				else{
					cout<<"Kaybettiniz Yeni Bakiyeniz : "<<bakiye<<endl;
					continue;
				}
				
			}
			else if( secim == 8 ){
				                  
				                  //burada gelen say�n�n 23 ve 36 aras�nda olup olmad��� sorgulanmaktad�r
				
				if( rnd_sayi >= 23 && rnd_sayi <= 36 ){
					
					bakiye = bakiye + (bahis * 3);
					
					cout<<"Kazandiniz Yeni bakiyeniz : "<<bakiye<<endl;
					
					continue;
				
				}
				else{
					cout<<"Kaybettiniz Yeni Bakiyeniz : "<<bakiye<<endl;
					continue;
				}
				
			}
			
			else if( secim == 9 ){
				
				                //burada gelen say�n�n 1 ve 18 aras�nda olup olmad��� sorgulanmaktad�r
				
				if( rnd_sayi >= 1 && rnd_sayi <= 18 ){
					
					bakiye = bakiye + (bahis * 2);
					
					cout<<"Kazandiniz Yeni bakiyeniz : "<<bakiye<<endl;
					
					continue;
				
				}
				else{
					cout<<"Kaybettiniz Yeni Bakiyeniz : "<<bakiye<<endl;
					continue;
				}
				
			}
			
			else if( secim == 10 ){
				
				                   //burada gelen say�n�n 19 ve 36 aras�nda olup olmad��� sorgulanmaktad�r
				
				if( rnd_sayi >= 19 && rnd_sayi <= 36 ){
					
					bakiye = bakiye + (bahis * 2);
					
					cout<<"Kazandiniz Yeni bakiyeniz : "<<bakiye<<endl;
					
					continue;
				
				}
				else{
					cout<<"Kaybettiniz Yeni Bakiyeniz : "<<bakiye<<endl;
					continue;
				}
				
			}
			
			
			
				
				
				
			
			
			
			
		
		}
		
		
		
		
		cout<<"Oyundan Ciktiniz ... "<<endl;
		
		
		
		
		
		return 0;
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

