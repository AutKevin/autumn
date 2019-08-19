require("TSLib")
require("common")

init(0)  --初始化(0,0)坐标
mSleep(3*1000)  --睡眠三秒,防止坐标没初始化好
-- setScreenScale(true, 720, 1280)
nLog('初始化成功')


startTime = os.time();
while (true) do  -- 无限执行
	moveTo(314,795,351,458,50,1)
    toast('等待10s...',5)
	mSleep(10*1000)
end
endTime = os.time()
toast('已运行时间:'..endTime - startTime,1)
mSleep(2*1000)