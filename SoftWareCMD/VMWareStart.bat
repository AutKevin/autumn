@echo 开始启动VMWare...
@echo off
net start ufad-ws60
net start VMAuthdService
net start VMnetDHCP
net start "VMware NAT Service"
net start VMUSBArbService
@echo VMWare启动成功!
pause