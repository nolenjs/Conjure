import requests
from bs4 import BeautifulSoup
import wget
import webbrowser
from selenium import webdriver
from selenium.webdriver.common.by import By
import time

import yaml
from xml.etree import ElementTree as ET
from lxml import etree
from lxml import html


def ICantBeBotheredToProperlyCleanThisYet():
    browser = webdriver.Firefox()
    site_url = 'https://www.ece.rutgers.edu/undergraduate-overview' #Given a URL
    browser.get(site_url)
    response = requests.get(site_url) # Response from request for website content

    # Using Beautiful Soup ---------

    #HTML source code of website
    soup = BeautifulSoup(response.content, 'html.parser') #HTML source code of website

    #Find link 'a' tags that point to links
    links = soup.find_all('a') 
    downloadLinks = []
    titleLinks = []

    print("\nSearching links\n")

    #Links found
    for links in links:
        link = links.get('href')
        title = links.text
        
        #Downloadable files based on file extensions
        downloadable = (".pdf" or ".txt" or ".docx" or ".png" or ".jpg" or ".pptx") in str(link)
        
        if downloadable: #Show downloadables
            downloadLinks.append(str(link))
            titleLinks.append(title)
            print("\n" + title)
            print(str(link))
            print("Is Downloadable  *******TRUE*******")

    print("\nDownloadable links array:")
    print(downloadLinks)

    time.sleep(5)

    print("\nDownloading Files\n")
    i=1

    for downloadLink in downloadLinks:
        #Open pdf page
        print("\nNavigating to "+ downloadLink)
        browser.get(downloadLink)
        time.sleep(3)
        fileName = "file" + str(i) + ".pdf"
        print(fileName)
        #Download
        r = requests.get(downloadLink)
        open(fileName, 'wb').write(r.content)
        print("Downloaded!")
        #Go back to main page
        time.sleep(3)
        print("Returning to main page")
        browser.get(site_url)
        time.sleep(3)
        i += 1


        

#Sitemap Content ----------

#content = response.content  # Content from the response
#root = etree.fromstring(content)
#urls = root.xpath("//loc/text()")

"""  Trial and Error below for Documentation

#Get Sitemap URLs ---------

sitemapTree = html.fromstring(content) # HTML handling
print(sitemapTree)  
urls = sitemapTree.xpath("//url/loc/text()")
print(urls)

#Downloadable Files -------

downloads = []
for url in urls:
    print(url)
    if url.endswith(('.pdf', '.doc', '.zip', '.txt')):
        downloads.append(url)

with open('output.txt', 'w') as file:
    for file_url in downloads:
        file.write(file_url + '\n')


#Parse the YAML Content
#sitemap = yaml.load(content, Loader=yaml.SafeLoader)

#Identify downloadable files

downloads = []

for url in sitemap['urls']:             #Sifts through links on the page
    if url['loc'].endWith('.pdf'):      #Checks for pdfs -- can be changed to download any file type
        downloads.append(url['loc'])

for fileURL in downloads:
    print(fileURL)


"""