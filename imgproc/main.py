import imageio
import numpy as np

def inversion(img):
    return 255 - img

def contrastModulation(img, c, d):
    a = img.min()
    b = img.max()
    return ((img-a)*((d-c)/(b-a)))+c

def logarithmicFunction(img):
    R = img.max()
    return 255*((np.log2(1+img))/(np.log2(1+R)))

def gammaAdjustment(img, W, lambd):
    return W*np.power(img,lambd)


def RSE(img_in, img_out):
    return np.sqrt(sum(sum(np.power(img_in-img_out,2))))

filename = str(input()).rstrip()

input_img = imageio.imread(filename).astype(np.int32)

method = int(input())

save = int(input())

if method == 1:
    output_img = inversion(input_img).astype(np.uint8)
if method == 2:
    c = int(input())
    d = int(input())
    output_img = contrastModulation(input_img, c, d).astype(np.uint8)
if method == 3:
    output_img = logarithmicFunction(input_img).astype(np.uint8)
if method == 4:
    W = int(input())
    lambd = float(input())
    output_img = gammaAdjustment(input_img, W, lambd)

print(RSE(input_img, output_img))

