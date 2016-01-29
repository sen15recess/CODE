
from selenium import webdriver
import time


baseurl = "https://192.168.100.2:8090/httpclient.html"


username = "1301000"
password = "123@kiit"

for i in range(200):
    mydriver = webdriver.Firefox()
    mydriver.get(baseurl)
    mydriver.maximize_window()
    xpaths = { 'usernameTxtBox' : "//input[@name='username']",
               'passwordTxtBox' : "//input[@name='password']",
               'submitButton' :   "//input[@name='btnSubmit']"
             }
    username = int(username)
    username = str(username + 1)  
    #Clear Username TextBox if already allowed "Remember Me" 
    mydriver.find_element_by_xpath(xpaths['usernameTxtBox']).clear()

    #Write Username in Username TextBox
    mydriver.find_element_by_xpath(xpaths['usernameTxtBox']).send_keys(username)

    #Clear Password TextBox if already allowed "Remember Me" 
    mydriver.find_element_by_xpath(xpaths['passwordTxtBox']).clear()

    #Write Password in password TextBox
    mydriver.find_element_by_xpath(xpaths['passwordTxtBox']).send_keys(password)

    #Click Login button
    mydriver.find_element_by_xpath(xpaths['submitButton']).click()
    time.sleep(2)
