/* 
 * Copyright (c) 2014, Kyushu Univ.
 * All rights reserved.
 */

/**
 * @file
 *      Number data counter main module.
 * @author
 *      Shigemi Ishida <ishida+devel@f.ait.kyushu-u.ac.jp>
 *
 * Number data counter program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

/*======================================================================
 * global variables
 *======================================================================*/

/*------------------------------
 * private
 *------------------------------*/

/*======================================================================
 * prototype declarations for private functions
 *======================================================================*/
static void usage(void);
static int load_data(char *filename, int *buf);
static int count_data(int target, int *buf);

/*======================================================================
 * functions
 *======================================================================*/
int main(int argc, char *argv[])
{
    int data[MAX_DATA+1] = {};/* input numbers; initialize with -1 */
    int arg_cnt;                /* counter for processing arguments */
    int arg_num;                /* number specified by an argument */
    int ret;                    /* return value handler */
    int i;

    for(i = 0; i < (MAX_DATA + 1); i++)data[i] = -1;

    /* handle arguments */
    if ( (argc < 2) || (argc > MAX_ARGS + 2) )
    {
        fprintf(stderr, "Invalid arguments.\n");
        usage();
        exit(-1);
    }

    /* open input file and load data on to number[] */
    ret = load_data(argv[1], data);
    if (ret < 0)
    {
        exit(-1);
    }

    //for(i = 0;data[i] != -1;i++)printf("data = %d \n",data[i]);

    /* process each number specified by arguments */
    for (arg_cnt = 2; arg_cnt < argc; arg_cnt++)
    {
        /* convert argument string to number */
        arg_num = (int)strtol(argv[arg_cnt], NULL, 10);

        /* count data */
        ret = count_data(arg_num, data);

        /* print result */
        printf("%d %d\n", arg_num, ret);
    }

    return(0);
}

/*======================================================================
 * private functions
 *======================================================================*/
static void usage(void)
{
    puts("Usage:");
    puts("\tnum_count <datafile> [num1] [num2] ...");

    return;
}

/*----------------------------------------------------------------------*/
static int load_data(char *filename, int *buf)
{
    FILE *dataf = NULL;         /* data file pointer */
    char *ret;
    char linebuf[5];            /* buffer for line read */

    /* open data file */
    dataf = fopen(filename, "r");
    if (!dataf)
    {
        fprintf(stderr, "Cannot open data file: %s\n", filename);
        perror("fopen");
        return(-1);
    }

    /* read from data file */
    while (*buf == -1)
    {
        ret = fgets(linebuf, sizeof(linebuf), dataf);
        if (!ret)
        {
            /* end of file */
            fclose(dataf);
            return(0);
        }

        //printf("data = %s \n",linebuf);

        /* convert string to integer and store */
        *buf = (int)strtol(linebuf, NULL, 10);

        buf++;
    }

    fclose(dataf);
    return(0);
}

/*----------------------------------------------------------------------*/
static int count_data(int target, int *buf)
{

    int result = 0;

    while (*buf != -1)
    {
        if (*buf == target)
            result++;
        buf++;
    }

    return(result);
}

/* end of main.c */
