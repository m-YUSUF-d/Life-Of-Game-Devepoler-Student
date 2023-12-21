#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <windows.h>


void uyu(char *isim , int *duzey , int ilkSecim , int uykuSaati)    //uyku - 0
{
    int secenek , kontrol = 1;

    if(ilkSecim == 1)
    {
        if(duzey[0] >= 10) //uyku 10
        {
            printf("%s nin uykusu yok",isim);
            printProgressBar(duzey);
        }
        else    //uyku 10 degil
        {
            printf("\nKac saat uyuyacaksin ?\n");
            printf("1) 4 saat uyu\t2) 7 saat uyu\t3) 10 saat uyu\n");

            while(kontrol)  //saat secimi
            {
            printf("Sec : ");
            scanf("%d" , &secenek);

                if(secenek == 1)
                {
                    kontrol = 0;
                    return uyu(isim , duzey , 0 , 4);
                }
                else if(secenek == 2)
                {
                    kontrol = 0;
                    return uyu(isim , duzey , 0 , 7);
                }
                else if(secenek == 3)
                {
                    kontrol = 0;
                    return uyu(isim , duzey , 0 , 10);
                }
                else
                {
                    kontrol = 1;
                }
            }
        }
    }

    else    //ilkSecim = 0
    {
        if(uykuSaati == 0)
        {
            printProgressBar(duzey);
        }
        else
        {
            duzey[0] += 1;
            return uyu(isim , duzey , 0 , uykuSaati - 1);
        }
    }
}

void yemekYe(char *isim , int *duzey)   //tokluk - 1
{
    char metin[5];
    int secim;
    int adet;
    int kontrol = 1;

    if(duzey[1] >= 10)
    {
        printf("%s ac degil." , isim);
    }

    else
    {
        printf("1 - kola\t +3 tokluk\t -2 saglik\t -4 tuvalet\n2 - corba\t +3 tokluk\t +1 saglik\t -2 tuvalet\n3 - yogurt\t +2 tokluk\t +2 saglik\t -1 tuvalet\n4 - kofte\t +2 tokluk\t -1 saglik\t -1 tuvalet\n");

        while(kontrol)  //yemek secimini tekrarla
        {
        printf("Sec : ");
        scanf(" %s" , metin);
        secim = atoi(metin);

        if(secim > 4 || secim <= 0){
            kontrol = 1;
        }
        else{
            break;
        }
        }

        while(kontrol) //adet secimini tekrarla
        {
        printf("Yenilecek adet miktari, 1-3 arasindan seciniz : ");
        scanf(" %d" , &adet);

        if(adet < 1 || 3 < adet)
        {
            kontrol = 1;
        }
        else
        {
            switch(secim)
            {
            case 1: //kola degerleri
                duzey[1] += adet * 3;
                duzey[4] -= adet * 2;
                duzey[7] -= adet * 4;
                break;

            case 2: //corba degerleri
                duzey[1] += adet * 3;
                duzey[4] += adet * 1;
                duzey[7] -= adet * 2;
                break;

            case 3: //yogurt degerleri
                duzey[1] += adet * 2;
                duzey[4] += adet * 2;
                duzey[7] -= adet * 1;
                break;

            case 4: //kofte degerleri
                duzey[1] += adet * 2;
                duzey[4] += adet * 1;
                duzey[7] -= adet * 1;
                break;
            }

            kontrol = 0;
        }
        }
    }

    printProgressBar(duzey);
}

void sev(char *isim, int *duzey)    // sevgi fonksiyonu - 2
{
    int secenek;
    int kontrol = 1;

    printf("Sevmek ve sevilmek dunyadaki en degerli duygulardan biridir.\n");
    printf("1 - Aile Sevgisi\t2 - Sevdigine Duyulan Sevgi\t3 - Arkadaslara Duyulan Sevgi\n");

    while(kontrol == 1) // kod
    {
        printf("Sec: ");
        scanf("%d",&secenek);

        if(secenek == 1)// Aile Sevgisi
        {
            kontrol = 2;
            printf("\nAile dunyada hep yanimizda olan kisilerdir.\nAile her şeydir.");

            duzey[3] += 4;
            duzey[11] += 4;
        }
        else if(secenek == 2) // Sevdigine Duyulan Sevgi
        {
            kontrol = 2;
            printf("\nBu dunyada insanin hayat arkadasinin olmasi kadar guzel bir sey yok.\n");

            duzey[3] += 3;
            duzey[11] += 3;
        }
        else if(secenek == 3) // Arkadaslara duyulan sevgi
        {
            kontrol = 2;
            printf("\nBazen bazi seyleri ailene sevdigine bile anlatamazsin.\n");
            printf("Bu durumda devreye arkadaslarin gelir onlar hep yanindadir.\n");

            duzey[3] += 2;
            duzey[11] += 2;
        }
    }
    printProgressBar(duzey);
}

void sosyal(char *isim, int *duzey, int para)     //sosyalite fonksiyonu - 3
{
    int secenek;
    int kontrol = 1;

    if(duzey[3] >= 10)    //duzey 10 ise foksiyonu bitirir
    {
        printf("%s gezecek havasinda degil.");
    }
    else
    {
    printf("\n1 - Disari Aktiviteleri\t\t2 - Evde Aktiviteler\n");

    while(kontrol == 1) //yer sec
    {
    printf("Sosyallesmek icin hangi tur aktiviteler yapmak istersin : ");
    scanf("%d" , &secenek);

    if(secenek == 1)    //disari
    {
        kontrol = 2;
        printf("\n1 - Top Oynamak\t\t2 - Seyahat Etmek\t3 - Sinemaya Gitmek\n");

        while(kontrol == 2) //aktivite sec
        {
        printf("Yapmak istediginiz aktiviteyi secin : ");
        scanf("%d" , &secenek);

        if(secenek == 1)    //top
        {
            kontrol = 3;
            printf("\nArkadaslarinla (1) mi top oynamak istiyorsun yoksa yalniz (2) mi : \n");

            while(kontrol == 3)
            {
            printf("Sec : ");
            scanf("%d",&secenek);

            if(secenek == 1)    //arkadasla
            {
                kontrol = 4;

                printf("\nArkadaslarinla oynamak sana cok iyi gelecek.\n");
                printf("Cok egleneceginden eminim.\n");

                duzey[0] -= 1;
                duzey[1] -= 1;
                duzey[3] += 5;
                duzey[4] += 5;
                duzey[6] -= 1;
                duzey[7] -= 1;
                duzey[8] += 5;
                duzey[10] += 5;
                duzey[11] += 5;
            }
            else if(secenek == 2)   //yalnız
            {
                kontrol = 4;

                printf("\nYalniz oynamak arkadaslarinla oynadigin kadar keyif vermeyebilir.\n");
                printf("Ama yine de kafanin dagilacagindan eminim.\n");

                duzey[0] -= 1;
                duzey[1] -= 1;
                duzey[3] += 3;
                duzey[4] += 3;
                duzey[6] -= 1;
                duzey[7] -= 1;
                duzey[8] += 3;
                duzey[10] += 3;
                duzey[11] += 3;
            }

            }   // 3.derece while
        }

        else if(secenek == 2)   //seyahat
        {
            kontrol = 3;
            printf("\nYurt ici seyahati (1) mi, yurt disi seyahat (2) mi yoksa mahalle ici gezi (3) mi ?\n");

            while(kontrol == 3)     //secim
            {
            printf("Sec : ");
            scanf("%d",&secenek);

            if(secenek == 1)    //yurt içi
            {
                kontrol = 4;

                char bolge[7][10000] = {"Marmara\t" , "Ege Bolgesi" , "Akdeniz Bolgesi" , "Dogu Anadolu" , "Guneydogu Anadolu" , "Karadeniz\t" , "Ic Anadolu\t"};
                int maliyet[7] = {50000 , 30000 , 30000 , 10000 , 10000 , 20000 , 25000};

                for(int i = 0; i < strlen(bolge) - 1; i++)
                {
                    printf("%d - %s \t\t %d\n", i + 1 , bolge[i] , maliyet[i]);
                }
                printf("\n%d kadar paran var. Paran yetmeyen etkinlikler secilemeyecektir." , para);
                printf("\nMenuye donmek icin 8 e bas\n");

                while(kontrol == 4) //bolge sec
                {
                    printf("Sec : ");
                    scanf("%d" , &secenek);

                    if(secenek == 1 && maliyet[0] <= para)   //1
                    {
                        duzey[12] -= maliyet[0];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 2 && maliyet[1] <= para)  //2
                    {
                        duzey[12] -= maliyet[1];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 3 && maliyet[2] <= para)  //3
                    {
                        duzey[12] -= maliyet[2];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 4 && maliyet[3] <= para)  //4
                    {
                        duzey[12] -= maliyet[3];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 5 && maliyet[4] <= para)     //5
                    {
                        duzey[12] -= maliyet[4];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 6 && maliyet[5] <= para)   //6
                    {
                        duzey[12] -= maliyet[5];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 7 && maliyet[6] <= para)  //7
                    {
                        duzey[12] -= maliyet[6];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 8)   //menuye dön
                    {
                        printProgressBar(duzey);
                        return 0;
                    }
                }
            }

            else if(secenek == 2)   //yurt dışı
            {
               kontrol = 4;

                char bolge[7][10000] = {"Fransa" , "Italya" , "Otuken" , "Neistion" , "Misir" , "Kosova" , "Norvec"};
                int maliyet[7] = {200000 , 300000 , 175000 , 325000 , 125000 , 90000 , 100000};

                for(int i = 0; i < strlen(bolge) - 1; i++)
                {
                    printf("%d - %s \t\t %d\n", i + 1, bolge[i] , maliyet[i]);
                }
                printf("\n%d kadar paran var. Paran yetmeyen etkinlikler secilemeyecektir.\n" , para);
                printf("Menuye donmek icin 8 e bas\n");

                while(kontrol == 4)
                {
                    printf("Sec : ");
                    scanf("%d" , &secenek);

                    if(secenek == 1 && maliyet[0] <= para)   //1
                    {
                        duzey[12] -= maliyet[0];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 2 && maliyet[1] <= para)  //2
                    {
                        duzey[12] -= maliyet[1];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 3 && maliyet[2] <= para)  //3
                    {
                        duzey[12] -= maliyet[2];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 4 && maliyet[3] <= para)  //4
                    {
                        duzey[12] -= maliyet[3];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 5 && maliyet[4] <= para)     //5
                    {
                        duzey[12] -= maliyet[4];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 6 && maliyet[5] <= para)   //6
                    {
                        duzey[12] -= maliyet[5];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 7 && maliyet[6] <= para)  //7
                    {
                        duzey[12] -= maliyet[6];
                        kontrol = 5;

                        printf("** Tatilinizde Yapabileceginiz Aktiviteler **\n");
                        printf("1 - Sehir Gezintisi\t2 - Doga Yuruyusu\t3 - Sahilde Guneslenme\t4 - Otelde Oturma ve Dinlenme\n");

                        while(kontrol == 5)
                        {
                            printf("Yapmak istediginiz aktiviteyi seciniz: ");
                            scanf("%d" , &secenek);

                            switch(secenek)
                            {

                            case 1:
                                kontrol = 6;

                                printf("\nYeni yerler kesfetmek, sehirleri tanimak seni her yonden cok gelistirecektir.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[5] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 2:
                                kontrol = 6;

                                printf("\nDoga huzurdur.\n");
                                printf("Doga yuruyusu yapmak senin cigerlerini acacak ve sana cok iyi gelecek.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 3:
                                kontrol = 6;

                                printf("\nSahilde guneslenmek cildine ve bedenine cok iyi gelecektir.\n");
                                printf("Van Golu sahilini tercih etmen cok iyiydi.\n");
                                printf("Sahilde dolastiktan sonra Akdamar Adasini ziyaret edebilirsin.\n");

                                duzey[0] -= 1;
                                duzey[1] -= 1;
                                duzey[3] += 5;
                                duzey[4] += 5;
                                duzey[6] -= 1;
                                duzey[7] -= 1;
                                duzey[8] += 5;
                                duzey[10] += 5;
                                duzey[11] += 5;
                                break;

                            case 4:
                                kontrol = 6;

                                printf("\nTatilde otelde kalmak senin icin iyi olabilir.\n");
                                printf("Bu kadar calismanin uzerine dinlenmeyi hak ettin.\n");

                                duzey[3] += 3;
                                duzey[4] += 3;
                                duzey[6] -= 1;
                                duzey[8] += 3;
                                duzey[10] += 3;
                                duzey[11] += 3;
                                break;
                            }
                        }
                    }

                    else if(secenek == 8)   //menuye dön
                    {
                        printProgressBar(duzey);
                        return 0;
                    }
                }
            }

            else if(secenek == 3)   //mahalle
            {
                kontrol = 4;

                printf("\nUzak bir yerlere gitmek istemiyorsun herhalde.\nMahalledeki yerleri ziyaret etmeyi deneyebilirsin.\n");

                duzey[0] -= 1;
                duzey[1] -= 1;
                duzey[3] += 3;
                duzey[4] += 3;
                duzey[5] += 3;
                duzey[6] -= 1;
                duzey[7] -= 1;
                duzey[8] += 3;
                duzey[10] += 3;
                duzey[11] += 3;
            }

            } // 3.derece while
        }

        else if(secenek == 3)   //sinema
        {
            kontrol = 3;
            printf("\nSinemaya arkadaslarinla (1) mi sevdiginle (2) mi ailenle (3) mi yoksa tanimadigin biriyle (4) mi gideceksin ? : \n");

            while(kontrol == 3)
            {
            printf("Sec : ");
            scanf("%d",&secenek);

            if(secenek == 1)    //arkadasla
            {
                kontrol = 4;

                printf("\nArkadaslarinla sinemaya gitmekten cok keyif alacaksin.\n");
                printf("\t**Egleneceginizden suphem yok.**\n");

                duzey[0] -= 1;
                duzey[1] -= 1;
                duzey[2] += 3;
                duzey[3] += 3;
                duzey[4] += 3;
                duzey[6] -= 1;
                duzey[7] -= 1;
                duzey[8] += 3;
                duzey[10] += 3;
                duzey[11] += 3;
            }

            else if(secenek == 2)   //sevdiginle
            {
                kontrol = 4;

                printf("\nVAAAAOOOWWW NE ROMANTIK :))\n");
                printf("Seninle birlikte olan cok sansli. Kiskanilacak bir iliskiniz var.\n");
                printf("\t**Size iyi eglenceler.**\n");

                duzey[0] -= 1;
                duzey[1] -= 1;
                duzey[2] += 5;
                duzey[3] += 5;
                duzey[4] += 5;
                duzey[5] += 5;
                duzey[6] -= 1;
                duzey[7] -= 1;
                duzey[8] += 5;
                duzey[10] += 5;
                duzey[11] += 5;
            }

            else if(secenek == 3)   //ailenle
            {
                kontrol = 4;

                printf("\nAilenle sinemaya gitmek cok keyiflidir.\n");
                printf("Asiri duygusal ve eglenceli anlar seni bekliyor.\n");
                printf("\t** Iyi eglenceler. **\n");

                duzey[0] -= 1;
                duzey[1] -= 1;
                duzey[2] += 5;
                duzey[3] += 3;
                duzey[4] += 3;
                duzey[6] -= 1;
                duzey[7] -= 1;
                duzey[8] += 3;
                duzey[10] += 3;
                duzey[11] += 3;
            }

            else if(secenek == 4)   //yabanciyla
            {
                kontrol = 4;

                printf("\nSinemaya tanimadigin insanlarla gitmemelisin. Senin icin kotu seyler olabilir.\n");

                duzey[0] -= 1;
                duzey[1] -= 1;
                duzey[2] -= 5;
                duzey[3] -= 3;
                duzey[4] -= 3;
                duzey[6] -= 1;
                duzey[7] -= 1;
                duzey[8] -= 3;
                duzey[10] -= 3;
                duzey[11] -= 3;
            }

            }   //3. derece while
        }

        }   // 2. derece while
    }

    else if(secenek == 2)   //iceri
    {
        kontrol = 2;

        printf("\nEvde yapilabilecek cok da aktivite yok aslinda ama senin icin birkac tane aktivite buldum.\n");
        printf("1 - Sosyal medya\t2 - Arkadasi aramak\n");

        while(kontrol == 2)
        {
        printf("Hangisini yapmak istersin : ");
        scanf("%d",&secenek);

        if(secenek == 1)    //sosyal medya
        {
            kontrol = 3;

            printf("\nSosyal medyada kac saat zaman harcicaksin ?\n");
            printf("1)  0-2 saat arasi \t2)  2-5 saat arasi \t3)  5 saatten fazla\n");

            while(kontrol == 3)
            {
            printf("Sec : ");
            scanf("%d",&secenek);

            if(secenek == 1) //0-2 saat
            {
                kontrol = 4;

                printf("\nTebrikler sosyal medyada fazla zaman harcamanin zararli oldugunu anlamissin.\n");
                printf("0-2 saat sosyallesmen icin gercekten yeterli bir sure.\n");

                duzey[0] -= 1;
                duzey[1] -= 1;
                duzey[3] += 3;
                duzey[4] -= 1;
                duzey[7] -= 1;
                duzey[8] += 3;
                duzey[11] -= 1;
            }

            else if(secenek == 2)    //2-5 saat
            {
                kontrol = 4;

                printf("\nSosyal medyada biraz daha az zaman harcasan daha iyi olur.\n");

                duzey[0] -= 1;
                duzey[1] -= 1;
                duzey[3] += 3;
                duzey[4] -= 1;
                duzey[7] -= 1;
                duzey[8] += 3;
                duzey[11] -= 1;
            }

            else if(secenek == 3)  //+5 saat
            {
                kontrol = 4;

                printf("\nSosyal medyada cok vakit harciyorsun.\n");
                printf("Gozlerin bozulacak biraz dikkat et kendine :(\n");

                duzey[0] -= 1;
                duzey[1] -= 1;
                duzey[3] += 3;
                duzey[4] -= 1;
                duzey[7] -= 1;
                duzey[8] += 3;
                duzey[11] -= 1;
            }

            }   // 3. dereceden while
        }

        else if(secenek == 2)   //arkadasi aramak
        {
            kontrol = 3;

            printf("\nKotu gununde de iyi gununde de arkadasinin olmasi ne mutlu.\n");
            printf("Selam soyle arkadasina :)\n");

            duzey[0] -= 1;
            duzey[1] -= 1;
            duzey[2] += 5;
            duzey[3] += 3;
            duzey[8] += 3;
            duzey[11] += 5;
        }

        }   //2.derece
    }

    }   // 1. derece while

    }

    printProgressBar(duzey);
}

void saglik(char *isim , int *duzey)    //saglik fonksiyonu - 4
{
    int secim;
    int adet;
    int kontrol = 1;

    if(duzey[4] >= 10)
    {
        printf("%s gayet saglikli.",isim);
    }
    else
    {
        printf("\n1 - asi ol\t\t +5 saglik\t \n2 - hap al\t\t +1 saglik\n3 - C vitamini al\t +2 saglik\n");

        while(kontrol)  //saglik secimini tekrarla
        {
        printf("Sec : ");
        scanf(" %d" , &secim);

        if(secim > 3 || secim <= 0)
        {
            kontrol = 1;
        }
        else
        {
            switch(secim)
            {
            case 1: //aşı
                duzey[4] += 5;
                break;

            case 2: // hap
                do
                {
                    printf("Alinacak hap miktari, 1-3 arasindan seciniz : ");
                    scanf(" %d" , &adet);
                }
                while(adet > 3 || adet < 1);
                duzey[4] += adet * 1;
                break;

            case 3: //c vitamin
                do
                {
                    printf("Alinacak C vitamini miktari, 1-2 arasindan seciniz : ");
                    scanf(" %d" , &adet);
                }
                while(adet > 2 || adet < 1);
                duzey[4] += adet * 2;
                break;
            }
            kontrol = 0;
        }
        }
    }

    printProgressBar(duzey);
}

void egit(char *isim, int *duzey)   //egitim - 5
{
    int secenek;
    int kontrol = 1;

    if(duzey[5] >= 10)    //duzey 10 ise foksiyonu bitirir
    {
        printf("%s in egitime ihtiyaci yok." , isim);
    }
    else
    {
    printf("\nBir insanin yasi kac olursa olsun kendini egitmeye ve yeni seyler ogrenmeye devam etmeli.\n");
    printf("Kendini egitme istegin ve ogrenme arzun cok guzel.\n\n");
    printf("1 - Evde Ogrenme\t2 - Kursa/Okula Giderek Ogrenme\n");

    while(kontrol == 1) //secim
    {
        printf("Nerede yeni seyler ogrenmek istersin: ");
        scanf("%d" , &secenek);

        if(secenek == 1)    //evde
        {
            kontrol = 2;

            printf("\nGunde kac saatini kendine egitmeye harcamayi dusunuyorsun ? \n\n");
            printf("1) 0-2 saat calisma\t 2) 2-5 saat calisma\t 3) +5 saat calisma\n");

            while(kontrol == 2)  //saat sec
            {
                printf("Sec : ");
                scanf("%d"  , &secenek);

                if(secenek == 1)    // 0-2
                {
                    kontrol = 3;

                    printf("\n0-2 saat calismak yeterli olmayabilir daha fazla calismani oneririm.\n");

                    duzey[0] -= 1;
                    duzey[1] -= 1;
                    duzey[4] -= 1;
                    duzey[5] += 3;
                    duzey[6] -= 1;
                    duzey[7] -= 1;
                }

                else if(secenek == 2)    // 2-5
                {
                    kontrol = 3;

                    printf("\n2-5 saat calismak yeterli boyle devam edersen basariya ulasacagindan eminim :)\n");

                    duzey[0] -= 1;
                    duzey[1] -= 1;
                    duzey[4] -= 1;
                    duzey[5] += 5;
                    duzey[6] -= 1;
                    duzey[7] -= 1;
                    duzey[11] += 5;
                }

                else if(secenek == 3)  // +5
                {
                    kontrol = 3;

                    printf("\n+5 saat ders calisman sagligin icin baya zararli bu kadar ders calismamalisin.\n");

                    duzey[0] -= 1;
                    duzey[1] -= 1;
                    duzey[4] -= 1;
                    duzey[5] -= 1;
                    duzey[6] -= 1;
                    duzey[7] -= 1;
                    duzey[11] -= 1;
                }
            }
        }

        else if(secenek == 2)   //kursta
        {
            kontrol = 2;

            printf("\nEgitimli hocalardan egitim alman kendin calismandan daha faydali olacaktir.\n");
            printf("Ogrenmek ve ogretmek cok kutsaldir. Gelecegin icin hocalarin sana cok faydali olacaktir.\n");
            printf("Gunde kac saat okulda/kursta egitim goruyorsun ? \n\n");
            printf("1) 0-2 saat calisma\t 2) 2-5 saat calisma\t 3) +5 saat calisma\n");

            while(kontrol == 2) //saat sec
            {
                printf("Sec : ");
                scanf("%d" , &secenek);

                if(secenek == 1)    // 0-2
                {
                    kontrol = 3;

                    printf("\nOkula/Kursa gitmenin cok bi faydasi olacagini sanmmiyorum.\n");
                    printf("Evde kendin calisman senin icin daha faydali olabilir.\n");
                    printf("Hem boylece yolda zaman gecirmezsin.\n");

                    duzey[0] -= 1;
                    duzey[1] -= 1;
                    duzey[3] += 3;
                    duzey[5] += 3;
                    duzey[6] -= 1;
                    duzey[7] -= 1;
                    duzey[8] += 3;
                    duzey[10] += 3;
                }

                else if(secenek == 2)   // 2-5
                {
                    kontrol = 3;

                    printf("\nBu kadar egitim yeterli daha evde de calisirsin zaten.\n");
                    printf("Basariya ulasacagindan eminim.\n");

                    duzey[0] -= 1;
                    duzey[1] -= 1;
                    duzey[3] += 5;
                    duzey[5] += 5;
                    duzey[6] -= 1;
                    duzey[7] -= 1;
                    duzey[8] += 5;
                    duzey[10] += 5;
                    duzey[11] += 5;
                }

                else if(secenek == 3)   // +5
                {
                    kontrol = 3;

                    printf("\nBu kadar calismak sagligin icin zararli.\n");
                    printf("Kafan agrir ve evde calismaya vaktin olmaz.\n");

                    duzey[0] -= 1;
                    duzey[1] -= 1;
                    duzey[3] += 3;
                    duzey[4] -= 1;
                    duzey[5] += 3;
                    duzey[6] -= 1;
                    duzey[7] -= 1;
                    duzey[8] += 3;
                    duzey[10] += 3;
                    duzey[11] -= 1;
                }

            }
        }

    }

}

    printProgressBar(duzey);
}

void bakim(char *isim , int *duzey)   //hijyen - 6
{
    int secenek;
    int kontrol = 1;

    if(duzey[6] >= 10)
    {
        printf("%s zaten bakimli, bakima ihtiyaci  yok" , isim);
    }

    else
    {
        printf("\nHangisini kullanacaksın ?\n");
        printf("1 - Dis fircalamak\t +4 hijyen \n2 - Tirnak kesmek\t +3 hijyen \n3 - Banyo yapmak\t +8 hijyen \n4 - Tiras olmak\t\t +6 hijyen \n");

        while(kontrol == 1)
        {
            printf("Sec : ");
            scanf("%d" , &secenek);

            switch(secenek)
            {
                case 1: //dis
                    kontrol = 2;

                    duzey[6] += 4;
                    break;

                case 2: //tirnak
                    kontrol = 2;

                    duzey[6] += 3;
                    break;

                case 3: //banyo
                    kontrol = 2;

                    duzey[6] += 8;
                    break;

                case 4: //banyo
                    kontrol = 2;

                    duzey[6] += 6;
                    break;
            }
        }
    }

    printProgressBar(duzey);
}

void tuvalet(char *isim , int *duzey)  //tuvalet - 7
{
    int secenek;
    int kontrol = 1;

    if(duzey[7] >= 10)
    {
        printf("%s' in tuvaleti yok" , isim);
    }
    else
    {
        printf("\nHangisini kullanacaksin ?\n");
        printf("1 - Alaturka\t -3 hijyen \t +10 tuvalet \n2 - Alafranga\t -5 hijyen \t +9 tuvalet \n3 - Pisuvar\t -6 hijyen \t +7 tuvalet \n");

        while(kontrol == 1)
        {
            printf("Sec : ");
            scanf("%d" , &secenek);

            switch(secenek)
            {
                case 1: //alaturka degerleri
                    kontrol = 2;

                    duzey[6] -= 4;
                    duzey[7] += 10;
                    break;

                case 2: //alafranga degerleri
                    kontrol = 2;

                    duzey[6] -= 5;
                    duzey[7] += 9;
                    break;

                case 3: //pisuvar degerleri
                    kontrol = 2;

                    duzey[6] -= 6;
                    duzey[7] += 7;
                    break;
            }
        }
    }

    printProgressBar(duzey);
}

void eglen(char *isim , int *duzey) // eglen - 8
{
    int secenek;
    int kontrol = 1;

    if(duzey[8] >= 10)
    {
        printf("Eglenmeye vaktim yok");
    }
    else
    {
        printf("Eglenmek de yasamin onemli bir parcasidir.");
        printf("1 - Bilgisayar oyunu oyna\t2 - Tahta oyunları oyna\t3 - Kardesinle saklambac oyna\n");

        while(kontrol == 1) // kod
        {
            printf("Sec: ");
            scanf("%d",&secenek);

            if(secenek == 1)// pc oyunu
            {
                kontrol = 2;
                printf("\nSana iyi oyunlar.Dikkat et fazla zaman gecirip gozlerini bozma.");

                duzey[3] -= 1;
                duzey[4] -= 1;
                duzey[5] -= 2;
                duzey[8] += 5;
                duzey[11] += 3;
            }

            else if(secenek == 2) // Tahta oyunları
            {
                kontrol = 2;
                printf("\nStratejik dusunebiliyorsan ozellikle satranc oynamanı tavsiye ederim.\n");

                duzey[5] += 1;
                duzey[8] += 4;
                duzey[11] += 3;
            }

            else if(secenek == 3) // Arkadaslara duyulan sevgi
            {
                kontrol = 2;
                printf("\nKardesin senin diger yarindir onla da vakit gecirmeyi unutma :)\n");

                duzey[4] += 1;
                duzey[8] += 6;
                duzey[11] += 3;
            }
        }
    }

    printProgressBar(duzey);
}

void ibadetEt(char *isim, int *duzey) // ibadet fonksiyonu - 9
{
    int secenek;
    int kontrol = 1;
    char *dinler[1000] = {"1 - Islam","2 - Hristiyanlik","3 - Yahudilik","4 - Budizm"};

    if(duzey[5] >= 10)
    {
        printf("%s in suan da ibadet ihtiyaci yok." , isim);
    }
    else
    {
        printf("\n");
        for(int i = 0; i <= strlen(dinler); i++)
        {
            printf("%s \t",dinler[i]);
        }
        printf("\n");

        while(kontrol == 1)
        {
            printf("Hangi dine mensubsun: ");
            scanf("%d",&secenek);

            switch(secenek)
            {
            case 1:
                kontrol = 2;
                printf("\nIbadetlerini yerine getirmen manevi yonden sana cok iyi gelecektir.\n");
                printf("Kendini cok iyi hissedeceginden eminim.\n");
                printf("Allah senden razi olsun guzel insan :)\n");

                duzey[0] += 5;
                duzey[2] += 5;
                duzey[3] += 3;
                duzey[4] += 5;
                duzey[5] += 5;
                duzey[9] += 5;
                duzey[10] += 5;
                duzey[11] += 5;
                break;

            case 2:
                kontrol = 2;
                printf("\nPazar gunu yapilan ayine katilman dinine bagliligini gosterir. O ayine mutlaka katil.\n");

                duzey[0] += 3;
                duzey[2] += 3;
                duzey[3] += 3;
                duzey[4] += 3;
                duzey[5] += 3;
                duzey[9] += 3;
                duzey[10] += 3;
                duzey[11] += 3;
                break;

            case 3:
                kontrol = 2;
                printf("\nSabat gunu dinlenmeyi ve dua etmeyi unutma.");

                duzey[0] += 3;
                duzey[2] += 3;
                duzey[3] += 3;
                duzey[4] += 3;
                duzey[5] += 3;
                duzey[9] += 3;
                duzey[10] += 3;
                duzey[11] += 3;
                break;

            case 4:
                kontrol = 2;
                printf("\nMeditasyon yapman sana cok iyi gelir.");

                duzey[0] += 3;
                duzey[2] += 3;
                duzey[3] += 3;
                duzey[4] += 3;
                duzey[5] += 3;
                duzey[9] += 3;
                duzey[10] += 3;
                duzey[11] += 3;
                break;
            }
        }

    }

    printProgressBar(duzey);
}

void sporYap(char *isim, int *duzey)    // spor fonksiyonu - 10
{
    int secenek;
    int kontrol = 1;

    printf("\nDuzenli spor yapmak insan sagligi icin cok onemlidir.\n");
    printf("1 - Evde Spor Yapmak\t2 - GYM'de Spor Yapmak\n");

    while(kontrol == 1)
    {
        printf("Sporunu nerede yapmak istersin: ");
        scanf("%d" , &secenek);

        if(secenek == 1)    //evde
        {
            kontrol = 2;

            printf("\nEvde spor yapmak gym de spor yapmak kadar etkili olmayabilir.\n");
            printf("Ama sana faydali olacagindan eminim.\n");
            printf("Gunde kac saat spor yapicaksin ? \n");
            printf("1) 0-2 saat \t 2) 2-5 saat \t 3) +5 saat\n");

            while(kontrol == 2)
            {
                printf("Sec :");
                scanf("%d" , &secenek);

                if(secenek == 1)   // 0-2
                {
                    kontrol =3;

                    printf("\n0-2 saat evde spor yapmak icin yeterli bir sure fazlasi senin icin zarar teskil edebilir.\n");

                    duzey[0] -= 1;
                    duzey[1] -= 1;
                    duzey[4] += 3;
                    duzey[6] -= 1;
                    duzey[7] -= 1;
                    duzey[10] += 3;
                    duzey[11] += 3;
                }

                else if(secenek == 2)  // 2-5
                {
                    kontrol = 3;

                    printf("\n2-5 saat spor yapmak icin biraz fazla, set aralarinda dinlenmeyi unutma.\n");

                    duzey[0] -= 1;
                    duzey[1] -= 1;
                    duzey[4] += 3;
                    duzey[6] -= 1;
                    duzey[7] -= 1;
                    duzey[10] += 3;
                    duzey[11] += 3;
                }

                else if(secenek == 3)  // +5
                {
                    kontrol = 3;

                    printf("\n+5 saat spor icin fazla bedenini cok yoruyorsun.\n");
                    printf("Spor saatlerini azaltmalisin. :)\n");

                    duzey[0] -= 1;
                    duzey[1] -= 1;
                    duzey[4] -= 1;
                    duzey[6] -= 1;
                    duzey[7] -= 1;
                    duzey[10] += 3;
                    duzey[11] += 3;
                }
            }
        }

        else if(secenek == 2)   //GYM
        {
            kontrol = 2;

            printf("\nGYM'de profesyonel bir hoca tarafindan spor yapman sana cok fayda saglar.\n");
            printf("Gunde kac saat spor yapicaksin: \n");            printf("1) 0-2 saat \t 2) 2-5 saat \t 3) +5 saat\n");

            while(kontrol == 2)
            {
                printf("Sec : ");
                scanf("%d",&secenek);

                if(secenek == 1)    // 0-2
                {
                    kontrol == 3;

                    printf("\n0-2 saat evde spor yapmak icin yeterli bir sure fazlasi senin icin zarar teskil edebilir.\n");

                    duzey[0] -= 1;
                    duzey[1] -= 1;
                    duzey[3] += 5;
                    duzey[4] += 5;
                    duzey[6] -= 1;
                    duzey[7] -= 1;
                    duzey[10] += 5;
                    duzey[11] += 5;
                }

                else if(secenek == 2)   //2-5
                {
                    kontrol = 3;

                    printf("\n2-5 saat spor yapmak icin biraz fazla. Set aralarinda dinlenmeyi unutma.\n");

                    duzey[0] -= 1;
                    duzey[1] -= 1;
                    duzey[3] += 5;
                    duzey[4] += 5;
                    duzey[6] -= 1;
                    duzey[7] -= 1;
                    duzey[10] += 5;
                    duzey[11] += 5;
                }

                else if(secenek == 3)  // +5
                {
                    kontrol = 3;

                    printf("\n+5 saat spor icin fazla bedenini cok yoruyorsun.\n");
                    printf("Spor saatlerini azaltmalisin. :)\n");

                    duzey[0] -= 1;
                    duzey[1] -= 1;
                    duzey[3] += 5;
                    duzey[4] -= 1;
                    duzey[6] -= 1;
                    duzey[7] -= 1;
                    duzey[10] += 3;
                    duzey[11] += 3;
                }

            }
        }
    }

    printProgressBar(duzey);
}

void mentalite(char *isim , int *duzey) // mental - 11
{
    int secenek;
    int kontrol = 1;

    if(duzey[11] >= 10)
    {
        printf("%s in mental sagligi yerinde" , isim);
    }
    else
    {
        printf("\n1 - Muzik dinlemek\t 2 - Kitap okumak\t 3 - Evcil hayvaninla vakit gecirmek\n");

        while(kontrol == 1)
        {
            printf("Sec : ");
            scanf("%d" , &secenek);

            if(secenek == 1)    //müzik
            {
                kontrol = 2;

                printf("\nMuzik ruhun gidasidir.");

                duzey[8] += 2;
                duzey[11] += 5;
            }
            else if(secenek == 2)   //kitap
            {
                kontrol = 2;

                printf("\nKitap okuyan bireyler genel kultur sahibi olurlar.");

                duzey[5] += 3;
                duzey[11] += 4;
            }
            else if(secenek == 3)   //hayvan
            {
                kontrol = 2;

                printf("\nEvcil hayvan beslemek mental olarak seni duyarli bir birey yapacaktir.");

                duzey[6] -= 2;
                duzey[8] += 2;
                duzey[11] += 3;
            }

        }
    }

    printProgressBar(duzey);
}

void calis(char *isim , int *duzey) //para - 12
{
    int secenek , kontrol = 1;

    printf("Hangi iste calisacaksin ?\n");
    printf("1 - Kod yazip satis yap \t2 - Part time iste calis \t3 - Aileden harclik iste\n");

    while(kontrol == 1) //secim
    {
        printf("Sec : ");
        scanf("%d" , &secenek);

        if(secenek == 1)    //Kod
        {
            kontrol = 2;
            int x = rand()%4;

            if(x == 0)  //başarısız
            {
                int para = 2000*(rand()%3 + 1);
                printf("\nSatis basarisiz, Sirkete %d kadar borclanildi ve odendi." , para );

                duzey[0] -= 1;
                duzey[3] -= 2;
                duzey[11] -= 2;
                duzey[12] -= para;
            }
            else    //başarılı
            {
                int para = 1000*(rand()%3 + 2);
                printf("\nSatis basarili : +%d para" , para);

                duzey[0] -= 1;
                duzey[3] -= 1;
                duzey[12] += para;
            }
        }

        else if(secenek == 2)   //part time
        {
            kontrol = 2;
            int x = rand()%3;

            if(x == 0)      //başarısız
            {
                int y = rand()%3 + 2;
                int para = 2000*(rand()%3 + 3);

                printf("Beklenmedik bir is kazasi yasadin : -%d saglik , -2 tokluk , -2 mental - +%d para." , y , para);

                duzey[0] -= 2;
                duzey[1] -= 2;
                duzey[4] -= y;
                duzey[7] -= 2;
                duzey[11] -= 2;
                duzey[12] += para;
            }
            else    //başarılı
            {
                int para = 2000*(rand()%3 + 2);

                printf("Isi basarili bir sekilde tamamladin : -2 uyku , -3 tokluk , +%d para." , para);

                duzey[0] -= 2;
                duzey[1] -= 3;
                duzey[7] -= 2;
                duzey[12] += para;
            }
        }

        else if(secenek == 3)   //harclik
        {
            kontrol = 2;
            int x = rand()%2;

            if(x == 0)  //başarısız
            {
                printf("Ailen sana para vermedi ve baban seni dovdu : -1 saglik , -2 mental");

                duzey[4] -= 1;
                duzey[11] -= 2;
            }
            else    //başarılı
            {
                int para = 100*(rand()%3 + 1);

                printf("Ailen sana para verdi : +%d" , para);

                duzey[12] += para;
            }
        }
    }

    printProgressBar(duzey);
}


void printProgressBar(int *duzey) //show the loading progress
{
    int num;
    printf("\n\n");

    for (num = 0; num <= 100; num += 5)
    {
        int num2;

        printf("\r[");

        int completeBlocks = num / 5;

        for (num2 = 0; num2 < completeBlocks; num2++)
        {
            printf("="); // Completed blocks
        }

        for (num2 = completeBlocks ; num2 < 20 ; num2++)
        {
            printf(" ");
        }

        printf("] %d%%", num);
        fflush(stdout);
        Sleep(25);
    }
    printf(" Islem tamamlandi menuye donuluyor...\n");


    if(duzey[0] <= 0)   //uyku
    {
        duzey[0] = 0;
        duzey[4] -= 1;
        printf("\n**Yetersiz uyku saglik degerini dusurur : -1 saglik");
    }
    if(duzey[1] <= 0)   //tokluk
    {
        duzey[1] = 0;
        duzey[4] -= 1;
        printf("\n**Ac durmak saglik degerini dusurur : -1 saglik");
    }
    if(duzey[2] <= 0)   //sevgi
    {
        duzey[2] = 0;
        duzey[11] -= 1;
        printf("\n**Sevgi yoksullugu mental degerini dusurur : -1 mental");
    }
    if(duzey[3] <= 0)   //sosyal
    {
        duzey[3] = 0;
        duzey[11] -= 1;
        printf("\n**Asosyal olmak mental degerini dusurur : -1 mental");
    }
    if(duzey[6] <= 0)   //bakim
    {
        duzey[6] = 0;
        duzey[4] -= 1;
        printf("\n**Pasakli olmak saglik degerini dusurur : -1 saglik");
    }
    if(duzey[7] <= 0)   //tuvalet
    {
        duzey[7] = 0;
        duzey[6] -= 1;
        duzey[11] -= 3;
        printf("\n**Tuvatetini altina yapmak (HAHAHA!) hijyen degerini dusurur : -1 hijyen -3 mental");
    }
    if(duzey[8] <= 0)   //eglen
    {
        duzey[8] = 0;
        duzey[11] -= 1;
        printf("\n**Mutsuz olmak mental degerini dusurur : -1 mental");
    }
    if(duzey[9] <= 0)   //ibadet
    {
        duzey[9] = 0;
        duzey[11] -= 2;
        printf("\n**Ibadetlerini yapmazsan mental degerin duser : -2 mental");
    }
    if(duzey[10] <= 0)   //spor
    {
        duzey[10] = 0;
        duzey[4] -= 1;
        printf("\n**Sporsuz bir yasam saglik degerini etkiler : -1 saglik");
    }
    if(duzey[11] <= 0)   //ibadet
    {
        duzey[11] = 0;
        duzey[4] -= 2;
        printf("\n**Mentalin duserse saglik degerini etkiler : -2 saglik");
    }
}


int main()
{
    printf("             ,----------------,              ,---------,\n        ,-----------------------,          ,\"        ,\"|\n      ,\"                      ,\"|        ,\"        ,\"  |\n     +-----------------------+  |      ,\"        ,\"    |\n     |  .-----------------.  |  |     +---------+      |\n     |  |                 |  |  |     | -==----'|      |\n     |  |     Life of     |  |  |     |         |      |\n     |  |  Game Developer |  |  |/----|`---=    |      |\n     |  |  C:\\>_          |  |  |   ,/|==== ooo |      ;\n     |  |                 |  |  |  // |(((( [==]|    ,\"\n     |  `-----------------'  |,\" .;'| |((((     |  ,\"\n     +-----------------------+  ;;  | |         |,\"\n        /_)______________(_/  //'   | +---------+\n   ___________________________/___  `,\n  /  oooooooooooooooo  .o.  oooo /,   \\,\"-----------,\n / ==ooooooooooooooo==.o.  ooo= //   ,`\\--{))     ,\"\n/_==__==========__==_ooo__ooo=_/'   /___________,\" \n`-----------------------------'\n");

    int i , secenek;
    char isim[100];
    char initalText[] = "\nMerhaba benim ismim .23 yasinda Bogazici Universitesi'nde Bilgisayar Muhendisligi okuyorum.\nKitap okumaktan, film izlemekten, yeni seyler ogrenip arastirmaktan keyif duyarim.\nIlgi alanim ise oyun sektorudur. Kucuklugumden beri oyun oynamayi seven bir insanim.\nBu sevgim beni bilgisayar muhendisligini kazanmamda ve bu yone yonlenmem de buyuk pay sahibi oldu.\nUmarim ileride bu yonde calismalar yapabilirim. Haydi seninle birkac aktivite yapalim.\n\n";
    char *ihtiyaclar[13] = {"Uyku","Tokluk","Sevgi","Sosyal","Saglik","Egitim","Hijyen","Tuvalet","Eglence","Ibadet","Spor","Mental","Para"};
    int duzey[13] = {5 , 5 , 5 , 5 , 5 , 0 , 5 , 5 , 5 , 5 , 5 , 5 , 5000};

    printf("Karakterinizin ismini girerek uygulamayi baslatabilirsiniz : \n");
    gets(isim);


    for(int j = 0 ; initalText[j] != '\0' ; j++)
    {
        printf("%c" , initalText[j]);
        Sleep(5);

        if(j == 20)
        {
            for(int a = 0 ; isim[a] != '\0' ; a++)
            {
                printf("%c" , isim[a]);
                Sleep(5);
            }
        }
    }

    printf("Hazir misin o zaman baslayalim");
    for(int b = 0 ; b < 3 ; b++)
    {
        printf(".");
        Sleep(1000);
    }


    while( duzey[4] > 0 )  //fonksiyon secme dongusu
    {
    system("cls");

    printf("\n\n\t===>%s'nin Hayati<===\t\n",isim);
    printf("**********************************************\n");

    printf("Ihtiyaclar\t\tDuzeyler\n\n");

    for(i = 0; i < sizeof(ihtiyaclar) / sizeof(ihtiyaclar[0]) - 1; i++) //ihtiyac - duzey listesini goster
    {
        if(duzey[i] > 10)
            duzey[i] = 10;

        printf("%s\t\t\t%d\n",ihtiyaclar[i],duzey[i]);
    }
    printf("%s\t\t\t%d\n",ihtiyaclar[12],duzey[12]);

    printf("\n");
    printf("\n** Arttirilmaya Ihtiyaci olan Ihtiyaclar **\n\n");

    for(i = 0; i < sizeof(duzey)/sizeof(duzey[0]); i++) //duzeyi dusuk olan ihtiyaclari goster
    {
        if(duzey[i] == 0)
        {
            printf("%s\n",ihtiyaclar[i]);
        }
    }
    printf("\n");


    printf("\nArttirmak istediginiz ihtiyac hangisi ?\n");

    for(i = 0; i < sizeof(ihtiyaclar)/sizeof(ihtiyaclar[0]); i++)   //ihtiyac sec
    {
        printf("%d. %s\n",i+1,ihtiyaclar[i]);
    }

    printf("\n13 den buyuk bir degere veya 1 den kucuk bir degere basarsaniz uygulamadan cikilacaktir.\n");
    printf("Lutfen arttirmak istediginz ihtiyac icin yandaki numarasini giriniz : ");
    scanf(" %d" , &secenek);

    switch(secenek) //fonksiyon sec
    {
        case 1:
            uyu(isim , duzey , 1 , 0);
            break;
        case 2:
            yemekYe(isim , duzey);
            break;
        case 3:
            sev(isim , duzey);
            break;
        case 4:
            sosyal(isim , duzey , duzey[12]);
            break;
        case 5:
            saglik(isim , duzey);
            break;
        case 6:
            egit(isim , duzey);
            break;
        case 7:
            bakim(isim , duzey);
            break;
        case 8:
            tuvalet(isim , duzey);
            break;
        case 9:
            eglen(isim , duzey);
            break;
        case 10:
            ibadetEt(isim , duzey);
            break;
        case 11:
            sporYap(isim , duzey);
            break;
        case 12:
            mentalite(isim , duzey);
            break;
        case 13:
            calis(isim , duzey);
            break;
        default:
            printf("\n==>Uygulamadan cikildi.<==\n");
            return 0;
            break;

    }
    sleep(3);
    }
    printf("\n\nxxxxx Saglik 0 oldu karakteriniz oldu. xxxxx\n");
    printf("              _\n             | |\n             | |===( )   //////\n             |_|   |||  | o o|\n                    ||| ( c  )                  ____\n                     ||| \\= /                  ||   \\_\n                      ||||||                   ||     |\n                      ||||||                ...||__/|-\"\n                      ||||||             __|________|__\n                        |||             |______________|\n                        |||             || ||      || ||\n                        |||             || ||      || ||\n------------------------|||-------------||-||------||-||-------\n                        |__>            || ||      || ||\n");

    sleep(25);
}
