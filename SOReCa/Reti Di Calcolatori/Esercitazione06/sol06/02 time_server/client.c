#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>  // htons() and inet_addr()
#include <netinet/in.h> // struct sockaddr_in
#include <sys/socket.h>

#include "common.h"

int main(int argc, char* argv[]) {
    int ret;

    // variables for handling a socket
    int socket_desc;
    struct sockaddr_in server_addr = {0}; // some fields are required to be filled with 0

    // create a socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc < 0) handle_error("Could not create socket");

    // set up parameters for the connection
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    server_addr.sin_family      = AF_INET;
    server_addr.sin_port        = htons(SERVER_PORT); // don't forget about network byte order!

    // initiate a connection on the socket
    ret = connect(socket_desc, (struct sockaddr*) &server_addr, sizeof(struct sockaddr_in));
    if (ret < 0) handle_error("Could not create connection");

    if (DEBUG) fprintf(stderr, "Connection established!\n");

    // send command to server
    char* command = SERVER_COMMAND;
    size_t command_len = strlen(command);

    /** [SOLUTION]
     *
     * Suggestions:
     * - send() with flags = 0 is equivalent to write() on a descriptor
     * 
     * For the time being we won't deal with partially sent messages.
     */
    int bytes_sent=0;
    while ( bytes_sent < command_len) {
        ret = send(socket_desc, command + bytes_sent, command_len - bytes_sent, 0);
        if (ret == -1 && errno == EINTR) continue;
        if (ret == -1) handle_error("Cannot write to the socket");
        bytes_sent += ret;
    }

    if (DEBUG) fprintf(stderr, "Message of %d bytes sent\n", ret);

    // read message from the server
    char recv_buf[256];
    size_t recv_buf_len = sizeof(recv_buf);
    int recv_bytes;

    /** [SOLUTION]
     *
     * Suggestions:
     * - recv() with flags = 0 is equivalent to read() on a descriptor
     * - on a socket we get 0 as return value only when the peer closes
     *   the connection: if there are no bytes to read and we invoke
     *   recv() we will get stuck since the call is blocking!
     * - store the number of received bytes in recv_bytes
     *
     * For the time being we don't deal with partially received replies!
     */
    recv_bytes = 0;
    do {
        ret = recv(socket_desc, recv_buf + recv_bytes, recv_buf_len-recv_bytes, 0);
        if (ret == -1 && errno == EINTR) continue;
        if (ret == -1) handle_error("Cannot read from the socket");
        if (ret == 0) break; // IMPORTANTE SENNO' CICLA ALL'INFINITO
        recv_bytes += ret;
    } while ( recv_buf[recv_bytes-1] != '\n' );  

    
    if (DEBUG) fprintf(stderr, "Message of %d bytes received\n", recv_bytes);

    recv_buf[recv_bytes] = '\0'; // add string terminator manually!

    // close the socket
    ret = close(socket_desc);
    if (ret < 0) handle_error("Cannot close socket");

    printf("Answer from server: %s", recv_buf);

    if (DEBUG) fprintf(stderr, "Exiting...\n");

    exit(EXIT_SUCCESS);
}
