require("TSLib")
require("common")

init(0)  --初始化(0,0)坐标
mSleep(3*1000)  --睡眠三秒,防止坐标没初始化好
nLog('初始化成功')
-- 今天是否分享过
isShare = false;

-- 根据坐标点击
function click(x,y)
	if(x~= -1 and y~= -1)  -- 根据多点颜色区域模糊查色返回的结果
	then
		touchDown(x, y)   -- 点击事件
		mSleep(20)
		touchUp(x, y)
	end
	mSleep(5*1000)
end
-- 打印坐标,调试用
function showClick(x,y)
	toast('返回视屏坐标x'..x..','..y)
end

-- 分享六次
function share(times)
	--如果今天没分享过
	if not isShare then
		local i = 0
		repeat
			-- 点击分享
			click(675,1046)
			-- 点击分享到学习强国
			click(95,660)
			-- 点击返回
			click(30,69)
			i = i+1
		until (i>times)
		isShare = true
	end
end

startTime = os.time();
while (true) do  -- 无限执行
	startTime = os.time();
	--2.关注栏目--
	if multiColor({{75,1026,0x9b9b9b},{214,1027,0xe32416},{341,1043,0xb3bbc1},{506,1028,0x9b9b9b},{648,1025,0xffffff}},80,false) == true then
		x,y = findMultiColorInRegionFuzzy( 0x191f25, "1|0|0x191f25,2|0|0x191f25,3|0|0x191f25", 90, 22, 190, 690, 958)  -- 查找黑色文字
		--showClick(x,y);
		click(x,y)  --点击进入
		mSleep(3*1000)  --观看3分钟
		share(6);  --分享六次
		click(40,74);  --点击返回
		touch():on(354,846):move(348,414):off()
		mSleep(5*1000)
		-- 进入学习栏目
		Type_study_x = 342
		Type_study_y = 1024
		Type_study_x = Type_study_x+common.getRandom(0,30)
		Type_study_y = Type_study_y+common.getRandom(0,25)
		-- showClick(Type_study_x,Type_study_y)
		common.click(Type_study_x,Type_study_y)
	end
	
	--3.学习栏目
	if multiColor({{75, 1026, 0x9b9b9b},{214,1028,0x9b9b9b},{341,1038,0xff3031},{357,1037,0xfff6f6},{507,1028,0x9b9b9b},{642,1032,0x9b9b9b}},80,false) == true then
		toast('进入视频学习栏目',1)
		x,y = findMultiColorInRegionFuzzy( 0x191f25, "1|0|0x191f25,2|0|0x191f25,3|0|0x191f25", 90, 22, 190, 690, 958)  -- 查找黑色文字
		--showClick(x,y);
		click(x,y)  -- 点击进入详情
		mSleep(3*60*1000)  -- 观看3分钟
		moveTo(314,795,351,458,50,1)
		click(40,74);  -- 点击返回
		moveTo(314,795,351,458,50,1)
		mSleep(5*1000)
		if(os.time()-startTime>80*60)  -- 如果时间到达1小时即3600s
		then
			--[[进入视频学习栏目]]--
			x,y = findMultiColorInRegionFuzzy( 0x9b9b9b, "-8|-1|0xffffff,-122|8|0xff3031,137|-3|0x9b9b9b,145|-3|0xffffff", 90, 7, 999, 677, 1078)
			click(x,y)
		end	
	end
	
	--4.视屏学习栏目
	if multiColor({{75,1025,0x9b9b9b},{215,1028,0x9b9b9b},{506,1028,0xe32416},{646,1026,0xffffff}},80,false) == true then
		--[[进入视频学习栏目]]--
		moveTo(314,795,351,458,50,1)
		toast("视屏学习栏",1)
		mSleep(1000)
		x,y = findMultiColorInRegionFuzzy( 0x191f25, "1|0|0x191f25,2|0|0x191f25,3|0|0x191f25", 90, 22, 190, 690, 958)  -- 查找视屏的黑色文字
		if(x==-1 and y==-1) then
		   toast("未找到黑色文字",1)
		end
		click(x,y)  --点击进入视屏
		mSleep(4*60*1000)  --观看四分钟
		click(40,74);  --点击返回
		moveTo(314,795,351,458,50,1)
		mSleep(5*1000)
	end
	
	endTime = os.time()
	toast('已运行时间:'..endTime - startTime,1)
	mSleep(2*1000)
end

