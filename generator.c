#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <dirent.h>
/**
* This function (generator) compile two input C programs referenceCodeFileName  and testCodeFileName C programs
* referenceCodeFileName C program define correct program that compile well
* When compile referenceCodeFileName C program with GCC referenceprogram.exe generate
* testCodeFileName C program define program that we are testing with judge and compare to referenceCodeFileName output
* @param referenceCodeFileName The reference file name written by student
* @param testCodeFileName The testing file name written by teacher and working well
* @param s1 @param s2 @param s3 @param s4 are strings that generate commands for program to execute 
*/

char referenceCodeFileName[100];
char testCodeFileName[100];
char s1[100],s2[100],s3[100],s4[100];
int generator(){
//system(gcc p1.c -o p1.exe)
    printf("Enter Referance C Program filename (without extention):");
    scanf("%s",referenceCodeFileName);
    printf("Enter Testing C Program filename (without extention):");
    scanf("%s",testCodeFileName);
    strcpy(s1,"gcc ");
    strcpy(s2,testCodeFileName);
    strcpy(s3,".c -o testprogram.exe");
    strcat(s1,s2);
    strcat(s1,s3);
    if(system(s1)){
        printf("----------------------------------------\n");
        printf("error on compile test code! \n");
        printf("----------------------------------------\n");
        return -1;
    }
    ////////////////
    strcpy(s1,"gcc ");
    strcpy(s2,referenceCodeFileName);
    strcpy(s3,".c -o referenceprogram.exe");
    strcat(s1,s2);
    strcat(s1,s3);
    if(system(s1)){
        printf("----------------------------------------\n");
        printf("error on compile reference code! \n");
        printf("----------------------------------------\n");
        return -1;
    }
  
    else{
        DIR *d;
        int counter=0;
        int countOfTestCases=1;
        struct dirent *dir;
        d = opendir("input");
        if (d) {
            while ((dir = readdir(d)) != NULL)
            {
                if(counter>=2){

                    /**
                    * runnig test compiled program (testprogram.exe) and generate output files with input files
                    * read input files from input directory
                    * input file names : input1.txt   input2.txt etc ...
                    * store output files in testoutput directory
                    * output file names : output1.txt   output2.txt etc ...
                    */

                    strcpy(s1,"testprogram.exe <.\\input\\");
                    strcpy(s2,dir->d_name);

                    strcpy(s3,">.\\test_output\\test_output");
                    itoa(countOfTestCases,s4,10);
                    strcat(s1,s2);
                    strcat(s1,s3);
                    strcat(s1,s4);
                    strcat(s1,".txt");
                    system(s1);

                    /**
                    * runnig reference compiled program (referenceprogram.exe) and generate output files with input files
                    * read input files from input directory
                    * input file names : input1.txt   input2.txt etc ...
                    * store output files in referenceoutput directory
                    * output file names : output1.txt   output2.txt etc ...
                    */

                    strcpy(s1,"referenceprogram.exe <.\\input\\");
                    strcpy(s2,dir->d_name);
                    strcpy(s3,">.\\ref_output\\ref_output");
                    itoa(countOfTestCases,s4,10);
                    strcat(s1,s2);
                    strcat(s1,s3);
                    strcat(s1,s4);
                    strcat(s1,".txt");
                    system(s1);
                    countOfTestCases++;

                }
                counter++;
            }
            closedir(d);
        }
        printf("Total number of testcases : %d\n",countOfTestCases-1);

        return countOfTestCases; 
        }
        printf("------------------------------------------------------------------------------------------------\n");

    
}
