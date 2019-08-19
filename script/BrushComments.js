var str = ['想要红米5~~~','小米加油~~~','支持小米~','雷军加油~~~','红米加油~~~','支持红米~~~','支持雷军~~~','大爱红米~~~','给雷总点个赞','千元全面屏,国民手机'];
function sub(){
	$('#J_chatContent').val(str[Math.floor(Math.random()*str.length)]);
	$("#J_sendChatBtn").addClass("active");
	$("#J_sendChatBtn").removeClass("disabled");
	$('#J_sendChatBtn').click();
}
setInterval("sub()",(Math.floor(Math.random()*3+3))*1000);