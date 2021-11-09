package edu.cdut.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class HelloController {

	@RequestMapping(value="springboot")
	@ResponseBody
	public String hello() {
		return "hello,SpringBoot";
	}
}