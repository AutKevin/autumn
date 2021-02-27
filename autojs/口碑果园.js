auto.waitFor();  //检查该应用开启无障碍后才执行其后面的代码
var height = device.height;
var width = device.width;
toast("\n设备宽" + width + "\n" + "设备高" + height + "\n" + "手机型号" + device.model + "\n安卓版本" + device.release)
//换成自己真实的宽和高
setScreenMetrics(width, height);
lingqu();

function lingqu() {
  
    var p1 = '去逛一逛';
    var p2 = '去参加';
    while (true) {
        var target =  text(p1).findOnce() || text(p2).findOnce();  //找p1,找不到就找p2
        if (target == null) {  //如果不存在
             toast("不存在"+p1+","+p2);
             break;  //则跳出
        }
        target.click();  //点击按钮
        
        sleep(25000);  //等待25s
        back();  //退回
        sleep(2000);  //等待2s
    }
 
    var r1 = '领取';
    while (text(r1).exists()) {  //查询是否存在text值为r1的按钮
         toast("存在"+r1);  //提示按钮
         text(r1).findOne().click();  //点击按钮
         sleep(2000);  //等待2s
         continue;   //继续循环
    }
    
    //向上滑动
    //swipe(device.width/2,device.height/8, device.width/2, device.height/6, 2000);
    
    sleep(2000);
    //如果存在,继续领取
    if(text(p1).exists() || text(p2).exists()){
       lingqu();
    }else{   //如果不存在
        toast('关掉活动页面');
        //点击取消叉掉任务
        click(Math.random() * (1040 - 950) + 950,Math.random() * (1002 - 885) + 885);
        sleep(3000);  //等待2s
        toast('开始浇水');
        //浇水
        for(var i=0;i<=50;i++){
            toast("正在第"+i+"次浇水");
            //点击浇水
            click(Math.random() * (1003 - 786) + 786,Math.random() * (2282 - 2065) + 2065);
            sleep(1500);  //等待1.5s
        }
    }

    toast("结束");
}