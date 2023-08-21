import random
import webbrowser
import yaml
import requests
import time
import wget
from selenium import webdriver
from selenium.webdriver.common.by import By


#Uncomment the time.sleep lines for realistic simulation

#--------RUH RAH RAH----------

# New Website -------------------
def newWebsite(url):
    browser = webdriver.Firefox()
    rutgers_url = 'https://grad.rutgers.edu/academics/programs/electrical-computer-engineering'
    browser.get(rutgers_url)
    time.sleep(1)
    rutgers_window = browser.current_window_handle

# Accept Cookies
def selectAcceptCookies():
    browser = webdriver.Firefox()
    button_selector = 'agree-button'
    cookies_button = browser.find_element(By.CLASS_NAME, button_selector)
    cookies_button.click()
    time.sleep(2)

# Apply
def selectApply():
    browser = webdriver.Firefox()
    button_selector = 'a.btn'
    apply_button = browser.find_element(By.CSS_SELECTOR, button_selector)
    apply_button.click()
    time.sleep(3)

# Newsletter PDF
def selectNewsletterPDF():
    browser = webdriver.Firefox()
    button_selector = '.pane-block-17 > p:nth-child(3) > strong:nth-child(3) > em:nth-child(1) > a:nth-child(1)'
    apply_button = browser.find_element(By.CSS_SELECTOR, button_selector)
    apply_button.click()
    time.sleep(3)

# Download PDF -------------------
def downloadPDF():
    browser = webdriver.Firefox()
    url = browser.current_url
    print(url)
    r = requests.get(url, allow_redirects=True)
    file = open('Download.pdf','w+')
    file.write(r.content)

# New Website --------------------
def rutgersGradTest():
    newWebsite("https://grad.rutgers.edu/academics/programs/electrical-computer-engineering")
    selectAcceptCookies()
    selectApply()
    selectNewsletterPDF()
    downloadPDF()
    # Close the tab
    browser.close

def rutgersBusTest():
    newWebsite("'https://myrbs.business.rutgers.edu/mba/downloadable-forms'")
    # Download link
    button_selector = '.field--name-field-p-wysiwyg-body > ul:nth-child(3) > li:nth-child(1) > a:nth-child(1)'
    apply_button = browser.find_element(By.CSS_SELECTOR, button_selector)
    apply_button.click()

    time.sleep(5)
    # Close the tab
    browser.close