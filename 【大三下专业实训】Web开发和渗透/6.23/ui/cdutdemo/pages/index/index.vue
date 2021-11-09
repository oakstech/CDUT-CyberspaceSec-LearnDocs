<template>
	<view class="content">
		<image class="logo" src="/static/logo.png"></image>
		<view class="text-area">
			<text class="title">{{title}}</text>
			<text>{{msg}}</text>
		</view>
		<view @tap="gotoLunBo">走起</view>
		<button v-on:click="thing1">click</button>
		<view v-html="rawHtml"></view>
		<view v-if="seen">看得到</view>
		<view v-else>看不到</view>
		<view v-for="(u,index) in users">
			{{index}}-{{u.username}}-{{u.age}}
		</view>
		
		<view class="text-area">
			<text class='title'>{{info}}</text>
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				title: 'Hello',
				msg: 'you',
				rawHtml: '<p>s</p>',
				seen: true,
				users: [
					{username: 'Bob',age: 18},
					{username: 'Tom',age: 19}
				],
				info: '无数据'
			}
		},
		onLoad() {
			this.getInfo();
		},
		methods: {
			gotoLunBo(){
				uni.navigateTo({
					url: "/pages/test/new_file"
				})
			},
			thing1(){
				console.log("s");
			},
			
			getInfo(){
			var _self=this;	
			uni.request({
				url: 'http://localhost:8888/uniapp',
				header: {
					'content-type': 'text/html,charset=utf-8'
				},
				success: (res) => {
					console.log(res.data);
					_self.info=res.data
				}
			});
			}
		}
	}
</script>

<style>
	.content {
		display: flex;
		flex-direction: column;
		align-items: center;
		justify-content: center;
	}

	.logo {
		height: 200rpx;
		width: 200rpx;
		margin-top: 200rpx;
		margin-left: auto;
		margin-right: auto;
		margin-bottom: 50rpx;
	}

	.text-area {
		display: flex;
		justify-content: center;
	}

	.title {
		font-size: 36rpx;
		color: #8f8f94;
	}
</style>
