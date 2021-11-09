package com.cdut.jdbc;

import java.sql.Connection;
import java.sql.SQLException;

public class JdbcUtil{

	private static final String username="javaweb";
	
	private static final String password="123456";
	
	private static final String url="jdbc:mysql:///javaweb?useUnicode=true&characterEncoding=UTF-8&serverTimezone=UTC&useSSL=false";
	
	private static final String driver="com.mysql.cj.jdbc.Driver";
	
	static {
		try {
			Class.forName(driver);
		}catch(ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public static Connection DriverManager() throws SQLException{
		return java.sql.DriverManager.getConnection(url,username,password);
	}
}