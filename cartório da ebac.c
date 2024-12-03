#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bliblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string // string s�o conjuntos de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis/string // lembrando que string � um juntos de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string. %s � usado toda vez que precisa salvar uma string/vari�vel
	
	strcpy(arquivo, cpf); // � respons�vel por copiar os valores das string
	
	FILE *file; //criar o arquivo 
	file = fopen(arquivo, "w"); //criar o arquivo e o "w" significa escrever, que ele vai criar um novo arquivo e j� vai escrever.
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fclose � respons�vel por fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//"a" � respons�vel por atualizar o arquivo j� existente que criamos com "w"
	fprintf(file,nome);
	fclose(file);
	
		file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
		file = fopen(arquivo, "a");
	fprintf(file, ",");
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
	setlocale (LC_ALL, "Portuguese"); //definindo a linguagem 
	
	 char cpf[40];
	 char conteudo[200];
	 
	 printf("Digite o CPF a ser consultado: ");
	 scanf("%s",cpf);
	 
	 FILE *file;
	 file = fopen(cpf, "r"); // "r" � para o computador ler o arquivo
	 
	 if(file == NULL)
	 {
	 	printf("N�o foi possivel localizar o arquivo:\n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)
	 {
	 	printf("\n Essas s�o as informa��es do usu�rio: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
	 
	 system("pause");
}

int deletar()
{
	 char cpf[40];
	 
	 printf("Digite o CPF do usu�rio a ser deletado: \n");
	 scanf("%s",cpf);
	 
	 remove(cpf);
	 
	 FILE *file;
	 file = fopen(cpf, "r"); //"r" � para ler 
	 
	 if(file == NULL )
	 {
	 	printf("o usu�ro n�o se encontrta no sistema! \n");
	 	system("pause");
	 }
}

int main()
{
	
	int opcao=0; //definindo as vari�veis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");// "cls" � respons�vel por limpar a tela
	
	
	setlocale (LC_ALL, "Portuguese"); //definindo a linguagem 
	
	printf("### Cart�rio da ebac ###\n\n"); //inicio do menu
	printf("escolha a op��o desejada do menu:\n\n");
	printf("\t1 - registrar nomes\n");
	printf("\t2 - consultar nomes \n");
	printf("\t3 - Deletar nomes\n"); 
	printf("op��o: "); //fim do menu 
	
	scanf("%d", &opcao);// armazenando a escolha do usu�rio 
	system("cls");
	
	switch(opcao)
	{
		case 1:
		registro(); //chamada de fun��es
		break; 
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
			printf("essa op��o n�o est� dispon�vel\n");
		system("pause");
		break;
	
	
	}
}
}
