#include <stdio.h>

int main(int argc, char* argv[]){
	
	int height, i, j,length;			// height main building / counters*/
	int windows_numb;					// windows subchurch*/
	int stegi;							// roof subchurch*/
	int margin;							// Counter for margin between windows and roof of church*/
	int windows_house;					// windows of main church 
	int space;							
	int margin_para8iro;				
	int k;								
	int w_portas;						
	int h_portas;						
	int margin_portas;					
	int dashes;							
	
	printf("Minimum height 10,and the number of windows must be greater than 0 \n");
	
	/*Input checks*/
	do {
		printf("Enter roof height (in chars): ");
		scanf("%d", &height);
		printf("Enter number of windows: ");
		scanf("%d",&windows_numb);
	}
	while(height<10 || (windows_numb< 0 || windows_numb == 0) );
	
	
	
	/*build of roof church*/
	
	stegi = 4+4*windows_numb+windows_numb-1;
	margin  = (height/2 - 3) / 2;
	
	if(stegi%2==1){
		stegi++;
	}
	for(i=0;i <height;i++){
		
		for(j=height;j>i+1;j--){
			printf(" ");
		}
		for(j=0;j<=i;j++){
			printf("/\\");
		}
		if(i==height - 1){
			for(j=0;j<stegi;j++){
				printf("_");
			}
		}	
			printf("\n");
	}
		windows_house = height/4;
		if(windows_house%2==1){
			windows_house--;
		}
		
		
	
		
		
		space = (height - windows_house)/2;			/* orismos apostashs*/
		length = stegi/2 ;							/*length of church roof */
		printf("|");
		
		for(j=1;j<(2*(height)-1);j++){
			printf("~");
		}
		printf("|");
		
		margin_para8iro = height / 10;
		k =windows_house/2;
		for(i=0;i<height/2;i++) {
			if(i!=0) {
				printf("|");
				for(j=0;j<2*height-2;j++) {			/*windows of main building*/
					if(i>=margin_para8iro && i<margin_para8iro + windows_house){
						if((j>=space && j<space + windows_house) || (j>=height+space-2 && j< space +  windows_house + height -2)){
							if(i <= margin_para8iro + windows_house/2 -1 ){
								if( j == space+k -1 || j == space+height-2+ k -1){
									printf("/");
								}else if(j==space+ windows_house -k || j == space+windows_house+height-2-k){
									printf("\\");
								}else{
									printf(" ");
								}
							}else{
								if( j == space+k -1 || j == space+height-2+ k -1){
									printf("\\");
								}else if(j==space+ windows_house -k || j == space+windows_house+height-2-k){
									printf("/");
								}else{
									printf(" ");
								}
							}
						}else{
							printf(" ");
						}
						if( j == 2*height - 3 && i >= margin_para8iro + windows_house/2 ){
							k++;
						}else if( j == 2*height - 3 && i<  margin_para8iro + windows_house/2 -1){
							k--;
						}else{
							
						}
					}else{
							printf(" ");
					}
					
				}
				
				printf("|");
				
			}
			for(j=0;j<i;j++) {
				printf(" ");
			}
			for(j=0;j<length;j++) {
				printf("\\/");
			}
			printf("\\\n");
		}
	
	
	w_portas=height/3;
	h_portas= height/3;
	if(h_portas<5){
		h_portas=5;
	}
	if(w_portas<6){
		w_portas = 6;
	}
	margin_portas = (2*height - 2)/2 -w_portas/2 -1;
	dashes = w_portas - 4;
	
	for(i=0;i<height/2;i++){
		printf("|");
		for(j=0;j<height*2-2;j++){						/*door building*/
			if(i >= height/2 -h_portas){
				if((j==margin_portas || j == margin_portas + w_portas) && i!= height/2 -h_portas && i!= height/2 - h_portas +1){
					printf("|");
				}else if(j>=margin_portas + 2 && j<= margin_portas + 2 + dashes && i== height/2 -h_portas){
					printf("_");
				}else if(j==margin_portas + 1 && i == height/2 - h_portas + 1){
					printf("/");
				}else if(j==margin_portas + w_portas -1 && i == height/2 - h_portas + 1){
					printf("\\");
				}else if(j==margin_portas + 1 && i == height/2 - h_portas + dashes){
					printf("-");
				}else{
					if(i == height/2 - 1){
						printf("_");
					}else{
						printf(" ");
					}
				}
				
			}else {
				printf(" ");
			}
		}
		printf("|");
		for(j=0;j<height/2-1;j++){
			if(i == height/2 -1 ){
				printf("_");
			}
			else{
				printf(" ");
			}
		}
		printf("|");
		for(j=0;j<stegi - 1;j++){
			if(i == height/2 -1 ){
				printf("_");
			}
			else if(i>=margin && i<margin+3){			/*windows subchurch*/
				if( j<2 ){
				printf(" ");
				}
				else if(j > stegi -3){
						printf(" ");
				}
				else if( i == margin ){
					printf(" /\\  ");
					j+=4;
				}
				else if( i == margin + 1){
					printf("|  |");
					printf(" ");
					j+=4;
				}
				else{
					printf("|__|");
					printf(" ");
					j+=4;
				}
			}
				else {
					printf(" ");
				}
		}
		printf("|");
		printf("\n");
	}
	return 0;
}
