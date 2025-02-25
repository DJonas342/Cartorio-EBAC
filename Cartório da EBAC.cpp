#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca para monitorar as vari�veis string


int registro()
{
	char arquivo[200];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [14];
	char conteudo[120];
	
	printf("Digite o CPF do usu�rio que deseja consultar:\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	system("cls");//Apagar as intru��es e respostas anteriores
	
	if (file == NULL)
	{
		printf("N�o foi possivel encontrar o usu�rio\n");
	}
	
	while(fgets(conteudo,120,file)!= NULL)//Enquanto o arquivo for diferente de nulo, mostrar as infoma��es do usu�rio consultado
	{
		printf("Essas s�o as informa��es do usu�rio consultado:\n");
		printf("%s\n",conteudo);	
	}	
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];
	
	setlocale(LC_ALL,"portuguese");

	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);

	FILE *file;
  	file = fopen(cpf, "r"); // Tenta abrir o arquivo para leitura
	fclose(file); // Fecha o arquivo, pois ele existe
	
	if (file == NULL) 
  	{
    	printf("O usu�rio n�o existe!\n");
	} 
	
	else 
	{
	    remove(cpf); // Agora voc� pode remover o arquivo
	    printf("%s\n",cpf);
    	printf("Usu�rio deletado!\n");
  	}
  	system("pause");
}

int main()
{
	int opcao=0;//Defini��o de valor a variavel
	int x=1; //Valor da variavel de repeti��o
	
	for(x=1;x=1;) //Inicio do repeti��o
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Configurando para linguagem nativa brasileira
		
		
		printf("$$$ Cart�rio da EBAC $$$\n\n"); //Inicio de menu ao usu�rio
		printf("Escolha a op��o desejada de menu:\n\n");
		printf("\t1 - Registrar usu�rio\n");
		printf("\t2 - Consultar usu�rio\n");
		printf("\t3 - Excluir usu�rio\n\n"); //Fim de menu ao usu�rio
		printf("Op��o: ");
	
		scanf("%d", &opcao); //Scaneamento a varia��o do usu�rio
	
		system("cls"); //apagar instru��es anterior ao usu�rio
	
		switch(opcao)//Inicio de estrutura de decis�o
		{
				case 1:
				registro();
				break;
				
				case 2:
				consulta();
    			break;
    			
    			case 3:
				deletar();
				break;
				
				default:
				printf("Op��o Indisponivel\n");
    			system("pause");
    			break;
		}	//Fim de estrutura de decis�o
	}
}

