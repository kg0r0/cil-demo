# cil-demo
## Usage
1.send_config.cを
```
$ gcc -o send_config send_config.c
```
としてコンパイルし、/opt/test_dir/bin以下に配置

2.run\_send\_config.hを/opt/test\_dir/script以下に配置

3./etc/systemd/system以下に、send\_config.serviceを登録

4.サービスとして登録されているか確認
```
# systemctl list-unit-files --type=service|grep send_config
send_config.service                         disabled
```

5.サービスを起動
```
# systemctl start send_config
```

6.サービスの自動起動を有効化
```
# systemctl enable send_config
```

7.ひとまずSELinuxをPermissiveモードにする
```
# setenforce 0
```

