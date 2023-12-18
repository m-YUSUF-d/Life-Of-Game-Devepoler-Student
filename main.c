#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>


void uyu(char *isim , int *duzey )
{
    int secim = 0;

    if(duzey == 10)
    {
        printf("%s nin uykusu yok",isim);
    }
    else
    {
        printf("1 - 3 saat uyu\n2 - 5 saat\n3 - 7 saat uyu\nSec : ");
        scanf(" %d" , &secim);

        switch(secim)
        {
        case 1:
            printf("hah hkajdhkfhsalkfa");
        }
    }
}

void yemekYe(char isim , int duzey)
{
    char metin[5];
    int secim = 0;
    int kontrol = 1;

    if(duzey == 1)
    {
        printf("%s nin uykusu yok",isim);
    }

    else
    {
        while(kontrol)
        {
        kontrol = 0;

        printf("1 - 3 saat uyu\n2 - 5 saat\n3 - 7 saat uyu\nSec :");
        scanf(" %s" , metin);
        secim = atoi(metin);

            switch(secim)
            {
            case 1:
                printf("hah hkajdhkfhsalkfa");
                break;
            case 2:
                printf("heh hskjdhak");
                break;
            case 3:
                printf("hih jsldahdl");
                break;
            default:
                kontrol = 1;
                break;
            }
        }
    }
    printf("Karnim tok");
}

void sev(char isim , int duzey)
{
    printf("Ask yalan");
}

void sosyalles(char isim , int duzey)
{

    printf("Derslerim var sosyallesmeye vaktim yok");

}

void saglik(char isim , int duzey)
{

    printf("Gayet saglikliyim");

}

void egit(char isim , int duzey)
{

    printf("Kendimin egitimli bir birey oldugunu dusunuyorum");

}

void bakim(char isim , int duzey)
{

    printf("Cildim cok temiz");

}

void taharetlen(char isim , int duzey)
{

    printf("Tuvaletim yok");

}

void eglen(char isim , int duzey)
{

    printf("Eglenmeye vaktim yok");

}

void ibadetEt(char isim , int duzey)
{

    printf("Her gun namazlarimi kilarim");

}

void sporYap(char isim , int duzey)
{

    printf("Duzenli spor yapan bir insanim");

}

void mentalite(char isim , int duzey)
{

    printf("Mental sağlığım yerinde");

}



int main()
{
    int i , secenek , yas;
    char isim[100];
    char *ihtiyaclar[] = {"Uyku","Tokluk","Sevgi","Sosyal","Saglik","Egitim","Hijyen","Tuvalet","Eglence","Ibadet","Spor","Mental"};
    int *duzey[12] = {10,10,10,0,10,0,10,10,0,0,0,0};

    printf("Sanal bebek uygulamasina hosgeldiniz\n");
    printf("Karakterinizin ismi ve yasi girerek uygulamayi baslatabilirsiniz\n");
    gets(isim);
    scanf("%d",&yas);

    printf("\nMerhaba benim ismim %s bu oyunu senle oynamak icin sabirsizlaniyorum\n\n",isim);

    while( duzey[4] >= 0 )
    {

    printf("\t\t===>%s'nin Hayati<===\t\n",isim);
    printf("**********************************************\n");

    printf("Ihtiyaclar\t\tDuzeyler\n\n");

    for(i = 0; i < sizeof(ihtiyaclar) / sizeof(ihtiyaclar[0]); i++)
    {
        printf("%s\t\t\t%d\n",ihtiyaclar[i],duzey[i]);
    }

    printf("\n");
    printf("\n** Arttirilmaya Ihtiyaci olan Ihtiyaclar **\n\n");

    for(i = 0; i < sizeof(duzey)/sizeof(duzey[0]); i++)
    {
        if(duzey[i] == 0)
        {
            printf("%s\n",ihtiyaclar[i]);
        }
    }
    printf("\n");


    printf("\nArttirmak istediginiz ihtiyac hangisi?\n");

    for(i = 0; i < sizeof(ihtiyaclar)/sizeof(ihtiyaclar[0]); i++)
    {
        printf("%d. %s\n",i+1,ihtiyaclar[i]);
    }

    printf("\n11 den buyuk bir degere veya 1 den kucuk bir degere basarsaniz uygulamadan cikilacaktir\n");
    printf("Lutfen arttirmak istediginz ihtiyac icin yandaki numarasini giriniz : ");
    scanf(" %d",&secenek);

    switch(secenek){
        case 1:
            uyu(isim , duzey[secenek - 1]);
            break;
        case 2:
            yemekYe(isim , duzey[secenek - 1]);
            break;
        case 3:
            sev(isim , duzey[secenek - 1]);
            break;
        case 4:
            sosyalles(isim , duzey[secenek - 1]);
            break;
        case 5:
            saglik(isim , duzey[secenek - 1]);
            break;
        case 6:
            egit(isim , duzey[secenek - 1]);
            break;
        case 7:
            bakim(isim , duzey[secenek - 1]);
            break;
        case 8:
            taharetlen(isim , duzey[secenek - 1]);
            break;
        case 9:
            eglen(isim , duzey[secenek - 1]);
            break;
        case 10:
            ibadetEt(isim , duzey[secenek - 1]);
            break;
        case 11:
            sporYap(isim , duzey[secenek - 1]);
            break;
        case 12:
            mentalite(isim , duzey[secenek - 1]);
            break;
        default:
            printf("\n==>Uygulamadan cikildi.<==\n");
            return 0;

    }

    sleep(2);
    //return 0;
    }
}
