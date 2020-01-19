## v2ray

官网：http://www.v2ray.com/

## 安装

```shell
wget --no-check-certificate -O v2ray.sh https://git.io/v2ray.sh
chmod +x v2ray.sh 
./v2ray.sh 2>&1 | tee v2ray.log
```

脚本会自动安装以下文件：
/usr/bin/v2ray/v2ray：V2Ray 程序；

/usr/bin/v2ray/v2ctl：V2Ray 工具；

/etc/v2ray/config.json：配置文件；

/usr/bin/v2ray/geoip.dat：IP 数据文件

/usr/bin/v2ray/geosite.dat：域名数据文件

安装时使用kcp传输协议

v2ray url 可生成 vmess URL 链接 / 输入 v2ray qr 可生成二维码链接

## 多用户多端口配置

生成uuid

```shell
cat /proc/sys/kernel/random/uuid
```

添加一个用户包括端口及uuid，vi /etc/v2ray/config.json

```json
{
    "inbounds": [
        /*单个端口单个用户（使用kcp方式，不写streamSettings默认tcp），推荐*/
        {
            "port": 39290,
            "protocol": "vmess",
            "settings": {
                "clients": [
                    {
                        "id": "生成的uuid0",
                        "alterId": 16,
                        "email": "autumn@v2ray.com"
                    }
                ]
            },
            "streamSettings": {
                "network": "kcp",
                "kcpSettings": {
                    "header": {
                        "type": "none"
                    }
                }
            },
            "sniffing": {
                "enabled": true,
                "destOverride": [
                    "http",
                    "tls"
                ]
            }
        },
        /*一个端口多个用户，但是可能存在问题*/
        {
            "port": 39238,
            "protocol": "vmess",
            "settings": {
                "clients": [
                    {
                        "id": "生成的uuid1",
                        "level": 1,
                        "alterId": 16,
                        "email": "first@v2ray.com"
                    },
                    {
                        "id": "生成的uuid2",
                        "level": 1,
                        "alterId": 16,
                        "email": "second@v2ray.com"
                    }
                ]
            }
        }
    ]
}
```

## 使用

```shell
v2ray info //查看 V2Ray 配置信息
v2ray config //修改 V2Ray 配置
v2ray link //生成 V2Ray 配置文件链接
v2ray infolink //生成 V2Ray 配置信息链接
v2ray qr //生成 V2Ray 配置二维码链接
v2ray ss //修改 Shadowsocks 配置
v2ray ssinfo //查看 Shadowsocks 配置信息
v2ray ssqr //生成 Shadowsocks 配置二维码链接
v2ray status //查看 V2Ray 运行状态
v2ray start //启动 V2Ray
v2ray stop //停止 V2Ray
v2ray restart //重启 V2Ray
v2ray log //查看 V2Ray 运行日志
v2ray update //更新 V2Ray
v2ray update.sh //更新 V2Ray 管理脚本
v2ray uninstall //卸载 V2Ray

```

## 客户端

电脑版
https://github.com/2dust/v2rayN/releases/tag/2.50

手机版
https://github.com/2dust/v2rayNG/releases
