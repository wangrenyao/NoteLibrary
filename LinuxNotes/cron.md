# <B><Center> CRON命令介绍 </Center></B>


### CRON是command run on 的缩写
crontab -e
service cron restart
@daily pwd

```bash
#write out current crontab
crontab -l > mycron
#echo new cron into cron file
echo "00 09 * * 1-5 echo hello" >> mycron
#install new cron file
crontab mycron
rm mycron
```
``` bash
/var/spool/cron/crontabs

/etc/cron.d/	Put all scripts here and call them from /etc/crontab file.
/etc/cron.daily/	Run all scripts once a day
/etc/cron.hourly/	Run all scripts once an hour
/etc/cron.monthly/	Run all scripts once a month
/etc/cron.weekly/	Run all scripts once a week
```
## 写脚本放到daily目录下
