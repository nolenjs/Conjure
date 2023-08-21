def randWebsite():
    webList = []
    with open("websites.txt") as webFile:
        for website in webFile:
            website = website.strip()       #get list of websites from text file into a list
            webList.append(website)


    randWeb = random.choice(webList)        #pick random website for user to access
    print(randWeb)

    url = "https://" + randWeb      #add "https://" to make valid url 

    # userCreds = yaml.load(open("webCredentials.yaml"))
    # googleButton = userCreds[randWeb]['class_name']                #access yaml file info to access the random page's button to click

    driver = webdriver.Chrome()        #instance of a web driver to access random websites on chrome

    driver.get(url)         #go to randomly chosen url
    driver.maximize_window()        #full screen to have more space to find links

    time.sleep(getRandInt())      #wait for random num of seconds to see effects of buttons before continuing on path

    tab_is_open = True
    while tab_is_open:                  #loop to naviagte down a path on the same website
        print("entering while loop\n")
    
        driver.implicitly_wait(3)

        pathLinks = driver.find_elements(By.PARTIAL_LINK_TEXT, "")      #tag_name finds all links available on page, builds list of all website links to choose one randomly
        print("got list of links\n")

        visibleLinks = getVisibleLinks(pathLinks)                      #sorting through all links to only get clickable ones
        print("got visible links\n")

        if len(visibleLinks)==0:           #if no visible links on page, close program -> FOR FUTURE -> maybe we could navigate to a new random website?
            time.sleep(3)
            driver.close()
            exit(0)

        pathLink = visibleLinks[randint(0, len(visibleLinks)-1)]        #choose random link from visible links
        print("got link\n")
        driver.implicitly_wait(3)       #giving time for driver+page to load before advancing   

        scrollSpeed = getRandScrollSpeed()      #use random int function to create a random speed for scrolling down page
        print("scrolling\n")
        scrollToElement(driver, scrollSpeed, pathLink)       #scroll down to random web element (pathLink)
        time.sleep(1)

        print("about to click\n")
        driver.execute_script("arguments[0].click();", pathLink)       #sub for pathLink.click(), fixes "elememt would be intercepted" error
        

        print("clicked on new link\n")
        time.sleep(getRandInt())
        pathLinks.clear()       #clear array of links before next loop iteration (redundant?)
        visibleLinks.clear()

        print("checking quitNum\n")
        quitNum = randint(0, 15)
        if quitNum==0:                              #exits loop randomly, when randint() == 0
            tab_is_open=False
            time.sleep(1)
            print("quitNum: ", quitNum)
            break


    driver.implicitly_wait(2)       #stay on page for 2 seconds, then close tab

    driver.close()    #close web driver