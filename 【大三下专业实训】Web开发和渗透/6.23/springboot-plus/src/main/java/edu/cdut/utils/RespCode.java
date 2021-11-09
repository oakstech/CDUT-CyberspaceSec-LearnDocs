package edu.cdut.utils;

public enum RespCode {

	SUCCESS(0,"请求成功"),
	WARN(-1,"网络异常"),
	SQL(1,"sql语法错误"),
	SQL_UPDATE(2,"修改失败");
	
	private int code;
	private String msg;
	
	RespCode(int code, String msg){
		this.msg=msg;
	}
	
	public int getCode() {
		return code;
	}
	public String getMsg() {
		return msg;
	}
}
