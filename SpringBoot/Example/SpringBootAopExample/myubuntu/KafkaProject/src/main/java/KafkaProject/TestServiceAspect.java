package KafkaProject;


import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.springframework.stereotype.Component;

@Aspect
@Component
public class TestServiceAspect {
    @Around("execution(* KafkaProject.sub.TestService.*(..))")
    public void logging(ProceedingJoinPoint pjp) throws Throwable {
        System.out.format("start - %s / %s / %s \n", pjp.getSignature().getDeclaringTypeName(), pjp.getSignature().getName(), pjp.getArgs()[0]);
        Object result = pjp.proceed();
        System.out.format("\nfinished - %s / %s / %s\n", pjp.getSignature().getDeclaringTypeName(), pjp.getSignature().getName(), pjp.getArgs()[0]);
    }
}
