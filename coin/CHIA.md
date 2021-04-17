## CHIA币官网

https://www.chia.net/

注册钱包账户。

## 矿池

https://www.hpool.com/

## 钱包挖矿

可以直接用官网的钱包先Plot再Farm挖矿，即先P盘再挖矿。

## 矿池挖矿

和钱包一样，先P盘再挖矿，先用**chia-plotter工具P盘**，生成PLOT文件后用**hpool-miner-chia软件挖矿**。

### 签名

访问[Hpool官网](https://www.hpool.com/tools)，在下载中心下载CHIA[算力签名软件](https://github.com/hpool-dev/chia-plotter/releases)；

运行签名软件“chia-plotter-gui-v0.11-win64.exe”，输入24个助记词，点击签名；生成**指纹**（Fingerprint，要和Chia Blockchain的Keys里一致）、**矿工公钥**（fpk）、**矿池公钥**（ppk）、**签名**。

### 开通矿池

登录[Hpool矿池](https://www.hpool.com/)，在个人中心-开通矿池页面，点击“全部”找到“CHIA生态池”并点击“开通矿池”；

### 绑定数据

在“chia-plotter-gui-v0.11-win64.exe”**运行界面**，找到Signature签名并复制；在个人中心-配置矿机页面，下拉菜单选择“CHIA生态池”，黏贴字符串至输入框中并点击“绑定”；绑定成功后下面会自动显示指纹和签名时生成的矿池公钥。

### P盘

#### 获取fpk和ppk

在签名工具“chia-plotter-gui-v0.11-win64.exe”**运行界面**，复制矿工公钥（fpk）及矿池公钥（ppk）；

#### P盘软件配置

下载[chia-plotter-v0.11-win64.zip](https://github.com/hpool-dev/chia-plotter/releases)工具，修改plotting.bat中的**fpk**和**ppk**以及**缓存路径**和**目标路径**。

若P盘成功，会在目标路径文件夹中生成一个类型为“PLOT文件”的文件，大小约为101G；

### 挖矿

下载挖矿工具[Hpool-Miner-Chia](https://github.com/hpool-dev/chia-miner/releases/)，双击运行hpool-miner-chia-gui.exe；

点击系统设置，开启扫描新文件并设置扫描间隔。点击新增选择PLOT目标文件生成的目录。显示mining即正在挖矿。