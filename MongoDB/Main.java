package com.company;

import com.mongodb.MongoClient;
import com.mongodb.ServerAddress;
import com.mongodb.client.FindIterable;
import com.mongodb.client.MongoIterable;
import org.bson.Document;

public class Main {

    public static void main(String[] args) {
        // write your code here
        String MongoDB_IP = "127.0.0.1";
        int MongoDB_PORT = 27017;
        String DB_Name = "test";

        MongoClient mongoClient = new MongoClient(new ServerAddress(MongoDB_IP, MongoDB_PORT));
        MongoIterable<String> databaseNames = mongoClient.listDatabaseNames();
        System.out.println("DB목록");
        for (String str : databaseNames) {
            System.out.println(str);
        }
        MongoIterable<String> collectionNames = mongoClient.getDatabase("test").listCollectionNames();
        System.out.println("test의 컬렉션 목록");
        for (String str : collectionNames) {
            System.out.println(str);
        }
        MongoIterable<Document> documents = mongoClient.getDatabase("test").getCollection("coltest").find();
        System.out.println("coltest의 도큐먼트 목록");
        for (Document document : documents) {
            System.out.println(document);
        }
        System.out.println("coltest의 값 key로 불러오기");
        for (Document document : documents) {
            System.out.println(document.get("name"));
        }
    }
}
