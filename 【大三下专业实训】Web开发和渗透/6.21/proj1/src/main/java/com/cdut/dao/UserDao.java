package com.cdut.dao;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import com.cdut.bean.User;
import com.cdut.jdbc.JdbcUtil;

public class UserDao {

	public List<User> showAll() throws SQLException{
		Connection con=JdbcUtil.DriverManager();
		Statement statement=con.createStatement();
		ResultSet rs=statement.executeQuery("select * from user");
		List<User> users=new ArrayList<>();
		User user=null;
		while(rs.next()) {
			String username=rs.getString(1);
			String realname=rs.getString(2);
			user=new User(username,realname);
			users.add(user);
		}
		return users;
	}
}
