#include "template.h"

void help(void) {
    printf("Usage: template [OPTIONS]\n");
    printf("\t-h --help\t\t\tDisplay this help message.\n");
    printf("\t-f --fork\t\t\tFork to background\n");
    printf("\t-D --debug\t<LEVEL>\t\tDebug to stdout. Debug level (1-5).\n");
    printf("\t-v --version\t\t\tDisplay version.\n");
}

void version(void) {
    printf("%s %s\n", NAME, VERSION);
}

static void init_defaults_pre(void) {
    _options.debug_level = 0;
    _options.socket = "/var/template.soc";
}

int main(int argc, char **argv) {
    int c, option_index = 0;
    int do_fork = 0;
    int cur_fd;

    init_defaults_pre();

    while ((c = getopt_long(argc, argv, "vhfD:s:", long_options, &option_index)) != -1) {
        /* getopt_long stores the option index here. */
        option_index = 0;

        switch (c) {
            case 'v':
                version();
                break;

            case 'f':
                printf("Fork\n");
                do_fork = 1;
                break;

            case 'D':
                _options.debug_level = atoi(optarg);;
                printf("Debug level %d\n", _options.debug_level);
                break;
            case 's':
                _options.socket = optarg;
                printf("Socket file '%s'", _options.socket);
                break;
            case '?':
            case 'h':
                help();
                exit(0);

            default:
                help();
                exit(0);
        }
    }

    /* fork (if enabled) */
    if (do_fork) {
        switch (fork()) {
            case -1:
                perror("fork()");
                exit(1);

            case 0:
                /* daemon setup */
                if (chdir("/"))
                    perror("chdir()");

                cur_fd = open("/dev/null", O_WRONLY);
                if (cur_fd > 0) {
                    dup2(cur_fd, 0);
                    dup2(cur_fd, 1);
                    dup2(cur_fd, 2);
                }

                break;

            default:
                exit(0);
        }
    }

    while (1) {
        printf("Template alive\n");
	sleep(1);
    }
}