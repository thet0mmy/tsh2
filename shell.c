#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tsh/sparam_tsh.h"
#include "tsh/color_tsh.h"

#define TRUE 1
#define FALSE 0

FILE *cfg;
char cmd[99];
char prompt = '%';
int promptcolor = 1;

void loadCfgFile(void)
{
    char cfgBuf[99];
    char cfgBufBase[99];
    char cfgBufParam[99];
    
    while(!feof(cfg))
    {
        fgets(cfgBuf,99,cfg);
        
        strcpy(cfgBufBase,pgetbase(cfgBuf).string);
        strcpy(cfgBufParam,pgetparam(cfgBuf).string);

        if (strcmp(cfgBufBase,"PROMPT") == 0)
        {
            int promptChoice = atoi(cfgBufParam);
            switch(promptChoice)
            {
            case 1:
                prompt = '%';
                break;
            case 2:
                prompt = '$';
                break;
            case 3:
                prompt = '#';
                break;
            }
        }
    }
}

int isTshCommand(char cmd[])
{
    cmd[strlen(cmd) - 1] = '\0';
    if (strcmp(cmd,"tsh::info") == 0)
    {
        puts("tommy's shell (tsh). written in C using sparam.h");
        return TRUE;
    }

    if (strcmp(cmd,"tsh::credits") == 0)
    {
        puts("tommy wilson: all of the programming");
        puts("tommy wilson: everything else");
        return TRUE;
    }

    return FALSE;
}

int main(int argc, char *argv[])
{
/*
    cfg = fopen("~/.tshcfg/tsh.cfg","r");
    loadCfgFile();
*/

    puts("welcome to tommy's shell (tsh)");

    for(;;)
    {
        promptcolor = (promptcolor + 1) % 8;
        if (promptcolor == 0)
        {
            promptcolor = 1;
        }

        color(promptcolor);
        printf("%c ",prompt);
        colreset();

        fgets(cmd,99,stdin);
        if (isTshCommand(cmd) == 0)
        {
            system(cmd);
        }
    }
}