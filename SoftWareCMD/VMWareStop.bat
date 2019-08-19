@echo 正在关闭VMWare...
@echo off
net stop ufad-ws60
net stop VMAuthdService
net stop VMnetDHCP
net stop "VMware NAT Service"
net stop VMUSBArbService
@echo VMWare关闭成功!
pause