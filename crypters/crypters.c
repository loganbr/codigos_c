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
#include <unistd.h>

char texto[28];
int cont=0;
int chave;

void limpa_tela(FILE *in) {
	int caracter;
	clearerr(in);
	do
        caracter = getc(in);
	while ( caracter != '\n' && caracter != EOF);
	clearerr(in);
}
int main(int argc,char* argv[]){
    
        int opt;
	static char opcoes[] = "cdfv:?";
        
	opt = getopt(argc,argv,opcoes);      	
            switch (opt) 
	     {
                case 'c':
                    printf("Encrypts Text Entered -c.\n");

		    if(opt > -1)
		    {
		      printf("\n ROT-13 Entre com uma chave de ate 13 posicoes");
		      printf("\n(KEY): ");
		      fflush(stdout);
		      /** Ajustar **/
		      /** while (scanf("%d", &chave) != 1 || &chave > 14) { **/
            while (scanf("%d", &chave) != 1) {
			limpa_tela(stdin);
			printf("Valor invalido, use apenas numeros menores que 13. Por favor tente novamente: ");
			fflush(stdout);
		      }
		      printf("\n Digite o texto a ser encriptado: ");
		      scanf("%s",texto);
		      printf("\n\n Frase encriptada com sucesso!\n\n");
		      printf("Encriptacao:  ");
		      for (cont=0;cont<strlen(texto);cont++) {
			int enc=(int)texto[cont]+chave;
			printf("%c",(char)enc);
		      }
		    }
		    else
		      {
			        /** Precisa deste printf??? Em que momento ele e usado?**/
                    printf("Falta passar parametros..");
                    break;
                case 'd':
                    printf("Decrypts text showing 13 possible keys -d. \n");
                    break;
                case 'f':
                    printf("File Format -f. \n");
                    break;
                case 'v':
                    printf("Version -v. with argument %s \n", optarg);
                    break;
                default:
printf("\nCryptrot13 - Is an Simple tool for encryption and decryption texts.\n\n");
printf("Usage: %s [-c] [-d] [-f] [-v <something>].\n", argv[0]);
printf("-c  -Encrypts Text Entered\n");
printf("-d  -Decrypts Text showing 13 possible keys\n");
printf("-f  -Format <text|csv|xml|html>\n");
printf("-h  -Show this help and exit\n");
printf("-v  -Version with argument\n");
}
				 }
printf("\n");
return 0;
}
