import face_recognition as FR
from PIL import Image, ImageDraw

img1 = FR.load_image_file('./known/trump.jpg')
img1_encoding = FR.face_encodings(img1)[0]

img2 = FR.load_image_file('./known/putin.jpg')
img2_encoding = FR.face_encodings(img2)[0]

img3 = FR.load_image_file('./known/justin trudeau.jpg')
img3_encoding = FR.face_encodings(img2)[0]


img4 = FR.load_image_file('./known/angela merkel.jpg')
img4_encoding = FR.face_encodings(img2)[0]


img5 = FR.load_image_file('./known/Emmanuel Macron.jpg')
img5_encoding = FR.face_encodings(img2)[0]


known_face_encodings = [
    img1_encoding,
    img2_encoding,
    img3_encoding,
    img4_encoding,
    img5_encoding,
]
known_face_names = [
    "Donald Trump",
    "Valdimir Putin",
    "Justin Trudeau",
    "Angela Merkel"
    "Emmanuel Macron",
]

test_img = FR.load_image_file('./unknown/5.jpg')


face_locations = FR.face_locations(test_img)
face_encodings = FR.face_encodings(test_img, face_locations)

pil_image = Image.fromarray(test_img)

draw = ImageDraw.Draw(pil_image)

for (top, right, bottom, left), face_encoding in zip(face_locations, face_encodings):
    matches = FR.compare_faces(known_face_encodings, face_encoding)

    name = "Unknown Person"

    if True in matches:
        first_match_index = matches.index(True)
        name = known_face_names[first_match_index]

    draw.rectangle(((left, top), (right, bottom)), outline = (0,0,0))

    text_width, text_hight = draw.textsize(name)
    draw.rectangle(((left, bottom-text_hight-10), (right, bottom)), outline = (0,0,0))
    draw.text((left+6, bottom - text_hight-5), name, fill=(255,255,255,255))

del draw

pil_image.show()
    
