/*

	Tunahan KAYA
	Akdeniz Üniversitesi
	11.03.2023

*/
#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS //visual studio community scanf fonksiyonu kullanımınını engelledigi icin bu satır gerekli farklı IDE'lerde gerekli degil
float TaylorExp(float radian, int n);
int main()
{
	
	printf("Taylor Serisi kullanarak Cos Hesaplama\n");
	for (;;) {//kullanici islemi bitirdikten sonra programin tekrar baslamisini saglayan sonsuz dongu



		float degree, radian, result; // gerekli verileri tutan float tipi degiskenler
		/*
		
			degree = kullanici tarafindan girilecek olan degeri tutan degisken
			radian = degree degerini radyana cevridikten sonra icinde tutulacak degisken
			result = hesaplanan son degeri icinde tutan degisken

		*/
		int n = 15; // Taylor serisinde Accuracy(Dogruluk) arttirmak icin isleme katilan eleman sayisini belirten degisken
		printf("Lutfen derece cinsinden cos icine girilecek degeri yaziniz: ");
		scanf("%f", &degree); //kullanici tarafindan girilecek olan degeri okuyan fonksiyon
		printf("Taylor serisinde Toplanacak eleman sayisi arttikca elde edilecek sonucun dogrulugu artar.\nProgramin stabil calisabilmesi icin eleman sayisi 15 olarak kabul edilmistir.\n");
		radian = degree * 0.017; // dereceden radyana ceviren islem
		result = TaylorExp(radian, n); //asagida cos'un taylor serisi ile hesaplanaması için gerekli islemleri yapıp sonucu ceviren fonksiyonu cagirip result degiskeni icinde tutan islem
		printf("Taylor serisi ile bulunan sonuc: %f\n", result);//sonucu kullaniciya gosteren fonksiyon
		

	}


}
float TaylorExp(float radian, int n) { //Cos'u hesaplayan fonksiyon
	float result = 1; //cos'u taylor serisi ile hesaplarken cos'u actıgımızda islem 1 ile basladıgı icin isleme baslangıc degeri olarak 1 atadim
	for (int i = 1; i <= n; i++) {//girilen n degeri kadar toplama / cikarma islemi yapana dongu
		int factorial = 1; /*
							cos'u taylor serisi ile hesaplarken cos'u actıgımızda 1 - ((x ^ 2) / n!) gibi bir islem goruyoruz
							burada n! hesaplayinca icinde tutacagimiz degiskeni atiyorum
							*/
		for (int j = 2 * i; j > 0; j--) { // faktoriyel hesaplayan dongu
			factorial = factorial * j;
		}
	
			
			result = result + (pow(-1, i)*(pow(radian, 2 * i) / factorial)); //(-1^n)((x ^ 2) / n!)
		
	}
	return result;//daha sonra fonksiyon buldugumuz sonucu donduruyor
}


