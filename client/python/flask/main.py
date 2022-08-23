# https://blog.miguelgrinberg.com/post/add-a-websocket-route-to-your-flask-2-x-application

from flask import Flask, render_template

app = Flask(__name__, template_folder=".")

@app.route("/")
def index():
  return render_template("index.html", methods=["GET"])

if __name__ == "__main__":
  app.run(host="127.0.0.1", port=5000)