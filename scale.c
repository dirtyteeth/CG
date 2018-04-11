#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<X11/Xlib.h>

void mat_multiply(float **mat1,float **mat2){

	for(int k = 0; k < 2; k++){
		for(int j = 0; j < 1; j++){
			float sum = 0;
			for(int i = 0; i < 2; i++){
				sum += mat2[k][i]*mat1[i][j];
			}
			mat1[k][j] = sum;
		}
	}
}

void mat_add(float **mat1,float **mat2){
		
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 1; j++){
			mat1[i][j] += mat2[i][j];
		}
	}
}  

void triangle(int arr[2][3]){
	line(arr[0][0],arr[1][0],arr[0][1],arr[1][1]);
	line(arr[0][1],arr[1][1],arr[0][2],arr[1][2]);
	line(arr[0][2],arr[1][2],arr[0][0],arr[1][0]);
}	

void square(int arr[2][4]){
	line(arr[0][0],arr[1][0],arr[0][1],arr[1][1]);
	line(arr[0][1],arr[1][1],arr[0][2],arr[1][2]);
	line(arr[0][2],arr[1][2],arr[0][3],arr[1][3]);
	line(arr[0][3],arr[1][3],arr[0][0],arr[1][0]);
	
}
int main(){
	printf("Enter the coordinates of line");
	int pt[2][2];
	for(int i = 0; i < 2; i++){
		scanf("%d%d",&pt[0][i],&pt[1][i]);
	}
	printf("Enter the coordinates of square");
	int sq[2][4];
	for(int i = 0; i < 4; i++){
                scanf("%d%d",&sq[0][i],&sq[1][i]);      
        }
	printf("Enter the coordinates of triangle");
	int tr[2][3];
	for(int i = 0; i < 3; i++){
		scanf("%d%d",&tr[0][i],&tr[1][i]);
	}
	
	printf("Enter the translation distance");
        int tx,ty;
        scanf("%d%d",&tx,&ty);
	
	printf("Enter the scaling factors");
	int sx,sy;
	scanf("%d%d",&sx,&sy);
	
	printf("Enter the rotation angle");
	float r;
	fflush(stdin);
	scanf("%f",&r);
	
	float **mat1;
        float **mat2;
	
	mat1 = malloc(2*sizeof(*mat1));
	mat2 = malloc(2*sizeof(*mat2));

	printf("Enter correct choice\n1: translation\n2: scaling\n3: rotation\n");
	int key;
	scanf("%d",&key);
	
	XInitThreads();
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	setbkcolor(WHITE);
	setcolor(BLACK);

	switch(key){
	case 1: {for(int i = 0; i < 2; i++){
			mat1[i] = malloc(sizeof(float));
			mat2[i] = malloc(sizeof(float));
		}
		
		mat2[0][0] = tx;
		mat2[1][0] = ty;
		line(pt[0][0],pt[1][0],pt[0][1],pt[1][1]);
		
		for(int i = 0; i < 2; i++){
			mat1[0][0] = pt[0][i];
			mat1[1][0] = pt[1][i];
			mat_add(mat1,mat2);
			pt[0][i] = mat1[0][0];
			pt[1][i] = mat1[1][0];
		}
		
		line(pt[0][0],pt[1][0],pt[0][1],pt[1][1]);
			
                square(sq);

                for(int i = 0; i < 4; i++){
                        mat1[0][0] = sq[0][i];
                        mat1[1][0] = sq[1][i];
                        mat_add(mat1,mat2);
                        sq[0][i] = mat1[0][0];
                        sq[1][i] = mat1[1][0];
                }

                square(sq);

		triangle(tr);

                for(int i = 0; i < 3; i++){
                        mat1[0][0] = tr[0][i];
                        mat1[1][0] = tr[1][i];
                        mat_add(mat1,mat2);
                        tr[0][i] = mat1[0][0];
                        tr[1][i] = mat1[1][0];
                }

                triangle(tr);
		break;
		}

	case 2:	{for(int i = 0; i < 2; i++){
			mat1[i] = malloc(sizeof(float));
			mat2[i] = malloc(2*sizeof(float));
		}
		
		mat2[0][0] = sx;
		mat2[0][1] = 0;
		mat2[1][0] = 0;
		mat2[1][1] = sy;
		line(pt[0][0],pt[1][0],pt[0][1],pt[1][1]);
		
		for(int i = 0; i < 2; i++){
			mat1[0][0] = pt[0][i];
			mat1[1][0] = pt[1][i];
			mat_multiply(mat1,mat2);
			pt[0][i] = mat1[0][0];
			pt[1][i] = mat1[1][0];
		}
		
		line(pt[0][0],pt[1][0],pt[0][1],pt[1][1]);
			
                square(sq);

                for(int i = 0; i < 4; i++){
                        mat1[0][0] = sq[0][i];
                        mat1[1][0] = sq[1][i];
                        mat_multiply(mat1,mat2);
                        sq[0][i] = mat1[0][0];
                        sq[1][i] = mat1[1][0];
                }

                square(sq);

		triangle(tr);

                for(int i = 0; i < 3; i++){
                        mat1[0][0] = tr[0][i];
                        mat1[1][0] = tr[1][i];
                        mat_multiply(mat1,mat2);
                        tr[0][i] = mat1[0][0];
                        tr[1][i] = mat1[1][0];
                }

                triangle(tr);
		break;
		}
	case 3: 		
		for(int i = 0; i < 2; i++){
			mat1[i] = malloc(sizeof(float));
			mat2[i] = malloc(2*sizeof(float));
		}
		
		mat2[0][0] = cos(r);
		mat2[0][1] = -sin(r);
		mat2[1][0] = sin(r);
		mat2[1][1] = cos(r);
		line(pt[0][0],pt[1][0],pt[0][1],pt[1][1]);
		int x_pivot,y_pivot;
		x_pivot = pt[0][0],y_pivot = pt[1][0];
		for(int i = 0; i < 2; i++){
			mat1[0][0] = pt[0][i] - x_pivot;
			mat1[1][0] = pt[1][i] - y_pivot;
			mat_multiply(mat1,mat2);
			pt[0][i] = fabs(mat1[0][0] + x_pivot);
			pt[1][i] = fabs(mat1[1][0] + y_pivot);
		}
		
		line(pt[0][0],pt[1][0],pt[0][1],pt[1][1]);
			
                square(sq);
		x_pivot = sq[0][0],y_pivot = sq[1][0];
                for(int i = 0; i < 4; i++){
                        mat1[0][0] = sq[0][i] - x_pivot;
                        mat1[1][0] = sq[1][i] - y_pivot;
                        mat_multiply(mat1,mat2);
                        sq[0][i] = fabs(mat1[0][0] + x_pivot);
                        sq[1][i] = fabs(mat1[1][0] + y_pivot);
                }

                square(sq);

		triangle(tr);
		x_pivot = tr[0][0],y_pivot = tr[1][0];
                for(int i = 0; i < 3; i++){
                        mat1[0][0] = tr[0][i] - x_pivot;
                        mat1[1][0] = tr[1][i] - y_pivot;
                        mat_multiply(mat1,mat2);
                        tr[0][i] = fabs(mat1[0][0] + x_pivot);
                        tr[1][i] = fabs(mat1[1][0] + y_pivot);
                }

                triangle(tr);
	}
	delay(50000);
	closegraph();
	return 0;
}
