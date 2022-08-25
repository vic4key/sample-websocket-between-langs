import { WebSocketServer } from "ws";

const ws = new WebSocketServer({ port: 1609 });

ws.on("connection", (s) => {
  console.log("WS Client connected");

  s.on("message", (data) => {
    console.log(`WS Client sent '${data}'`);
    s.send(`WS Server replied '${data}'`);
  });
});

// // does not work
// ws.on("close", () => {
//   console.log("WS Client disconnected");
// });