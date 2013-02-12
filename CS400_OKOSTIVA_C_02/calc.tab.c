// This file emulates the file that would normally be created by Bison
// This file would normally be generated by Bison

#include <stdio.h>
#include <stdlib.h>

#include "calc.tab.h"

FILE *yyin = NULL;
char *yytext = NULL;

char *tokenValue(int token)
{
	switch (token)
	{
		case END:
			return "<END>";
		case ID:
			return "<ID>";
		case INT:
			return "<INT>";
		case FLT:
			return "<FLT>";
		case OPAREN:
			return "<OPAREN>";
		case CPAREN:
			return "<CPAREN>";
		case ASSIGN:
			return "<ASSIGN>";
		case EXP:
			return "<EXP>";
		case MUL:
			return "<MUL>";
		case DIV:
			return "<DIV>";
		case ADD:
			return "<ADD>";
		case SUB:
			return "<SUB>";
		case SEMI:
			return "<SEMI>";
		case BAD:
			return "<BAD>";
		case NEWLINE:
			return "<NEWLINE>";
		case EOLCMT:
			return "<EOLCMT>";
		case BLKCMT:
			return "<BLKCMT>";
	}
}

int ExportToken(FILE *yyout, int token, char *yytext)
{
    fprintf(yyout, "%-10s %s\n", tokenValue(token), ((yytext)? yytext:""));
    if (yytext)
       free(yytext);
    yytext = NULL;
    return 0;
}

int yyparse(char const *filename)
{
   FILE *yyout;
   int token;
   
   yyin = fopen(filename, "rt");
   if (!yyin)
   {
      printf("File %s failed to open.\n", filename);
      return -1;
   }

   yyout = fopen(OUTPUTFILE, "wt");
   if (!yyout)
   {
      printf("File %s failed to open.\n", OUTPUTFILE);
      return -2;
   }

   while (token=yylex())
      ExportToken(yyout, token, yytext);
   ExportToken(yyout, token, yytext);
   
   fclose(yyin);
   fclose(yyout);
   
   return 0;
}

