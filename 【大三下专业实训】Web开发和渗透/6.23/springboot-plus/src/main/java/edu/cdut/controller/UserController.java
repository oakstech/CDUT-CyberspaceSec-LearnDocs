package edu.cdut.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.fasterxml.jackson.databind.ObjectMapper;

import edu.cdut.bean.User;
import edu.cdut.dao.UserDao;
import edu.cdut.utils.ReponseEntity;
import edu.cdut.utils.RespCode;

@Controller
@CrossOrigin
public class UserController {
	@Autowired  //代表注入不需要自己new了
	private UserDao userDao;

//	@RequestMapping("users")
//	@ResponseBody
//	public List<User> showAll(){
//		
//		ObjectMapper om=new ObjectMapper();
//		
//		try {
//			om.writeValueAsString(userDao.showall());
//			System.out.println(om.writeValueAsString(userDao.showall()));
//		} catch(JsonProcessingException e)
//		e.printStackTrace();
//		
//		return userDao.showall();
//	}

	@RequestMapping("users")
	@ResponseBody	
	public ReponseEntity showAll() {
		ReponseEntity reponseEntity=null;
		try {
			List<User> users=userDao.showall();
			reponseEntity = new ReponseEntity(RespCode.SUCCESS,users);
			return reponseEntity;
		} catch (Exception e) {
			reponseEntity=new ReponseEntity(RespCode.WARN);
			return reponseEntity;
		}
	}
	
	@RequestMapping("deluser")
	@ResponseBody
	public ReponseEntity delUser(){
		ReponseEntity reponseEntity=null;
		try {
			int rtn=userDao.deluser(3);
			reponseEntity = new ReponseEntity(RespCode.SUCCESS,rtn);
			return reponseEntity;
		} catch (Exception e) {
			reponseEntity=new ReponseEntity(RespCode.WARN);
			return reponseEntity;
		}
	}
	
	@RequestMapping("updateuser")
	@ResponseBody
	public ReponseEntity updateUser(){
		try {
			if(userDao.updateuser(new User(3,"lyp","lyp666"))>0){
				return new ReponseEntity(RespCode.SUCCESS);
			} else {
				return new ReponseEntity(RespCode.SQL_UPDATE);
			}
		} catch (Exception e) {
			return new ReponseEntity(RespCode.SQL);
		}
	}
	
	@RequestMapping("insertuser")
	@ResponseBody
	public ReponseEntity insertUser(){
		ReponseEntity reponseEntity=null;
		try {
			int rtn=userDao.insertuser(new User(3,"李义鹏","123456"));
			reponseEntity = new ReponseEntity(RespCode.SUCCESS,rtn);
			return reponseEntity;
		} catch (Exception e) {
			reponseEntity=new ReponseEntity(RespCode.WARN);
			return reponseEntity;
		}
	}
}
