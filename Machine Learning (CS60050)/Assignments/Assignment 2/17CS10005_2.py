###################################
# Name - Anshul Choudhary
# Roll No - 17CS10005
# Assignment No - 2
##################################

import csv
import numpy as np

def get_count(array,val):
    count=0
    for x in array: 
        if(x==val):
            count+=1
    return count
   

def get_yes_data(names,data,value,pos_count,find):
    p= []
    for x in range(len(names)-1):
        dist_values = ['1','2','3','4','5']
        size = len(dist_values)
        temp_p=[]
        for val in dist_values:
            indexes = np.where(data[:,x-1]==val)
            temp = []
            for i in indexes:
                temp.append(value[i])
            temp_p.append((get_count(temp[0],find)+1)/(pos_count+size))
        temp_p = np.asarray(temp_p)
        p.append(temp_p)
    p = np.asarray(p)
    return p


def single_testing(inp, exp_out,data_trained,train_dist_val,train_p):
    maximum = 0
    for i in range(np.shape(data_trained)[0]):
        p = train_p[i]
        for j in range(len(inp)):
            p *= float(data_trained[i][j-1][int(inp[j])-1])
        if(p>maximum):
            maximum = p
            out = train_dist_val[i]
    if(out == exp_out):
        return 1
    else:
        return 0

def train_data(values, count, names, data, value):
    tr = []
    for i  in range(len(values)):
        tr.append(get_yes_data(names,data,value,count[i],values[i]))
    tr = np.asarray(tr)
    return tr

def read(Address):
    value=[]
    data=[]
    with open(Address) as f:
        reader = csv.reader(f)
        count=0
        for row in reader:
            temp = row[0].split(',')
            if(count!=0):
                data.append(temp[1:7])
                value.append(temp[0])
            else:
                names = temp
            count = count + 1
    value = np.asarray(value)
    data = np.asarray(data)
    names = np.asarray(names)
    return names,data,value


names,training_data,training_value = read("data2_19.csv")
names,test_data,test_value = read("test2_19.csv")


tmp =[]
for x in training_value:
    tmp.append(x)
dist_values = np.unique(tmp)

dist_count = []
for i in dist_values:
    dist_count.append(int(get_count(training_value,i)))


total = sum(dist_count)
dist_p = [x/total for x in dist_count]

train = train_data(dist_values, dist_count, names, training_data, training_value)

total   = 0
correct = 0
for i in range(len(test_data)):
    correct += single_testing(test_data[i],test_value[i],train,dist_values,dist_p)
    total   += 1
accuracy= correct/total

ans = accuracy*100
print("Model accuracy is %.3f %%"%ans)