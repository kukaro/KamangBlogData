#!/usr/bin/env bash

export VERSION=2.0.4
apt-get update
apt-get install -y wget mysql-client inotify-tools procps
wget https://github.com/sysown/proxysql/releases/download/v${VERSION}/proxysql_${VERSION}-debian9_amd64.deb -O /opt/proxysql_${VERSION}-debian9_amd64.deb
dpkg -i /opt/proxysql_${VERSION}-debian9_amd64.deb
rm -f /opt/proxysql_${VERSION}-debian9_amd64.deb && \
rm -rf /var/lib/apt/lists/*
apt-get install vim

#proxysql --initial -c /etc/proxysql_1.cnf -D /root/proxy/proxy1
proxysql --initial

apt-get install -y mysql-server
#mysql -uadmin --port 6032 -h 127.0.0.1 -p
