using System;
using System.Collections.Generic;
using System.IO;
using OpenQA.Selenium;
using OpenQA.Selenium.Edge;
using OpenQA.Selenium.Support.UI;
using YamlDotNet.Serialization;
using YamlDotNet.Serialization.NamingConventions;

namespace RandomWebsiteAccess
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> webList = new List<string>();
            using (StreamReader sr = new StreamReader("websites.txt"))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    string website = line.Trim();
                    webList.Add(website);
                }
            }

            string randWeb = webList[new Random().Next(0, webList.Count)].Replace(".com", string.Empty);
            Console.WriteLine("Opening " + randWeb);

            string url = "https://" + randWeb + ".com";

            var deserializer = new DeserializerBuilder().WithNamingConvention(CamelCaseNamingConvention.Instance).Build();
            var userCreds = deserializer.Deserialize<Dictionary<string, Dictionary<string, string>>>(File.ReadAllText("webCredentials.yaml"));
            string googleButton = userCreds[randWeb]["class_name"]; // Access YAML file info to access the random page's button to click

            var driver = new EdgeDriver();

            driver.Navigate().GoToUrl(url);

            var webLinks = driver.FindElements(By.TagName("a")).ToList();

            var random = new Random();
            IWebElement link = webLinks[random.Next(0, webLinks.Count)];

            // IWebElement webButton = driver.FindElement(By.CssSelector(googleButton));

            System.Threading.Thread.Sleep(1000);

            link.Click();
            System.Threading.Thread.Sleep(5000);

            driver.Quit();
        }
    }
}

