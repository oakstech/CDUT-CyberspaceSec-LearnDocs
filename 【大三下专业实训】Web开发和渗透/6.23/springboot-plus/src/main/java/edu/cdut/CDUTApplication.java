package edu.cdut;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@MapperScan(value="edu.cdut.dao")
public class CDUTApplication {

	public static void main(String[] args){
		SpringApplication.run(CDUTApplication.class, args);
	}
}
