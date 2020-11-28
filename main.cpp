#include <stdio.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char** argv) {

    const char* helpString = "Program options:\n"
    "-h, --help                          - get helping message\n"
    "-v, --version                       - get version number\n"
    "-n, --name                          - get name of program\n"
    "-l[<val1>,...], --list=[<num1>,...] - get list of arg\n";
    
    static struct option lOptions[] = {
        {"help",    no_argument,       0, 'h'},
        {"version", no_argument,       0, 'v'},
        {"name",    no_argument,       0, 'n'},
        {"list",    required_argument, 0, 'l'},
        {0,         0,                 0, 0  },
    };

    struct visitedStruct {
        bool h = false;
        bool v = false;
        bool n = false;
        bool l = false;
    } visitedStruct;
    
    const char* optionsString = "hvnl:";
    int optionIndex;
    int result;
    
    while ((result = getopt_long(argc, argv, optionsString, lOptions, &optionIndex)) != -1) {
        switch (result) {
           
           
            case 'n': {
                if (!visitedStruct.n) {
                    printf("Program name is 'AK2-lab3'\n");
                    visitedStruct.n = true;
                }
                break;
            }
      case 'v': {
                if (!visitedStruct.v) {
                    printf("Program version is lab3-3245.442.1\n");
                    visitedStruct.v = true;
                }
                break;
            }
            case 'l': {
                if (!visitedStruct.l) {
                    printf("Entered list of arguments: { ");
                    char* elem = strtok(optarg, ",");
                    while (elem != NULL) {
                        printf("%s ", elem);
                        elem = strtok(NULL, ",");
                    }
                    printf("}\n");
                    visitedStruct.l = true;
                }
                break;
            }
      case 'h': {
                if (!visitedStruct.h) {
                    printf("%s\n", helpString);
                    visitedStruct.h = true;
                }
                break;
            }
            default: {
                printf("Type -help or -h to output the arguments\n");
                return 0;
            }
        }
    }
    return 0;
}