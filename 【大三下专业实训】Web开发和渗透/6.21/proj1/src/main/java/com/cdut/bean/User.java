package com.cdut.bean;

public class User {

	
	private String username;
	
	private String realname;

	public User(String username2, String realname2) {
		this.realname=username2;
		this.realname=realname2;
		// TODO Auto-generated constructor stub
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getRealname() {
		return realname;
	}

	public void setRealname(String realname) {
		this.realname = realname;
	}

	@Override
	public String toString() {
		return "User [username=" + username + ", realname=" + realname + "]";
	}
	
	
}
