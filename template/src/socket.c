#include "gpiod.h"

int
sock_init() {
    struct sockaddr_un local;
    int sock;

    /* Create the socket. */
    if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {

        log_err(errno, "could not allocate UNIX Socket!");

    } else {

        local.sun_family = AF_UNIX;

        /* Bind a name to the socket. */
        strcpy(local.sun_path, SOCKET_FILE);
        unlink(local.sun_path);

        if (bind(sock, (struct sockaddr *)&local,
                 sizeof(struct sockaddr_un)) == -1) {
            log_err(errno, "could bind UNIX Socket!");
            close(sock);
            sock = -1;
        } else {
            if (listen(sock, 5) == -1) {
                log_err(errno, "could listen to UNIX Socket!");
                close(sock);
                sock = -1;
            }
        }
    }

    return cmdsock;
}


void cmdsock_shutdown(int s) {
    if (s < 0) {
        return;
    }
    log_dbg("Shutting down cmdsocket");
    shutdown(s, 2);
    close(s);
}