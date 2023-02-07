# PROTOCOL

Welcome to the protocol of the r-type project
We use a UDP binary protocol to communicate between the server and the client.
The protocol is the RFC192119.

## Summary:

I Protocol of the server
    I-1 Presentation
    I-2 Part1: Header
    I-3 Part2: Connection
    I-4 Part3: Game
    I-5 Part4: Error
II Protocol of the client
    II-1 Presentation
    II-2 Part1: Header
    II-3 Part2: Connection
    II-4 Part3: Game
    II-5 Part4: Error

## I Protocol of the server

### I-1 Presentation

The server is a UDP server. He save just the port and the IP of the client to send him the data.
The server send a packet to the client and it is structurated like this:
First part: the header who is a 8 bytes integer who represent the type of the packet.
Second part: represent the data of the packet. It depend of the header. It can be a connection packet, a game packet or an error packet.

### I-2 Part1: Header

If the first byte of the header is 0x01, it is a connection packet.
If the first byte of the header is 0x02, it is a game packet.
If the first byte of the header is 0x03, it is an error packet.
All the next part will be about the data of the packet. It depend of the header. The structure is different if the header is 0x01, 0x02 or 0x03.

### I-3 Part2: Connection

If the first byte of the header is 0x01, it is a connection packet.
The data of this structure is a 8 bytes integer who represent which message the server send to the client.
In this part, the server send information of connection:
- Connection success : the server send the packet to the client to say that the connection is a success. The data is 0x00000001.
- Launch game : the server send the packet to the client to say that the game can start. The data is 0x00000002.
- End game : the server send the packet to the client to say that the game is finish. The data is 0x00000003.
- Disconnection : the server send the packet to the client to say that the client need to disconnect. The data is 0x00000004.

### I-4 Part3: Game

If the first byte of the header is 0x02, it is a game packet.
In this part, the server send sprite information to the client.
It represents the a square with the different color, the position.
It sends a 8 bytes integer who represent the Id of the square.
It sends a 8 bytes integer who represent the color of the square.
It sends a 32 bytes integer who represent the X position of the square.
It sends a 32 bytes integer who represent the Y position of the square.

### I-5 Part4: Error

If the first byte of the header is 0x03, it is an error packet.
The data of this structure is a 8 bytes integer who represent which message the server send to the client.
In this part, the server send information of error:
- Error of connection : the server send the packet to the client to say that the connection is a error, the client is disconnected. The data is 0x00000001.
- Error of launch game : the server send the packet to the client to say that the game can't start, the client is disconnected. The data is 0x00000002.
- Error of communication : the server send the packet to the client to say that the communication is a error, the client is disconnected. The data is 0x00000003.


## II Protocol of the client

### II-1 Presentation

The client is a UDP client. He save just the port and the IP of the server to send him the data.
The client send a packet to the server and it is structurated like this:
First part: the header who is a 8 bytes integer who represent the type of the packet.
Second part: represent the data of the packet. It depend of the header. It can be a connection packet, a game packet or an error packet.

### II-2 Part1: Header

If the first byte of the header is 0x01, it is a connection packet.
If the first byte of the header is 0x02, it is a game packet.
If the first byte of the header is 0x03, it is an error packet.

### II-3 Part2: Connection

If the first byte of the header is 0x01, it is a connection packet.
The data of this structure is a 8 bytes integer who represent which message the client send to the server.
In this part, the client send information of connection:
- Connection : the client send the packet to the server to say that the client want to connect. The data is 0x00000001.
- Launch game : the client send the packet to the server to say that the client want to launch the game. The data is 0x00000002.
- Disconnection : the client send the packet to the server to say that the client want to disconnect. The data is 0x00000003.
- End game : the client send the packet to the server to say that the client want to end the game. The data is 0x00000004.

### II-4 Part3: Game

If the first byte of the header is 0x02, it is a game packet.
In this part, the client send event information to the server.
The event is a move or a shoot.
- Move : the client send the packet to the server to say that the client want to move. The move is a 4 bytes integer who represent the direction of the move. The direction is 0x00000001 for left, 0x00000002 for right, 0x00000003 for up and 0x00000004 for down.
- Shoot : the client send the packet to the server to say that the client want to shoot. The shoot is a 4 bytes integer who say he is a shoot. The shoot is 0x00000010.

### II-5 Part4: Error

If the first byte of the header is 0x03, it is an error packet.
The data of this structure is a 8 bytes integer who represent which message the client send to the server.
In this part, the client send information of error:
- Error of connection : the client send the packet to the server to say that the connection is a error, the client is disconnected. The data is 0x00000001.
- Error of launch game : the client send the packet to the server to say that the game can't start, the client is disconnected. The data is 0x00000002.
- Error of communication : the client send the packet to the server to say that the communication is a error, the client is disconnected. The data is 0x00000003.