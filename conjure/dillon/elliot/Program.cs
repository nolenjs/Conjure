using System;
using System.IO;

class Program
{
    static void Main()
    {
        //Console.WriteLine("Enter the folder name:");
        //string folderName = Console.ReadLine();
	string folderName = "testF";

        try
        {
            // Combine the current directory with the folder name
            string path = Path.Combine(Directory.GetCurrentDirectory(), folderName);

            // Create the folder
            Directory.CreateDirectory(path);

            Console.WriteLine("Folder created successfully!");
        }
        catch (Exception ex)
        {
            Console.WriteLine("An error occurred: " + ex.Message);
        }

        Console.ReadLine();
    }
}

