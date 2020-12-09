import face_recognition as FR
from PIL import Image

img = FR.load_image_file('./unknown/1.jpg')
face_locations = FR.face_locations(img)

for face_location in face_locations:
    top, right, bottom, left = face_location

    face_image = img[top:bottom, left:right]
    pil_image = Image.fromarray(face_image)
    pil_image.show()

