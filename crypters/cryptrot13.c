/*
 cryptrot13 - Is an Simple tool for encryption and decryption texts

 Author: "Ricardo Logan"
 Contact: ricardologanbr[at]gmail[dot]com
 
        Copyright (C) 2013 rot13 authors

        This program is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h> /** realmente preciso? **/

char texto[20];
int cont=0;
int chave;

void limpa_tela(FILE *in)
{
	int caracter;
	clearerr(in);
	do
         caracter = getc(in);
	while ( caracter != '\n' && caracter != EOF);
	clearerr(in);
}

int 
main(int argc,char* argv[])
{
    
        int opt;
        
        while (1) 
        {
            char a;
            
            a = getopt (argc, argv, "cdv:");
            if (a == -1) 
                /* We have finished processing all the arguments. */
                break;
            
            switch (a) 
            {
                case 'c':
                    printf ("Encrypts Text Entered -c.\n");
                    break;
                case 'd':
                    printf ("Decrypts text showing 13 possible keys -d. \n", optarg);
                    break;
                case 'v':
                    printf ("Version -v. \n", optarg);
                    break;
                case '?':
                default:
                    printf ("Usage: %s [-c] [-d] [-v <something>].\n", argv[0]);
            }
        }
    argc -= optind;
    argv += optind;
    if (argc > 0) {
        printf ("There are %d command-line arguments left to process:\n", argc);
        for (opt = 0; opt < argc; opt++) {
            printf ("    Argument %d: '%s'\n", opt + 1, argv[opt]);
        }
    }
	printf("\n\n ROT-13 Entre com uma chave de até 13 posicoes");
	printf("\n\n (KEY): ");
	fflush(stdout);
     /** Ajustar **/
    /** while (scanf("%d", &chave) != 1 || &chave > 14) { **/
	while (scanf("%d", &chave) != 1) {
		limpa_tela(stdin);
		printf("Valor invalido, use apenas numeros menores que 13. Por favor tente novamente: ");
		fflush(stdout);
	}
	printf("\nDigite o texto a ser encriptado: ");
	scanf("%s",texto);
	printf("\n\nFrase encriptada com sucesso!\n\n");
	printf("Encriptacao:  ");
	for (cont=0;cont<strlen(texto);cont++) {
		int enc=(int)texto[cont]+chave;
		printf("%c",(char)enc);
	}
	printf("\n");
	return 0;
}

