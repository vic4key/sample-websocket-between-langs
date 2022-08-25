import WebSocket from "ws";

const ws = new WebSocket("ws://127.0.0.1:1609/echo");

ws.on("open", function open() {
  console.log("WS opened");
  ws.send("Howdy, I'm Client");
});

ws.on("close", function open() {
  console.log("WS closed")
});

ws.on("message", function message(data) {
  console.log("WS message", data.toString());
});