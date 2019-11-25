v2ray
官网：http://www.v2ray.com/
安装
wget --no-check-certificate -O v2ray.sh https://git.io/v2ray.sh
chmod +x v2ray.sh 
./v2ray.sh 2>&1 | tee v2ray.log
使用
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
