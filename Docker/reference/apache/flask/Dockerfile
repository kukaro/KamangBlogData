# Install ubuntu
FROM ubuntu:16.04
MAINTAINER kukaro <justkukaro@naver.com>
RUN apt-get -y update && apt-get -y upgrade

# Install python
RUN apt-get -y install python3
RUN apt-get -y update && apt-get -y install python3-pip

# Make port 80 available to the world outside
EXPOSE 5000

# Import python project
ADD FLASKAPP /var/www/html/FLASKAPP

# Install pip module
RUN /usr/bin/pip3 install --upgrade pip && pip3 install -r /var/www/html/FLASKAPP/requirements.txt

# CMD
CMD python3 /var/www/html/FLASKAPP/__init__.py -D FOREGROUND