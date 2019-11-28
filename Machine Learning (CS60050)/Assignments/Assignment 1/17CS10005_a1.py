'''
    Name : Anshul Choudhary
    Roll : 17CS10005
    Assignment No. : 1
'''

import numpy

def Entropy(TE_Y):
	accept_Y = TE_Y[numpy.where(TE_Y[:,0] == 'yes')]									# classify into accept and reject cases
	reject_Y = TE_Y[numpy.where(TE_Y[:,0] == 'no')]
	count_accY = accept_Y.shape[0]														# count accept cases
	count_rejY = reject_Y.shape[0]														# count reject cases

	prob_accY = count_accY / (count_accY + count_rejY)									# accept probability
	prob_rejY = count_rejY / (count_accY + count_rejY)									# reject probability
	return -(prob_accY * numpy.log(prob_accY)) - (prob_rejY * numpy.log(prob_rejY))		# return entropy


def Gain(TE,S,categ,index):
	n = TE.shape[0]																	# number of Training Examples
	sum = 0
	for catg in categ:																# calculate entropy for each case of 'categ' category(feature)
		sub_TE = TE[numpy.where(TE[:,index] == catg)]
		TE_Y = sub_TE[:,sub_TE.shape[1]-1]
		TE_Y.shape = (len(TE_Y),1)
		count_Y = TE_Y.shape[0]
		sum += (count_Y/n) * Entropy(TE_Y)

	return Entropy(S) - sum															# return Gain

def GenerateDecisionTree(TE,TE_X,TE_Y,categs,features,tab):
	
	feat_count = TE_X.shape[1]

	if(feat_count == 1):													# case when there is only one feature left
		index = 0

		for catg in categs[0]:

			sub_TE = TE[numpy.where(TE[:,index] == catg)]					# TE's where this feature takes value catg
			accept_TE = sub_TE[numpy.where(sub_TE[:,1] == 'yes')]			# corresponding accept TE
			reject_TE = sub_TE[numpy.where(sub_TE[:,1] == 'no')]			# corresponding reject TE

			if(accept_TE.shape[0] == 0 and reject_TE.shape[0] == 0):		# if no such TE, do nothing
				continue

			print(tab + features[index] + " = " + catg + ": ",end = " ")	

			if(accept_TE.shape[0] > reject_TE.shape[0]):					# if accept TE are more than reject TE 
				print("yes")
			else:
				print("no")
	
	else:																	# case where more than one feature are left
		index = 0
		max_gain = 0

		for i in range(feat_count):											# find feature with maximum gain
			gain = Gain(TE,TE_Y,categs[i],i)

			if(gain > max_gain):
				max_gain = gain
				index = i
		
		for catg in categs[index]:											# generate tree for each value of max_gain feature
			sub_TE = TE[numpy.where(TE[:,index] == catg)]
			count = sub_TE.shape[1]

			if(sub_TE.shape[0] == 0):										# if corresponding TE's are 0, continue to next feature value
				continue

			accept_TE = sub_TE[numpy.where(sub_TE[:,count-1] == 'yes')]		# accept TE's
			reject_TE = sub_TE[numpy.where(sub_TE[:,count-1] == 'no')]		# reject TE's

			if(accept_TE.shape[0] == 0):									# when all TE's are of accept case
				print(tab + features[index] + " = " + catg + ": no")		
				break
			elif(reject_TE.shape[0] == 0):									# when all TE's are of reject case
				print(tab + features[index] + " = " + catg + ": yes")
				break
																			# get new TE's for further proceeding
			TE_new = numpy.delete(sub_TE , index, axis=1)					# delete the feature cloumn that is already processed above
			count = TE_new.shape[1]
			TE_X_new = TE_new[:,0:count - 1]								# new TE conditions only
			TE_Y_new = TE_new[:,count-1]									# new TE outputs only
			TE_Y_new.shape = (len(TE_Y_new),1)
			features_new = numpy.delete(features,index)						# new features without the feature processed above
			categs_new = numpy.delete(categs,index)							# new categorys without category of feature processed above
			
			print(tab + features[index] + " = " + catg)
			
			GenerateDecisionTree(TE_new,TE_X_new,TE_Y_new,categs_new,features_new,tab + "|	")  	# recursive call for child nodes


data = numpy.genfromtxt('data1_19.csv', delimiter=',', dtype = str) 		# import data

features = data[0,0:3]														# array containing features

TE = data[1:]																# TE -> Traning Examples
TE_X = TE[:,0:3]															# TE conditions only
TE_Y = TE[:,3]																# TE outputs only
TE_Y.shape = (TE_X.shape[0],1)

categs = []																	# store all possible values of each feature
for i in range(3):
	categs.append(numpy.unique(TE_X[:,i]))

GenerateDecisionTree(TE,TE_X,TE_Y,categs,features,"")						# build decision tree