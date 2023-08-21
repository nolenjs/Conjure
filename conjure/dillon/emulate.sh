#!/bin/bash

# SSH connection details
WINDOWS_IP="10.65.181.206"
WINDOWS_USERNAME="futureleaders"
WINDOWS_PASSWORD="Conjure2023!"

# SSH connection and command execution
sshpass -p "$WINDOWS_PASSWORD" ssh -o StrictHostKeyChecking=no "$WINDOWS_USERNAME@$WINDOWS_IP" powershell -Command "cd dillon && cd win-x64 && ./edgeclicker"

