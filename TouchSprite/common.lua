common = {}
-- 根据坐标点击
function common.click(x,y)
	if(x~= -1 and y~= -1)  -- 根据多点颜色区域模糊查色返回的结果
	then
		touchDown(x, y)   -- 点击事件
		mSleep(common.getRandom(15,30))
		touchUp(x, y)
	end
	mSleep(common.getRandom(1000,3000))  -- 点击后等待一秒到三秒
end

--获取随机值，指定上限和下限
function common.getRandom(min,max)
	-- 接收一个整数n作为随即序列的种子
	math.randomseed(os.time())
	----然后不断产生随机数
	--[[
	for i=1, 5 do
	 print(math.random(100))
	end]]--
	return math.random(min,max)
end

-- 获取当前时间
function common.getNow()
	local nowTime = os.date("%Y-%m-%d %H:%M:%S", os.time())
	-- print(nowTime)
	return nowTime
end
print(os.time())