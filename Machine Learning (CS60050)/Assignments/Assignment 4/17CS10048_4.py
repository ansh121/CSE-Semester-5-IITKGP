# Roll : 17CS10048
# Name : Satyam Porwal
# Assignment Number : 4

import numpy as np
import csv

def read_input(fileAddress):
    data = [];
    with open(fileAddress) as csvFile:
        csvReader = csv.reader(csvFile)
        for row in csvReader:
            data.append(row[0:5])
    data = np.asarray(data);
    return data

def unique_list(d):
    tmp =[]
    for x in d:
        tmp.append(x)
    return np.unique(tmp)


def get_index_list(unique, data):
    list_ = []
    for x in unique:
        index = np.where(data==x)
        list_.append(index)
    return list_

# initialisation
def init(data,k):    
    index = np.random.choice(len(data),k,replace=False)
    return data[index]   


def distance(a,b):
    x = ((float(a[0])-float(b[0]))**2 + ((float(a[1])-float(b[1]))**2))
    x+= ((float(a[2])-float(b[2]))**2 + ((float(a[3])-float(b[3]))**2))
    return x


def closest(means, x):
    nearest = -1;
    minDist = float("inf")
    count=0
    for a in means:
        d = distance(a,x)
        if(d<=minDist):
            minDist = d
            nearest = count
        count+=1
    return nearest


def get_buckets_modified(means):
    bucket = []
    for j in range(0,3):
        temp = []
        temp = np.asarray(temp,dtype=np.int16)
        bucket.append(temp)
    for x in range(data.shape[0]):
        i = closest(means,data[x])
        bucket[i] = np.append(bucket[i],x)
    bucket = np.asarray(bucket)
    return bucket


def calc_new_mean_modified(bucket):
    means = []
    for i in range(bucket.shape[0]):
        temp  = [0.0,0.0,0.0,0.0]
        for j in bucket[i]:
            for k in range(len(temp)):
                temp[k] += float(data[j][k])
        for k in range(len(temp)):
            temp[k] /= (bucket[i].shape[0])        
        means.append(temp)
    return means


def k_means_iteration_modified(iteration,means):
    for i in range(iterations):
        bucket = get_buckets_modified(means)
        means  = calc_new_mean_modified(bucket)
    return means, bucket



def calc_jd(bucket,index_list):
    min_ind = -1
    min_d = 2
    for i in range(len(index_list)):
        d = 1.0
        intersection = np.intersect1d(bucket,index_list[i]).shape[0]
        union = np.union1d(bucket,index_list[i]).shape[0]
        d -= intersection/union
        if(d<min_d):
            min_d=d
            min_ind=i
    return min_d, min_ind


def print_jaccard_dist(bucket, mean, index_list, unique_list):
    for i in range(len(bucket)):
        jd, jind = calc_jd(bucket[i],index_list)
        formatted_mean = ['%.2f' % elem for elem in mean[i] ]        
        print("Jaccard dist for cluster ",i,"\n\t mean : ", formatted_mean, "\n\t with ",  unique_list[jind], f"\n\t is {jd:.2f} %\n")

data = read_input('data4_19.csv')
unique = unique_list(data[:,4])
index_list = get_index_list(unique,data[:,4])
k=3
means = init(data,k)
print("Initially random chosen means are :\n",means,"\n");
iterations = 10
bucket = get_buckets_modified(means)
means_f, bucket_f = k_means_iteration_modified(iterations,means)
print_jaccard_dist(bucket_f,means_f,index_list,unique)

