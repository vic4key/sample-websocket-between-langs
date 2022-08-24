// ws-client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// https://github.com/microsoft/cpprestsdk/wiki/Web-Socket

#include <iostream>
#include <cpprest/ws_client.h>

using namespace std;
using namespace web::websockets::client;

int main()
{
  try
  {
    websocket_client ws;
    ws.connect(L"ws://127.0.0.1:1609/echo").then([]()
    {
      cout << "WS openned" << endl;
    }).wait();

    websocket_outgoing_message data;
    data.set_utf8_message("Howdy, I'm Client");
    ws.send(data).wait();

    ws.receive().then([](const websocket_incoming_message& data)
    {
      cout << "WS message" << endl;
      return data.extract_string();
    }).then([](const string& data)
    {
      cout << data << endl;
    }).wait();

    ws.close().then([]()
    {
      cout << "WS closed" << endl;
    }).wait();
  }
  catch (const websocket_exception& e)
  {
    cout << e.what() << endl;
  }

  return 0;
}