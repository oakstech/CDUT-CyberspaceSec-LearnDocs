<template>
	<view class="content">
		<view class="text-area">
			<text class="title">{{title}}</text>
		</view>
	
		<view>
			<textarea placeholder="输入课程名:" v-model="coursename"></textarea>
			<button v-on:click="getCourse()">查询</button>
		</view>

		<view v-for="(index,item) in course">
			{{item}}：{{index}}
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				title: '课程查询',
				info: '未读取到数据',
				course: '',
				focus: false,
				inputValue: '',
				coursename: ''
			}
		},
		onLoad() {
		},
		methods: {
			getCourse() {
				uni.request({
					url: 'http://localhost:8888/course',
					header: {
						'content-type': 'applicaton/json'
					},
					data: {'coursename': this.coursename},
					success: (res) => {
						console.log(res.data);
						this.course = res.data.data
					}
				});
			},
			// onKeyInput: function(event) {
			// 	this.coursename = event.target.value
			// }
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
