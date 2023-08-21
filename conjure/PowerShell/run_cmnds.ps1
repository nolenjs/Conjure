function ExecuteDownloadedFiles {
    Param($path="~/Downloads")
    # Get current path before going to Downloads dir
    $oldPath = (Invoke-Expression -Command "Get-Location")
    # Write-Host "$oldPath -> $path"
    Invoke-Expression -Command "cd $path"
    # #Get desired date for ls (E.g. Jun 22)
    # if ($date="today"){
    #     $date = Get-Date -UFormat "%b %d"
    # }
    # $date = "Jun 11"
    # TODO -> List all files downloaded today (or on specified day) then save in array
        # the split takes the string output and splits by space then saves as array
    $files = Invoke-Expression -Command "Get-ChildItem -Path $path"

    # $types = Invoke-Expression -Command "ls -l | awk '/$date/ {print $firstLine}'"
    # $files = Invoke-Expression -Command "ls -l | awk '/$date/ {print $lastLine}'"
    $spltr = $files -split "/" #spltr[-1] gets the whole filename

    foreach ($f in $files){
        $type = Get-Item -Path $f
        $type = $type.GetType().Name
        $fileName = $spltr[-1] # find file name
        $fileEnd = $spltr[-1] -split '[.]' # find file extension (pdf, doc, txt, pptx, zip, ps1)
        $fileEnd = $fileEnd[-1]
        Write-Host "$fileName : $fileEnd"
        $finalPath = "$path/$f"
        if ($fileEnd[-1] -eq "zip"){ # If compressed archive
            # Write-Host "Expanding $path/$f to $finalPath"
            Expand-Archive -Path "$path/$f" -DestinationPath "$path/$fileName"
            executeDownloadedFiles($finalPath) #Add files from archived folder to cmnd list
        }
        elseif (($fileEnd -eq "ps1") || ($fileEnd -eq "exe")){ # If PowerShell script, add cmnd as "./powershell.ps1"
            Invoke-Expression -Command "$finalPath"
        }
        # elseif ($fileEnd -eq "txt") {# If txt file, open notepad.exe and add sleep function before closing
        #     Add-Content -Path ("~/Downloads/cmnds.txt") -Value "notepad.exe $finalPath"
        # }
        # elseif (($fileEnd -eq "pdf") -or ($fileEnd -eq "pptx") -or ($fileEnd -eq "png") -or ($fileEnd -eq "jpg")){ 
        #     # If pdf/jpg/png/powerpoint, open them w/ Start-Process
        #     Add-Content -Path ("~/Downloads/cmnds.txt") -Value "Start-Process -FilePath $finalPath"
        # }
        elseif ($null -ne $type){ # If a directory, go into it and add its files to cmnd list
            if ($type -eq "DirectoryInfo"){
                executeDownloadedFiles($path/$fileName) #Add files from directory to cmnd list
            }
        }
        else {
            continue
        }
    }
    Set-Location $oldPath # Return to the original path
}

function main{
    executeDownloadedFiles
}

main # To run the main function above