from bs4 import BeautifulSoup
import urllib2
import re
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
sender = 'indrajeet.lyfsgr8@gmail.com'
receiver = 'sen15recess@gmail.com'
GMAIL_USERNAME = "sentest15@gmail.com"
GMAIL_PASSWORD = "123@Kiit"
pageFile = urllib2.urlopen("http://internshala.com/internships/computer%20science-internship")
pageHtml = pageFile.read()
soup = BeautifulSoup("".join(pageHtml),"html5lib")
f = open("G:/tosend.txt","w+")
filename = "tosend.txt"
a = []

#get all links
for hit in soup.findAll(attrs={'class' : 'button_container'}):
	for link in hit.find_all('a'):
		a.append(link.get('href'))
#adding domain name to extended address		
for i in range(1,10):
	a[i] = "http://internshala.com" + a[i]
	
#writing internship details to file
for i in range(1,10):
    pageFile = urllib2.urlopen(str(a[i]))
    pageHtml = pageFile.read()
    soup = BeautifulSoup("".join(pageHtml),"html5lib")
    for hit in soup.findAll(attrs={'class' : 'individual_internship_details'}):
            k = (re.sub(' +',' ',hit.text))
            f.write(k)#date

    for hit in soup.findAll(attrs={'class' : 'freetext-container'}):
            l = (re.sub(' +',' ',hit.text))
            f.write(l.encode('utf-8').strip())#info
    m = "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------"
    f.write(m)

#attaching text file to email
attachment = MIMEText(f.read())
msg = MIMEMultipart('alternative')
attachment.add_header('Content-Disposition', 'attachment', filename=filename)
msg.attach(attachment)
#sending mail
smtpObj = smtplib.SMTP('smtp.gmail.com:587')
smtpObj.ehlo()
smtpObj.starttls()
smtpObj.login(GMAIL_USERNAME, GMAIL_PASSWORD)
smtpObj.sendmail(GMAIL_USERNAME, receiver, msg.as_string())         
print "Successfully sent email"

f.close()
