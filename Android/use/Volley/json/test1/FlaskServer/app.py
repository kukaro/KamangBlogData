from flask import Flask
import json

app = Flask(__name__)


@app.route('/')
def hello_world():
    val = {'id': 'kukaro', 'pw': 1234, 'language': ['java', 'python', 'js'], 'item': {'os': 'mac'}}
    json_val = json.dumps(val)
    return str(json_val)


if __name__ == '__main__':
    app.run()
