
#include <stdio.h>

/*
 *	Filename:  Hello.cpp
 *
 *	Description:  Conversao de tutorial mergesort (Canal do Codigo) 
 *		em java para clinguagem C. 
 *
 * 	App utilizado: AIDE
 *
 *	Created:  10/jul/20
 *    
 *	Revision:  none
 *
 *	@Author:  Fabricio J B ueredeveloper@gmail.com
 *   
 *	@Version:  1.0
 *
 * =======
*/
void intercalar(int *v, int *w, int ini,int mei, int fim){
	
	//fazer copia do vetor
	for (int k = ini;k<=fim;k++){
		w[k]=v[k];
		//printf("w[%d] = %d \n",ini,w[ini]);
	}	
		//mover dentro do vetor
		int i = ini;
		int m = mei + 1;
		//intercalar
		for (int k = ini;k<=fim;k++){
			// caso 1: um vetor terminou antes
			if(i>mei){
				v[k]=w[m++];
			}
			// caso 2: metade 2 chegou no final
			else if (m>fim){
				v[k]=w[i++];
			}
			//caso 3: ainda ha elementos da metad 2 na metade 1
			else if(w[i]<w[m]){
				v[k]=w[i++];
				
			}
			// caso 4: 
			else {
				v[k]=w[m++];
			}
			
		}
		
}

void mergeSort(int *v, int *w, int ini, int fim){
	//printf("mergeSort \n");
	if(ini<fim){
		//calcula elemento do meio
		int mei = (ini+fim)/2;
		
		mergeSort(v,w, ini, mei);
		mergeSort(v,w, mei+1, fim);
		intercalar(v,w, ini, mei, fim);
		
		}
}

int main()	{
	//vetor principal
	int v [] = {4,6,7,3,5,1,2,8};
	//tamanho do vetor
	int t = sizeof(v)/sizeof(int);
	//vetor auxiliar
	int w [t];
	//print vetor original
	printf("vetor original \n");
	for(int i=0;i<8;i++){
			printf("v[%d] = %d \n",i,v[i]);
	}
	
	
	mergeSort(v,w, 0, t);
	
	printf("vetor mergesort \n");
	for(int i=0;i<8;i++){
			printf("v[%d] = %d \n",i,v[i]);
	}
			
}



/*
		printf("--- inicio %d meio %d fim %d --- \n",ini,mei,fim);
		for(int i=0;i<fim;i++){
			printf("v[%d] = %d \n",i,v[i]);
			*/
