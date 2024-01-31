FROM alpine:3.18

# nginx 설치 및 openssl 인증서 생성
RUN apk add --no-cache nginx openssl && \
openssl req -x509 -nodes \
-days 365 -newkey rsa:2048 \
-out /etc/ssl/certs/nginx-selfsigned.crt \
-keyout /etc/ssl/private/nginx-selfsigned.key \
-subj "/C=KR/ST=Seoul/L=Gaepo/O=42Seoul/OU=Develop/CN=jikoo_blog"

# 포트 노출
EXPOSE 443

# Nginx 설정 파일 복사 후 실행
COPY conf/nginx.conf /etc/nginx/http.d
CMD [ "nginx", "-g", "daemon off;" ]