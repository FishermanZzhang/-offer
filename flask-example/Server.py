#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/11/7 下午4:06
# @File    : Server.py
# @Software: PyCharm


from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from flask import request, Flask
import os
import argparse
import json

parser = argparse.ArgumentParser(description='configure web.')
parser.add_argument('--ip', type=str, default='0.0.0.0', help='server ip')
parser.add_argument("--port", default=8000, type=int, help='server port')
args = parser.parse_args()

app = Flask(__name__)


@app.route("/simple", methods=['POST'])
def simple():
    # print("args", request.args)
    print("form", request.form)
    print("data", type(request.data), request.data)
    # print(type(request.data))
    print("json", type(request.json), request.json)
    # file = request.files['file']
    # print(file.filename)
    info = {}
    return json.dumps(info, ensure_ascii=False, encoding='utf-8')

if __name__ == "__main__":
  app.run(args.ip, port=args.port)
