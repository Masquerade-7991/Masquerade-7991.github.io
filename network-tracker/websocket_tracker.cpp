#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

#include <iostream>
#include <string>

// Convenience typedefs
typedef websocketpp::client<websocketpp::config::asio_client> client;

typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

class websocket_endpoint {
public:
    websocket_endpoint() {
        m_endpoint.clear_access_channels(websocketpp::log::alevel::all);
        m_endpoint.clear_error_channels(websocketpp::log::elevel::all);

        // Initialize ASIO
        m_endpoint.init_asio();

        // Bind handlers
        m_endpoint.set_open_handler(std::bind(&websocket_endpoint::on_open, this, std::placeholders::_1));
        m_endpoint.set_message_handler(std::bind(&websocket_endpoint::on_message, this, std::placeholders::_1, std::placeholders::_2));
        m_endpoint.set_close_handler(std::bind(&websocket_endpoint::on_close, this, std::placeholders::_1));
    }

    void on_open(websocketpp::connection_hdl hdl) {
        std::cout << "Connected" << std::endl;
    }

    void on_message(websocketpp::connection_hdl hdl, message_ptr msg) {
        std::cout << "Received: " << msg->get_payload() << std::endl;
    }

    void on_close(websocketpp::connection_hdl hdl) {
        std::cout << "Connection closed" << std::endl;
    }

    void run(const std::string& uri) {
        websocketpp::lib::error_code ec;
        client::connection_ptr con = m_endpoint.get_connection(uri, ec);
        if (ec) {
            std::cout << "Could not create connection because: " << ec.message() << std::endl;
            return;
        }

        m_endpoint.connect(con);
        m_endpoint.run();
    }

private:
    client m_endpoint;
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <ws://host:port/path>" << std::endl;
        return 1;
    }

    std::string uri = argv[1];

    websocket_endpoint endpoint;
    endpoint.run(uri);

    return 0;
}

