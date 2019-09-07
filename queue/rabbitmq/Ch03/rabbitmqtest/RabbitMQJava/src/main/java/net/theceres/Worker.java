package net.theceres;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;
import com.rabbitmq.client.DeliverCallback;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

public class Worker {

    public static void main(String[] argv) throws Exception {
        int TEST_Count = 3;
        for (int i = 0; i < TEST_Count; i++) {
            new MyThread(i).start();
        }
    }

}

class MyThread extends Thread {
    private static final String TASK_QUEUE_NAME = "task_queue";

    private int num;

    MyThread(int num) {
        this.num = num;
    }

    @Override
    public void run() {
        int TEST_qos = 2;
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        factory.setPort(35672);
        factory.setUsername("uguest");
        factory.setPassword("pguest");
        final Connection connection;
        try {
            connection = factory.newConnection();
            final Channel channel = connection.createChannel();

            channel.queueDeclare(TASK_QUEUE_NAME, false, false, false, null);
            System.out.println(" [*] Waiting for messages. To exit press CTRL+C");

            channel.basicQos(TEST_qos);

            DeliverCallback deliverCallback = (consumerTag, delivery) -> {
                String message = new String(delivery.getBody(), "UTF-8");

                System.out.println(num + " [x] Received '" + message + "'");
                try {
                    doWork(message);
                } finally {
                    System.out.println(num + " [x] Done");
//                    channel.basicAck(delivery.getEnvelope().getDeliveryTag(), false);
                }
            };
            channel.basicConsume(TASK_QUEUE_NAME, false, deliverCallback, consumerTag -> {
            });
        } catch (IOException e) {
            e.printStackTrace();
        } catch (TimeoutException e) {
            e.printStackTrace();
        }

    }

    private void doWork(String task) {
        int TEST_TIME = 20;
        try {
            Thread.sleep(TEST_TIME);
        } catch (InterruptedException _ignored) {
            Thread.currentThread().interrupt();
        }
    }
}
