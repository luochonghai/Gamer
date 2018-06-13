import matplotlib.pyplot as plt
import numpy as np
import os
import cv2

def draw_headcount(file_path):
	#read data from .txt
	del_name = "C:\\Users\\tjqqd\\Documents\\Visual Studio 2017\\Projects\\test\\test\\Resources\\headcount.jpg"
	if os.path.exists(del_name):
		os.remove(del_name)
	file = open(file_path)
	str = file.readline()
	y1 = str.split()
	for i in range(4):
		temp = int(y1[7-i])
		y1[7-i] = int(y1[i])
		y1[i] = temp
	x = [i for i in range(8)]

	plt.figure(figsize = (3.2,2.4))
	#create a chart
	plt.plot(x,y1)
	plt.title('headcount_chart')
	plt.ylabel('Headcount at the bar')
	plt.xlabel('Iteration time')
	#save chart
	plt.savefig("C:\\Users\\tjqqd\\Documents\\Visual Studio 2017\\Projects\\test\\test\\Resources\\headcount.jpg")
	plt.close()

def draw_capital(file_path):
	del_name = "C:\\Users\\tjqqd\\Documents\\Visual Studio 2017\\Projects\\test\\test\\Resources\\capital.jpg"
	if os.path.exists(del_name):
		os.remove(del_name)
	res = [[0 for i in range(8)] for j in range(9)]
	pc = 0
	with open(file_path ,'r') as file_to_read:
		while True:
			lines = file_to_read.readline()
			if not lines:
				break
				pass
			temp_str = lines.split()
			res[pc] = temp_str
			pc += 1

	index = [i for i in range(8)]
	for i in range(9):
		for j in range(4):
			temp = int(res[i][7-j])
			res[i][7-j] = int(res[i][j])
			res[i][j] = temp
		plt.plot(index,res[i])

	plt.title('capital_chart')
	plt.xlabel('Iteration time')
	plt.ylabel('Agent capital')

	plt.savefig("C:\\Users\\tjqqd\\Documents\\Visual Studio 2017\\Projects\\test\\test\\Resources\\capital.jpg")
	plt.close()

	img = cv2.imread("C:\\Users\\tjqqd\\Documents\\Visual Studio 2017\\Projects\\test\\test\\Resources\\capital.jpg")
	imgInfo = img.shape
	height = imgInfo[0]
	width = imgInfo[1]
	mode = imgInfo[2]
	dstHeight = int(height/2)
	dstWidth = int(width/2)

	dst = cv2.resize(img,(dstWidth,dstHeight))
	cv2.imwrite("C:\\Users\\tjqqd\\Documents\\Visual Studio 2017\\Projects\\test\\test\\Resources\\capital.jpg",dst)

def like_main():
	draw_headcount('D:\\FDU\\Template\\CS\\software_engineering\\pj\\headcount.txt')
	draw_capital('D:\\FDU\\Template\\CS\\software_engineering\\pj\\capital.txt')


if __name__ == '__main__':
	like_main()