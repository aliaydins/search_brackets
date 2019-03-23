#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>


using namespace std;

int main()
{
    int satir[100];
    int satir2[100];
    int dogruluk1[100];
    int dogruluk2 [100];
    int i=0;
    int acik_p=0;
    int kapali_p=0;
    int counter=0;
    int toplam=0;
    for(int k=0;k<100;k++)     // verilerin tekrar aynisini ekranan basmamasi icin degerleri sifirliyorum
    {
        dogruluk1[k]=0;
        dogruluk2[k]=0;
        satir2[k]=0;
        satir[k]=0;
        acik_p=0;
        kapali_p=0;
    }

    fstream dosya ;
    dosya.open("kontrol.txt",ios::in); // satirlari alacagim dosya ismi 'kontrol.txt' klasor icinde acilmali
    string satiral;

    if(dosya.is_open())
    {
    while(dosya.eof()!=true)
    {
     getline(dosya,satiral); // dosyadan 1 satir kod cekiyorum
     counter++;
     const char *array = satiral.c_str(); // satiri chara donusturup karakter karakter kontrol ediyorum parantez var mi yok mu
     array=&satiral[0];
     for(i=0;array[i]!=NULL;i++){

     if(array[i]=='{') // parantez aciksa satir dizime satirin bilgisini aliyorum  dogruluk dizime  1 ekliyorum
     {
       satir[acik_p]=counter;
       dogruluk1[acik_p]=1;

       acik_p+=1;
     }
     if(array[i]=='}')  // kapali parantez var ise  satir2 kapali_p de satiri tutuyorum
     {
       satir2[kapali_p]=counter;     // dogruluk kapali_p dizime  -1 degerini atiyorum
       dogruluk2[kapali_p]=-1;

       kapali_p+=1;          // kapali_p ve acik_p her eklendiginde 1 artiyor
     }
     }
     }
     }
     else
     {
         cout<<"kontrol.txt Dosyasi bulunamadi"<<endl;
         return 0 ;                                 // dosya bulunamadiysa cik
     }
     dosya.close();

    int sonuc=acik_p;
    if(acik_p>=kapali_p)
     {
     sonuc=acik_p;
     }
     else
     {
     sonuc=kapali_p;
     }                   //sonuç degiskenimde dongumun ne kadar donmesi gerektigini anlamak için acik_p ve kapali_p hangisi büyükse onu atiyorum

     kapali_p=0;
     acik_p-=1;    // acik_p yi  diziden dolayi 1 azaltiyorum  ve a nin en son acik paranteziyle eþleþtirmek için  kapali_p=0 atiyorum
     for(;sonuc!=0;sonuc--)
     {
          toplam=(dogruluk1[acik_p])+(dogruluk2[kapali_p]); // toplam degiskenime  dizilerdeki +1 ve -1 soncunu atiyorum



          if(toplam==1) // 1 açik { olan satirin karsiligi yok ise  satir numarasini ekrana basiyorm
          {

            cout<<satir[acik_p]<<".SATIR PARANTEZI KAPATILMAMIS"<<endl;
          }
          if(toplam==-1) // -1 kapali ise  satir numarasini ekrana basiyorm
          {

            cout<<satir2[kapali_p]<<". SATIR PARANTEZI ACILMAMIS"<<endl;

          }



          acik_p-=1;
          kapali_p+=1;


     }

}



