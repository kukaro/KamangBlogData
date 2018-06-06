from flask import Flask, request, render_template

app = Flask(__name__)


@app.route('/post', methods=['GET', 'POST'])
def post_test():
    if request.method == 'GET':
        return render_template('post.html')
    elif request.method == 'POST':
        req_dict = request.form
        return 'id=%s<br>pw=%s<br>' % (req_dict['id'], req_dict['pw'])


@app.route('/')
def hello_world():
    return 'Hello World!'


if __name__ == '__main__':
    app.run()
