package example;

import javax.servlet.AsyncContext;
import javax.servlet.AsyncEvent;
import javax.servlet.AsyncListener;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(urlPatterns = {"/async"}, asyncSupported = true)
public class AsyncServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        final AsyncContext asyncContext = request.startAsync(request, response);
        asyncContext.setTimeout(5000);
        asyncContext.addListener(new AsyncListener() {
            @Override
            public void onComplete(AsyncEvent asyncEvent) throws IOException {
                System.out.println("AsyncServlet.onComplete");
                System.out.println("asyncEvent = [" + asyncEvent + "]");
            }

            @Override
            public void onTimeout(AsyncEvent asyncEvent) throws IOException {
                System.out.println("AsyncServlet.onTimeout");
                System.out.println("asyncEvent = [" + asyncEvent + "]");
            }

            @Override
            public void onError(AsyncEvent asyncEvent) throws IOException {
                System.out.println("AsyncServlet.onError");
                System.out.println("asyncEvent = [" + asyncEvent + "]");
            }

            @Override
            public void onStartAsync(AsyncEvent asyncEvent) throws IOException {
                System.out.println("AsyncServlet.onStartAsync");
                System.out.println("asyncEvent = [" + asyncEvent + "]");
            }
        });
        asyncContext.start(() -> System.out.println("lambda"));
        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        asyncContext.complete();
    }
}
