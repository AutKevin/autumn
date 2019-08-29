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
                		Thread.sleep(3000);
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
			conn.setRequestProperty("accept", "*/*");
			conn.setRequestProperty("connection", "keep-alive");
			conn.setRequestProperty("Referer", "http://www.mi.com/a/h/11406.html?client_id=180100041086&masid=17409.0380=");
			conn.setRequestProperty("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.100 Safari/537.36");
			conn.setRequestProperty("Cookie","mstuid=1565660612968_2360; XM_agreement_sure=1; XM_agreement=0; xm_user_www_num=0;");

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
