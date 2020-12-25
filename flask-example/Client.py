#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019/11/7 下午4:06
# @File    : Client.py
# @Software: PyCharm


from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
import requests
import os
import numpy as np
import json
import base64

data = {"data": u"中国人"}
with open("image.jpg") as f:
  img = f.read()

img = base64.encodestring(img)
data['img'] = img
files = {'file': ("image.jpg", open("image.jpg"), 'application/octet-stream')}
files = {'file': open("image.jpg")}
data = json.dumps(data)
headers = {'Content-Type': 'application/json'}
# headers = {'Content-Type': 'multipart/form-data'}
# r = requests.post("http://0.0.0.0:8000/simple",
#                   data=data,
#                   json=jsondata,
#                   files=files)
r = requests.post("http://0.0.0.0:8000/simple",
                  headers=headers,
                  data=data)
# r = requests.post("http://0.0.0.0:8000/simple",
#                   data=data,
#                   files=files)
# r = requests.post("http://0.0.0.0:8000/simple",
#                   data=data,
#                   files=files)
text = r.text
print(text)
