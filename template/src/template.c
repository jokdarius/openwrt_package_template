#include "gpiod.h"

void help ( void ){
  printf("Usage: gpiod [OPTIONS]\n");
  printf("\t-h --help\t\t\tDisplay this help message.\n");
  printf("\t-d --daemon\t\t\tDaemonize.\n");
  printf("\t-D --debug\t<LEVEL>\t\tDebug to stdout. Debug level (1-5).\n");
  printf("\t-v --version\t\t\tDisplay version.\n");
}

void version ( void ){
  printf("%s %s\n", NAME, VERSION);
}

int main (int argc, char **argv)
{
  int c;

  while (1)
  {
    static struct option long_options[] =
            {
                    {"version",  required_argument,       0, 'v'},
                    {"help",  required_argument,       0, 'h'},
                    {"daemon",     required_argument,       0, 'd'},
                    {"debug",     required_argument,       0, 'D'},
                    {"socket",  required_argument,       0, 's'},
                    {0, 0, 0, 0}
            };
    /* getopt_long stores the option index here. */
    int option_index = 0;

    c = getopt_long (argc, argv, "vhdD:s:", long_options, &option_index);

    if (c == -1)
      break;

    switch (c)
    {
      case 'v':
        version ();
            break;

      case 'd':
        printf("Daemonize\n");
            break;

      case 's':
        printf("Daemonize socket file\n");
            break;

      case 'D':
        printf("Debug\n");
            break;

      case '?':
      case 'h':
        help ();
            exit (0);

      default:
        help ();
            exit (0);
    }
  }

  exit (0);
}