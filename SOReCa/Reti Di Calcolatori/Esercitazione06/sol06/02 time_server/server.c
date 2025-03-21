#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>  // htons()
#include <netinet/in.h> // struct sockaddr_in
#include <sys/socket.h>

#include "common.h"

void connection_handler(int socket_desc) {
    int ret;
    char* allowed_command = SERVER_COMMAND;
    size_t allowed_command_len = strlen(allowed_command);
    char send_buf[256];

    // receive command from client
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
        if (ret == 0) break;
        recv_bytes += ret;
        if (DEBUG) fprintf(stderr, "Message of %d bytes received\n", recv_bytes);
    } while ( recv_buf[recv_bytes-1] != '\n' );  

    if (DEBUG) fprintf(stderr, "Message of %d bytes received\n", recv_bytes);

    // parse command received and write reply in send_buf
    if (recv_bytes == allowed_command_len && !memcmp(recv_buf, allowed_command, allowed_command_len)) {
        time_t curr_time;
        time(&curr_time);
        sprintf(send_buf, "%s\n", ctime(&curr_time));
    } else {
        sprintf(send_buf, "INVALID REQUEST");
    }

    // send reply
    size_t server_message_len = strlen(send_buf);
    printf("Sending message %s of length %d\n", send_buf, server_message_len);

    /** INSERT CODE TO SEND DATA HERE
     *
     * Suggestions:
     * - send() with flags = 0 is equivalent to write() on a descriptor
     * - for now don't deal with messages partially sent
     *
     * For the time being we won't deal with partially sent messages!
     */
    int bytes_sent=0;
    while ( bytes_sent < server_message_len-1) {
        ret = send(socket_desc, send_buf + bytes_sent, server_message_len -1 - bytes_sent, 0);
        if (ret == -1 && errno == EINTR) continue;
        if (ret == -1) handle_error("Cannot write to the socket");
        bytes_sent += ret;
    }
    
    
    if (DEBUG) fprintf(stderr, "Message of %d bytes sent\n", ret);

    // close socket
    ret = close(socket_desc);
    if (ret<0) handle_error("Cannot close socket for incoming connection");
}

int main(int argc, char* argv[]) {
    int ret;

    int socket_desc, client_desc;

    // some fields are required to be filled with 0
    struct sockaddr_in server_addr = {0}, client_addr = {0};

    int sockaddr_len = sizeof(struct sockaddr_in); // we will reuse it for accept()

    // initialize socket for listening
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc<0) handle_error("Could not create socket");

    server_addr.sin_addr.s_addr = INADDR_ANY; // we want to accept connections from any interface
    server_addr.sin_family      = AF_INET;
    server_addr.sin_port        = htons(SERVER_PORT); // don't forget about network byte order!

    /* We enable SO_REUSEADDR to quickly restart our server after a crash:
     * for more details, read about the TIME_WAIT state in the TCP protocol */
    int reuseaddr_opt = 1;
    ret = setsockopt(socket_desc, SOL_SOCKET, SO_REUSEADDR, &reuseaddr_opt, sizeof(reuseaddr_opt));
    if (ret < 0) handle_error("Cannot set SO_REUSEADDR option");

    // bind address to socket
    ret = bind(socket_desc, (struct sockaddr*) &server_addr, sockaddr_len);
    if (ret < 0) handle_error("Cannot bind address to socket");

    // start listening
    ret = listen(socket_desc, MAX_CONN_QUEUE);
    if (ret < 0) handle_error("Cannot listen on socket");

    // loop to handle incoming connections serially
    while (1) {
        client_desc = accept(socket_desc, (struct sockaddr*) &client_addr, (socklen_t*) &sockaddr_len);
        if (client_desc < 0) handle_error("Cannot open socket for incoming connection");

        if (DEBUG) fprintf(stderr, "Incoming connection accepted...\n");

        connection_handler(client_desc);

        if (DEBUG) fprintf(stderr, "Done!\n");
    }

    exit(EXIT_SUCCESS); // this will never be executed
}
