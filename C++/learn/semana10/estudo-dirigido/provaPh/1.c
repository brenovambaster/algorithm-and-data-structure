#include <stdio.h>
typedef struct
{
    char nome[123];
    int idade;
} paciente_t;

void ler_paciente(paciente_t *p1)
{
    printf("nome:");
    scanf("%s", &p1->nome);
    printf("idade:");
    scanf("%i", &p1->idade);
    printf("nome ler paciente: %s\n", p1->nome);
}
int main()
{
    paciente_t p1, p2;
    ler_paciente(&p1);
    ler_paciente(&p2);
    printf("\n-----------------dados------------\n");
    printf("nome p1: %s\n", p1.nome);
    printf("idade p1: %i\n", p1.idade);
    printf("nome p2: %s\n", p2.nome);
    printf("idade p2: %i\n", p2.idade);
    return 0;
}