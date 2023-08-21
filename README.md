# Conjure

A Command Line Tool to automate user interaction and traffic on workstations. 
Primary use case includes a White team tool to simulate user interaction in a 
Red vs Blue competition environment.

# Preliminary Setup (**Remove before submission**)

The repository can be cloned with both https or ssh to run the code. However, 
problems pushing changes have occured using the HTTPS method. A solution we 
reached was to clone the repository via SSH (git clone <copied_ssh_address>). 
Before cloning, you should ensure that your public ssh key (your computer 
should have one from the other times we have used ssh here at ACE) saved in 
your settings. To add a ssh key pair in your profile settings, click on your 
profile and go to settings. In SSH keys on the sidebar, you can paste your key 
in the big text box. You can get your public key from your computer by running 
`cat ~/.ssh/id_rsa.pub` in a terminal anywhere on your computer and copy/paste 
the output in the big text box and clicking **Add key**. After adding your 
keys.

# Cloning the Repository (**Remove before submission**)

Copy the ssh address from the clone button in the repository home page. 
Once copied, go into the directory where you want to save the repository and 
run `git clone <copied_ssh_address>`. 

# Requirements 
- Both
   - 
- Conjure Server
   - The Conjure server should only exist on a White Team admin's computer. 
   - One should suffice, but multiple servers can be set up to manage different
     sets of machines.
   - It needs a list of every VM's IP Conjure will manage so it can control
     those VMs.
- Client VMs
   - Recommended to downlaod in Windows/System32. Can be placed anywhere 
     theoretically, but the System32 will have other services running to better 
     mask Conjure's interactions with the VM.
   - Conjure's client code should be running on the VMs before starting the 
     exercise to ensure they respond to the server's commands.

# How to Use (**TODO**)
- Help (./V2conjure -h –OR– ./V2conjure --help)
Running ./V2conjure -h will display the commands that a user can use with the conjure server. These are split into argument-free instructions & instructions that require some arguments. They can be run by typing 
	./V2conjure <flag> <parameters>

- Pause (./V2conjure -p –OR– ./V2conjure --pause)
The pause command will tell all running VMs to pause running. Each instance of conjure client will cease scrolling through webpages and instead continually wait for a new instruction

- Continue (./V2conjure -c –OR– ./V2conjure --continue)
The continue command will make all VMs continue running. Any paused instances of conjure client will continue scrolling through webpages. Any unpaused instances of conjure client will do nothing

- Logs (./V2conjure -l –OR– ./V2conjure --logs)
The logs command will retrieve all log information from all conjure client instances. This will be outputted into a text file called allLogs.txt

- End (./V2conjure -e –OR– ./V2conjure --end)
The end command will close all conjure client instances. Once these have been closed, the client can only be reopened by restarting the machine it is on

- Download (./V2conjure -d <IP of client> <address of file> –OR– ./V2conjure --download <IP of client> <address of file>)
The download command will download and execute an online file from <address of file> onto the client vm at <IP of client>

- Maxip (./V2conjure -i <max_ip_number> –OR– ./V2conjure --maxip <max_ip_number>)
Maxip determines the maximum number of IPs allowed to be stored within the conjure server

- Port (./V2conjure -l <port> –OR– ./V2conjure --port <port>)
Port will set the port number of the server to <port>. Make sure to set the clients to use the same port

- Enclaves (./V2conjure -n <count> –OR– ./V2conjure --enclaves <count>)
Enclaves will set the number of enclaves that conjure can access

# Features (**TODO**)
 - User Automation
   - Tunnel from Conjure into a target VM
   - Load an executable/script from Conjure on a VM (*ongoing*)
   - Access a random website on a target VM 
   - Scroll to a desired element on a website 
   - Explore to other sites via hyperlinks 
   - Download files from a website to VM 
   - Execute files that are downloaded 
 - Red Team Requests
   - Download specific files (*ongoing*)

# Credits
- Development
  - Alan Middleton
  - Dillon Shah
  - Elliot Viaud-Murat
  - Nolen Shubin
  - Quillen Flanigan
  - Veronica Vergara
- Research Mentors
  - Tom Henry
  - Matthew Rodrick
- Supervisor
  - Ryan Casa


