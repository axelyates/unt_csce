#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <pthread.h>
#include <unistd.h>



int main(int argc,char *argv[])
{
    int GoingToExit = 0;
    char cmdstr [513];
    char dirstr[1024];
    FILE *fp = NULL;//this block opens the file
    
    if(argc == 2)//make sure if the correct amount of arguments exist, if not exit
    {

        fp = fopen(argv[1],"r");
        if(fp == NULL)//make sure the file opened, if not exit.
        {
            fprintf(stderr, "Can't open file, exiting.\n");
            exit(EXIT_FAILURE);
        }
        //set stdin to fp
        fclose(fp);
    }
    while(GoingToExit == 0)//get each line until EOF
    {
            printf ("prompt> ");
            gets(cmdstr);
            if(strlen(cmdstr) > 512)
            {
                fprintf(stderr, "Really long command line.\n");
            }
            else
            {
                char * tok; //token string
                char * tok2; //token string
                char temp_str[512];
                char * temp_str2;
                char ** argexe;
                char ** cmds;
                int cmd_count = 0;
                int argcount = 0;
                int pipe_redir = 0;
                int pipe_count = 0;
                int redir_count = 0;
                int * pipe_position;
                int fd[2];
                
                stpcpy(temp_str,cmdstr);
                //print("temp: %s\n", temp_str);
                tok = strtok(temp_str, ";\n"); //tokenizing string
                while(tok != NULL)
                {
                    cmd_count++;
                    //printf("%s\n", tok);
                    tok = strtok(NULL, ";\n"); //tokenizing string
                }
                cmds = malloc(cmd_count * sizeof(char*));
                int i=0;
                for(i=0; i < cmd_count; i++)
                {
                    cmds[i] = malloc(512 * sizeof(char));
                }
                stpcpy(temp_str,cmdstr);
                tok = strtok(temp_str, ";\n"); //tokenizing string
                i=0;
                while(tok != NULL)
                {
                    strcpy(cmds[i],tok);
                    printf("cmd: %s\n", cmds[i]);
                    tok = strtok(NULL, ";\n"); //tokenizing string
                    i++;
                }
                //SHOULD FORK INSIDE i for loop
                for(i=0; i < cmd_count; i++)
                {   
                    //FORK HERE for multiproc???
                    if(fork() == 0) //if child package and run process begin IF
                    {
                        int j;
                        stpcpy(temp_str,cmds[i]);
                        tok = strtok(temp_str, " "); //tokenizing string
                        while(tok != NULL)
                        {
                            if(strcmp("|",tok) == 0)
                            {
                                pipe_count++;
                            }
                            argcount++; 
                            tok = strtok(NULL, " "); //tokenizing string
                        }
                        argexe = malloc((argcount+1) * sizeof(char*));
                        for(j=0; j < (argcount+1); j++)
                        {
                            argexe[j] = malloc(512 * sizeof(char));
                        }
                        argexe[argcount] = NULL;
                        pipe_position = malloc((pipe_count+1) * sizeof(int));
                        pipe_count = 0;
                        argcount = 0;
                        stpcpy(temp_str,cmds[i]);
                        tok = strtok(temp_str, " "); //tokenizing string
                        while(tok != NULL)
                        {
                            strcpy(argexe[argcount],tok);
                            if(strcmp("|",argexe[argcount]) == 0)
                            {
                                pipe_position[pipe_count] = argcount;
                                pipe_count++;
                            }
                            printf("argexe: %s\n", argexe[argcount]);
                            argcount++;
                            tok = strtok(NULL, " "); //tokenizing string
                        }
                        //printf("made through token\n");
                        
                        
                        pipe_position[pipe_count] = argcount;
                        
                        //printf("made through array end setting\n");
                        
                        pipe_count = 0;
                        
                        for(j=0; j < argcount; j++)
                        {
                            int k, tempargc = 0;
                            char ** thisargs;
                            for(k=j; k < pipe_position[pipe_count]; k++)
                            {
                                if(strcmp ("exit",argexe[k]) == 0)
                                {
                                    printf("Going to exit\n");
                                    GoingToExit= 9;
                                    exit(GoingToExit);
                                }
                                else if(strcmp ("cd",argexe[k]) == 0)
                                {
                                    //change directory using argexe[k+1]
                                }
                                else if(strcmp ("path",argexe[k]) == 0)
                                {
                                    if(k == (argcount-1))
                                    {
                                        //print working directory
                                        printf("printing working directory\n");
                                    }
                                    else if(strcmp ("+",argexe[k+1]) == 0)
                                    {
                                        //append argexe[k+2] to directory and print it
                                        printf("printing working directory + %s\n", argexe[k+2]);
                                        k++;
                                        k++;
                                    }
                                    else if(strcmp ("-",argexe[k+1]) == 0)
                                    {
                                        //remove argexe[k+2] from directory and print it
                                        printf("printing working directory - %s\n", argexe[k+2]);
                                        k++;
                                        k++;
                                    }
                                    else if((k+1) == pipe_position[pipe_count])
                                    {
                                        //print working directory cause we hit a pipe
                                        printf("printing working directory\n");
                                    }
                                    else
                                    {
                                        fprintf(stderr, "Invalid use of path.\n");
                                    }
                                }
                                else
                                {
                                    if(strcmp ("<",argexe[k]) == 0)
                                    {
                                        //change stdin to argexe[k+1] 
                                        printf("changing stdin to %s\n", argexe[k+1]);
                                        k++;
                                    }
                                    else if(strcmp (">",argexe[k]) == 0)
                                    {
                                        //change stdout to argexe[k+1] 
                                        printf("changing stdout to %s\n", argexe[k+1]);
                                        k++;
                                    }
                                    else if(strcmp (">>",argexe[k]) == 0)
                                    {
                                        //change stdout to argexe[k+1] also append to file.
                                        printf("changing stdout to %s and appending to file\n", argexe[k+1]);
                                        k++;
                                    }
                                    else
                                    {
                                        tempargc++;
                                        //printf("Found an arg\n");
                                    }
                                }
                            }
                            //printf("got to this args\n");
                            thisargs = malloc((tempargc+1) * sizeof(char*));
                            int l, m=j;
                            for(l = 0; l < tempargc; l++)
                            {
                                thisargs[l] = malloc(512 * sizeof(char));   
                                strcpy(thisargs[l],argexe[m]);
                                printf("thisargs: %s\n", thisargs[l]);
                                m++;
                            }
                            thisargs[tempargc] = NULL;
                            //FORK AND PIPE HERE for piping 
                            //Do stuff  
                            free(thisargs);
                            //END PIPE FORK
                            j = pipe_position[pipe_count];
                            pipe_count++;
                        }
                        free(argexe);
                        free(pipe_position);
                        exit(0);
                    } //END IF
                    //Parent does nothing here they get to wait.
                    //END mutliproc FORK
                }
                for(i=0; i < cmd_count; i++)//if your the parent wait for all children to return.
                {
                    int status;
                    wait(&status);
                    if(status!=0)
                    {
                        GoingToExit = 9;
                    }
                }
            }
    }
    
    return 0;
}
