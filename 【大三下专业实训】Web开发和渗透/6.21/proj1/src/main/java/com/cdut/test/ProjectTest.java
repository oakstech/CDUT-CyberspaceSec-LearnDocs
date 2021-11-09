package com.cdut.test;

import java.sql.SQLException;

import com.cdut.dao.UserDao;

public class ProjectTest {
	public static void main(String[] args) {
		
		UserDao userDao=new UserDao();
		try {
			System.out.println(userDao.showAll());
		} catch(SQLException e) {
			e.printStackTrace();
		}
	}
}
