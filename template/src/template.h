#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <getopt.h>
#include "config.h"

static struct option long_options[] =
        {
                {"version",  required_argument,       0, 'v'},
                {"help",  required_argument,       0, 'h'},
                {"fork",     required_argument,       0, 'f'},
                {"debug",     required_argument,       0, 'D'},
                {"socket",     required_argument,       0, 's'},
                {0, 0, 0, 0}
        };

struct config {
    const char *socket;
    int debug_level;
};

struct config _options;

void help ( void );
void version ( void );
int main (int argc, char **argv);
