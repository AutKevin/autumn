var str = ['小米加油~~~','支持小米~','雷军加油~~~'];
function sub(){
	$('#J_chatContent').val(str[Math.floor(Math.random()*str.length)]);
	$("#J_sendChatBtn").addClass("active");
	$("#J_sendChatBtn").removeClass("disabled");
	$('#J_sendChatBtn').click();
}
setInterval("sub()",(Math.floor(Math.random()*3+3))*1000);