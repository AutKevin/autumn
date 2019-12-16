## 注册门罗币钱包

[https://wallet.mymonero.com](https://wallet.mymonero.com/)

一定要记好MNEMONIC，否则登不上钱包。

## 注册矿池的账号

[https://www.f2pool.com/](https://www.f2pool.com/)

注册账号，找到对应币的挖矿软件

也要查看矿池地址

![](https://img2018.cnblogs.com/blog/1208477/201912/1208477-20191214202720559-721070618.png)

## 挖矿软件

### xmr-stak

登录服务器，下载挖矿软件

<div class="cnblogs_code">
<pre><span style="color: #0000ff;">wget</span> --no-check-certificate https:<span style="color: #008000;">//</span><span style="color: #008000;">github.com/fireice-uk/xmr-stak/releases/download/1.0.3-rx/xmr-stak-rx-linux-1.0.3-cpu.tar.xz</span></pre>
</div>

![](https://img2018.cnblogs.com/blog/1208477/201912/1208477-20191214203417340-2114629843.png)

出现问题

![](https://img2018.cnblogs.com/blog/1208477/201912/1208477-20191214212521169-1396299778.png)

sudo sysctl -w vm.nr_hugepages=128

/etc/security/limits.conf添加

    * soft memlock 262144
    * hard memlock 262144

### xmrig

官网

[https://xmrig.com/](https://xmrig.com/)

下载软件

![](https://img2018.cnblogs.com/blog/1208477/201912/1208477-20191216132228368-688688948.png)

运行，其中<span style="color: #ff0000;">**walletaddress**</span>为钱包地址，workname&nbsp;为工作名（随便取，但是多台时<span style="color: #ff0000;">**workname&nbsp;千万不能重复**</span>），stratum+tcp://xmr.f2pool.com:13531是xmr币挖矿池地址。

<div class="cnblogs_code">
<pre><span style="color: #008000;">//</span><span style="color: #008000;">下载挖矿软件</span>
<span style="color: #0000ff;">wget</span> --no-check-certificate  https:<span style="color: #008000;">//</span><span style="color: #008000;">github.com/xmrig/xmrig/releases/download/v5.2.1/xmrig-5.2.1-xenial-x64.tar.gz
</span><span style="color: #008000;">//</span><span style="color: #008000;">运行挖矿软件</span>
./xmrig -o stratum+tcp:<span style="color: #008000;">//</span><span style="color: #008000;">xmr.f2pool.com:13531 -u walletaddress.workname -p x -k
</span><span style="color: #008000;">//</span><span style="color: #008000;">后台运行，一定要用-B</span>
nohup ./xmrig -o stratum+tcp:<span style="color: #008000;">//</span><span style="color: #008000;">xmr.f2pool.com:13531 -u walletaddress.workname -B -p x -k &amp;</span></pre>
</div>

使用GPU挖矿

<div class="cnblogs_code">
<pre><span style="color: #000000;"><span style="color: #008000;">//CPU单挖</span>
xmrig -o xmr.f2pool.com:</span><span style="color: #800080;">13531</span><span style="color: #000000;"> -u wallet_address.worker_name -p x -k

<span style="color: #008000;">/**使用&ldquo;xmrig-</span></span><span style="color: #008000;">5.0.1</span><span style="color: #000000;"><span style="color: #008000;">-msvc-cuda10_1-win64&rdquo;版本还可支持CPU和GPU同时挖矿,CUDA是N卡特有的,opencl被很多显卡支持，挖矿参数如下**/</span>
<span style="color: #008000;">//CPU+GPU（N卡，需安装CUDA10.1或以上版本）,[cuda](https://baike.baidu.com/item/CUDA)</span>
xmrig -o xmr.f2pool.com:</span><span style="color: #800080;">13531</span><span style="color: #000000;"> -u wallet_address.worker_name -p x -k --cuda

<span style="color: #008000;">//CPU+GPU（A卡）,[opencl](https://baike.baidu.com/item/OpenCL/8477301)</span>
xmrig -o xmr.f2pool.com:</span><span style="color: #800080;">13531</span> -u wallet_address.worker_name -p x -k --opencl</pre>
</div>

[其他使用命令](https://github.com/xmrig/xmrig)

![](https://img2018.cnblogs.com/blog/1208477/201912/1208477-20191214223416996-857092155.png)

查看收益点击右上角查询，输入钱包地址即可&nbsp;![](https://img2018.cnblogs.com/blog/1208477/201912/1208477-20191214223417012-345493724.png)

查询后如下

![](https://img2018.cnblogs.com/blog/1208477/201912/1208477-20191214223643776-983945693.png)

&nbsp;
