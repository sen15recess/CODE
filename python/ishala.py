from bs4 import BeautifulSoup
import urllib2
import re
pageFile = urllib2.urlopen("http://internshala.com/internships/computer%20science-internship")
pageHtml = pageFile.read()
soup = BeautifulSoup("".join(pageHtml))
soup = BeautifulSoup("".join(pageHtml))

f = open("G:/tosend.txt","w")

a = []
b = []
c = []
#get all links
for hit in soup.findAll(attrs={'class' : 'button_container'}):
	for link in hit.find_all('a'):
		a.append(link.get('href'))
		
for i in range(1,3):
	a[i] = "http://internshala.com" + a[i]
	
#internship details

for i in range(1,3):
    pageFile = urllib2.urlopen(str(a[i]))
    pageHtml = pageFile.read()
    soup = BeautifulSoup("".join(pageHtml))
    soup = BeautifulSoup("".join(pageHtml))
    for hit in soup.findAll(attrs={'class' : 'individual_internship_details'}):
            print (re.sub(' +',' ',hit.text))

    for hit in soup.findAll(attrs={'class' : 'freetext-container'}):
            print (re.sub(' +',' ',hit.text))
    print("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------")


