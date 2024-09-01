# DNS Server-Client Application

This project demonstrates a simple DNS server-client application using C++. The server resolves domain names to IP addresses by searching through a local DNS record file. The client queries the server to retrieve the IP address for a given domain name.

(**Note:** This project is intended for educational purposes to illustrate how DNS resolution and socket programming work. It is not a fully-featured DNS server for deployment.)

## Features

- **DNS Server:** Handles requests from clients to resolve domain names to IP addresses.
- **DNS Client:** Sends domain name queries to the server and receives the corresponding IP address.
- **UDP Communication:** Utilizes UDP sockets for communication between the client and server.
- **Local DNS Record Lookup:** The server searches a local DNS record file to find the IP address corresponding to a domain name.

## Instructions

**Ensure that port `12345` is available before running the server.**

### 1. Run the Server

Compile and run the server program:

```bash
g++ Server.cpp -o Server
./Server
```

### 2. Run the client

Compile and run the client program:

```bash
g++ Client.cpp -o Client
./Client
```

(The client will prompt you to enter a domain name.)

### 3. Query the server

Enter the domain name (e.g., github.com, google.com). The server will return the corresponding IP address if the domain is found in the DNS record. The program will then terminate.

## Features

- **Multi-Client Support:** The server can handle multiple clients simultaneously, enabling group communication.
- **Real-Time Message Broadcasting:** Messages sent by any connected client are instantly broadcasted to all other clients.
- **Threaded Client Handling:** Each client connection is managed in a separate thread, ensuring smooth and efficient communication without blocking.
- **Simple Setup:** The server and client scripts are straightforward to run, with minimal configuration required.
- **Connection Management:** The server manages active connections, automatically removing clients that disconnect.

## Troubleshooting

- **Port Conflicts:** If port **12345** is in use, modify the `SERVER_PORT` in both `server.py` and `client.py`.
- **Connection Issues:** Ensure that the server is running and reachable from the client.

## Future Enhancements

- **DNS Record Caching:** Implement caching to store resolved domain names for quicker future responses.
- **Support for Multiple Record Types:** Extend the server to handle different types of DNS records (e.g., A, AAAA, CNAME).
- **Multi-threaded Server:** Modify the server to handle multiple client requests concurrently.
- **Error Handling Improvements:** Add more robust error handling for network failures and invalid queries.
- **Configuration File Support:** Allow the server to load DNS records from a configuration file instead of hardcoding them.




## Author

[Finny Joshua]
