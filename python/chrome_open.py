import os
from selenium import webdriver

chromedriver = "C:/Downloads/chromedriver_win32/chromedriver"
os.environ["webdriver.chrome.driver"] = chromedriver
driver = webdriver.Chrome(chromedriver)
driver.get("http://internshala.com/internships/computer%20science-internship")
