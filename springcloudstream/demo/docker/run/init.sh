#!/bin/bash

hostname=$(hostname -I | tr -d ' ')

cd /root
echo 'run init.sh' >> log.txt

cd kafka

sed -ri "s/#advertised.listeners=PLAINTEXT:\/\/your.host.name:9092/listeners=PLAINTEXT:\/\/${hostname}:9092/" config/server.properties

# zookeeper on
./bin/zookeeper-server-start.sh -daemon config/zookeeper.properties
# kafka on
./bin/kafka-server-start.sh -daemon config/server.properties

sleep 5s
# make topic
./bin/kafka-topics.sh --create --zookeeper localhost:2181 --replication-factor 1 --partitions 1 --topic test

# delete topic
#./bin/kafka-topics.sh --delete --zookeeper localhost:2181 --topic test

# see result , if you want to excute, you remove sharp(#) plz.
#./bin/kafka-topics.sh --describe --zookeeper localhost:2181 --topic test

# 프로듀서 시작할때 이거 키고 다.
#./bin/kafka-console-producer.sh --broker-list localhost:9092 --topic test

# 컨슈머로 읽을때 이거 키고 받는다.
#./bin/kafka-console-consumer.sh --bootstrap-server localhost:9092 --topic test --from-beginning

/usr/sbin/sshd -D

./bin/zookeeper-server-start.sh -daemon config/zookeeper.properties
./bin/kafka-server-start.sh -daemon config/server.properties
./bin/kafka-topics.sh --create --zookeeper localhost:2181 --replication-factor 1 --partitions 1 --topic test
