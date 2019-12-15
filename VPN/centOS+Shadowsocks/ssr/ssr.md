## 安装
```bash
wget --no-check-certificate -O shadowsocksR.sh https://raw.githubusercontent.com/AutKevin/autumn/master/VPN/centOS%2BShadowsocks/ssr/shadowsocksR.sh
chmod +x shadowsocksR.sh
./shadowsocksR.sh 2>&1 | tee shadowsocksR.log
```

## 配置文件
配置和ss一样。
```bash
cat /etc/shadowsocks-r/shadowsocksR_Config.json
```
## 使用
脚本启动关闭
```bash
启动：/etc/init.d/shadowsocksR start
停止：/etc/init.d/shadowsocksR stop
重启：/etc/init.d/shadowsocksR restart
状态：/etc/init.d/shadowsocksR status
```
ssr的客户端同样可以用shadowsocks，只不过不能设置混淆。
