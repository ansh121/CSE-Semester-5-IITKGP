####################################################################
#Name - Nilesh Mandal
#Roll - 17CS10031
#Assignment - 1
#*********Run With Python3***********
####################################################################

###############################BEGIN################################

#Importing required libraries
import numpy as np
from numpy import genfromtxt
#To calculate entropy
def Entropy(y):
	P = y[np.where(y[:,0] == 'yes')]
	N = y[np.where(y[:,0] == 'no')]

	p = P.shape[0]
	n = N.shape[0]

	f_p = p / (p + n)
	f_n = n / (p + n)
	entropy = - (f_p * np.log(f_p)) - (f_n * np.log(f_n))

	return entropy

#X : the array with selected attribute
#S : the parent array
#attr : list of values of selected attribute
#index : concerned column of attribute
def Gain(X,S,attr,index):
	n = X.shape[0]
	sum = 0
	for val in attr:
		A = X[np.where(X[:,index] == val)]
		l = A.shape[1]
		y = A[:,l-1]
		y.shape = (len(y),1)
		n_y = y.shape[0]
		sum += (n_y/n) * Entropy(y)
		#print(sum)
	gain = Entropy(S) - sum
	return gain

#Find max gain attribute
#Make that root
#For all possible values of that attribute,add a node
#For each path,recurse and repeat the process with subset array
#When only 1 attribute remains, assign the majority element('yes' or 'no') as the answer
def recursiveTree(data,X,y,attr,labels,tab):
	max_gain = 0
	index = 0
	L = X.shape[1]
	#When only 1 attribute
	if(L == 1):
		for val in attr[0]:
			A = data[np.where(data[:,index] == val)]
			l = A.shape[1]
			YES = A[np.where(A[:,1] == 'yes')]
			NO = A[np.where(A[:,1] == 'no')]
			if(YES.shape[0] == 0 and NO.shape[0] == 0):
				continue
			print(tab + labels[index] + " = " + val + ": ",end = " ")
			if(YES.shape[0] > NO.shape[0]):
				print("yes")
			else:
				print("no")
	#More than 1 attribute
	else:
		#find attribute with max gain and store its column no. in 'index'
		for i in range(0,L):
			gain = Gain(data,y,attr[i],i)
			if(gain > max_gain):
			   max_gain = gain
			   index = i
		
		#For all possible values of the max gain attribute 
		for val in attr[index]:
			A = data[np.where(data[:,index] == val)]
			l = A.shape[1]
			if(A.shape[0] == 0):
			   continue
			YES = A[np.where(A[:,l-1] == 'yes')]
			NO = A[np.where(A[:,l-1] == 'no')]
			if(YES.shape[0] == 0):			#if only 'no'
			   print(tab + labels[index] + " = " + val + ": no")
			   break
			elif(NO.shape[0] == 0):			#if only 'yes'
			   print(tab + labels[index] + " = " + val + ": no")
			   break
			
			#delete this attribute column to get the sub table in which we need to recurse
			data_new = np.delete(A , index, axis=1)
			l = data_new.shape[1]
			X_new = data_new[:,0:l - 1]
			y_new = data_new[:,l-1]
			y_new.shape = (len(y_new),1)
			labels_new = np.delete(labels,index)
			attr_new = np.delete(attr,index)
			
			#Printing current level
			print(tab + labels[index] + " = " + val)
			
			#recursive call to print child levels
			recursiveTree(data_new,X_new,y_new,attr_new,labels_new,tab + "|	")


#Loading data from the given csv file
data = genfromtxt('data1_19.csv', delimiter=',', dtype = str)

#Extracting data labels and attributes
labels = data[0,0:3]
X = data[1:,0:3]
attr = []

#make list of all possible values of all attributes 
for i in range(0,3):
	attr.append(np.unique(X[:,i]))

# Extracting target class
y = data[1:,3]
y.shape = (X.shape[0],1)

#tab : to add necessary indentation
tab = ""

#Build decision tree
recursiveTree(data[1:],X,y,attr,labels,tab)

################################END#################################
