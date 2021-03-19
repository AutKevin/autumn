## 环境

### CentOS

```bash
cat /etc/redhat-release
```
CentOS Linux release 7.7.1908 (Core)

### nginx

```bash
nginx -v
```
nginx version: nginx/1.16.0

#### 申请域名：

https://www.freenom.com/

#### cdn解析域名：

https://www.cloudflare.com

将vps的ip使用cdn解析到刚刚购买的域名上，开启代理时ping的ip会变成cloudflare的ip。

详见:https://www.cnblogs.com/aeolian/p/13920553.html

## 安装Nginx

安装并配好ssl证书

https://www.cnblogs.com/aeolian/p/9002084.html#autoid-1-0-0

```shell
#手动
vi /usr/local/nginx/conf/nginx.conf
#yum
vi /etc/nginx/nginx.conf
```

添加如下配置。一定要用utf-8无bom格式的文件替换（**<u>直接用记事本编辑会不识别</u>**）。

```json
#pid 需要mkdir /usr/local/nginx/logs -p 否则不能开机自启

pid /usr/local/nginx/logs/nginx.pid;   #yum安装的不需要

http {
	server {
	  listen  443 ssl;
	  #如果systemctl status nginx.service报错nginx: [warn] the "ssl" directive is deprecated, use the "listen ... ssl" directive instead,需要删除ssl on
	  # ssl on;    
	  ssl_certificate       /etc/v2ray/v2ray.crt;   #这里根据安装的证书路径填写
	  ssl_certificate_key   /etc/v2ray/v2ray.key;   #这里根据安装的证书路径填写
	  ssl_protocols         TLSv1 TLSv1.1 TLSv1.2;
	  ssl_ciphers           HIGH:!aNULL:!MD5;
	  server_name           mydomain.me;     #域名
		location /video/ {    #与V2Ray服务端 配置中的 path 保持一致
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
      "port": 10000,  #端口和nginx代理的端口一致
      "listen":"127.0.0.1",#只监听 127.0.0.1，避免除本机外的机器探测到端口,如果要所有机器检测到可以写0.0.0.0
      "protocol": "vmess",
      "settings": {
        "clients": [
          {
            "id": "b831381d-6324-4d53-ad4f-8cda48b30811", #uuid
            "alterId": 64   #和客户端保持一致
          }
        ]
      },
      "streamSettings": {
        "network": "ws",
        "wsSettings": {
        "path": "/video/"       #注意：和Nginx中配置一致，两个斜杠不能省略
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

### 多个配置
生成UUID:  cat /proc/sys/kernel/random/uuid
测试配置文件: /usr/bin/v2ray/v2ray --test --config /etc/v2ray/config.json
```json
{
  "log": {
	"access": "/var/log/v2ray/access.log",
	"error": "/var/log/v2ray/error.log",
	"loglevel": "warning"
  },
  "inbounds": [   //主要配置,只能配置一个
    {  //v2rayclient + cdn + tls + nginx + ws +v2rayserver 
      "port": 10000,  //这个端口自己修改一下
      "listen":"127.0.0.1",//只监听 127.0.0.1，避免除本机外的机器探测到开放了 10000 端口,配置为全部为0.0.0.0
      "protocol": "vmess",
      "settings": {
	"clients": [
		{
		"id": "857e5dfb-33e2-4f1c-8ba6-9fc86e8e6fb1",
		"level": 1,
		"alterId": 233
		}
	]
      },
      "streamSettings": {
        "network": "ws",
        "wsSettings": {
        "path": "/video/"       //注意：这里也改成和nginx一致的path，2条斜杠别漏了
        }
      }
    }
  ],
  "inboundDetour": [   //其余配置,可以配置多个
      {   //kcp配置
        "port": 39290,
        "protocol": "vmess",
        "settings": {
            "clients": [
                {
                    "id": "96400ac3-2bbd-41ea-959f-014e97dab410",
                    "alterId": 16,
                    "email": "autumn@v2ray.com"
                }
            ]
        },
        "streamSettings": {
            "network": "mkcp",
            "kcpSettings": {
                "header": {
                    "type": "wechat-video"
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
     }
  ],
    "outbounds": [
	{
		"protocol": "freedom",
		"settings": {}
	},
	{
		"protocol": "blackhole",
		"settings": {},
		"tag": "blocked"
	},
	{
		"protocol": "freedom",
		"settings": {},
		"tag": "direct"
	},
	{
		"protocol": "mtproto",
		"settings": {},
		"tag": "tg-out"
	}
	//include_out_config
    ]
}
```

### 两个vps的v2ray相连
服务器的v2ray的inbound端被nginx反向代理了,inbound使用ws的方式和nginx通信,v2ray的outbound端连接到另一个vps的inbound端
```json
{
	"log": {
		"access": "/var/log/v2ray/access.log",
		"error": "/var/log/v2ray/error.log",
		"loglevel": "warning"
	},
	"inbounds": [{
		"port": 10000, //这个端口和nginx443端口代理的端口要一致
		"listen": "127.0.0.1", //只监听 127.0.0.1，避免除本机外的机器探测到开放了 10000 端口
		"protocol": "vmess",
		"settings": {
			"clients": [{
				"id": "b831381d-6324-4d53-ad4f-8cda48b30811",
				"level": 1,
				"alterId": 64
			}]
		},
		"streamSettings": {
			"network": "ws",
			"wsSettings": {
				"path": "/video/" //注意：这里改成和nginx一致，2条斜杠别漏了
			}
		}
	}],
	"outbounds": [{
		"protocol": "vmess",
		"settings": {
			"vnext": [{
				"address": "其他vps的IP",
				"port": 20000,   //另一个vps的端口
				"users": [{
					"id": "cdec184e-56b2-4feb-8b86-f0c0228c56f2",   //另一个vps端的id认证
					"alterId": 233
				}]
			}]
		},
		"streamSettings": {   
			"network": "kcp",   //因为另一个vps的inbound端使用的inbound是kcp协议
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
	}],
	"transport": {
		"kcpSettings": {   //关于kcp的设置
			"uplinkCapacity": 100,
			"downlinkCapacity": 100,
			"congestion": true
		},
		"sockopt": {
			"tcpFastOpen": true
		}
	}
}
```

### 域名到期更换证书

域名到期后除了直接续费域名，如果要更换域名的话要更新服务器tls证书。

1.申请好域名。

2.服务器生成证书，.crt和.key尽量和之前的一致，这样不用配置nginx.conf的证书路径了。

```bash
#域名不够可以用一个域名的多个三级域名、可以绑定多个服务器IP
~/.acme.sh/acme.sh --issue -d mydomain.me --standalone -k ec-256
~/.acme.sh/acme.sh --installcert -d mydomain.me --fullchainpath /etc/crt/autumn.crt --keypath /etc/crt/autumn.key --ecc
```

3.配置nginx.conf，更新如下三个参数。

```json
  ssl_certificate       /etc/crt/autumn.crt;  #.crt路径
  ssl_certificate_key   /etc/crt/autumn.key;   #.key路径
  server_name           mydomain.me;   #更新的域名
```

4.配置Cloudflare

要想使用cdn，需要在https://dash.cloudflare.com/uuid/mydomain.me/dns中配置域名和服务器IP，以便域名可以使用cdn；配置完毕后复制页面上NS（nameserver），例如elsa.ns.cloudflare.com、 javier.ns.cloudflare.com。

还要配置SSL/TLS中的加密连接部分，https://dash.cloudflare.com/uuid/mydomain.me/ssl-tls，因为服务器配置了证书，所以一定要用full格式的，两端都加密。

5.登录域名供应商的账户

停用服务商自己的nameserver，使用自定义**Nameservers**，以便将解析托管给Cloudflare。

6.重启nginx

## 客户端配置

![image-20200228010334845](https://github.com/AutKevin/autumn/blob/master/VPN/centOS+Shadowsocks/v2ray/v2ray+ws+tls+nginx+cdn%E5%AE%A2%E6%88%B7%E7%AB%AF%E9%85%8D%E7%BD%AE.png?raw=true)

## 问题
配置好https://域名可访问,但是v2ray连接不上去.
查看nginx和v2ray日志

```bash
#查找服务的日志
lsof -p 进程ID|grep log

#查看nginx的error日志
#104: Connection reset by peer连接重置是正常情况
tail -f /var/log/nginx/error.log

#查看nginx的access日志
#代理成功后连接时会带有101状态码(Switching Protocols，切换协议)
#成功示例: "GET /video/ HTTP/1.1" 101 0 "-" "Go-http-client/1.1"
tail -f /var/log/nginx/access.log

#查看v2ray的error日志
#v2ray.com/core/app/proxyman/inbound: connection ends连接关闭时正常情况
tail -f /var/log/v2ray/error.log

#查看v2ray的access日志
#代理成功后,nginx会把请求转发给v2ray
#成功示例: tcp:61.YOUR.IP.ADDRRESS:30862 accepted tcp:www.baidu.com:443
tail -f /var/log/v2ray/access.log

```
### Nginx的access日志响应502

error日志
connect() to 127.0.0.1:10000 failed (13: Permission denied) while connecting to upstream
权限被拒绝

access日志
"GET /video/ HTTP/1.1" 502 173 "-" "Go-http-client/1.1" "-"
返回Http状态为502(而非正常的101切换协议状态码),表示上游服务器接收到无效的响应

经查阅,发现是selinux没,关闭后即可代理

### 用户ID错误

v2ray/access.log显示

```bash
rejected  v2ray.com/core/proxy/vmess/encoding: invalid user
```

### Nginx正常V2ray异常

nginx/access.log显示502(上游服务器已关闭 或者 上游服务器和网关/代理在使用不统一的协议交换数据 )

```bash
"GET /video/ HTTP/1.1" 502 173 "-" "Go-http-client/1.1"
```

nginx/error.log显示连接不上v2ray的端口

```bash
connect() to 127.0.0.1:10000 failed (13: Permission denied) while connecting to upstream, client: 108.162.215.87, server: aeolian.cf, request: "GET /video/ HTTP/1.1", upstream: "http://127.0.0.1:10000/video/", host: "yourdomain.com"
```

## Xshell使用代理连接被封的VPS
开启软件后浏览器默认设置代理,如果其他软件需要使用代理需要软件支持代理.
xshell -> 属性 -> 代理 -> 添加代理服务器

Type: http（我用的是ws + tls + nginx + cdn，所以要选择http,如果是ss要选择socket，具体要根据你服务器的协议来定）

Host: 127.0.0.1

Port: 10809 (具体要根据本地代理软件的代理in端口来设置,不知道的可以直接看浏览器的代理)
