#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;

#define SERVER_PORT 12345 // Define the port number to connect to the server

// Function to start the DNS client
void startDnsClient() {
    string domainName;
    cout << "Enter the domain name: "; // Prompt the user for the domain name
    getline(cin, domainName);

    // Create a UDP socket for the client
    int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

    // Configure the server address structure
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // Connect to localhost (127.0.0.1)
    serverAddress.sin_port = htons(SERVER_PORT); // Set the port number

    // Send the domain name to the server
    sendto(clientSocket, domainName.c_str(), domainName.size(), 0, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress));

    char response[1024]; // Buffer to store the server's response
    recvfrom(clientSocket, response, sizeof(response), 0, nullptr, nullptr); // Receive the response from the server

    // Display the resolved IP address to the user
    cout << "IP Address for " << domainName << ": " << response;
}

int main() {
    startDnsClient(); // Start the DNS client
    return 0;
}
