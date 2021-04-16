## 以太币钱包官网

https://www.myetherwallet.com/

注册钱包账户，也可以用火币网、币安网等交易平台的以太币钱包地址。

## 矿池

https://ethermine.org/start

asia1.ethermine.org:14444

## 挖矿

[lolMiner](https://github.com/Lolliedieb/lolMiner-releases/releases)

修改mine_eth_4G.bat文件（如果内存小于4G修改mine_eth.bat），修改矿池POOL=IP:端口，WALLET=钱包地址.矿工名。

```powershell
@echo off

setlocal enableDelayedExpansion

Rem #################################
Rem ## Begin of user-editable part ##
Rem #################################

set "POOL=eth.2miners.com:2020"
set "WALLET=0x155da78b788ab54bea1340c10a5422a8ae88142f.lolMinerWorker"							

Rem #################################
Rem ##  End of user-editable part  ##
Rem #################################

:loop
lolMiner.exe --algo ETHASH --pool !POOL! --user !WALLET! --watchdog exit
if %ERRORLEVEL% == 42 (
	timeout 10
	goto loop
)

pause
```

## 矿池监控

在矿池官网中的Miner Address搜索框中输入钱包地址，点击回车即可查看。

https://ethermine.org/miners/4f82C25E4A728ACfCe1830bb7097CCdC9Cb5B62E/dashboard

## 交易

首先注册火币网账号，然后把币从钱包账户转到火币网账号的以太网钱包账户中，然后去**币币交易**，**将ETH转换成USDT**（泰达币，一种将加密货币与法定货币美元挂钩的虚拟货币），最后再将**USDT转换成人民币**。