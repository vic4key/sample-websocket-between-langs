// ws-server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// https://www.daimajiaoliu.com/daima/486f712f4100407

#include <iostream>
#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>

using namespace std;

using websocketpp::lib::bind;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

typedef websocketpp::server<websocketpp::config::asio> websocket_server;
typedef websocketpp::frame::opcode::value message_t;
typedef websocket_server::message_ptr message_ptr;

void on_open(websocket_server* s, websocketpp::connection_hdl hdl)
{
  cout << "WS opened" << endl;
}

void on_close(websocketpp::connection_hdl hdl)
{
  cout << "WS closed" << endl;
}

void on_message(websocket_server* server, websocketpp::connection_hdl hdl, message_ptr data)
{
  cout << "WS Client sent '" << data->get_payload() << "'" << endl;

  try
  {
    std::string s = "WS Server replied '" + data->get_payload() + "'";
    server->send(hdl, s, message_t::text);
  }
  catch (websocketpp::exception const& e)
  {
    cout << e.what() << endl;
  }
}

int main()
{
  try
  {
    websocket_server ws;

    ws.set_message_handler(bind(on_message, &ws, ::_1, ::_2));
    ws.set_open_handler(bind(on_open, &ws, ::_1));
    ws.set_close_handler(bind(on_close, ::_1));

    ws.init_asio();
    ws.set_reuse_addr(true);
    ws.listen(1609);
    ws.start_accept();
    ws.run();
    ws.stop();
  }
  catch (const websocketpp::exception& e)
  {
    cout << e.what() << endl;
  }
}