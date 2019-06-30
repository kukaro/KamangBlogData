FROM ubuntu:latest
MAINTAINER kukaro <justkukaro@naver.com>
RUN apt-get update
RUN apt-get install -y openssh-server
RUN mkdir /var/run/sshd

#set password
RUN echo 'root:root' |chpasswd

#replace sshd_config
RUN sed -ri 's/^#?PermitRootLogin\s+.*/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -ri 's/UsePAM yes/#UsePAM yes/g' /etc/ssh/sshd_config

#make .ssh
RUN mkdir /root/.ssh

RUN apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

#install proxysql
RUN apt-get update
RUN wget https://github.com/sysown/proxysql/releases/download/v1.4.9/proxysql_1.4.9-ubuntu16_amd64.deb
RUN dpkg -i proxysql_1.4.9-ubuntu16_amd64.deb
RUN apt-get install -y lsb-release

RUN service proxysql start

EXPOSE 22

CMD ["/usr/sbin/sshd", "-D"]

