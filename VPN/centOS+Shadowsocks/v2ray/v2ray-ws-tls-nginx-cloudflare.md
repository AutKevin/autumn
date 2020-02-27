## 前提

#### 申请域名：

https://www.freenom.com/

https://www.namecheap.com/

#### cdn解析域名：

https://www.cloudflare.com

将vps的ip使用cdn解析购买的域名，开启代理时ping的ip会变成cloudflare的ip。

## 安装Nginx

安装并配好ssl证书

https://www.cnblogs.com/aeolian/p/9002084.html#autoid-1-0-0

```shell
vi /usr/local/nginx/conf/nginx.conf
```

添加如下配置。一定要用utf-8无bom格式的文件替换（**<u>直接用记事本编辑会不识别</u>**）。

```json
server {
  listen  443 ssl;
  ssl on;
  ssl_certificate       /etc/v2ray/v2ray.crt;   #这里根据安装的证书路径填写
  ssl_certificate_key   /etc/v2ray/v2ray.key;   #这里根据安装的证书路径填写
  ssl_protocols         TLSv1 TLSv1.1 TLSv1.2;
  ssl_ciphers           HIGH:!aNULL:!MD5;
  server_name           mydomain.me;   #域名需要修改
        location /autumn/ { # 与 V2Ray服务端 配置中的 path 保持一致
        proxy_redirect off;
        proxy_pass http://127.0.0.1:10000;  #这个端口和服务端保持一致
        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection "upgrade";
        proxy_set_header Host $http_host;

        # Show realip in v2ray access.log
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        }
}
```

## V2ray配置

这里inbound的端口被nginx的443代理了,并且443使用了ssl加密。

```shell
vi /etc/v2ray/config.json
```

删除所有的配置，输入如下配置一定要用utf-8无bom格式的文件替换（**<u>直接用记事本编辑会不识别</u>**）。

```json
{
  "log": {
	"access": "/var/log/v2ray/access.log",
	"error": "/var/log/v2ray/error.log",
	"loglevel": "warning"
  },
  "inbounds": [
    {
      "port": 10000,  //这个端口自己修改一下
      "listen":"127.0.0.1",//只监听 127.0.0.1，避免除本机外的机器探测到开放了 10000 端口
      "protocol": "vmess",
      "settings": {
        "clients": [
          {
            "id": "b831381d-6324-4d53-ad4f-8cda48b30811", //id自行修改，但保证位数一致
            "alterId": 64 //自行修改
          }
        ]
      },
      "streamSettings": {
        "network": "ws",
        "wsSettings": {
        "path": "/autumn/"       //注意：这里改成自己的,并且和Nginx中配置一致，2条斜杠别漏了
        }
      }
    }
  ],
  "outbounds": [
    {
      "protocol": "freedom",
      "settings": {}
    }
  ]
}
```

## 客户端配置
![image-20200228010334845](https://github.com/AutKevin/autumn/blob/master/VPN/centOS+Shadowsocks/v2ray/v2ray+ws+tls+nginx+cdn%E5%AE%A2%E6%88%B7%E7%AB%AF%E9%85%8D%E7%BD%AE.png?raw=true)

