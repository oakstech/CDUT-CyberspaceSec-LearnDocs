## 二层主机发现：

arp-scan -I eth0 ip网段

nmap -PR ip网段 -n -sP

nmap -PR ip网段 -n -sP -oX ping.xml

## 三层发现：

nmap -PE ip网段 -n -sP -oX ping3.xml





1. IP探测：`nmap -PE 192.168.92.0/24`（三层扫描）

   根据端口号开放情况，确认目标主机IP为192.168.92.163

2. 开放端口探测：`nmap -p 0-10000 192.168.92.163`

   发现开放端口为22、3000

3. 服务版本检测：`nmap -sV 192.168.92.163`

   探测到ssh、Node.js

| IP       | 192.168.92.163            |
| -------- | ------------------------- |
| 开放端口 | 22、3000                  |
| 版本检测 | ssh(22)：OpenSSH 7.2p2    |
|          | Node.js Express Framework |
| 系统版本 | Ubuntu/Linux3.x\|4.x      |

