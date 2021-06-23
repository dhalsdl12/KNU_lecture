from flask import Flask, render_template

app = Flask(__name__)


@app.route('/')
def introduce():
    return '2018115425 컴퓨터학부 권오민.'


@app.route('/me/')
def hobby():
    return render_template('index.html', my_img='태권도.jpeg')


if __name__ == "__main__":
    app.run(debug=True)