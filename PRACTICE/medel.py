# cook your dish here
t=int(input())
for i in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    while len(l)>2:
        if (l[0]>l[1] and l[1]>l[2]) or (l[2]>l[1] and l[1]>l[0]):
            del(l[1])
        elif (l[2]>l[1] and l[0]>l[2]) or (l[2]>l[0] and l[1]>l[2]):
            del(l[2])
        elif (l[0]>l[1] and l[0]<l[2]) or (l[2]<l[0] and l[1]>l[0]):
            del (l[0])
    print(str(l[0])+" "+str(l[1]))    
