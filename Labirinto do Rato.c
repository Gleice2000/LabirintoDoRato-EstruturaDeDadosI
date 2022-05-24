#include <stdio.h>
#include "pilhaEncadeada.h"
#include <stdlib.h>
#define MAX 15 //tamanho do labirinto (15x15)

void criaLabirinto(char l[MAX][MAX]){
     int i,j,x,y;       //i= coluna, j=linha
     srand(time(NULL));
     for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++){
          if((rand()%5)==1)
             l[i][j]='|';
             else
              l[i][j]='.';
          }
          
          
     for(i=0;i<MAX;i++){ //define * como a borda
           l[0][i]='*';
           l[MAX-1][i]='*';
           l[i][0]='*';
           l[i][MAX-1]='*';
           }// fim for
           
        x=  rand() % MAX;
        y=  rand() % MAX;
        l[x][y]='Q';
     }// fim funcao cria
     
     
void mostraLabirinto(char mat[MAX][MAX],int linha,int coluna){
    int i,j;
     for ( i = 0; i < linha; i++)
    {
     printf("\n");
          for ( j = 0; j < coluna; j++)
			printf (" %c ",mat[i][j] );
     	}

     } // fim funcao
     
 int SuperMouse(char lab[MAX][MAX],int i, int j){
     tpilha p1,p2;
     inicializa(&p1); 
     inicializa(&p2); 
	 do{
     	  lab[i][j]='v';
		  if(lab[i][j+1]=='.' || lab[i][j+1]=='Q' ){          // -->  j++
		     push (&p1, i); push (&p2, j);
			 j++;
			 }
			 else if(lab[i+1][j]=='.' || lab[i+1][j]=='Q'){   // baixo i++       
		     push (&p1, i); push (&p2, j);
			 i++;
			 }
			 else if(lab[i][j-1]=='.' || lab[i][j-1]=='Q'){    // <--  j--
		     push (&p1, i); push (&p2, j);  
			 j--;
			 }		  
		  	else if(lab[i-1][j]=='.' || lab[i-1][j]=='Q'){    // cima  i--
		     push (&p1, i); push (&p2, j);  
			 i--;
			 }
		  	else {
		  		if (isEmpty(p1) == 0 && isEmpty(p2) == 0){	// voltar // if pilha nao estiver vazia
		  			lab[i][j] = 'x';
				  	i = pop(&p1);
				  	j = pop(&p2);
			  	  
			  	  }else {
			  	  	printf("\nNao foi possivel encontrar o Queijo !");
					break;
					}			 	
			}
				  
		  Sleep(180);
		  system("cls");
		  mostraLabirinto(lab,MAX,MAX);   
	 }while(lab[i][j]!='Q');
	 if (lab[i][j] == 'Q')
	printf("\n\nQueijo encontrado na linha %d. Na coluna %d.", i,j);
 }// fim funcao



int main(){
    char mouseLab[MAX][MAX];
    int x,y;
    criaLabirinto(mouseLab);
    mostraLabirinto(mouseLab,MAX,MAX);
    printf("\nDigite a posicao inicial do rato:");
    scanf("%d %d",&x,&y);
    SuperMouse(mouseLab,x,y);
    getch();
    }
