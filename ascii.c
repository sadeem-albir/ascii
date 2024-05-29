#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ascii(char *s, int bin, int hex);
char *input(char *s);

int main(int argc, char *argv[])
{
	int c, bin, hex, typo;
	bin = hex = typo = 0;

	while (--argc > 0 && **++argv == '-')
		while (!typo && (c = (++*argv)[0])) {
			switch(c) {
				case 'b':
					if (!hex)
						bin = 1;
					else {
						argc = 0;
						typo = 1;
					}
					break;
				case 'x':
					if (!bin)
						hex = 1;
					else {
						argc = 0;
						typo = 1;
					}
					break;
				default:
					printf("Unknown option: %c\n", c);
					argc = 0;
					typo = 1;
					break;
			}
		}



	char *s = NULL;

	if (argc > 0) {
		s = malloc(sizeof(char));
		*s = '\0';
		size_t string_length = 0;

		while (argc-- > 0) {
			string_length += strlen(*argv);

			if ((s = realloc(s, sizeof(char) * string_length + 1)) == NULL) {
				printf("error: too much input to translate.\n");
				typo = 1;
			}
			strcat(s, *argv++);
			if (argc > 0) {
				s = realloc(s, sizeof(char) * ++string_length + 1);
				strcat(s, " ");
			}
		}
	} else
		s = input(s);



	if (typo) {
		printf("Usage: ascii [OPTIONS] [TEXT]\n\n  shows ascii value of TEXT.\n\n");
		printf("Options:\n\n\t-b: show in binary format\n\t-x: show in hexadecimal format\n\n");
		free(s);
		return 1;
	} else {
		print_ascii(s, bin, hex);
		free(s);
		return 0;
	}
}

void print_ascii(char *s, int bin, int hex)
{
	int linebreak = 0;
	if (bin)
		while (*s) {
			linebreak++;
			printf("%b%c", *s++, !(linebreak % 10) ? '\n' : ' ');
		}
	else if (hex)
		while (*s) {
			linebreak++;
			printf("0x%x%c", *s++, !(linebreak % 10) ? '\n' : ' ');
		}
	else
		while (*s) {
			linebreak++;
			printf("%d%c", *s++, !(linebreak % 10) ? '\n' : ' ');
		}
	printf("\n\n");
}

char *input(char *s)
{
	int c;
	size_t byte = 0;
	s = malloc(sizeof(char));
	*s = '\0';

nextline:
	while ((c = getchar()) != EOF && c != '\n') {
		s = realloc(s, sizeof(char) + byte + 1);
		s[byte++] = c;
	}
	if (c == '\n') {
		s = realloc(s, sizeof(char) + byte + 1);
		s[byte++] = c;
		goto nextline;
	}
	s[byte] = '\0';

	return s;
}
