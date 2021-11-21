import qrcode
from PIL import Image
import csv

    #read csv file
file_CSV = open('boardingPass_SpeedPlane.csv')
data_CSV = csv.reader(file_CSV,delimiter = ';')
list_CSV = list(data_CSV)
# print(list_CSV) -> [['Firstname', 'Lastname'...], ['Joe', 'JOE'...]]

    #join the 'key' and the 'value'
data = []
for i in range (len(list_CSV[0])):
    data.append('{} : {}'.format(list_CSV[0][i],list_CSV[1][i]))
# print(data) -> ['Firstname : Joe', 'Lastname : JOE'...]

    #set the layout
data_final = '\n'.join(str(x) for x in data)
# print(data_final) -> 
# Firstname : Joe
# Lastname : JOE

    #generate the qrcode
qr_img = qrcode.make(data_final)

    #remove background
qr_img = qr_img.convert("RGBA")
datas = qr_img.getdata()
newData = []

for item in datas:
	if item[0] == 255 and item[1] == 255 and item[2] == 255:
		newData.append((255, 255, 255, 0))
	else:
		newData.append(item)

qr_img.putdata(newData)

    #add qr code to back.png
background = Image.open("src/back.png")

background_w, background_h = background.size
foreground_w, foreground_h = qr_img.size

offset = ((background_w - foreground_w) //2, (background_h - foreground_h) //2)
background.paste(qr_img, offset,qr_img)

background.save('BoardingPass_SpeedPlane.png')