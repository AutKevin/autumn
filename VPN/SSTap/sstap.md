## SSTap全局代理

sstap不同于v2ray客户端和ssr客户端，sstap可以实现整个电脑的代理，不仅仅是网页的代理。

sstap和其他不一样的是，会在网络中新建一个SSTAP虚拟网卡，从而实现全软件代理（其他客户端仅仅用端口）。

![image-20200726100359585](https://raw.githubusercontent.com/AutKevin/autumn/master/VPN/SSTap/images\image-20200726100359585.png)

全局：代理所有软件

仅网页浏览器（全局）：和v2ray全局一样，只代理浏览器

仅网页浏览器（跳过中国站点）：只代理浏览器，但是不代理中国站点

仅代理中国IP：代理所有软件，给海外华人用，只代理国内的IP，国外的一律不代理

不代理中国IP：代理所有软件，不代理中国的IP。

## SSTap+V2ray

1. 启动v2ray并调试通
2. 点击参数设置，查看本地端口并开启UDP

![image-20200726100921268](https://raw.githubusercontent.com/AutKevin/autumn/master/VPN/SSTap/images\image-20200726100921268.png)

3.配置SSTap

![image-20200726101209631](https://raw.githubusercontent.com/AutKevin/autumn/master/VPN/SSTap/images\image-20200726101209631.png)

4.测试并连接，测试TCP和UDP都通后。然后点击连接。

![image-20200726101305739](https://raw.githubusercontent.com/AutKevin/autumn/master/VPN/SSTap/images\image-20200726101305739.png)
