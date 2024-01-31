FROM alpine:3.18

# PHP 및 MariaDB 클라이언트, wp-cli 설치
RUN apk add --no-cache php81 php81-fpm php81-mysqli php81-json php81-curl \
php81-dom php81-exif php81-fileinfo php81-mbstring php81-openssl php81-xml \
php81-zip php81-phar php81-iconv curl mariadb-client && \
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
chmod +x wp-cli.phar && \
mv wp-cli.phar /usr/local/bin/wp

# 작업 디렉토리 설정
WORKDIR /var/www/html

# php-fpm 설정 변경
RUN sed -i 's/;chdir = \/var\/www/chdir = \/var\/www\/html/g' /etc/php81/php-fpm.d/www.conf
RUN sed -i 's/listen = 127.0.0.1:9000/listen = 0.0.0.0:9000/g' /etc/php81/php-fpm.d/www.conf

# 포트 노출
EXPOSE 9000

# WordPress 초기화 및 실행 스크립트 복사 후 실행
COPY tools/init.sh /tmp/init.sh
ENTRYPOINT [ "sh", "/tmp/init.sh" ]