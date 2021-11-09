package edu.cdut.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import edu.cdut.bean.User;
import edu.cdut.dao.UserDao;

@Controller
public class UserController {
	@Autowired  //代表注入不需要自己new了
	private UserDao userDao;

	@RequestMapping("users")
	@ResponseBody
	public List<User> showAll(){
		return userDao.showall();
	}
	
	@RequestMapping("deluser")
	@ResponseBody
	public int delUser(){
		return userDao.deluser(3);
	}
	
	@RequestMapping("updateuser")
	@ResponseBody
	public int updateUser(){
		return userDao.updateuser(new User(3,"lyp","lyp666"));
	}
	
	@RequestMapping("insertuser")
	@ResponseBody
	public int insertUser(){
		return userDao.insertuser(new User(3,"李义鹏","123456"));
	}
}
