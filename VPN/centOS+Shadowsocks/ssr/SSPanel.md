## LNMP环境

- Nginx Stable - 最新版（最新稳定版版本号，比如1.16）
- MySQL - MySQL-8.0
- PHP - PHP-7.3
- phpMyAdmin - 越新越好（可选，建议，需要等前三项安装完成）
- PureFTPd（可选）

## 配置 PHP

软件商店里找到 PHP， 点击设置 禁用函数一栏删除 `system` `proc_open` `proc_get_status` `putenv`。 

## 部署 SSPanel 魔改版

### 添加网站

输入域名自动生成备注及根目录，设置FTP用户名密码以及数据库用户名密码。生成网站后会自动在/www/wwwroot/下面生成网站文件夹.

```shell
cd /www/wwwroot/网站文件夹
git clone -b master https://github.com/Anankke/SSPanel-Uim.git tmp && mv tmp/.git . && rm -rf tmp && git reset --hard
git config core.filemode false
wget https://getcomposer.org/installer -O composer.phar
php composer.phar
php composer.phar install
cd ../
chmod -R 755 文件夹/
chown -R www:www 文件夹/
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

菜单的 **数据库** 按钮，找到你刚 Link 的数据库，点击导入。导入界面会出现 `glzjin_all.sql`，直接导入。

### 配置网站程序

修改db_database等

```php
cd /www/wwwroot/文件夹/
cp config/.config.example.php config/.config.php
nano config/.config.php
```

### 创建管理员并同步用户
```shell
#创建管理员,会要求你输入邮箱和密码
php xcat createAdmin
#同步用户
php xcat syncusers
#下载IP解析库
php xcat initQQWry
#重置流量
php xcat resetTraffic
#下载工具包到服务器
php xcat initdownload
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

