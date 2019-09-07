package net.theceres;

import com.rabbitmq.client.Channel;
import com.rabbitmq.client.Connection;
import com.rabbitmq.client.ConnectionFactory;
import com.rabbitmq.client.MessageProperties;

public class NewTask {

    private static final String TASK_QUEUE_NAME = "task_queue";

    public static void main(String[] argv) throws Exception {
        int TEST_MESSAGES = 4;
        ConnectionFactory factory = new ConnectionFactory();
        factory.setHost("localhost");
        factory.setPort(35672);
        factory.setUsername("uguest");
        factory.setPassword("pguest");
        try (Connection connection = factory.newConnection();
             Channel channel = connection.createChannel()) {
            for (int i = 1; i <= TEST_MESSAGES; i++) {
                channel.queueDeclare(TASK_QUEUE_NAME, false, false, false, null);
                String message = "Hello World!" + i;
                channel.basicPublish("", TASK_QUEUE_NAME,
                        MessageProperties.PERSISTENT_TEXT_PLAIN,
                        message.getBytes("UTF-8"));
                System.out.println(" [x] Sent '" + message + "'");
            }
        }
    }

}
