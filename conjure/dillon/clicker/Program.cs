using System;
using System.Collections.Generic;
using System.IO;
using OpenQA.Selenium;
using OpenQA.Selenium.Edge;
using YamlDotNet.RepresentationModel;

namespace SeleniumTest
{
    class Program
    {
        static Random random = new Random();

        static void Main(string[] args)
        {
            List<string> webList = new List<string>();
            using (StreamReader reader = new StreamReader("websites.txt"))
            {
                string line;
                while ((line = reader.ReadLine()) != null)
                {
                    webList.Add(line.Trim());
                }
            }

            string randWeb = webList[random.Next(0, webList.Count)];
            Console.WriteLine(randWeb);

            string url = "https://" + randWeb;

            var driver = new EdgeDriver();
            driver.Url = url;
            driver.Manage().Window.Maximize();
            System.Threading.Thread.Sleep(GetRandInt() * 1000);

            bool tabIsOpen = true;
            while (tabIsOpen)
            {
                Console.WriteLine("Entering while loop");

                driver.Manage().Timeouts().ImplicitWait = TimeSpan.FromSeconds(3);

                var pathLinks = driver.FindElements(By.PartialLinkText(""));
                Console.WriteLine("Got list of links");

                var visibleLinks = GetVisibleLinks(pathLinks);
                Console.WriteLine("Got visible links");

                if (visibleLinks.Count == 0)
                {
                    System.Threading.Thread.Sleep(3000);
                    driver.Close();
                    Environment.Exit(0);
                }

                var pathLink = visibleLinks[random.Next(0, visibleLinks.Count)];
                Console.WriteLine("Got link");
                driver.Manage().Timeouts().ImplicitWait = TimeSpan.FromSeconds(3);

                var scrollSpeed = GetRandScrollSpeed();
                Console.WriteLine("Scrolling");
                ScrollToElement(driver, scrollSpeed, pathLink);
                System.Threading.Thread.Sleep(1000);

                Console.WriteLine("About to click");
                ((IJavaScriptExecutor)driver).ExecuteScript("arguments[0].click();", pathLink);
                Console.WriteLine("Clicked on new link");
                System.Threading.Thread.Sleep(GetRandInt() * 1000);

                pathLinks = null;
                visibleLinks.Clear();

                Console.WriteLine("Checking quitNum");
                int quitNum = random.Next(0, 16);
                if (quitNum == 0)
                {
                    tabIsOpen = false;
                    System.Threading.Thread.Sleep(1000);
                    Console.WriteLine("quitNum: " + quitNum);
                    break;
                }
            }

            driver.Manage().Timeouts().ImplicitWait = TimeSpan.FromSeconds(2);
            System.Threading.Thread.Sleep(2000);

            driver.Close();
        }

        static Tuple<int, int> GetLinkCoordinates(IWebElement pathLink)
        {
            int height = pathLink.Size.Height;
            int width = pathLink.Size.Width;
            return new Tuple<int, int>(width, height);
        }

        static bool HasSize(IWebElement link)
        {
            return link.Size.Height > 0 && link.Size.Width > 0;
        }

        static int GetRandInt()
        {
            int waitTime = random.Next(1, 3);
            return waitTime;
        }

        static int GetRandScrollSpeed()
        {
            int randScrollSpeed = random.Next(5, 17);
            return randScrollSpeed;
        }

        static void ScrollToElement(IWebDriver driver, int speed, IWebElement pathLink)
        {
            var coordinates = GetLinkCoordinates(pathLink);
            int x = coordinates.Item1;
            int y = coordinates.Item2;
            long pageHeight = (long)((IJavaScriptExecutor)driver).ExecuteScript("return document.body.scrollHeight");
            int randHeight = random.Next(100, (int)pageHeight);
            int currPos = 0;
            int scrollHeight = 1;
            while (currPos <= scrollHeight)
            {
                currPos += speed;
                ((IJavaScriptExecutor)driver).ExecuteScript("window.scrollTo(0, arguments[0]);", currPos);
                scrollHeight = y + randHeight;
            }
        }

        static List<IWebElement> GetVisibleLinks(IReadOnlyCollection<IWebElement> pathLinks)
        {
            List<IWebElement> visibleLinks = new List<IWebElement>();
            foreach (var link in pathLinks)
            {
                if (link.Displayed && link.Enabled && HasSize(link))
                {
                    visibleLinks.Add(link);
                }
            }
            return visibleLinks;
        }
    }
}

