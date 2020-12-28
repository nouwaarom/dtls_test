// Server side implementation of UDP client-server model 
#include <errno.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <dtls_server.h>

#define PORT        5100 
#define BUFFER_SIZE 1024 

static struct {
    size_t filled;
    uint8_t data[BUFFER_SIZE];
} rx;

static struct {
    size_t filled;
    uint8_t* data;
} mbus_rx;

// Driver code
int main() {
    dtls_main();

    int sockfd; 
    struct sockaddr_in servaddr;
    struct sockaddr cliaddr;
      
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
      
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
      
    // Filling server information 
    servaddr.sin_family    = AF_INET; // IPv4 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
    servaddr.sin_port = htons(PORT); 
      
    // Bind the socket with the server address 
    if ( bind(sockfd, (const struct sockaddr *)&servaddr,  
            sizeof(servaddr)) < 0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }

    printf("Server running on %i\r\n", PORT);

    socklen_t len = sizeof(cliaddr);
    while(1) { 
        rx.filled = recvfrom(sockfd, (char *)rx.data, BUFFER_SIZE, MSG_WAITALL, &cliaddr, &len); 

        if (rx.filled == -1) {
            int err = errno;
            printf("Error (%i): %s\r\n", err, strerror(err));
        } else {
            printf("Client received (%li bytes)\n", rx.filled);

            // Parse the message, TODO make this part of the communication interface.
            char *uuid = rx.data;
            char *delim = strchr(uuid, ',');
            *delim = '\0';
            char *timestamp = delim + 1;
            delim = strchr(timestamp, ',');
            *delim = '\0';
            char* message_type = delim + 1;
            delim = strchr(message_type, '\n');
            *delim = '\0';
            printf("id:%s timestamp:%s message_type:%s\n", uuid, timestamp, message_type);

            char* response = "Come one, please just receive my message!";
            int result = sendto(sockfd, response, strlen(response), MSG_NOSIGNAL, &cliaddr, len);
            if (result < 0) {
                printf("Failed to send a response :(\n");
            } else {
                printf("Sent a response!\n");
            }
        }
    } 
      
    return 0; 
}

