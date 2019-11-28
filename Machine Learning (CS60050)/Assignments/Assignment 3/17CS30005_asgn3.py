#17CS30005 - Anshul Goel
#Assignment 3 - Addaboost
#17CS30005_asgn3.py

import numpy as np
from numpy import genfromtxt
import math


def Gain(X,S,attr,index):
	n = X.shape[0]
	label=1
	sum = 0
	for val in attr:
		A = X[np.where(X[:,index] == val)]
		l = A.shape[1]
		y = A[:,l-1]
		if(label and len(y) == 0):
			continue
		y.shape = (len(y),1)
		if(label==1):
			n_y = y.shape[0]
			sum += (n_y/n) * Entropy(y)
		#print(sum)
	gain = Entropy(S) - sum
	return gain


class Node:
	def __init__(self):
		self.label = ""
		self.nodelist = []
		self.next = None



def Entropy(y):
	N = y[np.where(y[:,0] == 'no')]
	label=0
	P = y[np.where(y[:,0] == 'yes')]

	n = N.shape[0]
	p = P.shape[0]

	if(p == -n and label==0):
		return 0
	f_n = n / (p + n)
	f_p = p / (p + n)

	if(f_n == 0 and label==0):
		f_n = 0.0000000001

	if(f_p == 0):
		f_p = 0.0000000001

	v= -(f_p * np.log(f_p))
	if(label==0):
		w= - (f_n * np.log(f_n))
		entropy = v + w

	return entropy



def classifierWeight(error):
	label=0
	if(error == 1):
		error = 1 - 0.0000000001
	elif(error == 0 and label==0):
		error = 0.0000000001;

	p = (1 - error)/error
	return 0.5 * np.log(p)



def recursiveTree(data,X,y,attr,labels,tab):
	max_gain = 0
	tmp=0
	new_node = Node()
	index = 0
	flag=1;
	L = X.shape[1]
	#When only 1 attribute
	if(L == 1 and tmp==0):
		new_node.label = labels[index]
		for val in attr[0]:
			curr = Node()#male,female,etc
			curr.label = val
			new_node.nodelist.append(curr)
			if(flag==1):
				A = data[np.where(data[:,index] == val)]
				l = A.shape[1]
			NO = A[np.where(A[:,1] == 'no')]
			YES = A[np.where(A[:,1] == 'yes')]
			print(tab + labels[index] + " = " + val + " : ",end = " ")
			if(NO.shape[0] == 0 and  YES.shape[0] == 0 and flag==1):
				n_val = Node()
				n_val.label = "yes"
				new_node.nodelist[len(new_node.nodelist) - 1].next = n_val
				print("yes")
				continue
			if(YES.shape[0] <= NO.shape[0]):
				n_val = Node()
				if(flag==1):
					n_val.label = "no"
					new_node.nodelist[len(new_node.nodelist) - 1].next = n_val
					print("no")
			else:
				n_val = Node()
				if(flag==1):
					n_val.label = "yes"
					new_node.nodelist[len(new_node.nodelist) - 1].next = n_val
					print("yes")

	else:
		flag=0
		for i in range(0,L):
			gain = Gain(data,y,attr[i],i)
			if(gain > max_gain and flag==0):
			   max_gain = gain
			   index = i
		new_node.label = labels[index]
		tmp=1
		for val in attr[index]:
			curr = Node()#male,female,etc
			if(flag==0):
				curr.label = val
				new_node.nodelist.append(curr)
			A = data[np.where(data[:,index] == val)]
			l = A.shape[1]
			if(A.shape[0] == 0 and flag==0):
			   continue
			if(tmp==1):
				YES = A[np.where(A[:,l-1] == 'yes')]
				NO = A[np.where(A[:,l-1] == 'no')]
			if(YES.shape[0] == 0):			#if only 'no'
			   n_val = Node()
			   if(flag==0):
				   n_val.label = "no"
				   new_node.nodelist[len(new_node.nodelist) - 1].next = n_val
			   print(tab + labels[index] + " = " + val + ": no")
			   break
			elif(NO.shape[0] == 0):			#if only 'yes'
			   n_val = Node()
			   if(flag==0):
				   n_val.label = "yes"
				   new_node.nodelist[len(new_node.nodelist) - 1].next = n_val
			   print(tab + labels[index] + " = " + val + ": yes")
			   break

			#delete this attribute column to get the sub table in which we need to recurse
			if(tmp==1):
				data_new = np.delete(A , index, axis=1)
				l = data_new.shape[1]
			if(flag==0):
				y_new = data_new[:,l-1]
				X_new = data_new[:,0:l - 1]
			y_new.shape = (len(y_new),1)
			labels_new = np.delete(labels,index)
			attr_new = np.delete(attr,index)

			#Printing current level
			print(tab + labels[index] + " = " + val)
			#recursive call to print child levels
			new_node.nodelist[len(new_node.nodelist) - 1].next = recursiveTree(data_new,X_new,y_new,attr_new,labels_new,tab + "|	")
	return new_node


def traverseTree(X,root,labels):
	if(root == None):
		return ""
	flag=0
	if(len(root.nodelist) == 0 and flag==0):
		if(root.label == "yes" or root.label == "no"):
			return root.label
		else:
			return ""
	flag=1
	i = labels.index(root.label)
	for var in root.nodelist:
		if(X[i] == var.label and flag==1):
			return traverseTree(X,var.next,labels)
	return ""




def updateDataWts(wtList,y_test,y_pred,classWt):
	Z = 0
	label=0
	for i in range(0,len(wtList)):
		sign = 1
		if(y_test[i] != y_pred[i] and label==0):
			sign = -1
		wtList[i] = wtList[i] * math.exp(-1 * sign * classWt)
		label=1
		Z += wtList[i]

	for i in range(0,len(wtList)):
		if(label==1):
			wtList[i] = wtList[i]/Z

	return wtList



def finalOutput(classWts,y_array):
	label=1
	y_out = []
	for i in range(0,y_array.shape[0]):#1 row of test set
		noWt = 0
		yesWt = 0
		for j in range(1,y_array.shape[1]):
			if(y_array[i][j] == "yes" and label==1):
				yesWt += classWts[j]
			else:
				noWt += classWts[j]
		if(yesWt <= noWt ):
			if(label==1):
				y_out.append("no")
		else:
			if(label==1):
				y_out.append("yes")

	return y_out



#For complete test set
def runClassifier(X_test,root,labels):
	y_out = []
	for i in range(0,X_test.shape[0]):
		y_out.append(traverseTree(X_test[i],root,labels))
	return y_out



def main():

		data = genfromtxt('data3_19.csv', delimiter=',', dtype = str)

		#Training Phase
		p = []
		indexArray = []
		flag=1
		replace = True
		D = data[1:,]
		for i in range(0,D.shape[0]):
			p.append(1/D.shape[0])
			if(flag==1):
				indexArray.append(i)
		flag=0
		#Random Sampling
		randomSample = np.random.choice(indexArray,D.shape[0],replace,p)
		#print(len(randomSample))

		train = D[:]
		#print(train1.shape[0])
		for i in range(0,D.shape[0]):
			if(flag==0):
				train[i] = D[randomSample[i]]
		print(train)

		y_array = []
		y = data[1:,3]
		classWts = []
		X = data[1:,0:3]
		# Extracting target class
		y.shape = (X.shape[0],1)
		treeArray = []
		for k in range(1,4):
			print("------------------------------------------------------------------------")
			print("CLASSIFIER " + str(k))
			#Extracting data labels and attributes
			labels = data[0,0:3]
			if(flag==0):
				attr = []
				tab = ""
				X_train = train[:,0:3]
			for i in range(0,3):
				attr.append(np.unique(X[:,i]))

			y_train = train[:,3]
			y_t = train[:,3]
			if(flag!=1):
				y_train.shape = (X_train.shape[0],1)
				root = recursiveTree(train,X_train,y_train,attr,labels,tab)
				treeArray.append(root)
				labels = labels.tolist()

			y_pred = runClassifier(X_train,root,labels)

			#Accuracy calculation
			y_t = y_t.tolist()
			n_pred = len(y_pred)	#Number of test samples

			count = 0
			for i in range(0,len(y_pred)):
				if(y_pred[i] == y_t[i] and flag==0):
					count += 1

			#Display accuracy
			print("Accuracy of the Classifier " + str(k) + " is: ")
			print(str(count/n_pred))

			E = 1 - (count/n_pred)
			curr_wt = classifierWeight(E)
			classWts.append(curr_wt)
			p = updateDataWts(p,y_train,y_pred,curr_wt)

			randomSample = np.random.choice(indexArray,D.shape[0],replace,p)

			train = D[:]
			for i in range(0,D.shape[0]):
				if(flag==0):
					train[i] = D[randomSample[i]]

		print("------------------------------------------------------------------------")
		print("COMBINED CLASSIFIER ")

		data_test = genfromtxt('test3_19.csv', delimiter=',', dtype = str)
		if(flag==0):
			y_test = data_test[1:,3]
			X_test = data_test[1:,0:3]
			y_test = y_test.tolist()

		#Testing Phase
		y_p = []
		flag=1
		for i in range(0,3):
			y_p = runClassifier(X_test,treeArray[i],labels)
			if(flag==1):
				y_array.append(y_p)
		y_array = np.asarray(y_array)
		c = 1
		y_array = np.transpose(y_array)
		if(flag==1):
			c=0
			y_out = finalOutput(classWts,y_array)

		n_test = len(y_test)#Number of test samples
		for i in range(0,len(y_out)):
			if(y_test[i] == y_out[i] and flag==1):
				c += 1
		flag=0
		#Display accuracy
		print("The Accuracy of Combined Classifier is : ")
		print(str(c/n_test))


if __name__=='__main__':
    main()
