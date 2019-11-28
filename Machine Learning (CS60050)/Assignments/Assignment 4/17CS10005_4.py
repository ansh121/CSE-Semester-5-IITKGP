#######################################
#	Name - Anshul Choudhary
#	Roll No - 17CS10005
# 	Assignment No - 4 (clustering)
#######################################


import numpy
from numpy import genfromtxt

def EuclideanDistance(p1,p2):
    dist=0.0
    for i in range(4):
        dist = dist + (float(p1[i])-float(p2[i]))**2
    return numpy.sqrt(dist)

def calc_jaccard_distance(bucket,index_list,unique_list):
    
    for i in range(3):
        dist = 1.0
        intersection = numpy.intersect1d(bucket,index_list[i]).shape[0]
        union = numpy.union1d(bucket,index_list[i]).shape[0]
        dist -= intersection/union
        print("\tJaccard dist with ",  unique_list[i], " is : ", dist)

def print_jaccard_distance(bucket, mean, index_list, unique_list):
    for i in range(3):
        print("\ncluster : ",i,"\n\tMean : ", mean[i],"\n")
        calc_jaccard_distance(bucket[i],index_list,unique_list)
        
def get_index_list(n):
    index_list = []
    for i in range(n):
        index_list.append(i)
    return index_list

def get_cluster(n,mean,TE_X):
    cluster=[[],[],[]]
            
    for i in range(n):
        dist=0.000000
        select=0
        min=10000000.000
        for j in range(3):
            dist=EuclideanDistance(mean[j],TE_X[i])
            if(dist<min):
                select = j
                min = dist
        cluster[select].append(i)
    return cluster

def get_new_mean(cluster,TE):
    mean=[]
    for i in range(3):
        m=[float(0.0),float(0.0),float(0.0),float(0.0)]
        for ind in cluster[i]:
            #print(row)
            for k in range(4):
                m[k]=m[k]+float(TE[ind][k])

        for k in range(4):
            m[k]=m[k]/len(cluster[i])

        mean.append(m)
    return mean
    
    
def main():
    TE = genfromtxt('data4_19.csv', delimiter=',', dtype = str)

    TE_X = TE[:,0:4]
    TE_Y = TE[:,4]
    TE_Y.shape = (TE_X.shape[0],1)

    n = TE.shape[0]
    print("Dataset Size - ",n)

    index_list=get_index_list(n)

    randomPointIndex = numpy.random.choice(index_list,3)
    
    randomPoints=[]
    for i in range(3):
        randomPoints.append(list(TE_X[randomPointIndex[i]]))
    print("Random Points taken - ",randomPoints)

    mean=randomPoints
    for itr in range(10):
        cluster = get_cluster(n,mean,TE_X)
        mean = get_new_mean(cluster,TE)


    unique_clusters=numpy.unique(TE[:,4])
    orig_cluster_index_list=[[],[],[]]
    
    for i in range(n):
        index = list(numpy.where(unique_clusters==TE[i][4]))[0][0]
        orig_cluster_index_list[index].append(i)

    unique_clusters=list(unique_clusters)
    print_jaccard_distance(cluster, mean, orig_cluster_index_list, unique_clusters)
    
if __name__=='__main__':
    main()
