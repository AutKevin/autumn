## SSPanel Uim

官网：https://github.com/Anankke/SSPanel-Uim

## 硬件环境

- 1 CPU 以上
- 个人使用 1G 即可(需要swap)，长期稳定运行建议 2 G 及以上
- 10 G 硬盘空间及以上

## 安装宝塔

确保机器没有安装Apache/Nginx/php/MySQL等软件。

```bash
yum install -y wget && wget -O install.sh http://download.bt.cn/install/install_6.0.sh && sh install.sh
```

安装完后会自动显示url和用户名密码，一定要记录下来用户名和密码。

外网面板地址: http://xx.xx.xx.xx:8888/b335dfeb
内网面板地址: http://10.10.10.188:8888/b335dfeb
username: ****
password: ****

登录后进入面板设置界面修改用户名和密码。

## LNMP环境

在宝塔面板选择LNMP环境

- Nginx Stable - 最新版（最新稳定版版本号，比如1.16）
- MySQL - MySQL-8.0
- PHP - PHP-7.3
- phpMyAdmin - 越新越好（可选，建议，需要等前三项安装完成）
- PureFTPd（可选）

## 配置 PHP

宝塔软件商店里找到 已安装的PHP， 点击设置 禁用函数一栏删除 `system` `proc_open` `proc_get_status` `putenv`。 

## 部署 SSPanel 魔改版

### 添加网站

输入域名(如果**没有域名**输入**IP:port**，端口不能用80，可以使用88)自动生成备注及根目录，设置**FTP用户名密码**以及**Mysql数据库用户名密码**。生成网站后会自动在/www/wwwroot/下面生成网站文件夹.

```shell
cd /www/wwwroot/网站文件夹
#一定不可以网页上下载（<10M），无法下载可以本地挂代理clone后上传到/www/wwwroot/网站文件夹下面（100M左右）
#一定要用dev分支，master分支已停止更新
#yum install git
git clone -b dev https://github.com/Anankke/SSPanel-Uim.git tmp && mv tmp/.git . && rm -rf tmp && git reset --hard   
git config core.filemode false   #改变git忽略模式
wget https://getcomposer.org/installer -O composer.phar
php composer.phar
#会Installing很多包，如果是master会失败
#需要PHP删除shell_exec()、exec()禁用函数
#有些github上的资源不稳定，需要多试几次或者挂代理
php composer.phar install    
cd ../
chmod -R 755 文件夹/*
chown -R www:www 文件夹/*
ln -s /www/wwwroot/文件夹/sql/glzjin_all.sql /www/backup/database/
```

### 配置网站设置展开目录

点击 **网站** 最右侧的设置，在 **网站目录** 里取消 **防跨站攻击**，运行目录里面选择 `/public`，点击 **保存**。

 **伪静态** 中填入下面内容 

```nginx
location / {
    try_files $uri /index.php$is_args$args;
}
```

### 导入初始数据库

菜单的 **数据库** 按钮，**添加一个数据库**，然后点击导入按钮。导入界面会出现 `glzjin_all.sql`，直接导入。

### 配置网站数据库连接

修改db_database、mukey等
```php
cd /www/wwwroot/文件夹/
cp config/.config.example.php config/.config.php
cp config/appprofile.example.php config/appprofile.php
vi config/.config.php
```
$System_Config['db_host'] = 'localhost';						//数据库地址
$System_Config['db_database'] = 'dbname';						//数据库名
$System_Config['db_username'] = 'root';							//数据库用户名
$System_Config['db_password'] = '123456'

### 创建管理员并同步用户
```shell
cd /www/wwwroot/文件夹/
#创建管理员,会要求你输入邮箱和密码
#如果创建管理员出错请检查 config/.config.php 中的数据库连接信息
php xcat User createAdmin
#重置流量
php xcat User resetTraffic
#同步用户
php xcat User syncusers
#下载IP解析库
php xcat Tool initQQWry
#下载工具包到服务器
php xcat Tool initdownload
```
管理員和普通注冊用戶用的一個登錄頁面，只不過管理員登錄后，最後main有一個管理面板。

### 配置定时任务
```shell
crontab -e 30 22 * * * php /www/wwwroot/文件夹/xcat sendDiaryMail
crontab -e 0 0 * * * php -n /www/wwwroot/文件夹/xcat dailyjob
crontab -e */1 * * * * php /www/wwwroot/文件夹/xcat checkjob
crontab -e */1 * * * * php /www/wwwroot/文件夹/xcat syncnode
#每20小时备份一次
crontab -e 0 */20 * * * php -n /www/wwwroot/文件夹/xcat backup
#财务报表
crontab -e 5 0 * * * php /www/wwwroot/文件夹/xcat sendFinanceMail_day
crontab -e 6 0 * * 0 php /www/wwwroot/文件夹/xcat sendFinanceMail_week
crontab -e 7 0 1 * * php /www/wwwroot/文件夹/xcat sendFinanceMail_month
#检测是否被墙
crontab -e */1 * * * * php /www/wwwroot/文件夹/xcat detectGFW
#用radius
crontab -e */1 * * * * php /www/wwwroot/文件夹/xcat synclogin
crontab -e */1 * * * * php /www/wwwroot/文件夹/xcat syncvpn
crontab -e */1 * * * * php -n /www/wwwroot/文件夹/xcat syncnas
```

### V2ray对接

#### 一键安装

```bash
bash <(curl -Ls https://raw.githubusercontent.com/sprov065/soga/master/install.sh)
```

#### 同步时间（重要）

```
yum install -y ntp
systemctl enable ntpd
ntpdate -q 0.rhel.pool.ntp.org
systemctl restart ntpd
```

#### 配置节点

前端配置ws+tls，若不用CDN，可以去掉host

ip;80;2;ws;;path=/xxx|server=域名|host=CDN域名

#### 配置soga

```
# 输出当前配置文件内容
soga config

# 自动对配置文件进行配置，一行可填写任意数量的配置信息，示例：
soga config type=sspanel-uim server_type=v2ray
```

配置文件位置在 **/etc/soga/soga.conf**，内容如下

```
type=sspanel-uim                             # 必填这个
server_type=v2ray                            # 必填这个
api=webapi                                   # webapi 或 db，表示 webapi 对接或数据库对接

# webapi 对接
webapi_url=https://xxx.com/                  # webapi url，填写面板主页地址
webapi_key=xxxx                              # webapi 密钥，sspanel 配置中的 mukey

# 数据库对接
db_host=db.xxx.com                           # 数据库地址
db_port=3306                                 # 数据库端口
db_name=name                                 # 数据库名
db_user=root                                 # 数据库用户名
db_password=asdasdasd                        # 数据库密码

node_id=1                                    # 节点id
soga_key=                                    # 授权key，社区版无需填写，最多支持88用户，商业版无限制
user_conn_limit=0                            # 限制用户IP数，0代表无限制，默认会优先使用面板设置的限制IP数，在部分旧版面板下可能会获取不到，则使用这个值

force_close_ssl=false                        # 设为true可强制关闭tls，即使前端开启tls，soga也不会开启tls，方便用户自行使用nginx、caddy等反代

default_dns=8.8.8.8,1.1.1.1                  # 配置默认dns，可在此配置流媒体解锁的dns，以逗号分隔
dns_cache_time=10                            # 自定义dns缓存时间，单位分钟，仅在设置了default_dns时有效，或者v2board设置了dns规则时也有效

v2ray_reduce_memory=false                    # VMess 下有效，在已降低内存的基础上进一步降低内存使用，启用后客户端时间误差要求不超过15秒

proxy_protocol=false                         # 具体请参看中转获取真实 IP 教程
v2ray_fallback_addr=                         # v2ray fallback 地址，仅 tcp+tls 可使用
v2ray_fallback_port=0                        # v2ray fallback 端口，仅 tcp+tls 可使用
auto_update=false                            # soga 自动更新，只会检测稳定版

vless=false                                  # 设为 true 可切换为 VLESS 协议，目前 VLESS 协议未完全开发完成，仅供测试
vless_flow=                                  # vless 流控，具体请参考 v2ray 官方文档
xtls=false                                   # 设为 true 即可开启 xtls，仅支持 tcp + tls 时开启
```

#### 配置证书

若未开启 tls，则无需配置证书

1. 手动指定证书

```
cert_file=                                   # 手动指定证书路径
key_file=                                    # 手动指定密钥路径
```

2. http 模式自动申请证书

```
cert_domain=xxx.com                          # 申请证书的域名
cert_mode=http                               # 申请模式
cert_key_length=ec-256                       # 留空则申请RSA证书，填写ec-256或ec-384则申请ECC证书
```

3. dns 模式自动申请证书

   CloudFlare 配置

```
cert_domain=xxx.com                          # 申请证书的域名
cert_mode=dns                                # 申请模式
cert_key_length=ec-256                       # 留空则申请RSA证书，填写ec-256或ec-384则申请ECC证书
dns_provider=dns_cf                          # DNS 提供商

DNS_CF_Email=xxx@xx.com                      # CF 邮箱
DNS_CF_Key=xxxxx                             # CF API Global Key
```

### SSR后端一键安装

webapi: ip、mukey(config/.config.php)、结点ID 进行配置SSR.

database: ip、数据库的用户名、密码、结点ID 进行配置SSR.
```shell
yum -y install wget
wget -N --no-check-certificate https://raw.githubusercontent.com/lizhongnian/ss-panel-v3-mod-node-connect/master/ss-panel-v3-mod-node-connect.sh
chmod +x ss-panel-v3-mod-node-connect.sh && bash ss-panel-v3-mod-node-connect.sh
```

### composer install 被killed问题(内存不足导致)
```shell
# 查看内存和 swap 的使用情况:
$ free -m
# 在 var 目录创建制作swap文件
$ cd /var
$ mkdir swap
$ cd swap
# 创建一个空文件， count 表示创建的文件大小，这里代表1GB
$ dd if=/dev/zero of=swapfile bs=1024 count=1000000          
# 将创建的文件制作为 swap 文件 
$ mkswap swapfile
# 使swap文件生效
$ swapon swapfile
# 自动挂载
$ vim /etc/fstab
# 写入
 /var/swap/swapfile none swap sw 0 0
#再次查看使用情况
$ free -m
```

## 出现问题

### 没有找到站点

显示没有站点的界面，检查网站的域名有没有绑定（没有域名用ip:端口）

端口不能为80或者443