import websocket
from _thread import start_new_thread

# websocket.enableTrace(True)
# websocket.setdefaulttimeout(5)

def on_open(ws):
  print("WS openned", ws)
  def run(*args): ws.send("Howdy, I'm Client")
  start_new_thread(run, ())

def on_close(ws, close_status_code, close_msg):
  print("WS closed", close_status_code, close_msg)

def on_message(ws, message):
  print("WS message", ws, message)

ws = websocket.WebSocketApp(
  "ws://127.0.0.1:1609/echo",
  on_open=on_open,
  on_close=on_close,
  on_message=on_message,
  header={"test": "test"}
)
ws.run_forever()