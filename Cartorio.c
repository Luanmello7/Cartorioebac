#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //bliblioteca de alocação de texto por região 
#include <string.h> //biblicoteca responsável pelas string

	int registro() //Função responsavel por cadastrar os usuários no sistema
	{
	//Inicoo da criação de variaveis/string (conjunto de variaveis)
	char arquivo[40];
	char cpf[40];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//Final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando infrimaçãoes do usuario
	scanf("%s", cpf); // "%s" ele salva na string 
	
	strcpy(arquivo, cpf); //Resposavel por copiar o valor das string arquivo e cpf será a mesma coisa
	
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo "w" ele cria um novo arquivo 
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fecho o arquivo 
	
	file = fopen(arquivo, "a"); // "a" ele inclui informaçoes ao arquivo ja existente 
	fprintf(file, " | "); //"," server para da uma virgula dentro do arquivo para deixar organizado
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando outras infermações 
	scanf("%s",nome); //"%s" ele salva na string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); 
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " | ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose (file);
	
	system("pause"); //Pausa o sistema para o usuario conferir 


	}

	int consulta()
	{

	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[300];
	
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		printf ("CPF não cadastrado!\n");
	}
	
	
	while(fgets(conteudo, 300, file) != NULL) //While: Enquanto tiver contuedo 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		fclose(file);
	}
	system("pause");
	}
	int deletar()
	{
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	char conteudo[300];
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	

	while(fgets(conteudo, 300, file) != NULL) //While: Enquanto tiver contuedo 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		fclose(file);
	}

	system("pause");
	system("cls");
	
	
	remove(cpf); //Comando para deletar o cpf 
	
	file = fopen(cpf,"r"); //"r" significa q ele vai vizualizar o cpf
	
	if(file == NULL)
	{
		printf("O usuário foi deletado com sucesso.\n");
		system("pause");
	}
	

	}


	int main()
	{

	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar   nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção:"); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //limpa a tela
		
		switch(opcao) //Inicio da seleção do menu
		{
			case 1:
			registro(); //Chamada de função 
			break;
			
			case 2: 
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por ultilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel\n");
			system("pause");
			break;
			
		}

 	} 
		} 

