import face_recognition

img1 = face_recognition.load_image_file('./known/trump.jpg')
img1_encoding = face_recognition.face_encodings(img1)[0]


img2 = face_recognition.load_image_file('./unknown/2.jpg')
img2_encoding = face_recognition.face_encodings(img1)[0]

match = face_recognition.compare_faces([img1_encoding], img2_encoding)

if match[0]==1:
    print("This is donald turmp")
else:
    print("I don't know him")


