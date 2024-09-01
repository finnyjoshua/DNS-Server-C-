#include <iostream>
#include <cstring>
#include <cstdio>
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;

#define SERVER_PORT 12345 // Define the port number the server will listen on

// Function to handle DNS requests and return the IP address
void handleDnsRequest(const char* data, char* response) {
    string domainName(data); // Convert incoming data to a string representing the domain name
    string ipAddress;

    // Command to search the DNS record for the corresponding IP address
    string command = "grep " + domainName + " dns_record | awk '{print $2}'";
    FILE *pipe = popen(command.c_str(), "r");

    // If the domain is not found, set a "Domain Not Found!" response
    if(!pipe)
        ipAddress = "Domain Not Found!";
    else {
        char buffer[256];
        fgets(buffer, sizeof(buffer), pipe);
        ipAddress += buffer; // Retrieve the IP address from the command output
    }       

    ipAddress.copy(response, ipAddress.size(), 0); // Copy the IP address to the response buffer
}

// Function to start the DNS server
void startDnsServer() {
    // Create a UDP socket for the server
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    // Configure the server address structure
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); // Accept connections from any IP
    serverAddress.sin_port = htons(SERVER_PORT); // Set the port number

    // Bind the socket to the configured address and port
    bind(serverSocket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress));

    char data[1024]; // Buffer to store incoming data
    bzero(data, sizeof(data)); // Clear the buffer
    sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);

    while (true) {
        cout << "DNS Server is running..." << endl;

        // Receive a DNS request from the client
        recvfrom(serverSocket, data, sizeof(data), 0, reinterpret_cast<sockaddr*>(&clientAddress), &clientAddressLen);

        cout << "\t[*] Request received for " << data << endl;

        char response[1024];
        bzero(response, sizeof(response)); // Clear the response buffer

        cout << "\t[*] Searching in the DNS record..." << endl;
        handleDnsRequest(data, response); // Process the DNS request

        // Send the response back to the client
        sendto(serverSocket, response, sizeof(response), 0, reinterpret_cast<sockaddr*>(&clientAddress), clientAddressLen);
        if(strstr(response, "Domain Not Found!")) {
            cout << "\t[*] Domain not found in the DNS record..." << endl;  
        } else {
            cout << "\t[*] Request served successfully..." << endl; 
        }
    }
}

int main() {
    startDnsServer(); // Start the DNS server
    return 0;
}
