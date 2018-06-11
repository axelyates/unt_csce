#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <pthread.h>
#include <unistd.h>



int main(int argc,char *argv[])
{
    int GoingToExit = 0;
    char cmdstr [513];
    char *pathstr;
    FILE *fp = NULL;//this block opens the file
    if(argc > 2)//incorrect number of arguments
    {
        fprintf(stderr, "Incorrect number of arguments.\n");
    }
    else if(argc == 2)//batch mode
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
            char * tok; //token string
            char * tok2; //token string
            char temp_str[512];
            char * temp_str2;
            char ** argexe;
            char ** cmds;
            int argcount = 0;
            int pipe_redir = 0;
            int pipe_count = 0;
            int redir_count = 0;
            int * pipe_position;
            int cmd_count = 0;
            if(strlen(cmdstr) > 512)
            {
                fprintf(stderr, "Really long command line.\n");
            }
            else
            {
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
                    //printf("cmd: %s\n", cmds[i]);
                    tok = strtok(NULL, ";\n"); //tokenizing string
                    i++;
                }
                //SHOULD FORK INSIDE i for loop
                for(i=0; i < cmd_count; i++)
                {   
                    //cmd parseing
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
                        //printf("argexe: %s\n", argexe[argcount]);
                        argcount++;
                        tok = strtok(NULL, " "); //tokenizing string
                    }
                    //printf("made through token\n");
                    int num_pipes = pipe_count;
                    
                    pipe_position[pipe_count] = argcount;
                    
                    //printf("made through array end setting\n");
                    
                    pipe_count = 0;
                    int inbuilt = 0;
                    int k = 0;
                    if(strcmp ("exit",argexe[k]) == 0)//check if current command is a built in command
                    {
                        printf("Going to exit\n");
                        GoingToExit= 1;
                        inbuilt = 1;
                    }
                    else if(strcmp ("cd",argexe[k]) == 0)
                    {
                        int ret;
                        char cwd[1000];
                        ret = chdir(argexe[k+1]);
                        if(getcwd(cwd, sizeof(cwd)) != NULL){
                        printf("Current working directory: %s\n", cwd);
                        }
                        inbuilt = 2;
                    }
                    else if(strcmp ("path",argexe[k]) == 0)
                    {
                        if(k == (argcount-1))
                        {
                            //print path variable
                            pathstr = getenv("PATH");
                            printf("PATH: %s\n",(pathstr != NULL)? pathstr : "getenv returned NULL");
                            printf("printed path\n");
                            inbuilt = 3;
                        }
                        else if(strcmp ("+",argexe[k+1]) == 0)
                        {
                            //append argexe[k+2] to path variable and print it
                            char plus_path[1000];
                            strcpy(plus_path, argexe[k+2]);
                            pathstr = getenv("PATH");
                            strcat(pathstr, plus_path);
                            printf("printing path + %s\n", argexe[k+2]);
                            printf("path is now = %s\n", pathstr);
                            inbuilt = 4;
                        }
                        else if(strcmp ("-",argexe[k+1]) == 0)
                        {
                            //remove argexe[k+2] from path variable and print it

                            //just need to add functionality of removing "removing" from "pathstr"


                            char *removing = strstr(pathstr, argexe[k+2]); //this grabs what you want to remove
                            pathstr = getenv("PATH");
                            printf("printing path - %s\n", argexe[k+2]);
                            printf("removing = %s\n", removing);
                            printf("printing pathstr %s\n", pathstr);
                            inbuilt = 5;
                        }
                        else
                        {
                            fprintf(stderr, "Invalid use of path.\n");
                        }
                    }
                    //FORK HERE for multiproc
                    if(fork() == 0) //if child take package parent made and run process
                    {
                        if(inbuilt == 0)//if not inbuilt
                        {
                                for(j=0; j < argcount; j++)//check to see if current cmd is a built in.
                                {
                                    int k, tempargc = 0;
                                    char ** thisargs;
                                    for(k=j; k < pipe_position[pipe_count]; k++)
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
                                    //printf("got to this args\n");
                                    if(tempargc > 0)
                                    {
                                        thisargs = malloc((tempargc+1) * sizeof(char*));
                                        int l, m=j;
                                        for(l = 0; l < tempargc; l++)
                                        {
                                            thisargs[l] = malloc(512 * sizeof(char));   
                                            strcpy(thisargs[l],argexe[m]);
                                            //fprintf(stderr, "thisargs: %s\n", thisargs[l]);
                                            m++;
                                        }
                                        thisargs[tempargc] = NULL;
                                        //FORK AND PIPE HERE for piping 
                                        if(num_pipes > 0 && pipe_count < num_pipes) //if there are pipes
                                        {
                                            int fd[2];
                                            pipe(fd);
                                            if(fork() == 0)// In the child
                                            {
                                                dup2(fd[1], fileno(stdout)); //put this processes stdout to the write end of pipe
                                                //close where appropriate
                                                close(fd[0]);
                                                close(fd[1]);
                                                //execute the command with thisargs
                                                if (fork() == 0)
                                                {
                                                    //printf("Executing a Child of a pipe\n");
                                                    if(thisargs[0][0] == '/')
                                                    {
                                                        execv(thisargs[0], thisargs);
                                                    }
                                                    else
                                                    {
                                                        execvp(thisargs[0], thisargs);
                                                    }
                                                    exit(0);
                                                }
                                                else
                                                {
                                                    waitpid(0,NULL,0);
                                                    //printf("Child of a pipe Ended\n");
                                                }
                                                free(thisargs);
                                                exit(0);
                                            }
                                            else
                                            {
                                                dup2(fd[0], fileno(stdin)); //put this processes stdin to the read end of pipe
                                                free(thisargs);
                                                //close where appropriate
                                                close(fd[0]);
                                                close(fd[1]);
                                            }
                                        }
                                        else
                                        {
                                            if (fork() == 0)
                                            {
                                                if(thisargs[0][0] == '/')
                                                {
                                                    execv(thisargs[0], thisargs);
                                                }
                                                else
                                                {
                                                    execvp(thisargs[0], thisargs);
                                                }
                                                exit(0);
                                            }
                                            else
                                            {
                                                 waitpid(0,NULL,0);
                                                 //printf("Child Ended\n");
                                            }
                                            if(pipe_count >= num_pipes)//if you  are the parent and finished executing the last part of a piped command wait on the rest.
                                            {
                                                int p = 0;
                                                for(p = 0; p < num_pipes; p++)
                                                {
                                                    waitpid(0,NULL,0);
                                                }
                                            }
                                            free(thisargs);
                                        }
                                    }
                                    //END PIPE FORK
                                    j = pipe_position[pipe_count];
                                    pipe_count++;
                                }       
                            }
                            
                            free(argexe);
                            free(pipe_position);
                            exit(0);
                        }
                        //if parent free memory of stuff.
                        free(argexe);
                        free(pipe_position);
                    }

                    //Parent does nothing here they get to wait.
                    //END mutliproc FORK

                }
                int i;
                for(i=0; i < cmd_count; i++)//if your the parent wait for all children to return.
                {
                    int status;
                    waitpid(0,&status,0);
                    //printf("Child Ended\n");
                }

    }
    
    return 0;
}
