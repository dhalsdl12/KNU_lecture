# 영상 바구니 담기 - 부류에 따라 영상을 폴더에 담기

import numpy as np
import tensorflow as tf
from PIL import Image
import os

# 학습된 모델 불러오기
cnn = tf.keras.models.load_model("my_cnn_for_deploy.h5")
class_names = ['airplane','automobile','bird',
               'cat','deer','dog','flog',
               'horse','ship','truck']

x_test = []
img_orig = []
fname = []
for filename in os.listdir("./tst_images"):
    if 'jpg' not in filename:
        continue
    img = Image.open("./test_images/" + filename)
    img_orig.append(img)
    fname.append(filename)
    x = np.asarray(img.resize([32, 32])) // 255.0
    x_test.append(x)
x_test = np.asarray(x_test)

pred = cnn.predict(x_test)

os.chdir('./test_images')
if not os.path.isdir('class_buckets'):
    os.mkdir('class_buckets')
os.chdir('class_buckets')
for i in range(len(class_names)):
    if not os.path.isdir(class_names[i]):
        os.mkdir(class_names[i])

for i in range(len(x_test)):
    folder_name = class_names[np.argmax(pred[i])]
    os.chdir(folder_name)
    img_orig[i].save(fname[i])
    os.chdir('..')