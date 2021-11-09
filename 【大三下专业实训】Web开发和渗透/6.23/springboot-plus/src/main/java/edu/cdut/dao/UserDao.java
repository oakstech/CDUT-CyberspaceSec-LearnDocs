package edu.cdut.dao;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;

import edu.cdut.bean.User;
@Mapper
public interface UserDao {
	
	public List<User> showall();
	
	public int deluser(int id);
	
	public int updateuser(User user);
	
	public int insertuser(User user);

}
