import face_recognition

image = face_recognition.load_image_file('./unknown/1.jpg')

face_locations = face_recognition.face_locations(image)

print(len(face_locations))
