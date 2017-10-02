class sujeet:
	key=0
	l=0
	r=0
class manit:
	start=0
	end=0
t=int(input())
while t:
	t=t-1
	n,m=input().split()
	m=int(m)
	
	n=int(n)
	
	a=[sujeet() for i in range(m+1)]
	c=[manit() for i in range(m+1)]
	v=[manit() for i in range(n+1)]
 
	for i in range(1,n+1):
		v[i].start=0
		v[i].end=0
 
	for i in range(1,m+1):
		c[i].start=0
		c[i].end=0
 
	for i in range(1,m+1):
		x,y,z=input().split()
		a[i].key=int(x)
		a[i].l=int(y)
		a[i].r=int(z)
 
	sid=1
 
	for i in range(m,0,-1):
		sid=sid+c[i].end
		if a[i].key==2:
			c[a[i].l].start=c[a[i].l].start+sid
			c[a[i].r].end=c[a[i].r].end+sid
		sid=sid-c[i].start
 
	sid=1
 
	for i in range(1,m+1):
		sid=sid+c[i].start
		if a[i].key==1:
			v[a[i].l].start=v[a[i].l].start+sid
			v[a[i].r].end=v[a[i].r].end+sid	
		sid=sid-c[i].end
 
	sid=0
 
	p=0
 
	for i in range(1,n+1):
		sid=sid+v[i].start
		p=sid%1000000007
		print(p,end=" ");
		sid=sid-v[i].end
	print()
 
