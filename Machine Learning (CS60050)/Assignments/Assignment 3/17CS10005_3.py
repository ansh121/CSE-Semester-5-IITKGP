##########	Name - Anshul Choudhary
##########	Roll - 17CS10005
##########	Assignment - 3 (AdaBoost)

import numpy
import math
from numpy import genfromtxt

####################### Class #######################

class Node:
	def __init__(self): 
		self.label = ""
		self.next = None
		self.child_nodes = [] 

####################### Funcions #######################


def Entropy(TE_Y):
	reject_Y=[]
	accept_Y=[]
	for TE in TE_Y:
		if(TE[0]=='no'):
			reject_Y.append(TE)
		else:
			accept_Y.append(TE)

	count_accY = len(accept_Y)
	count_rejY = len(reject_Y)

	count = count_accY + count_rejY
	if(count == 0):
		return 0
	prob_accY = count_accY / count
	prob_rejY = count_rejY / count

	if(prob_accY == 0):
		prob_accY = 0.0000000001
	if(prob_rejY == 0):
		prob_rejY = 0.0000000001

	e1 = prob_rejY * numpy.log(prob_rejY)
	e2 = prob_accY * numpy.log(prob_accY)
	e = e1 - e2
		
	return  e


def Gain(TE,S,categ,index):
	n = TE.shape[0]
	sum = 0
	for catg in categ:
		sub_TE = TE[numpy.where(TE[:,index] == catg)]
		TE_Y = sub_TE[:,sub_TE.shape[1]-1]
		TE_Y.shape = (len(TE_Y),1)
		count_Y = TE_Y.shape[0]
		sum = sum + (count_Y/n) * Entropy(TE_Y)

	g = Entropy(S)
	g = g - sum

	return g 


def GenerateDecisionTree(TE,TE_X,TE_Y,feat_categs,features,indent):
	
	feat_count = TE_X.shape[1]
	root_node = Node()
	s_TE=[]

	if(feat_count == 1):
		index = 0

		root_node.label = features[index]
		for categ in feat_categs[0]:
			curr = Node()
			curr.label = categ
			root_node.child_nodes.append(curr)

			sub_TE = TE[numpy.where(TE[:,index] == categ)]
			accept_TE = sub_TE[numpy.where(sub_TE[:,1] == 'yes')]
			reject_TE = sub_TE[numpy.where(sub_TE[:,1] == 'no')]

			print(indent + features[index] + " = " + categ + ": ",end = " ")

			node_val = Node()
			node_val.label = "yes"

			if(accept_TE.shape[0] == 0 and reject_TE.shape[0] == 0):
				root_node.child_nodes[len(root_node.child_nodes) - 1].next = node_val
				print("yes")
				continue
			if(accept_TE.shape[0] > reject_TE.shape[0]):
				root_node.child_nodes[len(root_node.child_nodes) - 1].next = node_val
				print("yes")
			else:
				node_val.label = "no"
				root_node.child_nodes[len(root_node.child_nodes) - 1].next = node_val
				print("no")
	
	else:
		index = 0
		max_gain = 0
		
		for i in range(0,feat_count):
			gain = Gain(TE,TE_Y,feat_categs[i],i)
			if(gain > max_gain):
			   max_gain = gain
			   index = i
		root_node.label = features[index]
		
		for categ in feat_categs[index]:
			curr = Node()
			curr.label = categ
			root_node.child_nodes.append(curr)

			sub_TE = TE[numpy.where(TE[:,index] == categ)]

			l = sub_TE.shape[1]
			if(sub_TE.shape[0] == 0):
			   continue

			accept_TE = sub_TE[numpy.where(sub_TE[:,l-1] == 'yes')]
			reject_TE = sub_TE[numpy.where(sub_TE[:,l-1] == 'no')]

			reject=[]
			accept=[]
			for TE in s_TE:
				if(TE[0]=='no'):
					reject.append(TE)
				else:
					accept.append(TE)

			count_aY = len(accept)
			count_rY = len(reject)

			node_val = Node()
			node_val.label = "yes"

			if(accept_TE.shape[0] == 0):
			   node_val.label = "no"
			   root_node.child_nodes[len(root_node.child_nodes) - 1].next = node_val
			   print(indent + features[index] + " = " + categ + ": no")
			   break
			elif(reject_TE.shape[0] == 0):
			   root_node.child_nodes[len(root_node.child_nodes) - 1].next = node_val
			   print(indent + features[index] + " = " + categ + ": yes")
			   break
			
			new_TE = numpy.delete(sub_TE , index, axis=1)
			l = new_TE.shape[1]
			X_new = new_TE[:,0:l - 1]
			y_new = new_TE[:,l-1]
			y_new.shape = (len(y_new),1)
			new_features = numpy.delete(features,index)
			new_categs = numpy.delete(feat_categs,index)
			
			print(indent + features[index] + " = " + categ)

			root_node.child_nodes[len(root_node.child_nodes) - 1].next = GenerateDecisionTree(new_TE,X_new,y_new,new_categs,new_features,indent + "|	")
	return root_node


def DFS(Test_X,root_node,features):
	if(root_node == None):
		return ""
	if(len(root_node.child_nodes) == 0):
		if(root_node.label == "yes" or root_node.label == "no"):
			return root_node.label
		else:
			return ""
	i = features.index(root_node.label)
	for var in root_node.child_nodes:
		if(Test_X[i] == var.label):
			return DFS(Test_X,var.next,features)
	return ""

def Generate_Classifier(Test_X,root_node,features):
	y_out = []
	for i in range(0,Test_X.shape[0]):
		y_out.append(DFS(Test_X[i],root_node,features))
	return y_out

def Classifier_Evaluate(Test_X,root_node,categs,features):
	if(root_node!=None):
		return True
	l=[]
	for categ in categs:
		l.append(categ)
		print(l)
		n_node=DFS(TestX,root,features)
		i=features,index(root_node.label)

	for var in root_node.child_nodes:
		if(Test_X[i] != var.label):
			return DFS(Test_X,var.next,features)
	return "	"	


###  ADABOOST  ###

def get_classifier_Weight(error):
	if(error == 0):
		error = 0.0000000001
	elif(error == 1):
		error = 1 - 0.0000000001; 

	E=(1 - error)
	E=E/error
	E=numpy.log(E)
	E=0.5 * E
	return E 



def update_weights(weight_list,Test_Y,pred_Y,class_weight):
	Total_Weight = 0
	for i in range(0,len(weight_list)):
		f = -1
		if(Test_Y[i] == pred_Y[i]):
			f = 1
			
		temp = -1
		temp = temp * f
		temp = temp * class_weight
		weight_list[i] = weight_list[i] * math.exp(temp)
		Total_Weight = Total_Weight + weight_list[i]

	for i in range(0,len(weight_list)):
		weight_list[i] = weight_list[i]/Total_Weight
	
	return weight_list


############################ Main ##############################

def main():
	data = genfromtxt('data3_19.csv', delimiter=',', dtype = str)

	TE = data[1:,]
	TE_X = data[1:,0:3]
	TE_Y = data[1:,3]
	TE_Y.shape = (TE_X.shape[0],1)

	prob = []
	indexArray = []

	for i in range(0,TE.shape[0]):
		prob.append(1/TE.shape[0])
		indexArray.append(i)
	    
	treeArray = []
	class_weights = []
	y_array = []

	for k in range(1,4):
		
		randomSample = numpy.random.choice(indexArray,TE.shape[0],True,prob)
		
		TE_sample = TE[:]
		for i in range(0,TE.shape[0]):
			TE_sample[i] = TE[randomSample[i]]
	        
		print("\n-------------------> Classifier " + str(k) + " <-------------------")
		features = data[0,0:3]
		feat_categs = []

		indent = ""

		
		for i in range(0,3):
			feat_categs.append(numpy.unique(TE_X[:,i]))
		
		TE_sample_X = TE_sample[:,0:3]
		TE_sample_Y = TE_sample[:,3]
		Y_T = TE_sample[:,3]
		TE_sample_Y.shape = (TE_sample_X.shape[0],1)
	    
		root_node = GenerateDecisionTree(TE_sample,TE_sample_X,TE_sample_Y,feat_categs,features,indent)
		treeArray.append(root_node)
	    
		features = features.tolist()
		
		pred_Y = Generate_Classifier(TE_sample_X,root_node,features)
		
		Y_T = Y_T.tolist()
		
		corr_count = 0
		for i in range(0,len(pred_Y)):
			if(pred_Y[i] == Y_T[i]):
				corr_count += 1
		
		test_count = len(pred_Y)
		acc=corr_count/test_count
		print("\nAccuracy : "+str(acc) )

		E = 1 - (acc)
		curr_wt=get_classifier_Weight(E)
		class_weights.append(curr_wt)
		prob = update_weights(prob,TE_sample_Y,pred_Y,curr_wt)
	    
	    

	print("\n================> COMBINED CLASSIFIER <=============== ")

	data_test = genfromtxt('test3_19.csv', delimiter=',', dtype = str)
	Test_X = data_test[1:,0:3]
	Test_Y = data_test[1:,3]
	Test_Y = Test_Y.tolist()


	y_p = []
	for i in range(0,3):
		y_p = Generate_Classifier(Test_X,treeArray[i],features)
		y_array.append(y_p)
	    
	y_array = numpy.asarray(y_array)
	y_array = numpy.transpose(y_array)

	pred_Y = []
	for i in range(0,y_array.shape[0]):
		pos_weight = 0
		neg_weight = 0
		for j in range(1,y_array.shape[1]):
			if(y_array[i][j] == "yes"):
				pos_weight = pos_weight + class_weights[j]
			else:
				neg_weight = neg_weight + class_weights[j]
		if(neg_weight < pos_weight):
			pred_Y.append("yes")
		else:
			pred_Y.append("no")

	n_test = len(Test_Y)
	c = 0
	for i in range(0,len(pred_Y)):
		if(pred_Y[i] == Test_Y[i]):
			c = c + 1

	acc = c/n_test
	print("\nFinal Accuracy : "+str(acc)+'\n')

if __name__=='__main__':
    main()

