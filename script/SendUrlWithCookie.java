import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
/**
 * 相当于触发某个url(加入购物车,抢优惠卷...).
 */
public class SendUrlWithCookie {
	//红米5
	//private static String url = "https://cart.jd.com/gate.action?pid=5911944&pcount=1&ptype=1";
	//购物车
	private static String url = "https://order.jd.com/center/list.action";    
	//private static String url = "https://item.jd.com/5911944.html#crumb-wrap";
	
	
	private final static String TRANSENCODE = "iso-8859-1";    //传输的编码格式
	private final static String DECODE = "gbk";    //最终显示的编码格式
	public static void main(String[] args) {
		//while (true) {
			try {
				System.out.println(sendPostByUrl(url,"get",null));
			} catch (IOException e) {
				e.printStackTrace();
			}
		//}
	}

	public static String sendPostByUrl(String path, String method, String params)
			throws IOException {
		BufferedReader in = null;
		java.net.HttpURLConnection conn = null;
		String msg = "";// 保存调用http服务后的响应信息
		try {
			java.net.URL url = new java.net.URL(path);
			conn = (java.net.HttpURLConnection) url.openConnection();
			conn.setRequestMethod(method.toUpperCase());// 请求的方法get,post,put,delete
			conn.setConnectTimeout(5 * 1000);// 设置连接超时时间为5秒
			conn.setReadTimeout(20 * 1000);// 设置读取超时时间为20秒
			conn.setDoOutput(true);// 使用 URL 连接进行输出，则将 DoOutput标志设置为 true

			//从google浏览器请求地址中的cookie里面找到这个
			conn.setRequestProperty("Cookie", "3AB9D23F7A4B3C9B=");
			conn.addRequestProperty("Cookie", "Hm_lpvt_f16aaeb7ee42409d8dbeb6bf131c5f2a=1512743276");
			conn.addRequestProperty("Cookie", "Hm_lvt_f16aaeb7ee42409d8dbeb6bf131c5f2a=1512707344,1512712994,1512743276");
			conn.addRequestProperty("Cookie", "JSESSIONID=1995.s1");
			conn.addRequestProperty("Cookie", "__jda=122270672.365496518.1506901025.1512740467.1512742747.8");
			conn.addRequestProperty("Cookie", "__jdb=122270672.9.365496518|8.1512742747");
			conn.addRequestProperty("Cookie", "__jdc=122270672");
			conn.addRequestProperty("Cookie", "__jdu=365496518");
			conn.addRequestProperty("Cookie", "__jdv=122270672|baidu-pinzhuan|t_288551095_baidupinzhuan|cpc|0f3d30c8dba7459bb52f2eb5eba8ac7d_0_812205e2240f4ed28d29b6a26cfb27e4|1512743192207");
			conn.addRequestProperty("Cookie", "_pst=%E7%A7%8B%E5%A4%9C%E9%9B%A8%E5%B7%B7Q");
			conn.addRequestProperty("Cookie", "_tp=GyDDW8HjsKYh2lOdBa7v9c2s0T0C83lTUP3L%2FYa%2F%2BWSsZ7XSsWQ4WGIx7zcBiYYv");
			conn.addRequestProperty("Cookie", "areaId=12");
			conn.addRequestProperty("Cookie", "cn=2");
			conn.addRequestProperty("Cookie", "ipLoc-djd=12-951-956-52211.137989583");
			conn.addRequestProperty("Cookie", "ipLocation=%u6c5f%u82cf");
			conn.addRequestProperty("Cookie", "mt_xid=V2_52007VwEVVlhQVV4fQCkLBzMEGltVDU5bTx1NQABnBkFODV5WXwNBTAhSNwNGVVsKBVgvShhcA3sDEk5eXENaHkIcWQ5lCiJQbVhiWhhBEF4AYwURYlhf");
			conn.addRequestProperty("Cookie", "pin=%E7%A7%8B%E5%A4%9C%E9%9B%A8%E5%B7%B7Q");
			conn.addRequestProperty("Cookie", "pinId=LmnqqNUGYYjITBq5I3pwXw");
			conn.addRequestProperty("Cookie", "thor=0602FD7E0777F6D338E19F02D7FDD72CD3F4A9634AC686DF0B2E62A32098FD6D85AB9484F4E1C8C3B65FF5C67B4E2C9BB8BD2ACD1FEF1956127DC12F0B742974F5AB62D3D361CD38577D0024BA993793ED6F6EFB4AF923560533E9DD9BD71BEE7E95F3781F5CA8693656D40D58C4E5AE65DEF2143A701F551FA236A34B2E1B04");
			conn.addRequestProperty("Cookie", "unick=jd_%E7%A7%8B%E5%A4%9C%E9%9B%A8%E6%AE%87");
			conn.addRequestProperty("Cookie", "unpl=V2_ZzNtbUtXQBZ0DBJXeBxdUmJXR15LAkAdJg8WV3xLC1ZkBUZYclRCFXMURldnGFUUZAMZWEJcQh1FCHZXchBYAWcCGllyBBNNIEwHDCRSBUE3XHxcFVUWF3RaTwEoSVoAYwtBDkZUFBYhW0IAKElVVTUFR21yVEMldQl2VnwdWQ1gBxJUcmdEJUU4T1B8EVoNVwIiXHIVF0lyC0dceFReAmMGGlpGV0oldDhF");
			conn.addRequestProperty("Cookie", "user-key=9134f6d1-1940-444f-be5e-7209b36a50f6");

			// conn.setRequestProperty("Content-Encoding","gzip");
			conn.setRequestProperty("Content-Type", "text/xml;charset=UTF-8");
			conn.setRequestProperty("Content-Length",String.valueOf(params == null ? "" : params.length()));
			if (params != null && !params.isEmpty()) {
				OutputStream outStream = conn.getOutputStream();// 返回写入到此连接的输出流
				outStream.write(params.getBytes());
				outStream.close();// 关闭流
			}
			if (conn.getResponseCode() == 200) {
				// HTTP服务端返回的编码是UTF-8,故必须设置为UTF-8,保持编码统一,否则会出现中文乱码
				in = new BufferedReader(new InputStreamReader(
						(InputStream) conn.getInputStream(), TRANSENCODE));
				String temp = "";
				while ((temp = in.readLine())!=null) {
					msg += new String(temp.getBytes(TRANSENCODE),DECODE);
				}
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		} finally {
			if (null != in) {
				in.close();
			}
			if (null != conn) {
				conn.disconnect();
			}
		}
		return msg;
	}
}
