package edu.cdut.utils;

public class ReponseEntity {
	// 定义报文的规范
	private int code;
	
	private String msg;
	
	private Object data;

	public int getCode() {
		return code;
	}

	public void setCode(int code) {
		this.code = code;
	}

	public String getMsg() {
		return msg;
	}

	public void setMsg(String msg) {
		this.msg = msg;
	}

	public Object getData() {
		return data;
	}

	public void setData(Object data) {
		this.data = data;
	}
	
	public ReponseEntity(RespCode respCode) {
		this.code=respCode.getCode();
		this.msg=respCode.getMsg();
	}
	
	public ReponseEntity(RespCode respCode,Object data) {
		this(respCode);
		this.data=data;
	}
}
