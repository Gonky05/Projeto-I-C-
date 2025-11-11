/* Trabalho realizado por:
-Gonçalo Taborda, nº14065
-Henrique Domingos, nº14064
-Manuel Roque, nº14061 
*/

#include <stdio.h>

/* Função para desenhar uma linha de caracteres
*/
void linha(int num, char ch)
{
    int i;
    for (i = 1; i <= num; i++)
    {
        putchar(ch);
    }
    putchar('\n');
}

/* Função para desenhar o padrão A
*/
void padraoA(int n)
{
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            printf("%d ", j);
            j++;
        }
        printf("\n");
        i++;
    }
}

/* Função para desenhar o padrão B
*/
void padraoB(int n)
{
    int i = n;
    while (i >= 1)
    {
        int j = 1;
        while (j <= i)
        {
            printf("%d ", j);
            j++;
        }
        printf("\n");
        i--;
    }
}

/* Função para desenhar o padrão C
*/
void padraoC(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            printf("  ");
        }
        for (j = i; j >= 1; j--)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
}

int main()
{
    int opcao;
    do
    {
        printf("\n");
        linha(38, '*'); /* Chama a função linha para desenhar uma linha de asteriscos */

        printf("* Seja muito bem-vindo utilizador!!! *\n");
        linha(38, '*'); /* Desenha outra linha de asteriscos */

        printf("* (1)\tDesenho de padroes           *\n");
        printf("* (2)\tContagem de alunos           *\n");
        printf("* (3)\tSair\t                     *\n");

        linha(38, '*'); /* Desenha mais uma linha de asteriscos */

        printf("\nResposta (Sem parenteses):  ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
        {
            int n;
            printf("Digite um numero entre 1 e 9: ");
            scanf("%d", &n);

            if (n >= 1 && n <= 9)
            {
                printf("# Padrao A\n");
                padraoA(n);

                printf("# Padrao B\n");
                padraoB(n);

                printf("# Padrao C\n");
                padraoC(n);
            }
            else
            {
                printf("Numero invalido. \n");
            }

            getchar();
        }
            break;

        case 2:
        {
            int alunos[1000]; /* Declara um array para armazenar números de alunos */
            int aluno, contagem = 0;

            printf("Qual o numero do aluno (resposta entre 100 e 200), e o 0 cancela a contagem.\n");

            while (1)
            {
                printf("Numero do seu aluno: \t");
                scanf("%d", &aluno);

                if (aluno == 0)
                {
                    break;
                }

                if (aluno >= 100 && aluno <= 200)
                {
                    int repetido = 0;
                    int i;
                    for (i = 0; i < contagem; i++)
                    {
                        if (aluno == alunos[i])
                        {
                            printf("Este aluno ja foi inserido, escreva outro!\n"); /* este for é um verificador dos alunos repetidos e só armazena os válidos */
                            repetido = 1;
                            break;
                        }
                    }

                    if (repetido == 0)
                    {
                        alunos[contagem] = aluno; /* Armazena o número do aluno no array */
                        contagem++;
                    }
                }

                else
                {
                    printf("Numero invalido!!!\n");
                }
            }

            printf("\n O total de alunos que nos deu foi: %d \n", contagem);

            if (contagem > 0)
            {
                int i;
                printf("Numeros dos alunos inseridos pela ordem que foram inseridos:\n");
                
                for (i = 0; i < contagem; i++)
                {
                    printf("%d ", alunos[i]); /* Organiza o array pela ordem de entrada que o utilizador forneceu*/
                }

                printf("\n");
                getchar(); /* Aguarda a pressão da tecla "ENTER"*/
                  
            }
        }
            break;

        case 3:
            printf("Hasta la vista!!!\n");
            break;

        default:
            printf("Opcao invalida, tenta outra vez...\n");
            break;
        }

        if (opcao != 3)
        {
            printf("Pressione <ENTER> para voltar...\n");
            getchar(); /* Aguarda a pressão de Enter*/
        }

    } while (opcao != 3);

    return 0;
}