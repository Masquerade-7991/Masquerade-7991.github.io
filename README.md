# hello-world
Hello World repository for Git tutorial
This is an example repository for the Git tutoial on https://www.w3schools.com
This tutorial focuses mainly on Git and using GitHub as its remote

This repository is built step by step in the tutorial.

It now includes steps for GitHub.

## WebSocket traffic tracker

This repository includes a simple WebSocket client example in
`network-tracker/websocket_tracker.cpp`. It connects to a WebSocket endpoint
specified on the command line and prints any received messages to standard
output.

### Building

You need `g++`, Boost, and the `websocketpp` library installed. On Ubuntu you can
install the dependencies and compile with:

```sh
sudo apt-get install -y libwebsocketpp-dev libboost-system-dev
g++ -std=c++11 network-tracker/websocket_tracker.cpp -o network-tracker/websocket_tracker -lboost_system -pthread
```

Run the program by passing a WebSocket URI, for example:

```sh
./network-tracker/websocket_tracker ws://echo.websocket.events
```

