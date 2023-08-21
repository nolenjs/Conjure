In the project dir, we can see an example (console) dotnet project that will do website automation.

Requirements:
dotnet-6.0
dotnet package Selenium.WebDriver
dotnet package YamlDotNet

mono-mcs (for cross-compilation)

useful commands:
dotnet add package <packagename>
dotnet run

mcs /target:winexe /out:<ProjectName>.exe <ProgramName>.cs (cross-compile)

alternatively:
dotnet publish (look at args)
#can be used to produce an executable for windows with dependencies, probably better than mono

example: 
dotnet publish --self-contained true --runtime win-x64

would require installing .NET Core SDK
