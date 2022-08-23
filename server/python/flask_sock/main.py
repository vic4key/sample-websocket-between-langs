# https://blog.miguelgrinberg.com/post/add-a-websocket-route-to-your-flask-2-x-application

# NOTE: Seems this library has no event connected, disconnected, etc

from flask import Flask
from flask_sock import Sock

app = Flask(__name__)
ws = Sock(app)

@ws.route("/echo")
def echo(s):
  while True:
    data = s.receive()
    print(f"WS Client sent '{data}'")
    s.send(f"WS Server replied '{data}'")

if __name__ == "__main__":
  app.run(host="127.0.0.1", port=1609)