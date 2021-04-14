kubectl run echoserver --generator=run-pod/v1 --image="k8s.gcr.io/echoserver:1.10" --port=8080
#kubectl run nginx-app --image nginx --port=80