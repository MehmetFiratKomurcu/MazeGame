#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>

void bekle(unsigned int);
int bosmu();
void pop();
void push(int,int);
void yigingoster();
void listegoster(int);
void listeolustur(int);
int kapidondur(int,int,int);
void gitveata(int,int,int,int);


void bekle(unsigned int saniye)
{
    clock_t hedef = saniye + clock();
    while (hedef > clock());
}

struct kapi{
    int x;
    int y;
};

void listegosteryenilenen(int,struct kapi,struct kapi);
void listegosterson(int,struct kapi,struct kapi,int);

struct suan{
    int x;
    int y;
};

struct liste{
    struct suan deger;
    struct liste *sonraki;
};

struct bagliliste{
    int deger;
    struct bagliliste *sonraki;
};

struct liste *yigin;
struct liste *son;

struct bagliliste *listebas;
struct bagliliste *listeson;

int bosmu(){
    if(yigin==NULL){
        return 1;
    }else {
        return 0;
    }
}

void pop(){
    if(!bosmu()){
        yigin=yigin->sonraki;
    }else{
        printf("Yigin bos.");
    }

}
void push(int gelenx,int geleny){
    struct liste *yeni=(struct liste*)malloc(sizeof(struct liste));
    yeni->deger.x=gelenx;
    yeni->deger.y=geleny;
    yeni->sonraki=yigin;
    yigin=yeni;
}
void yigingoster(){
    while(yigin!=NULL){
        printf("x=%d y=%d ",yigin->deger.x,yigin->deger.y);
        yigin=yigin->sonraki;
    }
}
void listegoster(int n){


	int x=0,y=0,donen;
    struct bagliliste *kopyabas=listebas;
    int sayac=1,sayac2,sayac3,sayac4;
    sayac2=sayac3=sayac4=sayac;
    int left=80,bottom=50,top=80,right=140;
	int gd = DETECT, gm;
    initwindow(1280,720);
    char yazi[10];
    int i;
    while(kopyabas!=NULL){
        if(x==0){
        	settextstyle(3,HORIZ_DIR,1);
        	sprintf(yazi,"(%d,%d)",x,y);
        	outtextxy((32)+62*sayac,20,yazi);
		}
		if(y==0){
			settextstyle(3,HORIZ_DIR,1);
        	sprintf(yazi,"(%d,%d)",x,y);
        	outtextxy(15,(20)+32*sayac2,yazi);
        	sayac2++;
		}
		if(y==n-1){
			settextstyle(3,HORIZ_DIR,1);
        	sprintf(yazi,"(%d,%d)",x,y);
        	outtextxy((85)+(n*62),(20)+32*sayac3,yazi);
        	sayac3++;
		}if(x==n-1){
		 settextstyle(3,HORIZ_DIR,1);
        	sprintf(yazi,"(%d,%d)",x,y);
        	outtextxy((32)+62*sayac4,(55)+(n*32),yazi);
        	sayac4++;
		}
        if(kapidondur(x,y,n)==0){
				setfillstyle(SOLID_FILL, RED);
			}else if(kapidondur(x,y,n)==1){
				setfillstyle(SOLID_FILL, WHITE);
			}else if(kapidondur(x,y,n)==2){
				setfillstyle(SOLID_FILL, GREEN);
			}


			bar(left,top,right,bottom);
			left+=62;
			right+=62;
			y++;
        if(sayac%n==0){
			top+=32;
			bottom+=32;
			left=80;
			right=140;
			x++;
			y=0;
        }
        sayac++;
        kopyabas=kopyabas->sonraki;
    }
    settextstyle(3,HORIZ_DIR,1);
    setcolor(2);
	outtextxy(80,(55)+((n+2)*30),"Devam etmek icin herhangi bir tusa basiniz...");
	getch();
	closegraph();
}
void listegosteryenilenen(int n,struct kapi giris,struct kapi cikis){
	int x=0,y=0,donen;
    struct bagliliste *kopyabas=listebas;
    int sayac=1;
    int left=80,bottom=50,top=80,right=140;

    while(kopyabas!=NULL){

        if(kapidondur(x,y,n)==0){
				setfillstyle(SOLID_FILL, RED);
			}else if(kapidondur(x,y,n)==1){
				setfillstyle(SOLID_FILL, WHITE);
			}else if(kapidondur(x,y,n)==2){
				setfillstyle(SOLID_FILL, GREEN);
			}
			if(x==giris.x && y==giris.y){
				setfillstyle(SOLID_FILL, MAGENTA);
			}
			else if(x==cikis.x && y==cikis.y){
				setfillstyle(SOLID_FILL, CYAN);
			}

			bar(left,top,right,bottom);
			left+=62;
			right+=62;
			y++;
        if(sayac%n==0 && sayac!=0){
			top+=32;
			bottom+=32;
			left=80;
			right=140;
			x++;
			y=0;
        }
        sayac++;
        kopyabas=kopyabas->sonraki;
    }

}
void listegosterson(int n,struct kapi giris,struct kapi cikis,int cikildimi){
	int x=0,y=0,donen;
    struct bagliliste *kopyabas=listebas;
    int sayac=1;
    int left=80,bottom=50,top=80,right=140;
	int gd = DETECT, gm;
    initwindow(1280,720);
    settextstyle(3,HORIZ_DIR,1);
    if(cikildimi!=1){
    	outtextxy(80,10,"Bulunan yol:");
    	while(kopyabas!=NULL){

	        if(kapidondur(x,y,n)==2){
				setfillstyle(SOLID_FILL, GREEN);
			}else{
				setfillstyle(SOLID_FILL, RED);
			}
			if(x==giris.x && y==giris.y){
				setfillstyle(SOLID_FILL, MAGENTA);
			}
			else if(x==cikis.x && y==cikis.y){
				setfillstyle(SOLID_FILL, CYAN);
			}
				bar(left,top,right,bottom);
				left+=62;
				right+=62;
				y++;
	        if(sayac%n==0){
				top+=32;
				bottom+=32;
				left=80;
				right=140;
				x++;
				y=0;
	        }
	        sayac++;
	        kopyabas=kopyabas->sonraki;
    	}
    	settextstyle(3,HORIZ_DIR,1);
	    setcolor(2);
		outtextxy(80,(55)+((n+2)*30),"Devam etmek icin herhangi bir tusa basiniz...");
	}else{
		settextstyle(3,HORIZ_DIR,1);
	    setcolor(4);
		outtextxy(80,10,"Yol bulunamadi...");
	}


	getch();
	closegraph();
}


void listeolustur(int n){

    int sayac=0;

    while(sayac<n*n){
        struct bagliliste *yeni=(struct bagliliste*)malloc(sizeof(struct bagliliste));
        yeni->deger=rand()%2;
        yeni->sonraki=NULL;
        if(sayac==0){
            listebas=yeni;
            listeson=listebas;
        }else{
            listeson->sonraki=yeni;
            listeson=yeni;
        }
        sayac++;
    }


}

int kapidondur(int x,int y,int n){
    int sayac=0;
    struct bagliliste *kopya=listebas;
    while(sayac<(x*n)+y){
        kopya=kopya->sonraki;
        sayac++;
    }
    return kopya->deger;
}

void gitveata(int x,int y,int n,int gelendeger){
    int sayac=0;
    struct bagliliste *kopya=listebas;
    while(sayac<(x*n)+y){
        kopya=kopya->sonraki;
        sayac++;
    }
    kopya->deger=gelendeger;
}

int main()
{
    srand(time(NULL));
    int n,i,j,durum=0;
    struct kapi giris;
    struct kapi cikis;
    int integermi;


	do{
		printf("Labirentin boyutunu giriniz: ");
    	integermi=scanf("%d",&n);
    	if(integermi!=1){
    		printf("Lutfen gecerli bir giris yapiniz.");
		}
    	while ((integermi = getchar())!= '\n');
    	if(n>18){
    		printf("Lutfen labirentin ekrana sigmasi icin 18 den kucuk bir deger giriniz.\n");
		}
	}while(n>18 || n<1);


    listebas=(struct bagliliste*)malloc(sizeof(struct bagliliste));
    listeson=listebas;
    listeolustur(n);
    listegoster(n);

    do{
        printf("\nGiris kapisinin koordinatlarini giriniz.(Kapilarin kenarlar uzerinde olmasi gerekmektedir.)\n");
        printf("Labirent uzerindeki yollari tekrar gormek icin -1 degerini giriniz.\n");

        do{
        	printf("x=");
    		integermi=scanf("%d",&giris.x);
    		if(integermi!=1){
    			printf("Lutfen gecerli bir giris yapiniz.");
			}

    		if(giris.x==-1){
    			listegoster(n);
			}
	    }while(giris.x==-1 || (integermi = getchar())!= '\n');

        do{
        	printf("y=");
    		integermi=scanf("%d",&giris.y);
    		if(integermi!=1){
    			printf("Lutfen gecerli bir giris yapiniz.");
			}
    		if(giris.y==-1){
    			listegoster(n);
			}
	    }while(giris.y==-1 || (integermi = getchar())!= '\n');

        durum=0;
        if(!((giris.x==0 && giris.y>=0 && giris.y<=n-1) || (giris.x==n-1 && giris.y>=0 && giris.y<=n-1) ||
             (giris.y==0 && giris.x>=0 && giris.x<=n-1) || (giris.y==n-1 && giris.x>=0 && giris.x<=n-1))){
            printf("\nLutfen girmis oldugunuz kapinin, kenar uzerinde olduguna emin olunuz.\n");
            durum=1;
        }else{
            if(kapidondur(giris.x,giris.y,n)==0){
                printf("\nBelirlediginiz kapi kapali.\n");
                durum=1;
            }
        }
    }while(durum);
    do{
        printf("\nCikis kapisinin koordinatlarini giriniz.(Kapilarin kenarlar uzerinde olmasi gerekmektedir.)\n");
        printf("Labirent uzerindeki yollari tekrar gormek icin -1 degerini giriniz.\n");
        do{
        	printf("x=");
    		integermi=scanf("%d",&cikis.x);
    		if(integermi!=1){
    			printf("Lutfen gecerli bir giris yapiniz.");
			}
    		if(cikis.x==-1){
    			listegoster(n);
			}
		}while(cikis.x==-1 || (integermi = getchar())!= '\n');
		do{
        	printf("y=");
    		integermi=scanf("%d",&cikis.y);
    		if(integermi!=1){
    			printf("Lutfen gecerli bir giris yapiniz.");
			}
    		if(cikis.y==-1){
    			listegoster(n);
			}
		}while(cikis.y==-1 || (integermi = getchar())!= '\n');

        durum=0;
        if(!((cikis.x==0 && cikis.y>=0 && cikis.y<=n-1) || (cikis.x==n-1 && cikis.y>=0 && cikis.y<=n-1) ||
             (cikis.y==0 && cikis.x>=0 && cikis.x<=n-1) || (cikis.y==n-1 && cikis.x>=0 && cikis.x<=n-1))){
            printf("\nLutfen girmis oldugunuz kapinin, kenar uzerinde olduguna emin olunuz.\n");
            durum=1;
        }else{
            if(kapidondur(cikis.x,cikis.y,n)==0){
                printf("\nBelirlediginiz kapi kapali.\n");
                durum=1;
            }
        }
    }while(durum);

    struct suan suanki;
    int xUzaklik,yUzaklik;
    suanki.x=giris.x;
    suanki.y=giris.y;
    int cikildimi=0;

    yigin=(struct liste*)malloc(sizeof(struct liste));
    yigin=NULL;
    int isaret=0;
    gitveata(suanki.x,suanki.y,n,2);
    push(suanki.x,suanki.y);
    int oncekiyol=0;

	int gd = DETECT, gm;
    initwindow(1280,720);
    settextstyle(3,HORIZ_DIR,1);
    while(suanki.x!=cikis.x || suanki.y!=cikis.y){

        system("cls");

        if(oncekiyol==0){
            if(suanki.y!=n-1 && kapidondur(suanki.x,suanki.y+1,n)!=0 && kapidondur(suanki.x,suanki.y+1,n)!=2){
                suanki.y++;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=0;
                isaret=1;
            }else if(suanki.y!=0 && kapidondur(suanki.x,suanki.y-1,n)!=0 && kapidondur(suanki.x,suanki.y-1,n)!=2){
                suanki.y--;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=1;
                isaret=1;
            }else if(suanki.x!=n-1 && kapidondur(suanki.x+1,suanki.y,n)!=0 && kapidondur(suanki.x+1,suanki.y,n)!=2){
                suanki.x++;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=2;
                isaret=1;
            }else if(suanki.x!=0 && kapidondur(suanki.x-1,suanki.y,n)!=0 && kapidondur(suanki.x-1,suanki.y,n)!=2){
                suanki.x--;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=3;
                isaret=1;
            }else{
                isaret=0;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=0;
                pop();
                if(bosmu()){
                    printf("Yol yok.");
                    cikildimi=1;
                    break;
                }
                gitveata(suanki.x,suanki.y,n,0);
                suanki.x=yigin->deger.x;
                suanki.y=yigin->deger.y;

            }
        }else if(oncekiyol==1){
            if(suanki.y!=0 && kapidondur(suanki.x,suanki.y-1,n)!=0 && kapidondur(suanki.x,suanki.y-1,n)!=2){
                suanki.y--;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=1;
                isaret=1;
            }else if(suanki.y!=n-1 && kapidondur(suanki.x,suanki.y+1,n)!=0 && kapidondur(suanki.x,suanki.y+1,n)!=2){
                suanki.y++;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=0;
                isaret=1;
            }else if(suanki.x!=n-1 && kapidondur(suanki.x+1,suanki.y,n)!=0 && kapidondur(suanki.x+1,suanki.y,n)!=2){
                suanki.x++;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=2;
                isaret=1;
            }else if(suanki.x!=0 && kapidondur(suanki.x-1,suanki.y,n)!=0 && kapidondur(suanki.x-1,suanki.y,n)!=2){
                suanki.x--;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=3;
                isaret=1;
            }else{
                isaret=0;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=0;
                pop();
                if(bosmu()){
                    printf("Yol yok.");
                    cikildimi=1;
                    break;
                }
                gitveata(suanki.x,suanki.y,n,0);
                suanki.x=yigin->deger.x;
                suanki.y=yigin->deger.y;
            }

        }else if(oncekiyol==2){
            if(suanki.x!=n-1 && kapidondur(suanki.x+1,suanki.y,n)!=0 && kapidondur(suanki.x+1,suanki.y,n)!=2){
                suanki.x++;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=2;
                isaret=1;
            }else if(suanki.y!=0 && kapidondur(suanki.x,suanki.y-1,n)!=0 && kapidondur(suanki.x,suanki.y-1,n)!=2){
                suanki.y--;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=1;
                isaret=1;
            }else if(suanki.y!=n-1 && kapidondur(suanki.x,suanki.y+1,n)!=0 && kapidondur(suanki.x,suanki.y+1,n)!=2){
                suanki.y++;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=0;
                isaret=1;
            }else if(suanki.x!=0 && kapidondur(suanki.x-1,suanki.y,n)!=0 && kapidondur(suanki.x-1,suanki.y,n)!=2){
                suanki.x--;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=3;
                isaret=1;
            }else{
                isaret=0;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=0;
                pop();
                if(bosmu()){
                    printf("Yol yok.");
                    cikildimi=1;
                    break;
                }
                gitveata(suanki.x,suanki.y,n,0);
                suanki.x=yigin->deger.x;
                suanki.y=yigin->deger.y;
            }

        }else if(oncekiyol==3){

            if(suanki.x!=0 && kapidondur(suanki.x-1,suanki.y,n)!=0 && kapidondur(suanki.x-1,suanki.y,n)!=2){
                suanki.x--;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=3;
                isaret=1;
            }else if(suanki.x!=n-1 && kapidondur(suanki.x+1,suanki.y,n)!=0 && kapidondur(suanki.x+1,suanki.y,n)!=2){
                suanki.x++;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=2;
                isaret=1;
            }else if(suanki.y!=0 && kapidondur(suanki.x,suanki.y-1,n)!=0 && kapidondur(suanki.x,suanki.y-1,n)!=2){
                suanki.y--;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=1;
                isaret=1;
            }else if(suanki.y!=n-1 && kapidondur(suanki.x,suanki.y+1,n)!=0 && kapidondur(suanki.x,suanki.y+1,n)!=2){
                suanki.y++;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=0;
                isaret=1;
            }else{
                isaret=0;
                gitveata(suanki.x,suanki.y,n,2);
                oncekiyol=0;
                pop();
                if(bosmu()){
                    printf("Yol yok.");
                    cikildimi=1;
                    break;
                }
                gitveata(suanki.x,suanki.y,n,0);
                suanki.x=yigin->deger.x;
                suanki.y=yigin->deger.y;
            }


        }

        if(isaret){
            push(suanki.x,suanki.y);
            gitveata(suanki.x,suanki.y,n,2);
        }


        listegosteryenilenen(n,giris,cikis);
        bekle(500);
    }

	closegraph();

	listegosterson(n,giris,cikis,cikildimi);
    printf("\nProgram sonlandi...");

    return 0;
}
