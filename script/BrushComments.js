var str = ['��Ҫ����5~~~','С�׼���~~~','֧��С��~','�׾�����~~~','���׼���~~~','֧�ֺ���~~~','֧���׾�~~~','�󰮺���~~~','�����ܵ����','ǧԪȫ����,�����ֻ�'];
function sub(){
	$('#J_chatContent').val(str[Math.floor(Math.random()*str.length)]);
	$("#J_sendChatBtn").addClass("active");
	$("#J_sendChatBtn").removeClass("disabled");
	$('#J_sendChatBtn').click();
}
setInterval("sub()",(Math.floor(Math.random()*3+3))*1000);