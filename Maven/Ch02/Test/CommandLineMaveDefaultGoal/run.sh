#!/usr/bin/env bash

#run pom.xml
if [ -f "pom.xml" ];then
    echo "pom.xml exist"
else
    echo "pom.xml not exist"
    mvn archetype:generate -DgroupId=net.theceres -DartifactId=CommandLineMakeMaven -DarchetypeArtifactId=maven-archetype-quickstart -DinteractiveMode=false
fi