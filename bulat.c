#include <stdio.h>
char cel[100][100];

void setPixel(int i, int j){
	cel[i][j]='*';
}

//karena yang dibutuhkan hanya 45 derajat
void lingkaran(int x0, int y0, int x, int y, float p){
	setPixel(x0+x,y0+y);
	printf("%d\t%d\t%.02f\n",x0+x,y0+y,p);
	setPixel(x0-x,y0+y);
	printf("%d\t%d\t%.02f\n",x0-x,y0+y,p);
	setPixel(x0+x,y0-y);
	printf("%d\t%d\t%.02f\n",x0+x,y0-y,p);
	setPixel(x0-x,y0-y);
	printf("%d\t%d\t%.02f\n",x0-x,y0-y,p);
	setPixel(x0+y,y0+x);
	printf("%d\t%d\t%.02f\n",x0+y,y0+x,p);
	setPixel(x0-y,y0+x);
	printf("%d\t%d\t%.02f\n",x0-y,y0+x,p);
	setPixel(x0+y,y0-x);
	printf("%d\t%d\t%.02f\n",x0+y,y0-x,p);
	setPixel(x0-y,y0-x);
	printf("%d\t%d\t%.02f\n",x0-y,y0-x,p);
}

void midLingkaran(int x0, int y0, int r){
	int x,y,p;
	x=0;
	y=r;
	p=1-r;
	lingkaran(x0,y0,x,y,p);
	while (x<y) {
		x++;
		if(p<0){
			p=p+(2*x+1);
		}else{
			y--;
			p=p+(2*(x-y)+1);
		}
		lingkaran(x0,y0,x,y,p);
	}
}

//karena yang dibutuhkan hanya 90 derajat
void elips(int x0, int y0, int x, int y, float p){
	setPixel(x0+x,y0+y);
	printf("%d\t%d\t%.02f\n",x0+x,y0+y,p);
	setPixel(x0-x,y0+y);
	printf("%d\t%d\t%.02f\n",x0-x,y0+y,p);
	setPixel(x0+x,y0-y);
	printf("%d\t%d\t%.02f\n",x0+x,y0-y,p);
	setPixel(x0-x,y0-y);
	printf("%d\t%d\t%.02f\n",x0-x,y0-y,p);
}

void midElips(int x0, int y0, int rx, int ry){
	int rx2,ry2,duarx2,duary2,x,y;
	float py,px,p;
	rx2=rx*rx;
	ry2=ry*ry;
	x=0;
	y=ry;
	duarx2=2*rx2;
	duary2=2*ry2;
	px=0;
	py=duarx2*y;
	elips(x0,y0,x,y,0);
	//pertama
		p=(ry2-(rx2*ry)+(0.25*rx2));
		while (px<py){
			x++;
			px=px+duary2;
			if (p<0){
				p=p+(ry2+px);
			}else{
				y--;
				py=py-duarx2;
				p=p+(ry2+px-py);
			}
			elips(x0,y0,x,y,p);
		}
	//kedua
		p=(ry2*(x+0.5)*(x+0.5)+rx2*(y-1)-rx2*ry2);
		while (y>0) {
			y--;
			py=py-duarx2;
			if(p>0){
				p=p+(rx2-py);
			}else{
				x++;
				px=px+duary2;
				p=p+ry2+px-py;
			}
			elips(x0,y0,x,y,p);
		}
}

void free(){
	int i,j;
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			cel[i][j]=' ';
		}
	}	
}	

int main(){
	system("cls");
	printf("Program Membuat Lingkaran dan Elips menggunakan Algoritma MidPoint \nMK Grafika Komputer 2015\n");
	printf("[1] Lingkaran\n");
	printf("[2] Elips\n");
	printf("[any] Exit\n");
	printf("Pilih menu : ");
	int menu,i,j;
	scanf("%d", &menu);
	
	int x0,y0,r,rx,ry;
	switch(menu){
		case 1:
			printf("Masukkan nilai Koordinat Pusat [x,y] : ");
			scanf("%d,%d",&x0,&y0);
			printf("Masukkan nilai Radius : ");
			scanf("%d",&r);
			printf("--------------------------------------\n");
			printf("xi\tyi\td\n");
			printf("--------------------------------------\n");
			midLingkaran(x0,y0,r);
			printf("--------------------------------------\n");
			printf("Grafik\n");
			printf("--------------------------------------\n");
			for(i=0;i<=x0+(2*r);i++){
				for(j=0;j<=y0+(2*r);j++){
					if(cel[i][j]!='*'){
						printf(" ");
					}else{
						printf("*");
					}
				}printf("\n");
			}
			//free
			free();
		printf("\n");
		system("pause");
		
		main();

		break;
		case 2:
			printf("Masukkan nilai Koordinat Pusat [x,y] : ");
			scanf("%d,%d",&x0,&y0);
			printf("Masukkan nilai Radius [rx,ry] : ");
			scanf("%d,%d",&rx,&ry);
			printf("--------------------------------------\n");
			printf("xi\tyi\td\n");
			printf("--------------------------------------\n");
			midElips(x0,y0,rx,ry);
			printf("--------------------------------------\n");
			printf("Grafik\n");
			printf("--------------------------------------\n");
			for(i=0;i<=x0+(2*rx);i++){
				for(j=0;j<=y0+(2*ry);j++){
					if(cel[i][j]!='*'){
						printf(" ");
					}else{
						printf("*");
					}
				}printf("\n");
			}
			//free
			free();
		printf("\n");
		system("pause");
		
		main();

		break;
		default:
			system("exit");
		break;
	}
 return 0;	
}
/*  ferdilarahmi - 1202315*/
