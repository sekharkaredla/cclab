n=input("enter number of productions :")
head=[]
body=[]
for k in range(0,n):
	prod1=raw_input("enter the productions:")
	prod1=prod1.split('->')
	head.append(prod1[0])
	body.append(prod1[1])
#print head
#print body	
first={}
i=n-1

def isSmall(k):
	if ord(k)>=97 and ord(k)<=122:
		return True
	else:
		return False

for o in range(0,n):
	k=head[i]
	l=body[i].split('|')
	list=[]
#	print k
#	print l
	for m in l:
#               print m
		if isSmall(m[0]):
			list.append(m[0])
		else:
			list.append(''.join(first[m[0]]))	
	
	first[k]=list
	i-=1
#print first
for k in first.keys():
	print 'first of '+k+' is: '+''.join(first[k])
