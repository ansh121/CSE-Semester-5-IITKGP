####################################################################
#Name - Nilesh Mandal
#Roll - 17CS10031
#Assignment - 3
#*********Run With Python3***********
####################################################################

###############################BEGIN################################

#Importing required libraries
import numpy as np
import math
from numpy import genfromtxt

class Node:
	def __init__(self): 
		self.label = ""
		self.next = None
		self.nodelist = [] 
#To calculate entropy
def Entropy(y):
	P = y[np.where(y[:,0] == 'yes')]
	N = y[np.where(y[:,0] == 'no')]

	p = P.shape[0]
	n = N.shape[0]

	if(p + n == 0):
		return 0
	f_p = p / (p + n)
	f_n = n / (p + n)

	if(f_p == 0):
		f_p = 0.0000000001
	if(f_n == 0):
		f_n = 0.0000000001
		
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
		if(len(y) == 0):
			continue
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
	new_node = Node()
	#When only 1 attribute
	if(L == 1):
		new_node.label = labels[index]
		for val in attr[0]:
			curr = Node()#male,female,etc
			curr.label = val
			new_node.nodelist.append(curr)
			A = data[np.where(data[:,index] == val)]
			l = A.shape[1]
			YES = A[np.where(A[:,1] == 'yes')]
			NO = A[np.where(A[:,1] == 'no')]
			print(tab + labels[index] + " = " + val + ": ",end = " ")
			if(YES.shape[0] == 0 and NO.shape[0] == 0):
				n_val = Node()
				n_val.label = "yes"
				new_node.nodelist[len(new_node.nodelist) - 1].next = n_val
				print("yes")
				continue
			if(YES.shape[0] > NO.shape[0]):
				n_val = Node()
				n_val.label = "yes"
				new_node.nodelist[len(new_node.nodelist) - 1].next = n_val
				print("yes")
			else:
				n_val = Node()
				n_val.label = "no"
				new_node.nodelist[len(new_node.nodelist) - 1].next = n_val
				print("no")
	#More than 1 attribute
	else:
		#find attribute with max gain and store its column no. in 'index'
		for i in range(0,L):
			gain = Gain(data,y,attr[i],i)
			if(gain > max_gain):
			   max_gain = gain
			   index = i
		new_node.label = labels[index]
		#For all possible values of the max gain attribute 
		#E.g for gender,iterate through male and female
		for val in attr[index]:
			curr = Node()#male,female,etc
			curr.label = val
			new_node.nodelist.append(curr)
			A = data[np.where(data[:,index] == val)]
			l = A.shape[1]
			if(A.shape[0] == 0):
			   continue
			YES = A[np.where(A[:,l-1] == 'yes')]
			NO = A[np.where(A[:,l-1] == 'no')]
			if(YES.shape[0] == 0):			#if only 'no'
			   n_val = Node()
			   n_val.label = "no"
			   new_node.nodelist[len(new_node.nodelist) - 1].next = n_val
			   print(tab + labels[index] + " = " + val + ": no")
			   break
			elif(NO.shape[0] == 0):			#if only 'yes'
			   n_val = Node()
			   n_val.label = "yes"
			   new_node.nodelist[len(new_node.nodelist) - 1].next = n_val
			   print(tab + labels[index] + " = " + val + ": yes")
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
			new_node.nodelist[len(new_node.nodelist) - 1].next = recursiveTree(data_new,X_new,y_new,attr_new,labels_new,tab + "|	")
	return new_node


#For one row of test set
#Return predicted y value
def traverseTree(X,root,labels):
	if(root == None):
		return ""
	if(len(root.nodelist) == 0):
		if(root.label == "yes" or root.label == "no"):
			return root.label
		else:
			return ""
	i = labels.index(root.label)
	for var in root.nodelist:
		if(X[i] == var.label):
			return traverseTree(X,var.next,labels)
	return ""

#For complete test set
def runClassifier(X_test,root,labels):
	y_out = []
	for i in range(0,X_test.shape[0]):
		y_out.append(traverseTree(X_test[i],root,labels))
	return y_out

#####AdaBOOST Funtions#############################

#calculate weight of vote of a classifier
#If accuracy of classifier > 50%,then weight is positive,
#Else weight is negative
def classifierWeight(error):
	if(error == 0):
		error = 0.0000000001
	elif(error == 1):
		error = 1 - 0.0000000001; 
	p = (1 - error)/error
	return 0.5 * np.log(p)

#calculate final output list by combining results of all classifiers
#we pass a n x 3 array where we combine 
#y values of the 3 classifiers to get a single value for each row
def finalOutput(classWts,y_array):
	y_out = []
	for i in range(0,y_array.shape[0]):#1 row of test set
		yesWt = 0
		noWt = 0
		for j in range(1,y_array.shape[1]):
			if(y_array[i][j] == "yes"):
				yesWt += classWts[j]
			else:
				noWt += classWts[j]
		if(yesWt > noWt):
			y_out.append("yes")
		else:
			y_out.append("no")
	return y_out

#update weight of each data point so that
#incorrectly classified points have greater chance of being picked in next rounds
def updateDataWts(wtList,y_test,y_pred,classWt):
	Z = 0
	for i in range(0,len(wtList)):
		sign = 1
		if(y_test[i] != y_pred[i]):
			sign = -1
		wtList[i] = wtList[i] * math.exp(-1 * sign * classWt)
		Z += wtList[i]

	#Normalize
	for i in range(0,len(wtList)):
		wtList[i] = wtList[i]/Z
	
	return wtList


###################Calling Functions################################
#Loading data from the given csv file
data = genfromtxt('data3_19.csv', delimiter=',', dtype = str)

#Training Phase
p = []
indexArray = []
replace = True
D = data[1:,]
for i in range(0,D.shape[0]):
	p.append(1/D.shape[0])
	indexArray.append(i)

#Random Sampling
randomSample = np.random.choice(indexArray,D.shape[0],replace,p)
#print(len(randomSample))

train = D[:]
#print(train1.shape[0])
for i in range(0,D.shape[0]):
	train[i] = D[randomSample[i]]
print(train)

#3 rounds of adaboost
#3 classifiers built
classWts = []
y_array = []
X = data[1:,0:3]
# Extracting target class
y = data[1:,3]
y.shape = (X.shape[0],1)
treeArray = []
for k in range(1,4):
	print("########################################################################")
	print("CLASSIFIER " + str(k))
	#Extracting data labels and attributes
	labels = data[0,0:3]
	attr = []

	
	#tab : to add necessary indentation
	tab = ""

	#Build decision tree
	X_train = train[:,0:3]
	
	#make list of all possible values of all attributes 
	for i in range(0,3):
		attr.append(np.unique(X[:,i]))
	
	y_train = train[:,3]
	y_t = train[:,3]
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
		if(y_pred[i] == y_t[i]):
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
		train[i] = D[randomSample[i]]

print("########################################################################")
print("COMBINED CLASSIFIER ")

data_test = genfromtxt('test3_19.csv', delimiter=',', dtype = str)
X_test = data_test[1:,0:3]
y_test = data_test[1:,3]
y_test = y_test.tolist()

#Testing Phase
y_p = []
for i in range(0,3):
	y_p = runClassifier(X_test,treeArray[i],labels)
	y_array.append(y_p)
y_array = np.asarray(y_array)
y_array = np.transpose(y_array)

y_out = finalOutput(classWts,y_array)
#print(y_out)

#Accuracy calculation
n_test = len(y_test)#Number of test samples
c = 0
for i in range(0,len(y_out)):
	if(y_out[i] == y_test[i]):
		c += 1

#Display accuracy
print("Accuracy of the Combined Classifier is: ")
print(str(c/n_test))

################################END#################################
