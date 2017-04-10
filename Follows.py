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

#follows from here
follows={}
follows['S']=['^']
for o in range(0,n):
	k=head[o]
	count=0
	for l in body:
		count1=0
		for m in l:
			if k==m:
				if count1==len(l)-1:
					follows[k]=follows[head[count]]
				else:
					if l[count1+1]=='|':
						follows[k]=follows[head[count]]
					elif isSmall((l[count1+1])):
						follows[k]=l[count1+1]
					else:
						follows[k]=first[l[count1+1]]
					
			count1+=1
		count+=1

#print follows		
for k in follows.keys():
	print 'follows of '+str(k)+' is: '+''.join(follows[k])
