#!/usr/bin/env bash

#run myubuntu instance
docker build -t myubuntu ./docker/
docker-compose -f ./docker/docker-compose.yml up -d