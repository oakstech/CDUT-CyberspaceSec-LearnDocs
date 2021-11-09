<template>
	<view class="content">
		<view class="text-area">
			<text class="title">{{title}}</text>
		</view>
		<view v-for="(item) in info">
			<table border="1">
				<tr>
					<td>id：{{item.id}}</td>
					<td>姓名：{{item.username}}</td>
					<td>密码：{{item.password}}</td>
				</tr>
			</table>

			
			
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				title: '6.23-Homework',
				info: '未读取到数据'
			}
		},
		onLoad() {
			this.getInfo();
		},
		methods: {
			getInfo() {
				var _self = this;
				uni.request({
					url: 'http://localhost:8888/users',
					header: {
						'content-type': 'applicaton/json'
					},
					success: (res) => {
						console.log(res.data);
						_self.info = res.data.data
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

	.text-area {
		display: flex;
		justify-content: center;
	}

	.title {
		font-size: 36rpx;
		color: #8f8f94;
	}
</style>
