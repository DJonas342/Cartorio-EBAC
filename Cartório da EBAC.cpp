#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca para monitorar as variáveis string


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
	
	printf("Digite o CPF do usuário que deseja consultar:\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	system("cls");//Apagar as intruções e respostas anteriores
	
	if (file == NULL)
	{
		printf("Não foi possivel encontrar o usuário\n");
	}
	
	while(fgets(conteudo,120,file)!= NULL)//Enquanto o arquivo for diferente de nulo, mostrar as infomações do usuário consultado
	{
		printf("Essas são as informações do usuário consultado:\n");
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
    	printf("O usuário não existe!\n");
	} 
	
	else 
	{
	    remove(cpf); // Agora você pode remover o arquivo
	    printf("%s\n",cpf);
    	printf("Usuário deletado!\n");
  	}
  	system("pause");
}

int main()
{
	int opcao=0;//Definição de valor a variavel
	int x=1; //Valor da variavel de repetição
	
	for(x=1;x=1;) //Inicio do repetição
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Configurando para linguagem nativa brasileira
		
		
		printf("$$$ Cartório da EBAC $$$\n\n"); //Inicio de menu ao usuário
		printf("Escolha a opção desejada de menu:\n\n");
		printf("\t1 - Registrar usuário\n");
		printf("\t2 - Consultar usuário\n");
		printf("\t3 - Excluir usuário\n\n"); //Fim de menu ao usuário
		printf("Opção: ");
	
		scanf("%d", &opcao); //Scaneamento a variação do usuário
	
		system("cls"); //apagar instruções anterior ao usuário
	
		switch(opcao)//Inicio de estrutura de decisão
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
				printf("Opção Indisponivel\n");
    			system("pause");
    			break;
		}	//Fim de estrutura de decisão
	}
}

