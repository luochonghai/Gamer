#-*- coding:utf-8 -*-
import matplotlib.pyplot as plt
#import ctypes
#import sys
import os
from PIL import Image

def draw_headcount(file_path):
	#read data from .txt
	del_name = ".\\Resources\\headcount.jpg"
	if os.path.exists(del_name):
		os.remove(del_name)
	file = open(file_path,'r')
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
	plt.savefig(del_name)
	plt.close()

def draw_capital(file_path):
	del_name = ".\\Resources\\capital.jpg"
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

	plt.savefig(del_name)
	plt.close()

	img = Image.open(del_name)
	(x,y) = img.size
	x_s = int(x/2)
	y_s = int(y/2)
	out = img.resize((x_s,y_s),Image.ANTIALIAS)
	out.save(del_name)

def like_main():
	draw_headcount('.\\headcount.txt')
	draw_capital('.\\capital.txt')

if __name__ == '__main__':
	like_main()