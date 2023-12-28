#include <stdio.h>
#define SIFRE 1905

float toplama(float sayi1,float sayi2)
{
  float result = sayi1 + sayi2;
  return result;
}
float cikarma(float sayi1,float sayi2)
{
  float result = sayi1 - sayi2;
  return result;
}
float dolarToTl(float sayi)
{
  float dolarKuru = 29.40;
  float sonuc = sayi * dolarKuru;
  return sonuc;
}
float euroToTl(float sayi)
{
  float euroKuru = 32.65;
  float sonuc = sayi * euroKuru;
  return sonuc;
}
float tlToDolar(float sayi)
{
  float dolarKuru = 29.40;
  float sonuc = sayi / dolarKuru;
  return sonuc;
}
float tlToEuro(float sayi)
{
  float euroKuru = 32.65;
  float sonuc = sayi / euroKuru;
  return sonuc;
}

int main()
{
 int girilenSifre,sifreSayac = 0;
 float paraCekme,paraYatirma;
 float bakiye = 0;
 float ekHesapLimit = 3000,ekHesap = 3000;
 char paraYatirmaSecme;
 char ekHesapKullanma,bakiyeSorgulama;
 char havaleIsim[50];
 char havaleIban[50];
 float havaleParasi;
 float dovizParasi;
 float dolarDovizPara;
 float euroDovizPara;
 float dolarBakiye = 0;
 float euroBakiye = 0;
 char hangiHesap;
 printf("\n\t\tBANKAMIZA HOŞGELDİNİZ\n");

  while(sifreSayac < 3)
  {
    printf("Lütfen şifrenizi giriniz (3 defa yanlış şifre girerseniz hesabınız bloke edilecektir):");
    scanf("%d",&girilenSifre);
    if (girilenSifre == SIFRE)
    {
        printf("1-Para Yatırma\n2-Para Çekme\n3-Bakiye Sorgulama\n4-Ek Hesap\n5-Havale\n6-Döviz İşlemleri\n7-Çıkış\n");
        while(1)
        {
        printf("\nHangi işlemi yapmak istiyorsunuz:");
        int islem;
        scanf("%d",&islem);
        float sonuc;
          switch(islem)
            {
              case 1:
                printf("Hangi hesaba para yatırmak istiyorsunuz? (TL: 'T'/Dolar: 'D'/Euro: 'E'):");
                getchar();
                scanf("%c",&hangiHesap);
                if(hangiHesap == 'T')
                {
                  printf("Ne kadar para yatırmak istiyorsunuz? (Eğer ek hesabınız limitinden düşük ise ilk olarak ona yükleme yapılacaktır):");
                  scanf("%f",&paraYatirma);
                  if (ekHesap < ekHesapLimit)
                  {
                    sonuc = cikarma(ekHesapLimit,ekHesap);
                    ekHesap = toplama(sonuc,ekHesap);
                    bakiye = toplama(bakiye,cikarma(paraYatirma,sonuc));
                    printf("İşlem başarıyla gerçekleştirildi.");
                  }
                  else
                  {
                    bakiye = toplama(paraYatirma,bakiye);
                    printf("Para yatırma işlemi başarılı.");
                  }
                }
                else if (hangiHesap == 'D')
                {
                  printf("Dolar hesabınıza ne kadar para yatırmak istersiniz:");
                  scanf("%f",&paraYatirma);
                  dolarBakiye = toplama(dolarBakiye,paraYatirma);
                  printf("İşlem başarıyla gerçekleştirildi.");
                }
                else if (hangiHesap == 'E')
                {
                  printf("Euro hesabınıza ne kadar para yatırmak istersiniz:");
                  scanf("%f",&paraYatirma);
                  euroBakiye = toplama(euroBakiye,paraYatirma);
                  printf("İşlem başarılı bir şekilde gerçekleştirildi");
                }
                else
                  printf("Lütfen sizden istenilen değerlerden birini giriniz.");
                break;

              case 2:
                printf("Hangi hesabınızdan para çekmek istiyorsunuz? (Tl: 'T'/Dolar: 'D'/Euro: 'E'):");
                getchar();
                scanf("%c",&hangiHesap);
                if (hangiHesap == 'T')
                {
                  printf("TL hesabınızdan ne kadar para çekmek istiyorsunuz\n(Normal Hesap Bakiyeniz: %.1f / Ek Hesap Bakiyeniz: %.1f):",bakiye,ekHesap);
                  scanf("%f",&paraCekme);
                  getchar();
                  if ((paraCekme > bakiye) && (paraCekme <= toplama(ekHesap,bakiye)))
                  {
                    printf("Para çekmek için yeterli bakiyeniz bulunmamaktadır. Ek hesap bakiyesi kullanılsın mı(e/h):");
                    scanf("%c",&ekHesapKullanma);
                    getchar();
                    if (ekHesapKullanma == 'e')
                    {
                      ekHesap = cikarma(toplama(bakiye,ekHesap),paraCekme);
                      bakiye = 0;
                      printf("İşlem başarıyla gerçekleştirildi.");
                    }
                    else if (ekHesapKullanma == 'h')
                      printf("Para çekme işlemi gerçekleştirilemedi.");
                  }
                  else if (paraCekme > toplama(bakiye,ekHesap) + 1)
                    printf("Ek hesap ve bakiyenizin toplamından fazla para çekmek istiyorsunuz. Bu sebeple işlem gerçekleştirilemedi.");
                  else
                  {
                    bakiye = cikarma(bakiye,paraCekme);
                    printf("İşlem başarılı.");
                  }
                }
                else if (hangiHesap == 'D')
                {
                  printf("Dolar hesabınızdan ne kadar para çekmek istiyorsunuz:");
                  scanf("%f",&paraCekme);
                  if(paraCekme > dolarBakiye)
                    printf("Yeterli bakiyeniz yok işlem başarısız oldu. Lütfen daha sonra tekrar deneyiniz");
                  else
                  {
                    dolarBakiye = cikarma(dolarBakiye,paraCekme);
                    printf("İşlem başarılı bir şekilde gerçekleştirildi");
                  }
                }
                else if (hangiHesap == 'E')
                {
                  printf("Euro hesabınızdan ne kadar para çekmek istiyorsunuz:");
                  scanf("%f",&paraCekme);
                  if(paraCekme > euroBakiye)
                    printf("Yeterli bakiyeniz yok işlem başarısız oldu. Lütfen daha sonra tekrar deneyiniz");
                  else
                  {
                    dolarBakiye = cikarma(euroBakiye,paraCekme);
                    printf("İşlem başarılı bir şekilde gerçekleştirildi");
                  }
                }
                else
                    printf("Lütfen sizden istenilen değerlerden birini giriniz.");
                break;

              case 3:
                printf("Tl Bakiyeniz:%.1f ₺\n",bakiye);
                printf("Dolar Bakiyeniz:%.1f $\n",dolarBakiye);
                printf("Euro Bakiyeniz:%.1f €",euroBakiye);
                break;

              case 4:
                printf("Ek hesap için hangi işlemi yapmak istersiniz?\n1-Ek hesap bakiyesi sorgulama\n2-Ek hesap limit sorgulama\n3-Ek hesap limit arttırma");
                printf("\n4-Üst menüye dönme");
                      int islem2;
                      while(1)
                      {
                        float yeniLimit;
                        printf("\nEk hesap için hangi işlemi yapmak istiyorsunuz:");
                        scanf("%d",&islem2);
                        switch(islem2){
                          case 1:
                            printf("Ek Hesap Bakiyesi: %.1f",ekHesap);
                            break;
                  
                          case 2:
                            printf("Ek Hesap Limitiniz: %.1f",ekHesapLimit);
                            break;
                  
                          case 3:
                            printf("Ek hesap limitinizi ne kadar yapmak istersiniz:");
                            scanf("%f",&yeniLimit);
                            ekHesapLimit = yeniLimit;
                            printf("İşlem başarıyla gerçekleştirildi. Yeni ek hesap limitiniz: %.1f",yeniLimit);
                            break;
                  
                          case 4:
                            printf("Üst menüye dönülüyor");
                            break;
                  
                          default:
                            printf("Lütfen geçerli bir işlem giriniz.");
                            break;
                        }
                          if (islem2 == 4)
                            break;
                      }
                      break;
              case 5:
                  printf("Havale yapmak istediğiniz kişinin adını giriniz:");
                  getchar();
                  scanf("%[^\n]",havaleIsim);
                  while (getchar() != '\n');

                  printf("Havale yapmak istediğiniz kişinin IBAN numarasını giriniz:");
                  scanf("%[^\n]",havaleIban);

                  printf("%s adlı kişiye kaç TL havale yapmak istiyorsunuz:",havaleIsim);
                  scanf("%f",&havaleParasi);
                  if (havaleParasi <= bakiye)
                  {
                    bakiye = cikarma(bakiye,havaleParasi);
                    printf("İşlem başarılı bir şekilde gerçekleştirildi.");
                  }
                  else
                    printf("Bakiyenizin üstünde bir miktarda para gönderemezsiniz.");
                  break;
                    
              case 6:
                printf("\n1-Dolar\n2-Euro\n3-Üst menüye \n");
                    int islem3;
                    char doviz_islem;
                    while(1)
                    {
                        printf("Döviz için hangi işlemi yapmak istiyorsunuz:");
                        scanf("%d",&islem3);
                        switch(islem3){
                          case 1:
                            printf("Hangi işlemi yapmak istiyorsunuz? (Dolar'dan Tl'ye: 'D'/Tl'den dolar'a: 'T'):");
                            getchar();
                            scanf("%c",&doviz_islem);
                            if (doviz_islem == 'T')
                            {
                              if (bakiye > 0)
                              {
                                printf("\nNe kadar miktarı dolara çevirmek istersiniz? (Şuan ki ₺ bakiyeniz:%.1f):",bakiye);
                                scanf("%f",&dovizParasi);
                                if (dovizParasi <= bakiye)
                                {
                                  bakiye = cikarma(bakiye,dovizParasi);
                                  dolarBakiye = tlToDolar(dovizParasi);
                                  printf("İşlem başarılı bir şekilde gerçekleştirildi.\n");
                                }
                                else
                                  printf("\nBakiyenizin üstünde bir miktar para dönüştüremezsiniz\n");
                              }
                              else
                                printf("Tl hesabında bakiye bulunmadığı için işlem gerçekleştirilemedi. Lütfen ilk başta Tl hesabınıza para yükleyin\n");
                            }
                            else if (doviz_islem == 'D')
                            {
                              if (dolarBakiye > 0)
                              {
                                printf("\nNe kadar miktarı tl'ye çevirmek istersiniz? (Şu anki $ bakiyeniz:%.1f)",dolarBakiye);
                                scanf("%f",&dolarDovizPara);
                                if (dolarDovizPara <= dolarBakiye)
                                {
                                  dolarBakiye = cikarma(dolarBakiye,dolarDovizPara);
                                  bakiye = toplama(bakiye,dolarToTl(dolarDovizPara));
                                  printf("İşlem başarılı bir şekilde gerçekleştirildi.\n");
                                }
                                else
                                  printf("\nBakiyenizin üstünde bir miktar para dönüştüremezsiniz");
                              }
                              else
                                printf("Dolar hesabında bakiye bulunmadığı için işlem gerçekleştirilemedi. Lütfen ilk başta dolar hesabınıza para yükleyin\n");
                            }
                            break;

                          case 2:
                            printf("Hangi işlemi yapmak istiyorsunuz? (Euro'dan Tl'ye: 'E'/Tl'den euro'ya: 'T'):");
                            getchar();
                            scanf("%c",&doviz_islem);
                            if (doviz_islem == 'T')
                            {
                              if (bakiye > 0)
                              {
                                printf("\nNe kadar miktarı euroya çevirmek istersiniz? (Şuan ki ₺ bakiyeniz:%.1f):",bakiye);
                                scanf("%f",&dovizParasi);
                                if (dovizParasi <= bakiye)
                                {
                                  bakiye = cikarma(bakiye,dovizParasi);
                                  euroBakiye = tlToDolar(dovizParasi);
                                  printf("İşlem başarılı bir şekilde gerçekleştirildi.\n");
                                }
                                else
                                  printf("\nBakiyenizin üstünde bir miktar para dönüştüremezsiniz\n");
                              }
                              else
                                printf("Tl hesabında bakiye bulunmadığı için işlem gerçekleştirilemedi. Lütfen ilk başta Tl hesabınıza para yükleyin\n");
                            }
                            else if (doviz_islem == 'E')
                            {
                              if (euroBakiye > 0)
                              {
                                printf("\nNe kadar miktarı tl'ye çevirmek istersiniz? (Şu anki € bakiyeniz:%.1f):",euroBakiye);
                                scanf("%f",&euroDovizPara);
                                if (euroDovizPara <= euroBakiye)
                                {
                                  euroBakiye = cikarma(euroBakiye,euroDovizPara);
                                  bakiye = toplama(bakiye,euroToTl(euroDovizPara));
                                  printf("İşlem başarılı bir şekilde gerçekleştirildi.\n");
                                }
                                else
                                  printf("\nBakiyenizin üstünde bir miktar para dönüştüremezsiniz\n");
                              }
                              else
                                printf("Euro hesabında bakiye bulunmadığı için işlem gerçekleştirilemedi. Lütfen ilk başta euro hesabınıza para yükleyin\n");
                            }
                            break;
                          case 3:
                            printf("Üst menüye dönülüyor.");
                            break;

                          default:
                            printf("Lütfen geçerli bir işlem giriniz.");
                        }
                      if (islem3 == 3)
                        break;
                    }
                    break;
                    
              case 7:
                printf("Çıkış yapılıyor.");
                break;

              default:
                printf("Geçersiz işlem lütfen geçerli bir işlem seçiniz.");
                break;
            }
          if (islem == 7)
              break;
        }
        break;
    }
    else if (girilenSifre != SIFRE)
    {
      if(sifreSayac < 2)
      {
      printf("Girilen şifre hatalı lütfen tekrar deneyiniz kalan hakkınız: %d\n",2-sifreSayac);
      sifreSayac++;
      }
      else if (sifreSayac == 2)
      {
        printf("\nHakkınız kalmadı hesabınız bloke edildi");
        break;
      }
    }
  }
}