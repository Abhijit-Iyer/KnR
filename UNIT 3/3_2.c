#include <stdio.h>

#define LINESIZE 10000

int getline(char []);
int escape(char [],char []);
int redirection_escape(char [], char[]);

void main()
{
	char line[LINESIZE],newline[LINESIZE],redirection_line[LINESIZE];
	if(getline(line))
	{
		printf("\n TEXT WITH ESCAPE SEQUENCES: \n\n ");

		escape(line,newline);

		printf("%s\n",newline );

		printf("\n REDIRECTED TEXT: \n\n ");

		redirection_escape(newline,redirection_line);

		printf("%s\n", redirection_line);
	}
}

int getline(char line[])
{
	char ch;
	int index=0;
	while((ch=getchar()) != EOF)
		line[index++] = ch;
	if(ch == '\n')
	{
		line[index++] = ch;
	}
	line[index] = '\0';
	return index;
}

int escape(char line[], char newline[])
{
	int line_index = 0, newline_index = 0;
	while(line[line_index] != '\0')
	{
		switch(line[line_index])
		{
			case '\n' : newline[newline_index] = '\\';
						newline_index++;
						newline[newline_index] = 'n';
						break;

			case '\t' : newline[newline_index] = '\\';
						newline_index++;
						newline[newline_index] = 't';
						break;

			default   : newline[newline_index] = line[line_index];
						break;
		}
		newline_index++; line_index++;
	}

	newline[newline_index] = '\0';
}

int redirection_escape(char newline[], char redirection_line[])
{
	int newline_index = 0, redirection_line_index = 0;
	while(newline[newline_index] != '\0')
	{
		if(newline[newline_index] == '\\')
		{
			newline_index++;
			switch(newline[newline_index])
			{
				case 'n' : redirection_line[redirection_line_index] = '\n';
							redirection_line_index++; newline_index++;
							break;

				case 't' : redirection_line[redirection_line_index] = '\t';
							redirection_line_index++; newline_index++;
							break;
			}
		}
		redirection_line[redirection_line_index] = newline[newline_index];
		redirection_line_index++; newline_index++;
	}
}
