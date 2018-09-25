//
// Created by Arpit Jain on 9/22/18.
//
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "cmd_line_args.h"

int main(int argc, char *argv[]) {

    int opt;

    cmdLineArg inputArg = getDefaultInputArg();

    while ((opt = getopt(argc, argv, "p:s::U::S::v::c::")) != -1) {

        switch (opt) {

            case 'p':
                inputArg.processIdFlag = true;
                //TODO: This can actually be a character also. Make changes in cmdLineArg.
                inputArg.pid = atoi(optarg);
                break;

            case 's':
                inputArg.stateFlag = 1;
                inputArg.stateOptArg = optarg;
                break;

            case 'U':
                inputArg.userTimeOptArg = optarg;
                break;

            case 'S':
                inputArg.systemTimeFlag = '1';
                inputArg.systemTimeOptArg = optarg;
                break;

            case 'v':
                inputArg.vMemFlag = '1';
                inputArg.vMemOptArg = optarg;
                break;

            case 'c':
                inputArg.cmdLineFlag = '1';
                inputArg.cmdLineOptArg = optarg;
                break;

            default: /* '?' */
                fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
                        argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    toString(inputArg);

//    if (optind >= argc) {
//        fprintf(stderr, "Expected argument after options\n");
//        exit(EXIT_FAILURE);
//    }

//    printf("name argument = %s\n", argv[optind]);
//    printf("t argument = %s\n", argv[optind]);

    exit(EXIT_SUCCESS);
}