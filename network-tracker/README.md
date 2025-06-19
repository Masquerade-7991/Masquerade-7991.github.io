# network-tracker

This repository contains a simple WebSocket client written in C++ that connects to a specified endpoint and logs all received messages. The example uses `websocketpp` and Boost.Asio.

## Building

Install dependencies and compile with:

```sh
sudo apt-get install -y libwebsocketpp-dev libboost-system-dev
g++ -std=c++11 websocket_tracker.cpp -o websocket_tracker -lboost_system -pthread
```

## Usage

Run the program with the WebSocket URI you want to connect to:

```sh
./websocket_tracker ws://echo.websocket.events
```
